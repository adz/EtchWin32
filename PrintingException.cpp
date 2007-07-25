#include "StdAfx.h"
#include "PrintingException.h"
using namespace System::Runtime::InteropServices;
PrintingException::PrintingException(char * message)
{
	fMessage = message;
}

PrintingException::~PrintingException(void)
{
}

char * PrintingException::getMessage() {
	return fMessage;
}
