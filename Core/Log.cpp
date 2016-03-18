#include "stdafx.h"
#include "Log.h"

#define LOGNAME "Log.log"
namespace EngineCore
{
	//-------Констурктор класса----------//
	Log::Log()
	{
		/*if (!m_instance)
		{
			m_file = nullptr;
			m_instance = this;
			m_init();
		}
		else
			Err("Log has been created");
			*/
	}


	Log::~Log()
	{
		m_close();
		//m_instance = nullptr;
	}


	//--------Инициализация класса--------//
	void Log::m_init()
	{
		setlocale(LC_ALL, "RUS");
		//Если файл можно открыть для записи
		if (fopen_s(&m_file, LOGNAME, "w") == 0)
		{
			//Получение времени и даты
			char timer[9];
			_strtime_s(timer, 9);
			char date[9];
			_strdate_s(date, 9);
			//Запись в файл
			fprintf(m_file, "Log has created at %s %s \n", date, timer);
			fprintf(m_file, "-------------------------------------------\n\n");
		}
		else
		{
			printf("Error while log creating....\n");
			m_file = nullptr;
		}
	}

	void Log::m_close()
	{
		if (!m_file)
			return;
		char timer[9];
		_strtime_s(timer, 9);
		char date[9];
		_strdate_s(date, 9);
		fprintf(m_file, "\n---------------------------------------\n");
		fprintf(m_file, "Log end: %s %s\n", date, timer);
		fclose(m_file);
	}

	void Log::Print(const char *message)
	{
		m_print("MESSAGE: ", message);
	}

	void Log::Debug(const char *message)
	{
#ifdef _DEBUG
		m_print("*DEBUG: ", message);
#endif // _DEBUG
	}

	void Log::Err(const char *message)
	{
		m_print("*ERROR: ", message);
	}

	void Log::m_print(const char *levtext, const char *text)
	{
		char timer[9];
		_strtime_s(timer, 9);
		clock_t cl = clock();
		
		printf("%s::%d: %s%s\n", timer, cl, levtext, text);
		if (m_file)
		{
			fprintf(m_file, "%s::%d: %s%s\n", timer, cl, levtext, text);
			fflush(m_file);
		}
	}
}

