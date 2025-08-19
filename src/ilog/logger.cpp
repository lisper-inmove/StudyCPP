#include "ilog/logger.h"

#include <string>
using namespace std;

void Logger::write(const LogLevel lv, const string file, const int32_t line, const string s) {
	string lvStr = "debug";
	switch (lv) {
	case LogLevel::info:
		lvStr = "info";
		break;
	case LogLevel::error:
		lvStr = "error";
		break;
	case LogLevel::fatal:
		lvStr = "fatal";
		break;
	default:
		lvStr = "debug";
		break;
	}
	string msg = fmt_->format(
		lvStr, file, line, s
	);
	out_->output(msg);
}