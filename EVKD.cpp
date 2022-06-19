#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
class EVKD
{
private:
	char *Data;
	int AnzChar;
	EVKD *Next;

public:
	EVKD(char *LPSZData, EVKD *Next)
	{
		Data = LPSZData;
		AnzChar = 0;
		while (Data[AnzChar] != '\0')
		{
			AnzChar++;
		}
		this->Next = Next;
	}
	void ShowData()
	{
		cout << "Data = " << Data << endl;
		cout << "AnzChar = " << AnzChar << endl;
		cout << "Next = " << Next << endl;
	}
	char *getData()
	{
		return Data;
	}
	int getAnzChar()
	{
		return AnzChar;
	}
	EVKD *getNext()
	{
		return Next;
	}
	void setNext(EVKD *Next)
	{
		this->Next = Next;
	}
	bool  operator>(const EVKD &RHS)
	{
		if (strcmp(Data, RHS.Data) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator==(EVKD &RHS)
	{
		if (strcmp(Data, RHS.Data) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};