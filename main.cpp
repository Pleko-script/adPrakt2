#include "QUEUE.cpp"
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{


    QUEUE *Reihe = new QUEUE();
    while (true){
    int eingabeZahl;

    cout<< "\n\n1.) Warteschlange erstellen \n 2.) Verkettete Liste anzeigen \n 3.) Neues Element zu Warteschlange hinzufuegen \n 4.) Element aus der Warteschlange entfernen \n 5.) Liste sortieren \n 12.) Ende! "<< endl;
    cout << "Bitte geben Sie eine Zahl ein: ";
    cin >> eingabeZahl;
    cout << "\n";

    if(eingabeZahl==1){
        char * Name[] = {"SCHMITZ", "JOSEF","MUELLER", "JOSI","SCHMITZ", "ANNA","MUELLER", "JOSEF","SCHMITZ", "JOSI","MUELLER", "ANNA","MEIER", "JOSEF","ZACHER", "JOSI","ANKER", "ANNA"};
    for (int i = 0; i < 18; i++)
    {
        Reihe->queueIn(Name[i]);
    }
    }

    if(eingabeZahl==2){
        Reihe->zeigDich();
    }

    if(eingabeZahl==3){
        cout << "Bitte geben Sie einen Namen ein: ";
        char * Name = new char[20];
        cin >> Name;
        Reihe->queueIn(Name);



    }

    if(eingabeZahl==4){
        Reihe->queueOut();
    }

    if(eingabeZahl==5){
        Reihe->selSort2();
    }
    if(eingabeZahl==12){
        cout << "Ende!" << endl;
        return 0;
    }
    if(eingabeZahl>5 || eingabeZahl<1){
        cout << "Falsche Eingabe!" << endl;
    }

}



}
