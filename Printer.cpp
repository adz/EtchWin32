#include "StdAfx.h"
#include "Printer.h"
#include "PrintContextImpl.h"

using namespace System::Drawing::Printing;

Printer::Printer(char * name)
{
	fName = name;
}

Printer::~Printer()
{
	delete [] (fName);
}

char * Printer::getName() {
	return fName;
}
