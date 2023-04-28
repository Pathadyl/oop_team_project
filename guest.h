#include "user.h"
#include "member.h"
#include <string>
using namespace std;

class Guest : public User {
    private:
        int id;

    public:
        Guest();

        Guest(int, int);

        void setId(int);

        int getId(int) const
            {return id;}

        Member* inviteRegister(int, string, string, int, string, string);


};