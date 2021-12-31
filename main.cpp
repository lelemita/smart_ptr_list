#include <iostream>
#include "myList.h"
using namespace std;

int main(void)
{
    cout << "Double Linked Sample code" << endl;
    old::List<int> oldListDesc;
    old::List<int> oldListAsc;
    for (int i = 0; i < 10; i++)
    {
        oldListDesc.addFront(i);
        oldListAsc.addLast(i);
    }

    if(oldListDesc.chkEmpty() || oldListAsc.chkEmpty()) {
        cout << "input data fail" << endl;
        return 0;
    }

    oldListAsc.moveFront();
    do {
        cout << oldListAsc.getValue() << " ";
    } while (oldListAsc.moveNext());
    cout << endl;

    oldListDesc.moveLast();
    do {
        cout << oldListDesc.getValue() << " ";
    } while (oldListDesc.movePrev());
    cout << endl;
    
    return 0;
}