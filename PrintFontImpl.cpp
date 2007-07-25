#include "StdAfx.h"
#include "PrintFontImpl.h"

using namespace System;

PrintFontImpl::PrintFontImpl(char * name, float size, FontStyle style) : PrintFont(name, size, style)
{
	fSystemFont = gcnew System::Drawing::Font( gcnew String(name), 
		size, PrintFontImpl::getTranslatedFont(style));
}

PrintFontImpl::~PrintFontImpl(void)
{
	if (fSystemFont) {
		delete(fSystemFont);
	}
}

System::Drawing::FontStyle PrintFontImpl::getTranslatedFont(PrintFont::FontStyle style) {

	switch (style) {
		case PrintFont::BOLD:
			return System::Drawing::FontStyle::Bold;
		case PrintFont::ITALIC:
			return System::Drawing::FontStyle::Italic;
		case PrintFont::STRIKEOUT:
			return System::Drawing::FontStyle::Strikeout;
		case PrintFont::UNDERLINE:
			return System::Drawing::FontStyle::Underline;
		default:
			return System::Drawing::FontStyle::Regular;
	}
}

Font^ PrintFontImpl::getSystemFont() {
	return fSystemFont;
}

float PrintFontImpl::getHeight() {
	return fSystemFont->GetHeight();
}
