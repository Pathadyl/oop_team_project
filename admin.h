#pragma once
#include "register_user.h"
// #include "collection.h"
// #include "book.h"
#include "string"
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin : public RegisterUser {
    private:
        // Collection *listCollection;
        // Book *listBook;
        int sizeListCollection;
        int sizeListBook;
    
    public: 
        Admin();

        Admin(int, string, string, int, string, string);

        // void addBook(Book b);

        // void createAdmin();

        // void showBook(Book b);

        // void hideBook(Book b);

        // void editBook(Book b);

        // void createCollection();

        // void deleteCollection(Collection c);

        ~Admin();

};

#endif