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

void output(){
    system("cls");
    for (int index = 0; index < arraySize; index++) {
        if(partyArray[index].party == 1){
            cout<<"A";
        }
        else{
            cout<<"-";
        }
    }
}

void compare(int party1, int party2, int indexCitizen, int neighbour){
    if(party1 != party2){
        int i = 1 + rand() % 2;
        if(i == 1){ //Wenn der anderer Buerger ueberzeugt wurde
            partyArray[neighbour].party = party1;
        }
        else{
            partyArray[indexCitizen].party = party2;
        }
        output();

        VOID WINAPI Sleep( DWORD dwMilliseconds );
        Sleep(100);
    }
}

int getNeighbour(int party2, int indexCitizen, int neighbour){
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
    return party2;
}

int main()
{
    srand((int)time(0));


    for (int i = 0; i < arraySize; i++) {
        setParty(1 + rand() % 2,i);
    }
    while(isNotFinished()){
        int indexCitizen = rand() % citizenNumber;
        int party1 = partyArray[indexCitizen].party;
        int neighbour = 1 + rand() % 4;
        int party2 = getNeighbour(party2, indexCitizen, neighbour);
        compare(party1, party2, indexCitizen, neighbour);
    }
}
