#pragma once
#include "printfont.h"
#using <System.Drawing.dll>
#include <vcclr.h>
using namespace System::Drawing;

class PrintFontImpl :
	public PrintFont
{
public:
	PrintFontImpl(char * name, float size, FontStyle style);
	~PrintFontImpl(void);

	static System::Drawing::FontStyle getTranslatedFont(PrintFont::FontStyle style);

	Font^ getSystemFont();
	float getHeight();
private:
	gcroot<Font^> fSystemFont;
};
