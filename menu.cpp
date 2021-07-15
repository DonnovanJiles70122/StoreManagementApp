#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

class Menu
{
public:
    // Class constructor
    Menu(){}
    
    ~Menu(){}
    
    void welcomeMenu(){
        system("clear");
        cout << "_________________________________\n"
        << "| Trader Joe's schedule tracker |\n"
        << "|      1. Manager login         |\n"
        << "|      2. Employee login        |\n"
        << "|      3. Quit progam           |\n"
        << "---------------------------------\n\n";
    }
    
    void manLogin(){
        const int userID = 94501;
        const int userPW = 70122;
        int password = 0;
        int iD = 0;
        
        
        cout << "Enter your user ID : ";
        cin >> iD;
        cout << "Enter your password : ";
        cin >> password;
        
        if(password == userPW && iD == userID)
        {
            system("clear");
            manMenu();
        }
        else
        {
            cout << "Your Username or Password are incorrect please try again\n";
            system("clear");
            cout << "Enter your user ID : ";
            cin >> iD;
            cout << "Enter your password : ";
            cin >> password;
        }
    }
    
    void manMenu(){
        
        int option;
        
        cout << "\n_________________________________\n"
        << "| Trader Joe's Manager Menu     |\n"
        << "|      1. Set schedule          |\n"
        << "|      2. View/Update schedule  |\n"
        << "|      3. Return to Main Menu   |\n"
        << "|      4. Quit                  |\n"
        << "---------------------------------\n\n";
        
        cin >> option;
        
        switch(option)
        {
            case 1:
                system("clear");
                setSchedule();
                break;
            case 2:
                system("clear");
                veiwSch();
                break;
            case 3:
                system("clear");
                welcomeMenu();
                break;
            case 4:
                cout << "Exiting program!\n";
                exit(0);
                break;
        }
        
    }
    
    void emLogin(){
        const int userID = 94501;
        const int userPW = 70122;
        int password =0;
        int iD =0;
        
        
        cout << "Enter your user ID : ";
        cin >> iD;
        cout << "Enter your password : ";
        cin >> password;
        
        if(password == userPW && iD == userID)
        {
            system("clear");
            emViewSch();
        }
        else
        {
            cout << "Your Username or Password are incorrect please try again\n";
            system("clear");
            cout << "Enter your user ID : ";
            cin >> iD;
            cout << "Enter your password : ";
            cin >> password;
        }
    }
    
    void emViewSch()
    {
        int choice;
            cout << "   Employee Menu\n"
            << "----------------------\n"
            << "1. View schedule\n"
            << "2. Return to Main Menu\n"
            << "3. Quit Program\n";
            
            cin >> choice;
            
            switch(choice)
            {
                case 1:
                    system("clear");
                    empSho();
                    break;
                case 2:
                    system("clear");
                    welcomeMenu();
                    break;
                case 3:
                    cout << "Exiting program!\n";
                    exit(0);
                    break;
            }
    }
    
    void empSho()
    {
        string donn[8];
        int option;
        
        system("clear");
        cout << "Schedule\n"
        << "--------\n";
        ifstream donnFile;
        donnFile.open("employee.csv");
        if(donnFile.is_open())
        {
            for(int i = 0; i <= 7; i++)
            {
                donnFile >> donn[i];
                cout << "\nHour " << i+1 << ": " << donn[i];
            }
            cout << "\n\n";
        }
        donnFile.close();
        
        cout << "\n1.Go back to main menu"
             << "\n2.Quit program\n";
        cin >> option;
        
        if(option == 1)
            welcomeMenu();
        else
        {
            cout << "Exiting program!\n";
            exit(0);
        }
        
    }
    
    void setSchedule()
    {
        int choice;
        string option;
        
            cout << "Choose the employee's schedule you would like to set\n"
            << "----------------------------------------------------\n"
            << "              1. Donnovan Jiles\n"
            << "              2. Brianna Lawrence\n"
            << "              3. Micheal Scott\n"
            << "              4. Return to Manager menu\n"
            << "              5. Quit program\n";
            cin >> choice;
            switch(choice)
            {
                case 1:
                {
                    system("clear");
                    set();
                    break;
                }
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    system("clear");
                    welcomeMenu();
                    break;
                case 5:
                    cout << "Exiting program!\n";
                    exit(0);
                default:
                    break;
            }

    }
    
    void set(){
        string option;
        int opt;
        system("clear");
        ofstream donnFile;
        donnFile.open("employee.csv");
        cout << "Donnovan Jiles";
        for(int i = 0; i <= 7; i++)
        {
            cout << "\nHour " << i+1 << " : ";
            //getline(cin, option);
            cin >> option;
            donnFile << option << endl;
        }
        
        cout << "\n1.Go back to main menu"
        << "\n2.Quit program\n";
        cin >> opt;
        
        if(opt == 1)
            manMenu();
        else
        {
            cout << "Exiting program!\n";
            exit(0);
        }
        
        donnFile.close();

    }
    
    void veiwSch(){
        int choice;
        char update;
        string donn[8];
        
        cout << "Choose the employee's schedule you would like to view\n"
        << "----------------------------------------------------\n"
        << "              1. Donnovan Jiles\n"
        << "              2. Brianna Lawrence\n"
        << "              3. Micheal Scott\n"
        << "              4. Return to Manager menu\n"
        << "              5. Quit program\n";
        
        cin >> choice;
        
        switch(choice)
        {
            case 1:
            {
                ifstream donnFile;
                donnFile.open("employee.csv");
                if(donnFile.is_open())
                {
                    for(int i = 0; i <= 7; i++)
                    {
                        donnFile >> donn[i];
                        cout << "\nHour " << i+1 << ": " << donn[i];
                    }
                    cout << "\n\nWould you like to update?(Y/N)\n";
                    cin >> update;
                    
                    if(update == 'y' || update == 'Y'){
                        system("clear");
                        updateSch(donn, 1);
                    }
                }
                donnFile.close();
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                system("clear");
                manMenu();
                break;
            }
            case 5:
            {
                cout << "Exiting program!\n";
                exit(0);
                break;
            }
        }
        
    }
    
    void updateSch(string arr[], int option) {
        
        int choice;
        string duty;
        
        do
        {
            cout << "Which hour would you like to update?\n";
            for(int i = 0; i <= 7; i++)
            {
                cout << "\nHour " << i+1 << ": " << arr[i];
            }
            
            cout << "\nGo back to previous menu [press 0]\n";
            cin >> choice;
            
            if(choice != 0 && choice <= 8)
            {
                cout << "Hour " << choice << " : ";
                cin >> arr[choice - 1];
            } else
            {
                system("clear");
                veiwSch();
                
            }
            
            if(option == 1)
            {
                ofstream donnFile;
                donnFile.open("employee.csv");
                
                for(int i = 0; i <= 7; i++)
                {
                    donnFile << arr[i] << endl;
                }
                donnFile.close();
            }
        } while(choice != 0);
    }
};
