#include "stdafx.h"
#include "Logger.h"


Logger::Logger(std::string file, LoggingOptions opts) :
    filename(file), enabledLevels(SEVERE | WARNING | INFO) {
    this->options = opts;
    //open the file
    try {
        stream = new std::fstream(file);
        //gets the current date
        boost::gregorian::date now = boost::gregorian::day_clock::local_day();
        //write the default headers for the file
        *stream << "Log created on (yyyy-mm-dd) ";
        *stream << boost::gregorian::to_iso_extended_string(now) << std::endl;
    } catch (std::exception e) {
        std::cout << "Error while trying to create a logfile: " << file << std::endl;
        std::cout << e.what() << std::endl;
    }
}

bool Logger::isOptionEnabled(LoggingOptions opt) {
    return (this->options & opt) >= 1;
}

Logger::~Logger() {
    //close and delete the file
    stream->close();
    delete stream;
}

void Logger::toggleLoggingLevels(Level l) {
    this->enabledLevels ^= l;
}

bool Logger::isLevelEnabled(Level l) {
    return (this->enabledLevels & l) >= 1;
}

void Logger::enableLevel(Level l) {
    this->enabledLevels |= l;
}

void Logger::disableLevel(Level l) {
    this->enabledLevels &= (~l);
}

void Logger::log(Level l, std::string message) {
    if (this->isLevelEnabled(l)) {
        if (this->isOptionEnabled(LOG_TO_FILE)) {
            boost::gregorian::date now = boost::gregorian::day_clock::local_day();
			*stream << "[" << boost::gregorian::to_iso_extended_string(now) << "]";
			*stream << "[" << this->levelToString(l) << "]: ";
			*stream << message << std::endl;
        }
		if (this->isOptionEnabled(LOG_TO_CONSOLE)){
			std::cout << "[" << this->levelToString(l) << "]: " << message << std::endl;
		}
    }
}

std::string Logger::levelToString(Level l) {
	switch (l){
	case 0x1:
		return "FINEST";
	case 0x2:
		return "FINER";
	case 0x4:
		return "FINE";
	case 0x8:
		return "CONFIG";
	case 0x10:
		return "INFO";
	case 0x20:
		return "WARNING";
	case 0x40:
		return "SEVERE";
	default:
		return "SEVERE";
	}
}
