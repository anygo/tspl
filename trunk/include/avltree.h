/*****************************************************************************
 *                                 avltree.h
 *
 * AVL Tree implemented by C++ class template.
 *
 * This class provides "traversal(preorder,inorder or postorder), "search",
 * "insert" and "remove" operations by using an AVL Tree. The rotation
 * technology is used to keep the tree balanced. Of cause, you can get the
 * height of the tree by the subroutine "height".
 *
 * Zhang Ming, 2009-10
 *****************************************************************************/


#ifndef AVLTREE_H
#define AVLTREE_H


#include <cstdlib>
#include <stack.h>


namespace itlab
{

    /**
     * Node in AVL Tree
     */
    template <typename Object, typename Key>
    struct AVLNode
    {
        Object data;
        int balance;

        AVLNode<Object, Key> *left,
                             *right;

        AVLNode() : left(NULL), right(NULL), balance(0)
        { }

        AVLNode( const Object &x, AVLNode<Object, Key> *lp=NULL,
                 AVLNode<Object, Key> *rp=NULL ) : balance(0)
        {   data = x; left = lp; right = rp;    }

        bool operator<( AVLNode<Object, Key> &t )
        {   return data < t.data;    }

        bool operator>( AVLNode<Object, Key> &t )
        {   return data > t.data;    }

        bool operator==( AVLNode<Object, Key> &t )
        {	return data == t.data;    }

    };
    // class AVLNode


    /**
     * AVL Tree
     */
    template <typename Object, typename Key>
    class AVLTree
    {

    public:

        AVLTree();
        ~AVLTree();

    //	AVLTree( const AVLTree<Object, Type> &rhs );
    //	AVLTree<Object, Type>& operator=( const AVLTree<Object, Type> &rhs );

        inline bool isEmpty() const;
        inline void makeEmpty();

        inline void print( const string &mode );

        inline int height() const;
        inline AVLNode<Object, Key>* search( Key k );
        inline bool insert( Object &x );
        inline bool remove( Key k, Object &x );

    private:

        AVLNode<Object, Key> *root;

        void preTraversal( AVLNode<Object, Key> *t );
        void inTraversal( AVLNode<Object, Key> *t );
        void postTraversal( AVLNode<Object, Key> *t );

        void makeEmpty( AVLNode<Object, Key> * &t );

        int height( AVLNode<Object, Key> *t ) const;
        AVLNode<Object, Key>* search( Key k, AVLNode<Object, Key> *t );
        bool insert( AVLNode<Object, Key> * &ptr, Object &x );
        bool remove( AVLNode<Object, Key> * &ptr, Key k, Object &x );

        void rotateL( AVLNode<Object, Key> * &ptr );
        void rotateR( AVLNode<Object, Key> * &ptr );
        void rotateLR( AVLNode<Object, Key> * &ptr );
        void rotateRL( AVLNode<Object, Key> * &ptr );

        void handleUnderflow();

    };
    // class AVLTree


    #include <avltree-impl.h>

}
// namespace itlab


#endif
// AVLTREE_H
