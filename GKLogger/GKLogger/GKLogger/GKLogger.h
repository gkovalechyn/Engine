#ifdef GKLOGGER_EXPORTS
#define GKLOGGER_API __declspec(dllexport) 
#else
#define GKLOGGER_API __declspec(dllimport) 
#endif

#include "Logger.h"
#include <string>

class GKLogger{
public:
	GKLOGGER_API Logger* createNewLogger(std::string filename, Logger::LoggingOptions opts = Logger::LOG_TO_FILE);
};