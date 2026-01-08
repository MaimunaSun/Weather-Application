# Weather Application

This is a **desktop weather application** built with **C++/CLI** and **Windows Forms**. It retrieves live weather data from a Web API using **libcurl** and presents it in a **user-friendly GUI**.

## Features
- Live weather data retrieval: Temperature, Humidity, Pressure
- Derived calculations: Dew point, Rain likelihood, Weather comfort
- Predictions for next hour and weather cycle
- Visual GUI built with Windows Forms

## Technologies
- C++/CLI
- libcurl
- Windows Forms
- Standard C++ Libraries

## How It Works

1. **Data Retrieval**:  
   The `Client` class fetches weather data from the Web API using libcurl.

2. **Data Processing**:  
   The raw data is split and converted into usable formats (temperature, humidity, pressure, dew point, etc.).

3. **Data Visualization**:  
   The `Home` Windows Form displays the current weather, predictions, and insights.
