#include <iostream>
#include "menu.cpp"
using namespace std;

int main()
{
    int userChoice;
    
    do {
        userChoice = 0;
        Menu menu;
        menu.welcomeMenu();
        
        cin >> userChoice;
        
        if(userChoice > 3)
        {
            cout << "Invalid Entry!\nPlease select option 1-3\n";
            menu.welcomeMenu();
            cin >> userChoice;
        }
        
        
            switch(userChoice)
            {
                case 1:
                    system("clear");
                    menu.manLogin();
                    break;
                case 2:
                    system("clear");
                    menu.emLogin();
                    break;
                case 3:
                    cout << "Exiting program!";
                    exit(0);
                    break;
                default:
                    break;
            }
    } while(userChoice != 3);
}
