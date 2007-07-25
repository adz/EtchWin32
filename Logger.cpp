#include "StdAfx.h"
#include "Logger.h"

void Logger::logMessage(const char * message) {
#ifdef _DEBUG
	System::Diagnostics::Debug::WriteLine(gcnew System::String(message));
#endif _DEBUG
}
