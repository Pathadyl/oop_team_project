#pragma once
#ifndef USER_H
#define USER_H

class User{

    private:
        int access;

    public:
        User();

        User(int);

        virtual void read();

        void searchByTitle();

        void searchBySerial();

        void setAccessibility(int);

        int getAccessibility() const
            {return access;}

        void login();
};

#endif