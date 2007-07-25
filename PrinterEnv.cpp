#include "StdAfx.h"
#include "PrinterEnv.h"
#include "Printer.h"
#include "Logger.h"
#include "PrintingException.h"
#include "Util.h"
#include <windows.h>
#using <System.Drawing.dll>

using namespace System::Drawing::Printing;
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace std;

PrinterEnv::PrinterEnv(void)
{
	Logger::logMessage("PrinterEnv::<init>()");
	fPrinters = 0;
}

PrinterEnv::~PrinterEnv(void)
{
	Logger::logMessage("PrinterEnv::~PrinterEnv");
	if (fPrinters) {
		for (unsigned int i=0; i<fPrinters->size(); i++) {
			Printer * printer = (*fPrinters)[i];
			delete(printer);
		}
		delete(fPrinters);
	}
}

int PrinterEnv::getPrinterCount() {
	Logger::logMessage("PrinterEnv::getPrinterCount()");
	return PrinterSettings::InstalledPrinters->Count;
}

Printer * PrinterEnv::getPrinter(unsigned int index) {
	Logger::logMessage("PrinterEnv::getPrinter(int)");
	if (index < getPrinters().size()) {
		return getPrinters()[index];
	}
	String^ message = "Couldn't find printer at index " + index;
	Util::throwExceptionWithMessage(message);
	return (Printer *)0;
}

Printer * PrinterEnv::getPrinter(const char * name) {
	Logger::logMessage("PrinterEnv::getPrinter(char*)");
	std::vector<Printer *> printers = getPrinters();
	for (unsigned int i=0; i<printers.size(); i++) {
		Logger::logMessage("PrinterEnv::getPrinter(char*): checking ");
		Logger::logMessage(name);
		if (strcmp(name, printers[i]->getName()) == 0) {
			Logger::logMessage("PrinterEnv::getPrinter(char*): returning printer");
			return printers[i];
		}
	}
	Logger::logMessage("PrinterEnv::getPrinter(char*): returning null printer ");
	String^ msg = gcnew String("Printer not found: ");
	String^ errorMessage = msg + gcnew String(name);
	Util::throwExceptionWithMessage(errorMessage);
	return (Printer *)0;
}

std::vector<Printer *> PrinterEnv::getPrinters() {

	Logger::logMessage("PrinterEnv::getPrinters()");
	if (fPrinters == 0) {
		fPrinters = new std::vector<Printer *>();
		for (int i=0; i<getPrinterCount(); i++) {
			const char * printerName = (char*)(void*)Marshal::StringToHGlobalAnsi(PrinterSettings::InstalledPrinters[i]);
			int size = strlen(printerName) + 1;
			char * name = new char[size];
			strcpy_s(name, size, printerName);
			fPrinters->push_back(new Printer(name));
		}

	}
	return *fPrinters;
}
