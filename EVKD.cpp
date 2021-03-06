/* Dateiname: EVKD.cpp
AD Praktikum 1 - SOSE22
Gruppe: 21
Name: Nik Tykhomyrov Matr:11134921
Name: Jonas Pardeyke Matr:11142973

EVKD Klasse zum Orgransieren der Datenstruktur


*/
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include "EVKD.h"

//EVKD Klasse

	EVKD::EVKD(char *LPSZData, EVKD *Next)
	{
		Data = LPSZData;
		AnzChar = 0;
		while (Data[AnzChar] != '\0')
		{
			AnzChar++;
		}
		this->Next = Next;
	}
	//Daten zeigen
	void EVKD::ShowData()
	{
		cout << "   Data = " << Data << "   AnzChar = " << AnzChar  << "   Next = " << Next << endl;
	}
	//Daten zurueckgeben
	char *EVKD::getData()
	{
		return Data;
	}
	//getAnzChar zurueckgeben
	int EVKD::getAnzChar()
	{
		return AnzChar;
	}
	//Nachfolger zurueckgeben
	EVKD * EVKD::getNext()
	{
		return Next;
	}
	//Nachfolger setzen
	void EVKD::setNext(EVKD *Next)
	{
		this->Next = Next;
	}
	//operator zum vergleichen überladen
	bool  EVKD::operator>(const EVKD &RHS)
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
	bool EVKD::operator==(EVKD &RHS)
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