#pragma once
#include <string>

#include "ilog/logger.h"

class LogFactory {
private:
	LogFactory() = default;
	LogFactory& operator=(const LogFactory&);
	Logger logger_;
public:
	static LogFactory& instance();
	Logger& getLogger() {
		return logger_;
	}
};

#define LogWrite(lv, s) LogFactory::instance().getLogger().write(lv, __FILE__, __LINE__, s)

#define DEBUG(s) LogWrite(LogLevel::debug, s)
#define INFO(s) LogWrite(LogLevel::info, s)
#define ERROR(s) LogWrite(LogLevel::error, s)
#define FATAL(s) LogWrite(LogLevel::fatal, s)