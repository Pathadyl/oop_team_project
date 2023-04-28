#include <iostream>
#include <string>
#include <vector>
#include "user.h"
#include "register_user.h"
#include "member.h"
#include "admin.h"
#include "guest.h"
// #include "book.h"
#include "Library_menu.h"
using namespace std;


// Member login(string &username, string &password, vector<Member>& list){
//     for(int i = 0; i < list.size(); i++){
//         if(list[i].getUsername() == username && list[i].getPassword() == password){
//             return list[i];
//         }
//     }
// }

int checkAccount(string &username, string &password, vector<Member*>& list){
    for(int i = 0; i < list.size(); i++){
        if(list[i]->getUserName() == username && list[i]->getPassword() == password){
            return i;
        }
    }
    return -1;
}

int checkAccount(string &username, string &password, vector<Admin*>& list){
    for(int i = 0; i < list.size(); i++){
        if(list[i]->getUserName() == username && list[i]->getPassword() == password){
            return i;
        }
    }
    return -1;
}



enum ACTIONTYPE {GUESS_READ, REGISTER, EXIT, LOGIN_MEMBER, LOGIN_ADMIN, LOGOUT, 
                 CREATE_ADMIN, ADD_BOOK, SHOW_BOOK, HIDE_BOOK, REMOVE_BOOK, EDIT_BOOK, 
                 MANAGE_COLLECTION, BORROW_BOOK, RETURN_BOOK};

int main(){
    vector<Member*> memberList;
    vector<Admin*> adminList;
    Member* m = new Member(1, "dylan245", "12345", 14, "0906159559", "Pham Thanh Dat");
    memberList.push_back(m);
    Admin* a = new Admin(2, "admin01", "abcdef", 1, "0906159559", "Dylan Pham");
    adminList.push_back(a);
    Guest g;
    Member* currentMember = nullptr;
    Admin* currentAdmin = nullptr;

//General menu
    Menu* searchMenu = new Menu("SEARCHING BOOK", "Choose kind of method to search");
    Menu* logOut = new Menu("LOG OUT", "Thank you for using our service!", LOGOUT);
    Menu* registerReadMenu = new Menu("READING SECTION FOR REGISTERED USER","Read Book");
    Menu* exitMenu = new Menu("EXIT LIBRARY", "Bye!", EXIT);


//Main Menu
    Menu* mainMenu = new Menu("ONLINE LIBRARY", "Guess Loby");
        Menu* guessReadMenu = new Menu("READING SECTION FOR GUESS", "Read Book", GUESS_READ);
        Menu* loginMenu = new Menu("USER LOGIN", "Please login");
        Menu* userRegisterMenu = new Menu("USER REGISTER", "Please enter your information", REGISTER);

    mainMenu->addSubMenu(guessReadMenu);
    mainMenu->addSubMenu(searchMenu);
    mainMenu->addSubMenu(loginMenu);
    mainMenu->addSubMenu(userRegisterMenu);
    mainMenu->addSubMenu(exitMenu);
    
// Login Menu
    Menu* loginAdminMenu = new Menu("ADMIN LOGIN", "Please login", LOGIN_ADMIN);
    Menu* loginMemberMenu = new Menu("MEMBER LOGIN", "Please login", LOGIN_MEMBER);
    loginMenu->addSubMenu(loginAdminMenu);
    loginMenu->addSubMenu(loginMemberMenu);
    loginMenu->addSubMenu(mainMenu);

// Member Menu
    Menu* memberMenu = new Menu("MEMBER SECTION", "Welcome to member section");
        Menu* serviceMenu = new Menu("SERVICE SECTION", "Choose kind of service");
            Menu* borrowBookMenu = new Menu("BORROW BOOK", "Borrow book", BORROW_BOOK);
            Menu*  returnBookMenu = new Menu("RETURN BOOK", "Return book", RETURN_BOOK);
        serviceMenu->addSubMenu(borrowBookMenu);
        serviceMenu->addSubMenu(returnBookMenu);
        serviceMenu->addSubMenu(memberMenu);

    memberMenu->addSubMenu(registerReadMenu);
    memberMenu->addSubMenu(serviceMenu);
    memberMenu->addSubMenu(logOut);
    memberMenu->addSubMenu(exitMenu);

// Admin Menu
    Menu* adminMenu = new Menu("ADMIN SECTION", "Welcome to admin section");
        Menu* createAdminMenu = new Menu("CREATE ADMIN", "Create admin", CREATE_ADMIN);
        Menu* manageMenu = new Menu("MANAGEMENT SECTION", "Choose manage action!");
            Menu* addBookMenu = new Menu("ADD BOOK", "Add book", ADD_BOOK);
            Menu* showBookMenu = new Menu("SHOW BOOK", "Show book", SHOW_BOOK);
            Menu* hideBookMenu = new Menu("HIDE BOOK", "Hide book", HIDE_BOOK);
            Menu* removeBookMenu = new Menu("REMOVE BOOK", "Remove book", REMOVE_BOOK);
            Menu* editBookMenu = new Menu("EDIT BOOK", "Edit book", EDIT_BOOK);
            Menu* manageCollectionMenu = new Menu("MANAGE COLLECTION", "Manage collection", MANAGE_COLLECTION);
        manageMenu->addSubMenu(addBookMenu);
        manageMenu->addSubMenu(showBookMenu);
        manageMenu->addSubMenu(hideBookMenu);
        manageMenu->addSubMenu(removeBookMenu);
        manageMenu->addSubMenu(editBookMenu);
        manageMenu->addSubMenu(manageCollectionMenu);
        manageMenu->addSubMenu(adminMenu);
    adminMenu->addSubMenu(searchMenu);
    adminMenu->addSubMenu(manageMenu);
    adminMenu->addSubMenu(createAdminMenu);
    adminMenu->addSubMenu(logOut);
    adminMenu->addSubMenu(exitMenu);
    
// Start

    Menu* currentMenu = mainMenu;

    while(true){
        currentMenu->displayMenu();
        int opt = currentMenu->promptOption();
        currentMenu = currentMenu->getSubMenu(opt);

        switch (currentMenu->getAction()){

        case -1:
            break;

        case GUESS_READ:
            currentMenu->displayMenu();
            cout << "Name: " << memberList.back()->getFullName() << endl; 
            cout << "Phone: " << memberList.back()->getPhone() << endl;
            system("pause");
            currentMenu = mainMenu;
            break;


        case REGISTER:
           {    
                currentMenu->displayMenu();
                char ch;
                string registerName; 
                string registerPhone; 
                string registerUserName;
                string registerPassword;
                int id = memberList.back()->getId() + 1;

                cin.ignore();
                cout << "Full name: "; 
                getline(cin, registerName);
                cout << "Phone number: "; 
                getline(cin, registerPhone);
                cout << "User Name: "; 
                getline(cin, registerUserName);
                cout << "Password: "; 
                getline(cin, registerPassword);

                memberList.push_back(g.inviteRegister(1, registerUserName, registerPassword, id, registerPhone, registerName));
                cout << "Register success! Press  any key to continue: "; cin.get(ch);
                currentMenu = mainMenu;
                break;
            }

        case EXIT:
            cout << "Exit the library" << endl;
            exit(0);
            break;

        case LOGIN_MEMBER:
            {
                currentMenu->displayMenu();
                string username;
                string password;
                char ch;

                cin.ignore();
                cout << "Username: "; getline(cin, username);
                cout << "Password: "; getline(cin, password);
                
                if(checkAccount(username, password, memberList) != -1){
                    currentMember = memberList[checkAccount(username, password, memberList)];
                    cout << "Login success! Press any key to continue: ";
                    cin.get(ch);
                    currentMenu = memberMenu;
                } else {
                    cout << "Login fail! Please try again: ";
                    cin.get(ch);
                    currentMenu = loginMenu;
                }

            }
            break;

        case LOGIN_ADMIN:
            {
                currentMenu->displayMenu();
                string username;
                string password;
                char ch;

                cin.ignore();
                cout << "Username: "; getline(cin, username);
                cout << "Password: "; getline(cin, password);
                
                if(checkAccount(username, password, adminList) != -1){
                    currentAdmin = adminList[checkAccount(username, password, adminList)];
                    cout << "Login success! Press any key to continue: ";
                    cin.get(ch);
                    currentMenu = adminMenu;
                } else {
                    cout << "Login fail! Press any key to continue: ";
                    cin.get(ch);
                    currentMenu = loginMenu;
                }

            }
            break;

        case LOGOUT:
            currentMenu->displayMenu();
            currentMenu = mainMenu;
            break;
            
        
        default:
            cout << "Default action!" << endl;
            break;
        }

    }

//Deallocate memory

    for(int i = 0; i < memberList.size(); i++){
        delete memberList[i];
    }
    memberList.clear();

    for(int i = 0; i < adminList.size(); i++){
        delete adminList[i];
    }
    adminList.clear();

    delete currentMember;
    delete currentAdmin;

    return 0;
}