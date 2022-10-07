
#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main() {
    LinkedList<int> list;
    list.insertFirst(5);
    list.insertFirst(3);
    list.insertFirst(2);
    // list.insertFirst(8);
    //should be [8,2,3,5]
    // for (int i = 0; i<3; i++){
    //   cout << list.get(i) <<endl;
    // } 

    //reverse
    list.reverseIt();

    //should be [5,3,2,8]

    for (int i = 0; i<3; i++){
      cout << list.get(i) <<endl;
    } 

    cout << list.getFirst() << endl;
    cout << list.getLast() << endl;
    

    return 0;
}
