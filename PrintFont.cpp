#include "StdAfx.h"
#include "PrintFont.h"

using namespace System;

PrintFont::PrintFont(char * name, float size, FontStyle style)
{
	fName = name;
	fSize = size;
	fStyle = style;
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

PrintFont::FontStyle PrintFont::getStyle() {
	return fStyle;
}


