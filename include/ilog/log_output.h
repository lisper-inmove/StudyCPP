#pragma once

#include <string>
#include <iostream>
#include <fstream>

class LogOutput {
public:
	virtual void output(const std::string s) = 0;
};

class ConsoleLogOutput : public LogOutput {
public:
	void output(const std::string s) override;
};

class FileLogOutput : public LogOutput {
public:
	void output(const std::string s) override;
	FileLogOutput(const std::string filename);
private:
	std::fstream fout_;
};