#pragma once

#include <string>
#include "ilog/log_format.h"
#include "ilog/log_output.h"

enum class LogLevel: uint8_t
{
	debug,
	info,
	error,
	fatal,
};

class Logger {
private:
	LogFormat* fmt_{nullptr};
	LogOutput* out_{nullptr};
public:
	void setFormat(LogFormat* fmt) { fmt_ = fmt; }
	void setOutput(LogOutput* out) { out_ = out; }

	void write(const LogLevel lv, const std::string file, const int32_t line, const std::string s);
};

