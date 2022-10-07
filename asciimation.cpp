/*
  Michael Pham
  Fall 2022
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;


int main(int argc, char** argv) {    
    string n;
    string second_n;
    n=argv[1];
    if (n=="--reverse"){
      second_n = argv[2];
      List<pair<int,string>>* list = loadMovie(second_n);
      list->reverseIt();
      playMovie(list);

    } else {
      List<pair<int,string>>* list = loadMovie(n);
      playMovie(list);
    }


    return 0;
}
