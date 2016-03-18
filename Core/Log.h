#pragma once

namespace EngineCore
{
	class Log
	{
		public:
			Log();
			~Log();

			//static Log* Get() { return m_instance; }

			static void Print(const char *message);
			static void Debug(const char *message);
			static void Err(const char *message);
	private:
		//static Log *m_instance;

		static void m_init();
		static void m_close();
		static void m_print(const char *levText, const char *text);
		static FILE *m_file;
	};
}


