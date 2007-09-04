#include "StdAfx.h"
#include "PrintFont.h"

using namespace System;

PrintFont::PrintFont(char * name, float size, FontStyle style)
{
	fName = name;
	fSize = size;
	fStyles = new vector<FontStyle>();
	fStyles->push_back(style);
}
PrintFont::PrintFont(char * name, float size, std::vector<PrintFont::FontStyle> styles) {
	fName = name;
	fSize = size;
	fStyles = new vector<FontStyle>();
	fStyles->assign(styles.begin(), styles.end());
}

PrintFont::~PrintFont(void)
{
}

char * PrintFont::getName() {
	return fName;
}

float PrintFont::getSize() {
	return fSize;
}

vector<PrintFont::FontStyle> PrintFont::getStyles() {
	return * fStyles;
}


