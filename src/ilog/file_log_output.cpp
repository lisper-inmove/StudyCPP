#include "ilog/log_output.h"

#include <fstream>
using namespace std;

FileLogOutput::FileLogOutput(const std::string filename) : fout_(std::fstream(filename, std::ios::app)) {}

void FileLogOutput::output(const std::string s) {
	fout_ << s << endl;
}