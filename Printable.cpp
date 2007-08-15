#include "StdAfx.h"
#include "Printable.h"
#include "PrintDocumentImpl.h"
#include "Logger.h"
#include "PrintingException.h"
using namespace System;


Printable::Printable()
{
	fPrinter = (Printer *)0;
}

Printable::~Printable(void)
{
}

void Printable::print(PrintContext * ctx){
		puts("No print operation defined.");
}

void Printable::setPrinter(Printer * printer) {
	Logger::logMessage("Printable::setPrinter()");
	fPrinter = printer;
}

void Printable::printDocument(){

	Logger::logMessage("Printable::printDocument()");

	if (!fPrinter) {
		throw PrintingException("A printer must be set before the document can be printed.");
	}

	char * printerName = fPrinter->getName();
	//TODO: copy other configuration info to document

	PrintDocumentImpl^ document = gcnew PrintDocumentImpl(this);
	
	document->PrinterSettings->PrinterName = gcnew String(printerName);

	document->PrintPage += gcnew PrintPageEventHandler(	document, &PrintDocumentImpl::printPageHandler );
			
	try {

		document->Print();
	} catch (Exception^ e) {
		char * message = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(e->ToString());
		throw PrintingException(message);
	} 
}