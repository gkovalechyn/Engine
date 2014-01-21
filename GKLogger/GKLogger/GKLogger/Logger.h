#pragma once

#include <fstream>
#include <string>

//-- boost
#include <boost/date_time/gregorian/gregorian.hpp>

class Logger {
public:
    enum LoggingOptions {
        LOG_TO_CONSOLE = 0x1,
        LOG_TO_FILE = 0x2
    };

	enum Level{
		FINEST = 0x1,
		FINER= 0x2,
		FINE = 0x4,
		CONFIG = 0x8,
		INFO = 0x10,
		WARNING = 0x20,
		SEVERE = 0x40
	};

	Logger(std::string file, LoggingOptions opts = LOG_TO_FILE);
	void toggleLoggingLevels(Level l);
	bool isOptionEnabled(LoggingOptions opt);
	/**
	@param Level l - The level to be checked if the logging is enabled
	*/
	bool isLevelEnabled(Level l);
	/**
	Enables logging for that level.
	*/
	void enableLevel(Level l);
	/**
	Disables logging for that level.
	*/
	void disableLevel(Level l);
	/**
	Logs a message to a file(if enabled) and to the console(if enabled)
	If the level is not enabled for logging, the message will not be logged.
	@param level The level of this message, it can be: FINEST, FINER, FINE, CONFIG,
	INFO, WARNING, SEVERE
	@param message The string wich should be logged.
	*/
	void log(Level level, std::string message);

	static std::string levelToString(Level l);
private:
	std::string filename = "";

	unsigned char options = 0x0;
	unsigned char enabledLevels = 0x0;

	std::fstream* stream = NULL;

	Logger(Logger& l);
	~Logger();
};

