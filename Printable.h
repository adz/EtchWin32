#pragma once
#include <iostream>
#include "PrintContext.h"
#include "Printer.h"

class Printable
{
public:
	Printable();
	virtual ~Printable(void);
	void setPrinter(Printer * printer);
	void printDocument();
	virtual void print(PrintContext * ctx);

private:
	Printer * fPrinter;
	
};
