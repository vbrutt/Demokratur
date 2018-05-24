#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>

using namespace std;

const int citizenNumber = 400;
//string partyArray[citizenNumber];
int arraySize = citizenNumber - 1;
int height = 10;
int width = 40;

class Person{
public:
  int party;
};
Person partyArray[citizenNumber];

void setParty(int randomNumber, int index){
    switch(randomNumber){
    case 1:
        partyArray[index].party = randomNumber;
        break;
    case 2:
        partyArray[index].party = randomNumber;
        break;
    }
}
bool isNotFinished(){
    for (int i = 0; i < arraySize; i++) {
        if(partyArray[i].party != partyArray[i + 1].party){
            return true;
        }
    }
    return false;
}

int main()
{
    srand((int)time(0));


    for (int i = 0; i < arraySize; i++) {
        setParty(1 + rand() % 2,i);
    }
    do{
        int indexCitizen = rand() % citizenNumber;
        int party1 = partyArray[indexCitizen].party;
        int neighbour = 1 + rand() % 4;
        int party2;

        switch(neighbour){
        case 1: {
            if(indexCitizen < width){
                neighbour = indexCitizen + (citizenNumber - width);
            }else{
                neighbour = indexCitizen - width;
            }
            party2 = partyArray[neighbour].party;
            break;
        }
        case 2:{
            if(indexCitizen == arraySize){
                neighbour = 0;
            }else{
                neighbour = indexCitizen + 1;
            }
            party2 = partyArray[neighbour].party;
            break;
        }
        case 3:{
            if(indexCitizen >= (citizenNumber - width)){
                neighbour = indexCitizen - (citizenNumber - width);
            }else{
                neighbour = indexCitizen + width;
            }
            party2 = partyArray[neighbour].party;
            break;
        }
        case 4: {
            if(indexCitizen  == 0){
                neighbour = arraySize;
            }else{
                neighbour = indexCitizen - 1;
            }
            party2 = partyArray[neighbour].party;
            break;
        }
        }

        if(party1 != party2){
            int i = 1 + rand() % 2;
            if(i == 1){
                partyArray[neighbour].party = party1;
            }
            else{
                partyArray[indexCitizen].party = party1;
            }
            system("cls");
            for (int index = 0; index < arraySize; index++) {
                if(partyArray[index].party == 1){
                    cout<<"A";
                }
                else{
                    cout<<"-";
                }
            }
            //VOID WINAPI Sleep( DWORD dwMilliseconds );
            //Sleep(100);
        }



}while(isNotFinished());
return 0;
}
