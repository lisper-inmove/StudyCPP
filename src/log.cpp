#include "log.h"
#include "utils/datetime.h"
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <iostream>

using namespace std;

string format_ = "[%TIME%] [%LEVEL%] [%FILE%:%LINE%]: %MESSAGE%";

std::vector<std::reference_wrapper<std::ostream>> logStreams;

void ReplaceStr(string &str, string ostr, string nstr)
{
	auto pos = str.find(ostr);
	if (pos != string::npos)
	{
		str.replace(pos, ostr.size(), nstr);
	}
}

string ParseMessage(LogLevel level, const string &file, int line, const string &message)
{
	string levelStr = "DEBUG";
	switch (level)
	{
	case LogLevel::DEBUG:
		break;
	case LogLevel::INFO:
		levelStr = "INFO";
		break;
	case LogLevel::ERROR:
		levelStr = "ERROR";
		break;
	case LogLevel::FATAL:
		levelStr = "FATAL";
		break;
	}
	string output = format_;
	ReplaceStr(output, "%TIME%", GetNow());
	ReplaceStr(output, "%LEVEL%", levelStr);
	ReplaceStr(output, "%FILE%", file);
	ReplaceStr(output, "%LINE%", to_string(line));
	ReplaceStr(output, "%MESSAGE%", message);
	return output;
}

void LogWrite(LogLevel level, std::string file, int line, std::string message)
{
	string output = ParseMessage(level, file, line, message);
	for (auto & stream: logStreams)
	{
		stream.get() << output << endl;
	}
}

void LogInit(string format)
{
	if (!format.empty())
	{
		format_ = format;
	}
}

void AddStream(ostream &stream)
{
	logStreams.push_back(stream);
}

void AddFileStream(string filename)
{
	auto ofs = new std::ofstream(filename, ios::app);
	if (ofs->is_open())
	{
		AddStream(*ofs);
	}
}

/**
 *
 *#include <vector>
#include <iostream>
#include "log.h"

using namespace std;

int main()
{
	LogInit();
	AddStream(cout);
	AddFileStream("log.txt");
	DEBUG("Hello");
	INFO("This is an info message.");
	ERROR("There is an error");
	FATAL("This is a fatal error message.");
	
	return 0;
}
 *
 * 
 */