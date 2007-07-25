#pragma once

class PageSpec
{
public:
	PageSpec(int topMargin, int bottomMargin, int leftMargin, int rightMargin);
	~PageSpec(void);

	int getTopMargin();
	int getBottomMargin();
	int getLeftMargin();
	int getRightMargin();

private:


	int fTopMargin;
	int fBottomMargin;
	int fLeftMargin;
	int fRightMargin;
};
