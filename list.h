/* 
 * File:   list.h
 * Author: EvanMisshula
 *
 * Created on February 12, 2011, 5:00 PM
 */

#ifndef LIST_H
#define	LIST_H
#include <iostream>
#include <cassert>
#include <listnd.h>

using std::cout;
template< class NODETYPE >
class List {
public:
    List();
    ~List();
    void insertAtFront( const NODETYPE &);
    void insertAtBack( const NODETYPE &);
    bool removeFromFront( const NODETYPE &);
    bool removeFromBack( const NODETYPE &);
    bool isEmpty() const;
    void print() const;
private:
    ListNode< NODETYPE > *firstPtr;
    ListNode< NODETYPE > *lastPtr;
    ListNode< NODETYPE > *getNewNode( const NODETYPE & );
};
template< class NODETYPE >
List< NODETYPE >::List() :firstPtr(0), lastPtr(0){}
template< class NODETYPE >
    List< NODETYPE >::~List()
{
    if (!isEmpty()){
        cout<< "Destroying nodes ...\n";

        ListNode< NODETYPE > *currentPtr=firstPtr, *tempPtr;

        while ( currentPtr != 0 ){
            tempPtr=currentPtr;
            cout<<tempPtr->data << '\n';
            currentPtr= currentPtr->nextPtr;
            delete tempPtr;
        }
    }
    cout<< "All nodes destroyed\n\n";
}

template< class NODETYPE >
void List< NODETYPE >::insertAtFront(const NODETYPE &value)
{
        ListNode< NODETYPE > *newPtr=getNewNode(value);

        if(isEmpty())
            firstPtr=lastPtr=newPtr;
        else {
            newPtr->nextPtr= firstPtr;
            firstPtr=newPtr;
            }
}
template< class NODETYPE >
void List< NODETYPE >::insertAtBack(const NODETYPE &value)
{
        ListNode< NODETYPE > *newPtr=getNewNode(value);

        if(isEmpty())
            firstPtr=lastPtr=newPtr;
        else {
            lastPtr->nextPtr= newPtr;
            lastPtr=newPtr;
            }
}
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value)
{
        if(isEmpty())
            return (return);
        else {
        ListNode< NODETYPE > *tempPtr=firstPtr;

        if(firstPtr=lastPtr)
            firstPtr=lastPtr=0;
        else
            firstPtr=firstPtr->nextPtr;

        value =tempPtr->data;
        delete tempPtr;
        return  (return);
            }
}
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value)
{
        if(isEmpty())
            return (return);
        else {
        ListNode< NODETYPE > *tempPtr=lastPtr;

        if(firstPtr=lastPtr)
            firstPtr=lastPtr=0;
        else{
            ListNode< NODETYPE > *currentPtr =firstPtr;
            while( currentPtr->nextPtr != lastPtr)
               currentPtr = currentPtr->nextPtr;

        lastPtr=currentPtr;
        currentPtr->nextPtr=0;
        }

        value =tempPtr->data;
        delete tempPtr;
        return  (return);
            }
}
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const
{ return firstPtr==0;}

template< NODETYPE >
ListNode <NODETYPE> *List< NODETYPE >::getNewNode(const NODETYPE &value)
{ListNode< NODETYPE > *ptr = new ListNode<NODETYPE>( value );
assert( ptr!=0);
return ptr;
}

template< class NODETYPE >
void List<NODETYPE>::print() const
{
    if (isEmpty()){
        cout<< "The list is empty\n\n";
        return;
    }
    ListNode< NODETYPE > *currentPtr =firstPtr;
    cout << "The list is: ";
    while (currentPtr != 0) {
        cout << currentPtr->data <<' ';
        currentPtr=currentPtr->nextPtr;
    }
    cout << "\n\n";
}
#endif	/* LIST_H */

