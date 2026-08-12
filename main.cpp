#include<iostream>
#include<iomanip>
#include <string>
using namespace std;

void participantManagement();
void tournamentManagement();

int main() {

    int choice;

    cout << setfill('=') << setw(10) << endl;
    cout << "ESPORTS EVENT REGISTRATION SYSTEM" << endl;
    cout << setfill('=') << setw(10) << endl;
    cout << "1. Participant Management" << endl;
    cout << "2. Tournament Management" << endl;
    cout << "3. Registration Management" << endl;
    cout << "4. Reports" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;

	if (choice == 1) 
	{
		participantManagement();	
    }
    else if (choice == 2) {
        tournamentManagement();
    }
    else if (choice == 3) {
        registrationManagement();
    }
    else if (choice == 4) {
        reports();
    }
    else if (choice == 5) {
        cout << "Exiting the program." << endl;
        return 0;
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }
    return 0;
}

void participantManagement()
{
    string id, gmail, game_or_team;
    int age, choice = 0;

    cout << "\n----------------------" << endl;
    cout << "   Participant menu  " << endl;
    cout << "------------------------" << endl;
    cout << "1. Add participant" << endl;
    cout << "2. Update participant" << endl;
    cout << "3. Search participant" << endl;
    cout << "4. Display all participant" << endl;
    cout << "5. Back" << endl;
    cout << "Enter choice ： ";
    cin >> choice;

    while (choice != 5)
    {
        if (choice == 1)
        {
            cout << "Add participant" << endl;
        }
        else if (choice == 2)
        {
            cout << "Update participant" << endl;
        }
        else if (choice == 3)
        {
            cout << "Search participant" << endl;
        }
        else if (choice == 4)
        {
            cout << "Display all participant" << endl;
        }
        else if (choice == 5)
        {
            cout << "Back" << endl;
        }
        else
        {
            cout << "Invalid choice " << endl;
        }
        cout << "Enter choice";
        cin >> choice;
    }
}

    void tournamentManagement() {
        string tournament_name, game_name, date;
        int choice = 0;

        cout << "\n----------------------" << endl;
        cout << "   Tournament menu  " << endl;
        cout << "------------------------" << endl;
        cout << "1. Add tournament" << endl;
        cout << "2. Update tournament" << endl;
        cout << "3. Search tournament" << endl;
        cout << "4. Display all tournament" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        while (choice != 5) {
            if (choice == 1) {
                add();   
            }
            else if (choice == 2) {
                update();
            }
            else if (choice == 3) {
                search();
            }
            else if (choice == 4) {
                cout << "Display all tournament successful!" << endl;
            }
            else {
                cout << "Invalid choice" << endl;
            }

            cout << "Enter choice: ";
            cin >> choice;
        }
        cout << "Back" << endl;
    }

    void add() {
        string tournament_name, game_name, date;
        cout << "Please enter the tournament name: ";
        cin >> tournament_name;
        cout << "Please enter the game name: ";
        cin >> game_name;
        cout << "Please enter the date: ";
        cin >> date;
        cout << "Add tournament successful!" << endl;
    }

    void update() {
        string tournament_name, game_name, date;
        cout << "Please enter the tournament name to update: ";
        cin >> tournament_name;
        cout << "Please enter the new game name: ";
        cin >> game_name;
        cout << "Please enter the new date: ";
        cin >> date;
        cout << "Update tournament successful!" << endl;
    }

    void search() {
        string tournament_name;
        cout << "Please enter the tournament name to search: ";
        cin >> tournament_name;
        cout << "Search tournament successful!" << endl;
    }