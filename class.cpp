/* this is a log system
it prints messages to console based on the level of warning and message input by user
level of warning = Error, Warning, and Info
Error = treated as lowest level, print "ERROR! (message)"
Warning  = treated as level above, prints both Error message and Warning Message
Info - treated as highest level, choosing this level prints only "INFO: (message)", does not print error or warning message. any wrong level name input by user also prints out info

done by making a log class that has the required functionalities*/


#include <iostream>
#include<string.h>

class Log
{

public:
	const int LogLevelError = 0;
	const int LogLevelWarn = 1;
	const int LogLevelInfo = 2;

	void SetLevel(std::string a)
	{
		if (a == "Error" || a == "error")
		{
			m_level = LogLevelError;
		}
		else if (a == "Warning"|| a == "warning")
		{
			m_level = LogLevelWarn;
		}
	}

	void Error(std::string a)
	{
		if (m_level >= LogLevelError && m_level< LogLevelInfo)
		{
			std::cout << "ERROR! " << a << std::endl;
		}
	}
	void Warn(std::string a)
	{
		if (m_level >= LogLevelWarn && m_level < LogLevelInfo)
		{
			std::cout <<"WARNING!! " << a << std::endl;
		}
	}
	void Info(std::string a)
	{
		if (m_level >= LogLevelInfo)
		{
			std::cout << "Info: " << a << std::endl;
		}
	}
private:
	int m_level = LogLevelInfo;
};
int main()
{
	Log log;
	std::string input;
	std::string message;
	std::cout << "Enter Message to be printed:" << std::endl;
	std::cin >> message;
	std::cout << "Enter Level of Warning:" << std::endl;
	std::cin >> input;
	log.SetLevel(input);
	log.Error(message);
	log.Warn(message);
	log.Info(message);
}
