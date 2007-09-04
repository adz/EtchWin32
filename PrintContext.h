#pragma once
#include "PageSpec.h"
#include "PrintFont.h"
#include <vector>
#include "PrinterEnv.h"

class PrintContext
{
public:

	virtual void drawString(char * toDraw, float x, float y, PrintFont * font)=0;
	virtual PageSpec * getPageSpec()=0;
	virtual PrintFont * getFont(char * font, float size, PrintFont::FontStyle style)=0;
	virtual PrintFont * getFontMultistyle(char * font, float size, std::vector<int>)=0;

};
