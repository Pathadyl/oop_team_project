#include "member.h"

Member::Member()
    :RegisterUser()
{
    startYear = 2022;
    endYear = 2024;
    // memberList.push_back(this);
}

Member::Member(int access, string userName, string password, int id, string phone, string fullName)
    :RegisterUser(access, userName, password, id, phone, fullName)
{
    startYear = 2022;
    endYear = 2024;
    // memberList.push_back(this);
}

// Member Member::login(string userName, string password){
//     for(int i = 0; i < memberList.size(); i++){
//         if(memberList[i].getUserName() == userName && memberList[i].getPassword() == password){
//             return memberList[i];
//         }
//     } 
// }
