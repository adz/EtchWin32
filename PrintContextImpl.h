#pragma once
#include "PrintContext.h"
#using <System.Drawing.dll>
#include <vcclr.h>
#include "PageSpec.h"
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System;

class PrintContextImpl : public PrintContext
{
public:
	PrintContextImpl(PrintPageEventArgs^ graphics);
	~PrintContextImpl(void);

	//Actions
	void drawString(char * toDraw, float x, float y, PrintFont * font);
	PrintFont * getFont(char * font, float size, PrintFont::FontStyle style);

	//Properties
	PageSpec * getPageSpec();
private:
	gcroot<PrintPageEventArgs^> fPrintPageEvent;
	PageSpec * fPageSpec;
};