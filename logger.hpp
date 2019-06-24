#ifndef LOGGER_H
#define LOGGER_H
#define _CRT_SECURE_NO_WARNINGS

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <iostream> // stringstream
#include <sstream>
#include <iomanip> // put_time
#include <string>  // string

struct Logger
{
	std::string return_current_time_and_date();
	
	void initialize()
	{
		std::cout << "Space Simulation initialized on:\n";
		std::cout << return_current_time_and_date() << "\n";
	}

	Logger()
	{
		initialize();
	}

	

private:
	long long int iter = 0;
};

#endif