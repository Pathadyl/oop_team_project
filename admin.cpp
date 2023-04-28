#include "admin.h"
#include "string"
#include <iostream>
using namespace std;

Admin::Admin()
    :RegisterUser()
{
    // listCollection = new Collection;
    // listBook = new Book;
}

Admin::Admin(int access, string userName, string password, int id, string phone, string fullName)
    :RegisterUser(access, userName, password, id, phone, fullName)
{
    
}

// void Admin::addBook(Book b){
//     cout << "Add book!" << endl;
// }

// void Admin::createAdmin()
// {
    
// }

// void Admin::showBook(Book b)
// {
//     cout << "Show Book" << endl;
// }

// void Admin::hideBook(Book b)
// { 
//     cout << "Hide book" << endl;
// }

// void Admin::editBook(Book b)
// {
//     cout << "Edit book" << endl;
// }

// void Admin::createCollection(){
// }

// void Admin::deleteCollection(Collection c)
// {
// }

Admin::~Admin(){
    // delete [] listBook;
    // delete [] listCollection;
}
