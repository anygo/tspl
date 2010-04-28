/*****************************************************************************
 *                                    student.h
 *
 * A student class including comparison operators.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>


using namespace std;


namespace itlab
{

    class Student
    {

    public:

        Student() : key(0), firstName("Ming"), lastName("Zhang")
        { }

        Student( int number, const string &name1="Ming",
                             const string &name2="Zhang" )
        {
            key = number;
            firstName = name1;
            lastName = name2;
        }

        ~Student()
        { }

        inline void operator=( const Student &stu )
        {
            key = stu.key;
            firstName = stu.firstName;
            lastName = stu.lastName;
        }

        inline bool operator<( const Student &stu )
        {   return key < stu.key;   }

        inline bool operator>( const Student &stu )
        {   return key > stu.key;   }

        inline bool operator==( const Student &stu )
        {   return key == stu.key;   }

        friend istream& operator>>( istream &in, Student &stu )
        {
            in >> stu.key >> stu.lastName >> stu.firstName;
            return in;
        }

        friend ostream& operator<<( ostream &out, Student &stu )
        {
            out << stu.key << "\t"
                << stu.lastName << " " << stu.firstName << endl;
            return out;
        }

        int key;

    private:

        string firstName;
        string lastName;

    };
    // class Student

}
// namespace itlab


#endif
// STUDENT_H
