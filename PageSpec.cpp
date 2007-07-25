#include "StdAfx.h"
#include "PageSpec.h"

PageSpec::PageSpec(int topMargin, int bottomMargin, int leftMargin, int rightMargin)
{
	fTopMargin = topMargin;
	fBottomMargin = fBottomMargin;
	fLeftMargin = leftMargin;
	fRightMargin = rightMargin;
}

PageSpec::~PageSpec(void)
{
}

	
int PageSpec::getTopMargin() {
	return fTopMargin;
}

int PageSpec::getBottomMargin() {
	return fBottomMargin;
}

int PageSpec::getLeftMargin() {
	return fLeftMargin;
}

int PageSpec::getRightMargin() {
	return fRightMargin;
}