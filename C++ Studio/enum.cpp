#include <iostream>
class Log
{
public:								//信息级别常量
	enum Level {					//Level中的值只存在Class Log中
		LevelError=0, LevelWarning, LevelInfo	//在值前加上Level避免值与函数名冲突
	};
private:							//信息级别
	Level m_LogLevel = LevelInfo;		//限制赋值为Level中枚举的值
public:								//修改信息级别接口
	void SetLevel(Level level)
	{
		m_LogLevel = level;
	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
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