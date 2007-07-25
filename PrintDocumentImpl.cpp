#include "StdAfx.h"
#include "PrintDocumentImpl.h"
#include "PrintContextImpl.h"
PrintDocumentImpl::PrintDocumentImpl(Printable * printable)
{
	fPrintable = printable;
}

PrintDocumentImpl::~PrintDocumentImpl(void)
{
}

void PrintDocumentImpl::printPageHandler(System::Object^ sender, PrintPageEventArgs^ e){
	PrintContext * ctx = new PrintContextImpl(e);
	fPrintable->print(ctx);
	delete(ctx);
}
