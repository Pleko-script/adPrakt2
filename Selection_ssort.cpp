
#include <string.h>
using namespace std;
#include <stdio.h>
#include <iostream>

void selectionSort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        int min = i;

        for (int j = i + 1; j < 6; j++)
        {

            if(arr[j] < arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp = arr[min];
            arr[min]=arr[i];
            arr[i]=temp;

        }
    }
};

int main()
{

    int myarr[] = {3, 7, 1, 1, 5, 4};

    for (int i = 0; i < 6; i++)
    {
        cout << myarr[i] << ",";
    }

    selectionSort(myarr);
    cout << "\n"
         << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << myarr[i] << ",";
    }
}