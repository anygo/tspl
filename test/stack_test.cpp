/*****************************************************************************
 *                               stack_test.cpp
 *
 * Stack class testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#include <iostream>
#include <string>
#include <utility>
#include <stack.h>


using namespace std;
using namespace itlab;


int main()
{
    pair<int, string > stu;

    Stack< pair<int, string> > s;

    s.push( make_pair(1, "XiaoMing") );
    s.push( make_pair(2, "XiaoHong") );
    s.push( make_pair(3, "XiaoLing") );

    s.getTop( stu );
    cout << stu.first << "\t" << stu.second << endl;

    cout << endl;
    while( !s.isEmpty() )
    {
        s.pop( stu );
        cout << stu.first << "\t" << stu.second <<endl;
    }
    cout << endl;

    s.getTop( stu );
    cout << stu.first << "\t" << stu.second <<endl;

    cout << endl;
    return 0;
}
