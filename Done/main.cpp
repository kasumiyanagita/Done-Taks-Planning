#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Step.h"

int main() {
	std::string problem;
	std::string solution;
	std::string step = "";
	std::vector<Step> steps;
	int counter = 0;
	std::string time = "";

	std::cout << "What is the problem?" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, problem);
	std::cout << "\nTo solve this problem, what do you have to do?" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, solution);
	std::cout << "\nLet's create step by step plan (enter \"end\" after all the steps entered)" << std::endl;

	while (step != "end") {
		Step tmp_s;
		std::cout << ++counter << ": ";
		std::getline(std::cin, step);
		tmp_s = step;
		if (step != "end") {
			steps.push_back(tmp_s);
		}
	}

	std::cout << "\nDo you want to add the time for each step? (Y/N)" << std::endl;
	std::cout << "> ";
	while (std::tolower(time[0]) != 'y' && std::tolower(time[0]) != 'n') {
		std::getline(std::cin, time);
	}
	counter = 0;
	if (std::tolower(time[0]) == 'y') {
		std::cout << "\nAssign time for each step (min)" << std::endl;
		for (auto& x : steps) {
			double m;
			std::cout << ++counter << ". " << static_cast<std::string>(x) << ": ";
			while (!(std::cin >> m)) {
				try {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw std::string("Invalid value, please enter the time for the step again: ");
				}
				catch (std::string err) {
					std::cerr << err;
				}
			}
			x = m;
		}
	}
	std::cout << "\nBased on the information entered, program is creating the final table for your work plan..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "Program completed to create work plan for you\n\n" << std::endl;

	std::cout << "---------------------------" << std::endl;
	std::cout << "      *** Result ***" << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Problem : " << problem << std::endl;
	std::cout << "Solution: " << solution << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "Step by Step Work Plan" << std::endl;
	std::cout << "---------------------------" << std::endl;
	counter = 0;
	if (std::tolower(time[0]) == 'y') {
		for (auto& x : steps) {
			std::cout << ++counter << ". " << static_cast<std::string>(x) << " (" << x.minute() << ")" << std::endl;
		}
	}
	else {
		for (auto& x : steps) {
			std::cout << ++counter << " : " << static_cast<std::string>(x) << std::endl;
		}
	}
	std::cout << "---------------------------" << std::endl;
	
}