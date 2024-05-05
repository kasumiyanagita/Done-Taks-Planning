#ifndef STEP_H
#define STEP_H
#include <string>
#include <ctime>

class Step {
	int m_id{};
	std::string m_description{};
	double m_minute{};
public:
	Step();
	Step& operator=(std::string desc);
	Step& operator=(int min);
	operator std::string() const;
	int minute() const;

};
#endif