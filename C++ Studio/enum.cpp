#include <iostream>
class Log
{
public:								//��Ϣ������
	enum Level {					//Level�е�ֵֻ����Class Log��
		LevelError=0, LevelWarning, LevelInfo	//��ֵǰ����Level����ֵ�뺯������ͻ
	};
private:							//��Ϣ����
	Level m_LogLevel = LevelInfo;		//���Ƹ�ֵΪLevel��ö�ٵ�ֵ
public:								//�޸���Ϣ����ӿ�
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