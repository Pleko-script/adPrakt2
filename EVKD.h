
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>


#ifndef EVKD_H_INCLUDED
#define EVKD_H_INCLUDED

//EVKD Klasse
class EVKD
{
private:
    char *Data;
    int AnzChar;
    EVKD *Next;
public:
    EVKD(char *LPSZData, EVKD *Next);
    void ShowData();
    char *getData();
    int getAnzChar();
    EVKD *getNext();
    void setNext(EVKD *Next);
    bool  operator>(const EVKD &RHS);
    bool operator==(EVKD &RHS);



};


#endif // EVKD_H_INCLUDED