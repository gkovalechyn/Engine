// GKLogger.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "GKLogger.h"

Logger* GKLogger::createNewLogger(std::string filename, Logger::LoggingOptions opts){
	return new Logger(filename, opts);
}

