#pragma once

class PrintingException
{
public:
	PrintingException(char * message);
	~PrintingException(void);
	char * getMessage();

private:
	char * fMessage;
};
