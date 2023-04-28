#pragma once
#include "register_user.h"
// #include "book.h"
#include "vector"

#ifndef MEMBER_H
#define MEMBER_H

class Member : public RegisterUser{
    private:
        int startYear;
        int endYear;
        // vector<Member> memberList;
        // vector<Book> borrowBook;

    public:
        Member();

        Member(int, string, string, int, string, string);

        // Member login(string, string);


};

#endif