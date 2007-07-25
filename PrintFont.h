#pragma once

class PrintFont
{

public:
	enum FontStyle {
		BOLD, ITALIC, REGULAR, STRIKEOUT, UNDERLINE
	};

	PrintFont(char * name, float size, FontStyle style);
	~PrintFont(void);

	char * getName();
	float getSize();
	FontStyle getStyle();
	virtual float getHeight()=0;

private:
	char * fName;
	float fSize;
	FontStyle fStyle;


};
