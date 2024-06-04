

#include "Home.h"
#include <iostream>
#include <array>
#include "CLIENT.h"
using namespace System;

using namespace System::Windows::Forms;


[STAThreadAttribute]

int main(array<System::String^>^ args) {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	WeatherApp1::Home hp;
	Application::Run(% hp);
	Client stuff;
	return 0;
}





