#include "ilog/log_format.h"
#include "utils/datetime.h"

#include <string>

using namespace std;

string XLogFormat::format(const string lv, const string file, const int32_t line, const string s) {
	string output = "[%TIME%]: [%FILE%]-[%LINE%]: [%MSG%]";
	output.replace(output.find("%TIME%"), 6, GetNow());
	output.replace(output.find("%FILE%"), 6, file);
	output.replace(output.find("%LINE%"), 6, to_string(line));
	output.replace(output.find("%MSG%"), 5, s);
	return output;
}