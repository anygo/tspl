/*****************************************************************************
 *                               algraph_test.cpp
 *
 * Adjacency List Based Undirected Graph testing.
 *
 * Zhang Ming, 2009-10, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <algraph.h>


using namespace std;
using namespace itlab;


int main()
{
    ALGraph<char, int> g( 6 );

    g.insertVertex( 'A' );
    g.insertVertex( 'B' );
    g.insertVertex( 'C' );
    g.insertVertex( 'D' );
    g.insertVertex( 'E' );
    g.insertVertex( 'F' );
    cout << g << endl << endl;

    g.insertEdge( 'A', 'B', 6 );
    g.insertEdge( 'A', 'C', 1 );
    g.insertEdge( 'A', 'D', 5 );
    g.insertEdge( 'B', 'C', 5 );
    g.insertEdge( 'B', 'E', 3 );
    g.insertEdge( 'C', 'D', 5 );
    g.insertEdge( 'C', 'E', 6 );
    g.insertEdge( 'C', 'F', 4 );
    g.insertEdge( 'D', 'F', 2 );
    g.insertEdge( 'E', 'F', 6 );
    cout << g << endl << endl;

    cout << "The Depth First Search traverse:" << endl;
    g.dfs();
    cout << endl << endl;
    cout << "The Breadth First Search traverse:" << endl;
    g.bfs();
    cout << endl << endl;

    cout << "The Minimum Span Tree:" << endl;
    int vtxNum = g.getVertexNumber();
    int start = 0,
        *addedVertex = new int[vtxNum],
        *conectedVertex = new int[vtxNum],
        *lowCost = new int[vtxNum];
    g.minSpanTree( start, addedVertex, conectedVertex, lowCost );
    for( int i=0; i<vtxNum; ++i )
        cout << "( " << addedVertex[i] << ", "
             << conectedVertex[addedVertex[i]] << ", "
             << lowCost[addedVertex[i]] << " )" << endl;
    cout << endl << endl;

    g.removeVertex('B');
    cout << g << endl << endl;

    g.removeEdge( 'A', 'B' );
    cout << g << endl << endl;
    g.removeEdge( 'A', 'D' );
    cout << g << endl << endl;
    g.removeEdge( 'E', 'D' );
    cout << g << endl << endl;

    cout << "The depth first search traverse:" << endl;
    g.dfs();
    cout << endl << endl;
    cout << "The Breadth First Search traverse:" << endl;
    g.bfs();
    cout << endl << endl;

    delete []addedVertex;
    delete []conectedVertex;
    delete []lowCost;
    return 0;
}
