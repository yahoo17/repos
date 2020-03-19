#include "Time.h"
static Time staticoj("static ¶ÔÏó");
void Time::printTime()
{
	cout << setw(2) << setfill('0') << m_hour <<':'<< setw(2) << setfill('0') \
		<< m_minute << ':' << setw(2) << setfill('0') << m_second << '\n';
}