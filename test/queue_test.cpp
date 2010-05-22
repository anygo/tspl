/*****************************************************************************
 *                               queue_test.cpp
 *
 * Queue class testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#include <iostream>
#include <string>
#include <queue.h>


using namespace std;
using namespace itlab;


struct Student
{
    int     stuNum;
    string  stuName;
    string  department;

    Student( int number = 0, const string &name = "Tom&Jerry",
             const string &dpt = "Information" )
    : stuNum(number), stuName(name), department(dpt)
    { }

};


int main()
{
    Student stu;
    Queue<Student> q;

    q.enqueue( Student(11, "ZhangMing", "Information") );
    q.enqueue( Student(16, "HuZhaoJun") );
    q.enqueue( Student(11, "ZhangYuYang", "AutoControl") );
    q.enqueue( Student() );


    q.getFront( stu );
    cout << "  " << stu.stuNum << "\t" << stu.stuName << "\t"
         << stu.department << endl;

    cout << endl;
    while( !q.isEmpty() )
    {
        q.dequeue( stu );
        cout << "  " << stu.stuNum << "\t" << stu.stuName << "\t"
             << stu.department << endl;
    }
    cout << endl;

    q.getFront( stu );
    cout << "  " << stu.stuNum << "\t" << stu.stuName << "\t"
         << stu.department;

    cout << endl << endl;
    return 0;
}
