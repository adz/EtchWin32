#pragma once

class Printer
{
public:
	Printer(char *);
	~Printer();
	char * getName();

private:
	char * fName;
};
