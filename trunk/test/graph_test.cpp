/*****************************************************************************
 *                               graph_test.cpp
 *
 * Adjacency List Based Undirected Graph testing.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <graph.h>


using namespace std;
using namespace itlab;


int main()
{
    ALGraph<char, int> g( 5 );

    g.insertVertex( 'A' );
    g.insertVertex( 'B' );
    g.insertVertex( 'C' );
    g.insertVertex( 'D' );
    cout << g << endl << endl;

    g.insertEdge( 'A', 'B', 4 );
    g.insertEdge( 'A', 'C', 2 );
    g.insertEdge( 'B', 'D', 3 );
    cout << g << endl << endl;

    g.removeEdge( 'A', 'B' );
    cout << g << endl << endl;

    g.removeVertex('B');
    cout << g << endl << endl;

    g.removeEdge( 'A', 'B' );
    cout << g << endl << endl;

    g.removeVertex('B');
    cout << g << endl;

    return 0;
}
