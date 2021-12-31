#include <iostream>
#include "myList.h"
using namespace std;

int main(void)
{
    cout << "Double Linked Sample code" << endl;
    old::List<int> oldList;
    for (int i = 0; i < 10; i++)
    {
        oldList.addFront(i);
    }

    if(!oldList.chkEmpty()) {
        oldList.moveFront();
        do {
            cout << oldList.getValue() << " ";
        } while (oldList.moveNext());
    }
    cout << endl;
    return 0;
}