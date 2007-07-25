#pragma once
#include "PrintingException.h"
class Util
{
public:
	static void throwExceptionWithMessage(System::String^ message) {
		throw PrintingException((char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(message));
	}
};
