#pragma once
#include "Printer.h"
#include <vector>

class PrinterEnv
{
public:
	PrinterEnv(void);
	~PrinterEnv();
	int getPrinterCount();
	Printer * getPrinter(unsigned int index);
	Printer * getPrinter(const char * name);
	Printer * getDefaultPrinter();

private:
	std::vector<Printer *> getPrinters();
	std::vector<Printer *> * fPrinters;
	
};

