#include <iostream>
#pragma warning(disable:4996)
class EXP
{
private:
	int kod;
	char message[80];
	char *povtor = "\nRepeat enter: ";
public:
	EXP(char *mas, int kod)
	{
		strcpy(message, mas);
		this->kod = kod;
	}

	char* whatMessage() { return message; }
	int whatKod() { return kod; }
	char* povtorMessage() { return povtor; }
};