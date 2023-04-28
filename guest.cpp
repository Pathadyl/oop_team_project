#include<iostream>
#include "guest.h"
#include "member.h"
using namespace std;

Guest::Guest()
    :User()
{
    id = 0;
}

Guest::Guest(int access, int id)
    :User(access)
{
    this -> id = id;
}

void Guest::setId(int id){
    this -> id = id;
}

Member* Guest::inviteRegister(int access, string userName, string password, int id, string phone, string fullName){
    Member* member = new Member(access, userName, password, id, phone, fullName);
     return member;
}

