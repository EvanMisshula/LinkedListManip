/* 
 * File:   main.cpp
 * Author: EvanMisshula
 *
 * Created on February 12, 2011, 4:43 PM
 */
#include <iostream>
#include <cstdlib>
#include "list.h"

using namespace std;
using std::cin;
using std::endl;

template< class T >
void testList( List< T > &listObject, const char *type )
{
    cout<<"Testing a list of "<<type << " values\n";
            instructions();
    int choice;
    T value;
    do{
        cout<<"? ";
        cin>> choice;
        switch (choice){
            case 1:
                cout<< "Enter "<< type << ": ";
                cin>> value;
                listObject.insertAtFront( value );
                listObject.print();
                break;
            case 2:
                cout<< "Enter "<< type << ": ";
                cin>> value;
                listObject.insertAtBack( value );
                listObject.print();
                break;
            case 3:
                if( listObject.removeFromFront( value))
                    cout<< value << " removed from list\n";
                listObject.print();
                break;
            case 4:
                if( listObject.removeFromBack( value ))
                    cout<< value << " removed from list\n";
                listObject.print();
                break;
        }
    } while ( choice != 5 );
    cout << "End list test \n\n";

}

void instructions()
{
    cout<<"Enter one of the following:\n"
         << "  1 to insert at begining of the list\n"
         << "  2 to insert at the end of the list\n"
         << "  3 to delete from begining of the list\n"
         << "  4 to delete from the end of the list\n"
         << "  5 to end list processing\n";
}

/*
 * 
 */
int main() {
    List< int > integerList;
    testList( integerList, "integer");
    List< double > doubleList;
    testList( doubleList, "double");
    return 0;
}

