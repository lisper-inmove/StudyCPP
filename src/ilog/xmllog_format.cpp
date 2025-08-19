#include "ilog/log_format.h"
#include "utils/datetime.h"

#include <string>
#include <sstream>
#include <cstdint>

using namespace std;

string XMLLogFormat::format(const string lv, const string file, const int32_t line, const string s) {
    std::ostringstream oss;
    oss << "<log>"
        << "<level>" << lv << "</level>"
        << "<file>" << file << "</file>"
        << "<line>" << line << "</line>"
        << "<message>" << s << "</message>"
        << "</log>";
    return oss.str();
}