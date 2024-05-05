#include <ctime>
#include "Step.h"

Step::Step() {
	m_id = 0;
	m_description = "";
	m_minute = 0;
}
Step& Step::operator=(std::string desc) {
	m_description = desc;
	return *this;
}
Step& Step::operator=(int min) {
	m_minute = min;
	return *this;
}
Step::operator std::string() const {
	return m_description;
}
int Step::minute() const {
	return m_minute;
}