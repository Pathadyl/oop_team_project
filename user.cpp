#include "user.h"

User::User(){
    access = 0;
}

User::User(int access){
    this -> access = access;
}

void User::read(){

}

void User::searchByTitle(){
}

void User::searchBySerial(){
}


void User::setAccessibility(int access)
{
    this -> access = access;
}

