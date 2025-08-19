#include "ilog/log_factory.h"

LogFactory& LogFactory::instance() {
	static LogFactory instance;
	return instance;
}

LogFactory& LogFactory::operator=(const LogFactory&) {
	return instance();
}

/**
 *#include <vector>
#include <iostream>
#include "ilog/logger.h"
#include "ilog/log_format.h"
#include "ilog/log_output.h"
#include "ilog/log_factory.h"

using namespace std;

int main()
{
	XMLLogFormat f = XMLLogFormat();
	LogFactory& fac = LogFactory::instance();
	fac.getLogger().setFormat(&f);
	// fac.getLogger().setOutput(new ConsoleLogOutput);
	fac.getLogger().setOutput(new FileLogOutput("log.txt"));
	DEBUG("This is a DEBUG message");
	INFO("This is a INFO message");
	ERROR("This is a ERROR message");
	FATAL("This is a FATAL message");
}
 *
 * 
 */