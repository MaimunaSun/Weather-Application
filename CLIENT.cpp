#define CURL_STATICLIB
#include "CLIENT.h"
#include <iostream>
#include <string>
#include <sstream>
#include "curl/curl.h"

int Client::ID = 9995;
size_t Client::my_write(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);
	return totalsize;
}

void Client::SplitParameters() {
	char space_char = ' ';
	int i = 0;
	std::stringstream sstream(GetRow());
	std::string word;
	while (getline(sstream, word, space_char)) {
		SplitParamters[i] = word;
		i++;
	}

}

void Client::setRow() {
	std::string string1 = "https://www.ecobliss.co.za/get_row.php?row=";
	std::string string2 = std::to_string(ID);
	std::string url = string1 + string2;
	const char* c_url = url.c_str();

	std::string result;
	CURL* curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();
	if (curl) {

		curl_easy_setopt(curl, CURLOPT_URL, c_url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}

	curl_global_cleanup();
	this->result = result;
	ID++;
}

std::string Client::GetRow() {
	return result;
}

std::string Client::GetID() {
	SplitParameters();
	std::string ID = SplitParamters[0];
	return ID;


}
std::string Client::GetDate() {
	SplitParameters();
	std::string Date;
	Date = SplitParamters[2];
	return Date;
}
std::string Client::GetTime() {
	SplitParameters();
	std::string Time;
	Time = SplitParamters[3];
	return Time;
}
std::string Client::GetTemperature() {
	SplitParameters();
	std::string Temperature;
	Temperature = SplitParamters[4];
	return Temperature;
}
std::string Client::GetRelativeHumidity() {
	SplitParameters();
	std::string RelativeHumidity;
	RelativeHumidity = SplitParamters[5];
	return RelativeHumidity;
}
std::string Client::GetPressure() {
	SplitParameters();
	std::string Pressure;
	Pressure = SplitParamters[6];
	Pressure = Pressure.substr(0, 4);
	return Pressure;
}
int Client::GetTemperatureInt() {
	this->TemperatureInt = stoi(GetTemperature());
	return TemperatureInt;

}
int Client::GetRelativeHumidityInt() {
	this->RelativeHumidityInt = stoi(GetRelativeHumidity());
	return RelativeHumidityInt;
}
int Client::GetPressureInt() {
	this->PressureInt = stoi(GetPressure());
	return PressureInt;
}


