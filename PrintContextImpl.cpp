#include "StdAfx.h"
#include "PrintContextImpl.h"
#include "PrintFontImpl.h"
#include "Util.h"

PrintContextImpl::PrintContextImpl(PrintPageEventArgs^ e)
{
	fPrintPageEvent = e;
	fPageSpec = 0;
}

PrintContextImpl::~PrintContextImpl(void)
{
	delete(fPrintPageEvent);
	if (fPageSpec) {
		delete(fPageSpec);
	}
}

void PrintContextImpl::drawString(char * toDraw, float x, float y, PrintFont * printFont)
{
	if (!printFont) {
		Util::throwExceptionWithMessage("drawString requires a font");
	}

	if (!toDraw) {
		Util::throwExceptionWithMessage("drawString requires a string");
	}

	PrintFontImpl * fontImpl = (PrintFontImpl*) printFont; 
	System::Drawing::Font^ font = fontImpl->getSystemFont();
	
    SolidBrush^ brush = gcnew SolidBrush( Color::Black );
	PointF point = PointF(x, y);

	String^ string = gcnew String(toDraw);
	fPrintPageEvent->Graphics->DrawString(string, font, brush, point);
}

PageSpec * PrintContextImpl::getPageSpec() {
	if (!fPageSpec) {
		fPageSpec = new PageSpec(fPrintPageEvent->MarginBounds.Top, fPrintPageEvent->MarginBounds.Bottom, 
			fPrintPageEvent->MarginBounds.Left, fPrintPageEvent->MarginBounds.Right);
	}
	return fPageSpec;
}

PrintFont * PrintContextImpl::getFont(char * font, float size, PrintFont::FontStyle style) {
	return new PrintFontImpl(font, size, style);
}

PrintFont * PrintContextImpl::getFontMultistyle(char * font, float size, std::vector</*PrintFont::FontStyle*/int> styles) {

	//There must be a better way to do this
	std::vector<PrintFont::FontStyle> convertedStyles;
	for (unsigned int i=0; i<styles.size(); i++) {
		convertedStyles.push_back((PrintFont::FontStyle)styles[i]);
	}
	return new PrintFontImpl(font, size, convertedStyles);
}
