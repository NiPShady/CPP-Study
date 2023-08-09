#include <iostream>
class Log
{
public:								//信息级别常量
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:							//信息级别
	int m_LogLevel = LogLevelInfo;
public:								//修改信息级别接口
	void SetLevel(int level) 
	{
		m_LogLevel = level;
	}
	void Error(const char* message)
	{
		if(m_LogLevel>= LogLevelError)
			std::cout << "[ERROR]" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]" << message << std::endl;
	}
};
int main() {
	Log log;
	log.Error("Hello!");
	log.Warn("Hello!");
	log.Info("Hello!");
	std::cin.get();
}