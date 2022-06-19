#include "EVKD.h"

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

class QUEUE
{
private:
    EVKD *Enter;
    EVKD *Last;
    long AnzElem;
public:
    QUEUE();
    void queueIn(char *InText);
    char *queueOut();
    void einfuegeBei(EVKD *In, int Pos);
    EVKD *loesche(int Pos);
    void zeigDich();
    void selSort();



};

#endif // QUEUE_H_INCLUDED