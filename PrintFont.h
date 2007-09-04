#pragma once
#include <vector>
using namespace std;
class PrintFont
{

public:
	enum FontStyle {
		BOLD, ITALIC, REGULAR, STRIKEOUT, UNDERLINE
	};

	PrintFont(char * name, float size, FontStyle style);
	PrintFont(char * name, float size, std::vector<PrintFont::FontStyle> styles);

	~PrintFont(void);

	char * getName();
	float getSize();
	vector<FontStyle> getStyles();
	virtual float getHeight()=0;

private:
	char * fName;
	float fSize;
	vector<FontStyle> * fStyles;


};
