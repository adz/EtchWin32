#pragma once
#include "printfont.h"
#using <System.Drawing.dll>
#include <vcclr.h>
using namespace System::Drawing;
#include <set>
using namespace std;

class PrintFontImpl :
	public PrintFont
{
public:
	PrintFontImpl(char * name, float size, FontStyle style);
	PrintFontImpl(char * name, float size, vector<FontStyle> styles);
	~PrintFontImpl(void);

	static System::Drawing::FontStyle getTranslatedFont(PrintFont::FontStyle style);

	Font^ getSystemFont();
	float getHeight();
private:
	gcroot<Font^> fSystemFont;
};
