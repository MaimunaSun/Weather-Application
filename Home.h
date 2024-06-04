#pragma once

#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include "CLIENT.h"
#include <ctime>


namespace WeatherApp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	
	public:
		Home(void)
		{
			
				InitializeComponent();
					
					//Get the current date and time
					DateTime datetime = DateTime::Now;
					this->currenttime->Text = datetime.ToString();


					int currtemperature;
					int currrelativehumidity;
					int currairpressure;
					
					Client stuff;
					stuff.setRow();
					currtemperature = stuff.GetTemperatureInt();
					currrelativehumidity = stuff.GetRelativeHumidityInt();
					currairpressure = stuff.GetPressureInt();
				


					this->temperature->Text = currtemperature.ToString();
					this->humidity->Text = currrelativehumidity.ToString();
					this->airpressure->Text = currairpressure.ToString();
					int rh = Convert::ToDouble(humidity->Text);
					int temp = Convert::ToDouble(temperature->Text);
					int pressure = Convert::ToDouble(airpressure->Text);
					String^ statement = weathercomfort->Text;
					String^ statement2 = rainprediction->Text;
					String^ statement3 = rainprediction->Text;
					String^ statement4 = rainhourprediction->Text;
					String^ statement5 = rainsign->Text;
					String^ statement6 = dewpointsign->Text;
					String^ statement7 = cycle->Text;
					String^ statement8 = explanation->Text;

					int dp = Convert::ToDouble(temp - ((100 - rh) / 5));
					this->dewpoint->Text = dp.ToString();


					if (rh >= 100) {

						statement2 = "Raining";
						this->rainprediction->Text = statement2->ToString();
						statement7 = "Precipitation";
						statement8 = "Precipitation is occuring in the form of rain";
						this->cycle->Text = statement7->ToString();
						this->explanation->Text = statement8->ToString();
						statement = "Cold but Comfortable";
						this->weathercomfort->Text = statement->ToString();
						statement6 = "It is raining, it could be windy, which might cause the air to feel cold";
						this->dewpointsign->Text = statement6->ToString();

					}
					else if (rh <= 100) {

						statement3 = "No Rain";
						this->rainprediction->Text = statement3->ToString();

						if (dp <= 16) {
							statement = "Feeling Dry and Comfortable";
							this->weathercomfort->Text = statement->ToString();
							statement6 = "The air mositure is dry and comfortable, cool clothing will do!";
							this->dewpointsign->Text = statement6->ToString();
						}
						else if ((dp = 16) || (dp = 21)) {

							statement = "Its Sticky and Muggy";
							this->weathercomfort->Text = statement->ToString();
							statement6 = "The moisture in the air is moderately high and moist, you might want to consider wearing something cool";
							this->dewpointsign->Text = statement6->ToString();

						}
						else if (dp >= 21) {

							statement = "The air is moist";
							this->weathercomfort->Text = statement->ToString();
							statement6 = "The moisture in the air is very high,and your body could be at risk of heat illnesses, please stay hydrated and in shaded areas to avoid dehydration!";
							this->dewpointsign->Text = statement6->ToString();

						}
						else {}

					}
					else {}


					if (temp <= dp || rh >= 100) {
						statement4 = "Most Likely To Rain";
						this->rainhourprediction->Text = statement4->ToString();

						if (rainprediction->Text == "No Rain") {
							statement5 = "It most likely will rain, please wear a jersey and carry an umbrella!";
							this->rainsign->Text = statement5->ToString();
							statement7 = "Condensation";
							statement8 = "Clouds have formed in the sky, and precipitation is likely to occur";
							this->cycle->Text = statement7->ToString();
							this->explanation->Text = statement8->ToString();
						}
						else if (rainprediction->Text == "Raining") {
							statement5 = "It is raining, please wear something warm and stay dry";
							this->rainsign->Text = statement5->ToString();

						}
					}
					else if (temp >= dp || rh >= 100) {
						statement4 = "Most Likely to not rain";
						this->rainhourprediction->Text = statement4->ToString();
						statement5 = "It likely will not rain, an umbrella will not be needed";
						this->rainsign->Text = statement5->ToString();
						statement7 = "Evaporation";
						statement8 = "Evaporation is taking place";
						this->cycle->Text = statement7->ToString();
						this->explanation->Text = statement8->ToString();
					}
					else {}


					if (pressure >= 1030) {
						this->predictedtemperature->Text = stuff.GetTemperatureInt().ToString();
						String^ statement4 = predictedweathercondition->Text;
						statement4 = "Weather Conditions will stay the same";
						this->predictedweathercondition->Text = statement4->ToString();
					}
					else if (pressure <= 1030) {
						int predictedtemp = temp - 2;
						this->predictedtemperature->Text = predictedtemp.ToString();
						String^ statement4 = predictedweathercondition->Text;
						statement4 = "The Weather condition is likely to be cold/windy or raining";
						this->predictedweathercondition->Text = statement4->ToString();
					}
			
		
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ rainsign;
private: System::Windows::Forms::TextBox^ dewpointsign;




	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ explanation;
	private: System::Windows::Forms::TextBox^ cycle;
	private: System::Windows::Forms::TextBox^ weathercycle;

	private: System::Windows::Forms::TextBox^ predictedweathercondition;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ weathercomfort;
	private: System::Windows::Forms::TextBox^ dewpoint;
	private: System::Windows::Forms::TextBox^ airpressure;


	private: System::Windows::Forms::TextBox^ rainprediction;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ currentweatherblock;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ currenttime;
	private: System::Windows::Forms::Label^ temperature;

	private: System::Windows::Forms::TextBox^ humidity;
private: System::Windows::Forms::Label^ predictedtemperature;
private: System::Windows::Forms::TextBox^ rainhourprediction;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::PictureBox^ weatherpic;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->weatherpic = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->rainhourprediction = (gcnew System::Windows::Forms::TextBox());
			this->predictedtemperature = (gcnew System::Windows::Forms::Label());
			this->humidity = (gcnew System::Windows::Forms::TextBox());
			this->temperature = (gcnew System::Windows::Forms::Label());
			this->currenttime = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->rainsign = (gcnew System::Windows::Forms::TextBox());
			this->dewpointsign = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->explanation = (gcnew System::Windows::Forms::TextBox());
			this->cycle = (gcnew System::Windows::Forms::TextBox());
			this->weathercycle = (gcnew System::Windows::Forms::TextBox());
			this->predictedweathercondition = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->weathercomfort = (gcnew System::Windows::Forms::TextBox());
			this->dewpoint = (gcnew System::Windows::Forms::TextBox());
			this->airpressure = (gcnew System::Windows::Forms::TextBox());
			this->rainprediction = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->currentweatherblock = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weatherpic))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->weatherpic);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->rainhourprediction);
			this->panel1->Controls->Add(this->predictedtemperature);
			this->panel1->Controls->Add(this->humidity);
			this->panel1->Controls->Add(this->temperature);
			this->panel1->Controls->Add(this->currenttime);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->rainsign);
			this->panel1->Controls->Add(this->dewpointsign);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->explanation);
			this->panel1->Controls->Add(this->cycle);
			this->panel1->Controls->Add(this->weathercycle);
			this->panel1->Controls->Add(this->predictedweathercondition);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->weathercomfort);
			this->panel1->Controls->Add(this->dewpoint);
			this->panel1->Controls->Add(this->airpressure);
			this->panel1->Controls->Add(this->rainprediction);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->currentweatherblock);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(771, 395);
			this->panel1->TabIndex = 2;
			// 
			// weatherpic
			// 
			this->weatherpic->Location = System::Drawing::Point(173, 60);
			this->weatherpic->Name = L"weatherpic";
			this->weatherpic->Size = System::Drawing::Size(139, 63);
			this->weatherpic->TabIndex = 40;
			this->weatherpic->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label12->Location = System::Drawing::Point(49, 354);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(81, 13);
			this->label12->TabIndex = 39;
			this->label12->Text = L"degrees celcius";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Location = System::Drawing::Point(55, 129);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(81, 13);
			this->label11->TabIndex = 38;
			this->label11->Text = L"degrees celcius";
			// 
			// rainhourprediction
			// 
			this->rainhourprediction->Location = System::Drawing::Point(136, 351);
			this->rainhourprediction->Multiline = true;
			this->rainhourprediction->Name = L"rainhourprediction";
			this->rainhourprediction->Size = System::Drawing::Size(166, 21);
			this->rainhourprediction->TabIndex = 37;
			// 
			// predictedtemperature
			// 
			this->predictedtemperature->AutoSize = true;
			this->predictedtemperature->BackColor = System::Drawing::SystemColors::HotTrack;
			this->predictedtemperature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->predictedtemperature->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->predictedtemperature->Location = System::Drawing::Point(48, 305);
			this->predictedtemperature->Name = L"predictedtemperature";
			this->predictedtemperature->Size = System::Drawing::Size(78, 55);
			this->predictedtemperature->TabIndex = 36;
			this->predictedtemperature->Text = L"10";
			// 
			// humidity
			// 
			this->humidity->Location = System::Drawing::Point(37, 214);
			this->humidity->Multiline = true;
			this->humidity->Name = L"humidity";
			this->humidity->Size = System::Drawing::Size(89, 21);
			this->humidity->TabIndex = 35;
			// 
			// temperature
			// 
			this->temperature->AutoSize = true;
			this->temperature->BackColor = System::Drawing::SystemColors::HotTrack;
			this->temperature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->temperature->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->temperature->Location = System::Drawing::Point(48, 74);
			this->temperature->Name = L"temperature";
			this->temperature->Size = System::Drawing::Size(78, 55);
			this->temperature->TabIndex = 33;
			this->temperature->Text = L"10";
			this->temperature->Click += gcnew System::EventHandler(this, &Home::temperature_Click_1);
			// 
			// currenttime
			// 
			this->currenttime->AutoSize = true;
			this->currenttime->BackColor = System::Drawing::Color::Transparent;
			this->currenttime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currenttime->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->currenttime->Location = System::Drawing::Point(17, 20);
			this->currenttime->Name = L"currenttime";
			this->currenttime->Size = System::Drawing::Size(70, 24);
			this->currenttime->TabIndex = 32;
			this->currenttime->Text = L"label12";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(394, 164);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(61, 13);
			this->label10->TabIndex = 30;
			this->label10->Text = L"RAIN FALL";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(394, 74);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(60, 13);
			this->label9->TabIndex = 29;
			this->label9->Text = L"HUMIDITY";
			// 
			// rainsign
			// 
			this->rainsign->Location = System::Drawing::Point(397, 180);
			this->rainsign->Multiline = true;
			this->rainsign->Name = L"rainsign";
			this->rainsign->Size = System::Drawing::Size(287, 55);
			this->rainsign->TabIndex = 28;
			this->rainsign->TextChanged += gcnew System::EventHandler(this, &Home::rainsign_TextChanged);
			// 
			// dewpointsign
			// 
			this->dewpointsign->Location = System::Drawing::Point(397, 89);
			this->dewpointsign->Multiline = true;
			this->dewpointsign->Name = L"dewpointsign";
			this->dewpointsign->Size = System::Drawing::Size(287, 72);
			this->dewpointsign->TabIndex = 27;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(382, 48);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(124, 18);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Significant Details";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::HotTrack;
			this->textBox2->Location = System::Drawing::Point(385, 49);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(309, 203);
			this->textBox2->TabIndex = 24;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(382, 278);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(105, 18);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Weather Cycle";
			// 
			// explanation
			// 
			this->explanation->Location = System::Drawing::Point(397, 335);
			this->explanation->Multiline = true;
			this->explanation->Name = L"explanation";
			this->explanation->Size = System::Drawing::Size(276, 37);
			this->explanation->TabIndex = 22;
			// 
			// cycle
			// 
			this->cycle->Location = System::Drawing::Point(397, 305);
			this->cycle->Name = L"cycle";
			this->cycle->Size = System::Drawing::Size(129, 20);
			this->cycle->TabIndex = 21;
			// 
			// weathercycle
			// 
			this->weathercycle->BackColor = System::Drawing::SystemColors::HotTrack;
			this->weathercycle->Location = System::Drawing::Point(385, 277);
			this->weathercycle->Multiline = true;
			this->weathercycle->Name = L"weathercycle";
			this->weathercycle->Size = System::Drawing::Size(309, 106);
			this->weathercycle->TabIndex = 20;
			// 
			// predictedweathercondition
			// 
			this->predictedweathercondition->Location = System::Drawing::Point(136, 305);
			this->predictedweathercondition->Multiline = true;
			this->predictedweathercondition->Name = L"predictedweathercondition";
			this->predictedweathercondition->Size = System::Drawing::Size(166, 41);
			this->predictedweathercondition->TabIndex = 18;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(24, 277);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 18);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Next Hour";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->textBox1->Location = System::Drawing::Point(27, 278);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(309, 105);
			this->textBox1->TabIndex = 15;
			// 
			// weathercomfort
			// 
			this->weathercomfort->Location = System::Drawing::Point(163, 129);
			this->weathercomfort->Name = L"weathercomfort";
			this->weathercomfort->Size = System::Drawing::Size(158, 20);
			this->weathercomfort->TabIndex = 14;
			// 
			// dewpoint
			// 
			this->dewpoint->Location = System::Drawing::Point(255, 214);
			this->dewpoint->Multiline = true;
			this->dewpoint->Name = L"dewpoint";
			this->dewpoint->Size = System::Drawing::Size(57, 21);
			this->dewpoint->TabIndex = 13;
			// 
			// airpressure
			// 
			this->airpressure->Location = System::Drawing::Point(145, 214);
			this->airpressure->Multiline = true;
			this->airpressure->Name = L"airpressure";
			this->airpressure->Size = System::Drawing::Size(57, 21);
			this->airpressure->TabIndex = 12;
			// 
			// rainprediction
			// 
			this->rainprediction->Location = System::Drawing::Point(38, 161);
			this->rainprediction->Multiline = true;
			this->rainprediction->Name = L"rainprediction";
			this->rainprediction->Size = System::Drawing::Size(283, 24);
			this->rainprediction->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(133, 198);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"AIR PRESSURE";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(252, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"DEW POINT";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 198);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"HUMIDITY";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(24, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Current Weather";
			// 
			// currentweatherblock
			// 
			this->currentweatherblock->BackColor = System::Drawing::SystemColors::HotTrack;
			this->currentweatherblock->Location = System::Drawing::Point(27, 48);
			this->currentweatherblock->Multiline = true;
			this->currentweatherblock->Name = L"currentweatherblock";
			this->currentweatherblock->Size = System::Drawing::Size(309, 203);
			this->currentweatherblock->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Lucida Sans", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(16, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(247, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Durban, KwaZulu Natal";
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 397);
			this->Controls->Add(this->panel1);
			this->Name = L"Home";
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->weatherpic))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void temperature_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void weatherconditions_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void temperature_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rainsign_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
