#include <iostream>
#include "List.h"
// #include "oldList.h"
using namespace std;

int main(void)
{
    cout << "Double Linked Sample code" << endl;
    homework::List<int> listDesc;
    homework::List<int> listAsc;
    for (int i = 0; i < 10; i++)
    {
        listDesc.addFront(i);
        listAsc.addLast(i);
    }

    if(listDesc.chkEmpty() || listAsc.chkEmpty()) {
        cout << "input data fail" << endl;
        return 0;
    }

    listAsc.moveFront();
    do {
        cout << listAsc.getValue() << " ";
    } while (listAsc.moveNext());
    cout << endl;

    listDesc.moveLast();
    do {
        cout << listDesc.getValue() << " ";
    } while (listDesc.movePrev());
    cout << endl;
    
    return 0;
}