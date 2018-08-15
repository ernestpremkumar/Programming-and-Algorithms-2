#include <iostream>
using namespace std;
#include "list.h"

int main()
{
    int m_num;

    // instantiate a List class (the constructor takes NO arguments)
    List list;

    // NOTE:
    // List list();  is incorrect, when there are no arguments don't use ()

    // insert numbers into the list
    // list.print();
    // list.insert(1);
    // list.print();
    // list.insert(2);
    // list.print();
    // list.insert(3);
    // list.print();

    while (cin>>m_num) {
      list.insert_at_end(m_num);
    }

    list.print();

    cout<<"sum = "<<list.sum()<<endl;

    return 0;
}
