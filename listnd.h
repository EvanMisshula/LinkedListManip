/* 
 * File:   listnd.h
 * Author: EvanMisshula
 *
 * Created on February 12, 2011, 4:44 PM
 */

#ifndef LISTND_H
#define	LISTND_H

template< class NODETYPE > class List;  //forward declaration

template<class NODETYPE>
class  ListNode {
    friend class List< NODETYPE >;
public:
    ListNode( const NODETYPE &);
    NODETYPE getdata() const;
private:
    NODETYPE data;
    ListNode< NODETYPE > *nextPtr;
};

// Constructor
template<class NODETYPE >
NODETYPE ListNode< NODETYPE >::getdata() const { return data;}

#endif	/* LISTND_H */

