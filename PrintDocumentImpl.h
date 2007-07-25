#pragma once
#using <System.Drawing.dll>
#include "Printable.h"
using namespace System::Drawing::Printing;

ref class PrintDocumentImpl : public PrintDocument
{
public:
	PrintDocumentImpl(Printable *);
	~PrintDocumentImpl(void);
	void printPageHandler(System::Object^ sender, PrintPageEventArgs^ e);

private:
	Printable * fPrintable;
};
