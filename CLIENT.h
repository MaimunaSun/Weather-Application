#pragma once
#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <sstream>
#include "curl/curl.h"

class Client {
private:
	std::string result;
	int TemperatureInt = 0;
	int RelativeHumidityInt = 0;
	int PressureInt = 0;
	std::string SplitParamters[10];
	static int ID;

public:
	static size_t my_write(void* buffer, size_t size, size_t nmemb, void* param);
	void SplitParameters();
	void setRow();
	std::string GetRow();
	std::string GetID();
	std::string GetDate();
	std::string GetTime();
	std::string GetTemperature();
	std::string GetRelativeHumidity();
	std::string GetPressure();
	int GetTemperatureInt();
	int GetRelativeHumidityInt();
	int GetPressureInt();
};

