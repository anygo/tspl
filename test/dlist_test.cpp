/*****************************************************************************
 *                               dlist_test.cpp
 *
 * Double list class testing.
 *
 * Zhang Ming, 2009-10, Xi'an Jiaotong University.
 *****************************************************************************/


#include <iostream>
#include <string>
#include <doublelist.h>


using namespace std;
using namespace itlab;


template <typename Type>
void printList( const DList<Type> &dl )
{
    if( dl.isEmpty() )
        cout << "  The list is empty!" << endl;

    typename DList<Type>::Iterator itr = dl.begin();
    while( itr != dl.end() )
        cout << "  " << *itr++ << endl;

    cout << endl;
}


int main()
{
    string name;
    DList<string> dl;

    dl.pushBack( "Zhang Ming" );
    dl.pushBack( "Zhang Zong" );
    printList( dl );

    dl.pushFront( "Yu Kai" );
    dl.pushFront( "Yu Zong" );
    printList( dl );

    dl.popFront();
    dl.popFront();
    printList( dl );

    dl.popBack();
    printList( dl );

    DList<string>::Iterator itr = dl.begin();
    dl.insert( itr, "Yu Kai" );
    printList( dl );

    dl.insert( dl.end(), "Yu Zong" );
    printList( dl );

    cout << "  The first element in the list is: " << dl.front() << endl;
    cout << "  The last element in the list is: " << dl.back() << endl;
    cout << endl;

    dl.erase( dl.begin() );
    dl.erase( --dl.end() );
    printList( dl );

    DList<string>::Const_Iterator citr = dl.begin();
    cout << "  " << *citr << endl;
    cout << endl;

    dl.clear();
    printList( dl );

    return 0;
}
