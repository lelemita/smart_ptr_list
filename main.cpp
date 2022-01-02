#include <iostream>
#include "List.h"
// #include "oldList.h"
using namespace std;

int main(void)
{
    cout << "Double Linked Sample code" << endl;
    cout << "--- Test1: ASC and DESC ---" << endl;
    homework::List<int> listDesc;
    homework::List<int> listAsc;
    for (int i = 0; i < 10; i++)
    {
        listDesc.addFront(i);
        listAsc.addLast(i);
    }
    if(listDesc.size() == 0 || listAsc.chkEmpty()) {
        cout << "input data fail" << endl;
        return 0;
    }
    listAsc.printFromFront();
    listAsc.printFromLast();
    listDesc.printFromFront();
    listDesc.printFromLast();    

    cout << "--- Test2: REMOVE head and tail ---" << endl;
    listAsc.removeFront();
    listAsc.removeLast();
    
    listAsc.printFromFront();
    listAsc.printFromLast();

    cout << "--- Test3: Use Index ---" << endl;
    homework::List<int> listOne;
    for (int i = 0; i < 10; i++)
    {
        listOne.addFront(1);
    }
    listOne.move(3);
    listOne.add(0);

    listOne.printFromFront();
    listOne.printFromLast();

    listOne.move(3);
    listOne.remove();

    listOne.printFromFront();
    listOne.printFromLast();

    return 0;
}