/* Dateiname: QUEUE.cpp
AD Praktikum 1 - SOSE22
Gruppe: 21
Name: Nik Tykhomyrov Matr:11134921
Name: Jonas Pardeyke Matr:11142973


QUEUE Klasse zur Verwaltung einer Reihe von Daten


*/

#include "EVKD.cpp"
// ------------------NOCH NICHT FERTIG ----------------
class QUEUE
{
private:
    EVKD *Enter;
    EVKD *Last;
    long AnzElem;

public:
    QUEUE()
    {
        Enter = NULL;
        Last = NULL;
        AnzElem = 0;
    }
    void queueIn(char *InText)
    {
        EVKD *NewElem = new EVKD(InText, Enter);
        if (Enter == NULL)
        {
            Enter = NewElem;
            Last = NewElem;
        }
        else
        {
            Last->setNext(NewElem);
            Last = NewElem;
        }
        AnzElem++;
    }
    char *queueOut()
    {
        if (Enter == NULL)
        {
            return NULL;
            cout << "Queue ist leer" << endl;
        }
        else
        {
            EVKD *OutElem = Enter;
            Enter = Enter->getNext();
            char *OutText = OutElem->getData();
            delete OutElem;
            AnzElem--;
            cout << "\nEntfernter Name: " << OutText << "\n"
                 << endl;
        }
    }
    /* the method void einfuegeBei (EVKD * In, int Pos), which inserts the object In before
    of the position in the list indicated by Pos.*/
    void einfuegeBei(EVKD *In, int Pos)
    {
        EVKD *NewElem = new EVKD(In->getData(), In->getNext());
        if (Pos == 0)
        {
            NewElem->setNext(Enter);
            Enter = NewElem;
        }
        else
        {
            EVKD *Temp = Enter;
            for (int i = 0; i < Pos - 1; i++)
            {
                Temp = Temp->getNext();
            }
            NewElem->setNext(Temp->getNext());
            Temp->setNext(NewElem);
        }
        AnzElem++;
    }

    EVKD *loesche(int Pos)
    {
        Pos--;
        EVKD *Vor = Enter;
        for (int i = 0; i < Pos - 2; i++)
        {
            Vor = Vor->getNext();
        }
        EVKD *Out = Vor->getNext();
        Vor->setNext(Out->getNext());
        AnzElem--;
        return Out;
    }

    void zeigDich()
    {
        EVKD *Ausgabe = Enter;
        for (int i = 0; i < AnzElem; i++)
        {

            cout << 1 + i << ". "<< "Adresse: " << Ausgabe;
            Ausgabe->ShowData();


            Ausgabe = Ausgabe->getNext();
        }
    }
    void selSort()
    {
        int importNumber;

        int PosNumber = 0;
        for (int i = 0; i < AnzElem; i++)
        {

            int hodl = 1;       // Zahl haltet die Position des kleinsten Elements
            int count = 0;      // Zahl zählt die Position des aktuellen Elements
            bool found = false; // bool ist true wenn das kleinstes Element gefunden wurde

            EVKD *smallest = new EVKD("ZZZZZZZ", NULL);
            EVKD *Ausgabe = Enter; // Ausgabe ist der Startpunkt des Listeners

            for (int j = 0; j < AnzElem; j++)
            {
                count++;
                // cout << "count: " << count << "  start:" << start << endl;

                if (*smallest > *Ausgabe && count > i)
                {
                    //cout << "-----" << endl;
                    smallest = Ausgabe;
                    hodl = count;
                    found = true;
                }
                Ausgabe = Ausgabe->getNext();
            }

            //cout << "Smallest Element: " << smallest->getData() << endl;
            if (found == true)
            {
               // cout << "Position: " << hodl << endl;
                importNumber = hodl;
            }
            else
            {
               // cout << "Position: " << AnzElem << endl;
                importNumber = AnzElem;
            }
            PosNumber = importNumber;
            EVKD *Temp = loesche(PosNumber + 1);
            einfuegeBei(Temp, i);
        }
    }
};