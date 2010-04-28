/*****************************************************************************
 *                               graph-impl.h
 *
 * Implementation for ALGraph class.
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


/**
 * constructors and destructor
 */
template<typename Object, typename Weight>
ALGraph<Object,Weight>::ALGraph( int n )
{
    maxSize = n;
    curSize = 0;
    edgeNum = 0;

    vertexArray = new Vertex<Object,Weight>[maxSize];
    if( vertexArray == NULL )
    {
        cerr << "Out of memory!";
        exit(1);
    }

    for( int i=0; i<maxSize; ++i )
		vertexArray[i].adj = NULL;
}

template<typename Object, typename Weight>
ALGraph<Object,Weight>::~ALGraph()
{
    for( int i=0; i<maxSize; ++i )
    {
        Edge<Weight> *p = vertexArray[i].adj;
        while( p != NULL )
        {
            vertexArray[i].adj = p->next;
            delete p;
            p = vertexArray[i].adj;
        }
    }

    delete []vertexArray;
}


/**
 * Get the vertex number of the graph.
 */
template<typename Object, typename Weight>
int ALGraph<Object,Weight>::getVertexNumber() const
{
    return curSize;
}


/**
 * Get the edge number of the graph.
 */
template<typename Object, typename Weight>
int ALGraph<Object,Weight>::getEdgeNumber() const
{
    return edgeNum;
}


/**
 * Return the content of vertex "i".
 */
template<typename Object, typename Weight>
inline Object ALGraph<Object,Weight>::getData( int i ) const
{
#ifdef BOUNDS_CHECK
    assert( 0 <= i );
	assert( i < maxSize );
#endif

    return vertexArray[i].data;
}


/**
 * Return the index of vertex "x".
 */
template<typename Object, typename Weight>
int ALGraph<Object,Weight>::getIndex( const Object &x ) const
{
    for( int i=0; i<curSize; ++i )
        if( vertexArray[i].data == x )
            return i;

    return -1;
}


/**
 * Return weight on the edge between vertex "x1" and "x2".
 */
template<typename Object, typename Weight>
Weight ALGraph<Object,Weight>::getWeight( const Object &x1, const Object &x2 ) const
{
    int v1 = getIndex(x1),
        v2 = getIndex(x2);

    if( v1 == -1 )
    {
        cerr << "There is no vertex x1!" << endl;
        return Weight(0);
    }
    else if( v2 == -1 )
    {
        cerr << "There is no vertex x2!" << endl;
        return Weight(0);
    }
    else
    {
        Edge<Weight> *p = vertexArray[v1].adj;
        while( p != NULL && p->dst != v2 )
            p = p->next;

        if( p != NULL )
            return p->cost;
        else
        {
            cerr << "There is no edge between x1 and x2!" << endl;
            return Weight(0);
        }
    }
}


/**
 * Get the position of the next adjacency point of vertex "x".
 */
template<typename Object, typename Weight>
int ALGraph<Object,Weight>::getNextDst( const Object &x ) const
{
    int i = getIndex(x);

    if( i == -1 )
    {
        cerr << "There is no vertex x!" << endl;
        return -1;
    }
    else
    {
        Edge<Weight> *p = vertexArray[i].adj;
        if( p != NULL )
            return p->dst;
        else
            return -1;
    }
}

template<typename Object, typename Weight>
int ALGraph<Object,Weight>::getNextDst( const Object &x1, const Object &x2 ) const
{
    int v1 = getIndex(x1),
        v2 = getIndex(x2);

    if( v1 == -1 )
    {
        cerr << "There is no vertex x1!" << endl;
        return -1;
    }
    else if( v2 == -1 )
    {
        cerr << "There is no vertex x2!" << endl;
        return -1;
    }
    else
    {
        Edge<Weight> *p = vertexArray[v1].adj;
        while( p != NULL && p->dst != v2 )
            p = p->next;

        if( p != NULL && p->next != NULL )
            return p->next->dst;
        else
            return -1;
    }
}


/**
 * Insert a new vertex "x". If the vertex array is full, then
 * return false, else return true.
 */
template<typename Object, typename Weight>
void ALGraph<Object,Weight>::insertVertex( const Object &x )
{
    if( curSize < maxSize )
        vertexArray[curSize++] = Vertex<Object,Weight>( x, NULL );
    else
        cerr << "The vertex table is full!" << endl;
}


/**
 * Remove the vertex "x".
 */
template<typename Object, typename Weight>
void ALGraph<Object,Weight>::removeVertex( const Object &x )
{
    int i = 0,
        v = getIndex(x);

    if( v == -1 )
        cerr << "There is no vertex x!" << endl;
    else
    {
        Edge<Weight> *p, *r, *s;

        while( vertexArray[v].adj != NULL )
        {
            p = vertexArray[v].adj;
            i = p->dst;

            r = vertexArray[i].adj;
            s = NULL;
            while( r != NULL && r->dst != v )
            {
                s = r;
                r = r->next;
            }
            if( s != NULL )
                s->next = r->next;
            else
                vertexArray[i].adj = r->next;
            delete r;

            vertexArray[v].adj = p->next;
            delete p;
            edgeNum--;
        }

        vertexArray[v] = vertexArray[--curSize];
        vertexArray[curSize].adj = NULL;

        p = vertexArray[i].adj;
        while( p != NULL )
        {
            r = vertexArray[p->dst].adj;
            while( s != NULL )
            {
                if( s->dst == curSize )
                {
                    s->dst = v;
                    break;
                }
                else
                    s = s->next;
            }
            p = p->next;
        }
    }
}


/**
 * Insert an edge (x1,x2) with weight "c". If the edge already exist then
 * return false, else return true.
 */
template<typename Object, typename Weight>
void ALGraph<Object,Weight>::insertEdge( const Object &x1, const Object &x2, Weight c )
{
    int v1 = getIndex(x1),
        v2 = getIndex(x2);

    if( v1 == -1 )
        cerr << "There is no vertex x1!" << endl;
    else if( v2 == -1 )
        cerr << "There is no vertex x2!" << endl;
    else
    {
        Edge<Weight> *p = vertexArray[v1].adj,
                     *q = NULL;

        while( p != NULL && p->dst != v2 )
            p = p->next;
        if( p != NULL )
            cerr << "The edge is already existence!" << endl;

        p = new Edge<Weight>( v2, c, vertexArray[v1].adj );
        vertexArray[v1].adj = p;

        q = new Edge<Weight>( v1, c, vertexArray[v2].adj );
        vertexArray[v2].adj = q;

        edgeNum++;
    }
}


/**
 * Remove the edge (x1,x2).
 */
template<typename Object, typename Weight>
void ALGraph<Object,Weight>::removeEdge( const Object &x1, const Object &x2 )
{
    int v1 = getIndex(x1),
        v2 = getIndex(x2);

    if( v1 == -1 )
        cerr << "There is no vertex x1!" << endl;
    else if( v2 == -1 )
        cerr << "There is no vertex x2!" << endl;
    else
    {
        Edge<Weight> *p = vertexArray[v1].adj,
                     *q = NULL,
                     *r = p;

        while( p != NULL && p->dst != v2 )
        {
            q = p;
            p = p->next;
        }

        if( p != NULL )
        {
            if( p == r )
                vertexArray[v1].adj = p->next;
            else
            {
                q->next = p->next;
                delete p;
            }
        }
        else
            cerr << "There is no such edge!" << endl;

        p = vertexArray[v2].adj;
        q = NULL;
        r = p;

        while( p->dst != v1 )
        {
            q = p;
            p = p->next;
        }

        if( p == r )
            vertexArray[v2].adj = p->next;
        else
        {
            q->next = p->next;
            delete p;
        }

        edgeNum--;
    }
}


/**
 * Reload the "<<" operator.
 */
template<typename Object, typename Weight>
ostream& operator<<( ostream &out, const ALGraph<Object,Weight> &g )
{
    int verNum = g.getVertexNumber(),
        edgeNum = g.getEdgeNumber();

    out << "This graph has " << verNum << " vertexes and " << edgeNum << " edges." << endl;
    for( int i=0; i<verNum; ++i )
    {
        Object x1 = g.getData(i);
        out << x1 << " :    ";
        int j = g.getNextDst(x1);
        if( j != -1 )
        {
            Object x2 = g.getData(j);
            out << "( " << x1 << ", " << x2 << ", " << g.getWeight(x1,x2) << " )" << "    ";
            do
            {
                j = g.getNextDst( x1, x2 );
                if( j != -1 )
                {
                    x2 = g.getData(j);
                    out << "( " << x1 << ", " << x2 << ", " << g.getWeight(x1,x2) << " )" << "    ";
                }
                else
                    break;
            }
            while( j != -1 );
        }
        out << endl;
    }
    return out;
}
