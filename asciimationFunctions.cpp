/*
  Michael Pham, Brandon Xu
  Fall 2022
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

List<pair<int, string>>* loadMovie(string filename) {
    ifstream myFile;
    string data;
    string data1;
    string data2;
    LinkedList<pair<int,string>>* list = new LinkedList<pair<int, string>>();
        
    myFile.open(filename);
    if(!myFile.is_open()){
        throw runtime_error("file " + filename + "failed to open ");
    }
    string s ="";
    getline(myFile, data);
    while (!myFile.eof()){
        int p=stoi(data);
        for (int i =0; i<13; i++){
            getline(myFile, data);
            s=s+data+"\n";
        }
        pair<int,string>p1(p,s);
        list->insertLast(p1);
        getline(myFile, data);
    }
       return list;

}

void playMovie(List<pair<int, string>>* list) {
    while (list->getSize() != 0){   
       cout << list->getFirst().second << endl;
       usleep(list->getFirst().first*1000000/15);
       usleep(1000000/15);
       system("clear");
       list->removeFirst();
    }
   }
