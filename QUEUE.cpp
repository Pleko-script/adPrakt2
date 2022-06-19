/* Dateiname: QUEUE.cpp
AD Praktikum 1 - SOSE22
Gruppe: 21
Name: Nik Tykhomyrov Matr:11134921
Name: Jonas Pardeyke Matr:11142973


QUEUE Klasse zur Verwaltung einer Reihe von Daten

Enthält die methoden queueIn, queueOut, einfuegeBei ,loesche , zeigDich , selSort
*/
#include "QUEUE.h"
#include "EVKD.cpp"

//QUEUE Klasse

    QUEUE::QUEUE()
    {
        Enter = NULL;
        Last = NULL;
        AnzElem = 0;
    }
    //Eintrag in die Warteschlange
    void QUEUE::queueIn(char *InText)
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
    //Element aus der Liste entfernen nach FIFO prinzip
    char *QUEUE::queueOut()
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
    //Element in die Reihe hinzufügen in einer bestimmte stelle
    void QUEUE::einfuegeBei(EVKD *In, int Pos)
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
    //Element aus der Liste entfernen
    EVKD *QUEUE::loesche(int Pos)
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

    //Reihe zeigen
    void QUEUE::zeigDich()
    {
        EVKD *Ausgabe = Enter;
        for (int i = 0; i < AnzElem; i++)
        {

            cout << 1 + i << ". "<< "Adresse: " << Ausgabe;
            Ausgabe->ShowData();


            Ausgabe = Ausgabe->getNext();
        }
    }
    //Reihe sortieren
    void QUEUE::selSort()
    {
        int importNumber;

        int PosNumber = 0;
        for (int i = 0; i < AnzElem; i++)
        {

            int hodl = 1;     
            int count = 0;      
            bool found = false; 

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