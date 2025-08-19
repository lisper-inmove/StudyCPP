#pragma once

#include <vector>
#include <string>
#include <ostream>

enum class LogLevel {
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

enum class LogType {
	LOG_Console,
	LOG_File
};

void LogInit(std::string format = "");
void LogWrite(LogLevel level, std::string file, int line, std::string message);
void AddStream(std::ostream &stream);
void AddFileStream(std::string filename);

#define DEBUG(message) LogWrite(LogLevel::DEBUG, __FILE__, __LINE__, message);
#define INFO(message) LogWrite(LogLevel::INFO, __FILE__, __LINE__, message);
#define ERROR(message) LogWrite(LogLevel::ERROR, __FILE__, __LINE__, message);
#define FATAL(message) LogWrite(LogLevel::FATAL, __FILE__, __LINE__, message);