#include "ilog/log_output.h"

#include <string>

using namespace std;

void ConsoleLogOutput::output(const std::string s) {
	cout << s << endl;
}