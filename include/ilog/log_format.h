#pragma once

#include <string>

class LogFormat {
public:
	virtual std::string format(const std::string lv, const std::string file, const std::int32_t line, const std::string s) = 0;
};

class XLogFormat: public LogFormat
{
public:
	std::string format(const std::string lv, const std::string file, const std::int32_t line, const std::string s);
};

class XMLLogFormat: public LogFormat
{
public:
	std::string format(const std::string lv, const std::string file, const std::int32_t line, const std::string s);
};