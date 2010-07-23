/*****************************************************************************
 *                               amgraph_test.cpp
 *
 * Adjacency Matrix Based Undirected Graph testing.
 *
 * Zhang Ming, 2010-07, Xi'an Jiaotong University.
 *****************************************************************************/


#define BOUNDS_CHECK

#include <iostream>
#include <amgraph.h>


using namespace std;
using namespace itlab;


int main()
{
    AMGraph<char,int> g;

    g.insertVertex( 'A' );
    g.insertVertex( 'B' );
    g.insertVertex( 'C' );
    g.insertVertex( 'D' );
    g.insertVertex( 'E' );
    g.insertVertex( 'F' );
    cout << g << endl << endl;

    g.insertEdge( 'A', 'B', 50 );
    g.insertEdge( 'A', 'E', 70 );
    g.insertEdge( 'A', 'C', 10 );
    g.insertEdge( 'B', 'C', 15 );
    g.insertEdge( 'B', 'E', 10 );
    g.insertEdge( 'C', 'A', 20 );
    g.insertEdge( 'C', 'D', 15 );
    g.insertEdge( 'D', 'B', 20 );
    g.insertEdge( 'D', 'E', 35 );
    g.insertEdge( 'E', 'D', 30 );
    g.insertEdge( 'F', 'D', 3 );
    cout << g << endl << endl;

    int verNum = g.getVertexNumber(),
        start = g.getIndex( 'A' ),
        *dist = new int[verNum],
        *path = new int[verNum];
    g.dijkstra( start, dist, path );
    cout << "The Dijkstra algorithm for Single-Source Shortest Path." << endl;
    for( int i=0; i<verNum; ++i )
    {
        if( dist[i] < g.MAXWEIGHT )
        {
            cout << i << ":\t" << dist[i] << "\t" << i << " <-- ";
            for( int j=path[i]; j!=start; j=path[j] )
                cout << j << " <-- ";
            cout << start << endl;
        }
        else
            cout << i << ":\tMAX\tNo Path!" <<endl;
    }
    cout << endl << endl;

    int **dist2D,
        **path2D;
    makeMatrix( dist2D, verNum, verNum );
    makeMatrix( path2D, verNum, verNum );
    g.floyd( dist2D, path2D );
    cout << "The Floyd algorithm for All-Pairs Shortest Paths." << endl;
    for( int v=0; v<verNum; ++v )
    {
        cout << "The " << v << "th vertex's shortest path: " << endl;
        for( int i=0; i<verNum; ++i )
        {
            if( dist2D[v][i] < g.MAXWEIGHT )
            {
                cout << i << ":\t" << dist2D[v][i] << "\t" << i << " <-- ";
                for( int j=path2D[v][i]; j!=v; j=path2D[v][j] )
                    cout << j << " <-- ";
                cout << v << endl;
            }
            else
                cout << i << ":\tMAX\tNo Path!" <<endl;
        }
        cout << endl;
    }
    cout << endl;

    g.removeVertex( 'B' );
    cout << g << endl << endl;

    g.removeEdge( 'A', 'E' );
    g.removeEdge( 'F', 'D' );
    cout << g << endl << endl;

    g.removeVertex( 'B' );
    g.removeEdge( 'A', 'B' );
    g.removeEdge( 'E', 'C' );
    g.removeEdge( 'F', 'D' );

    cout << endl;
    return 0;
}
