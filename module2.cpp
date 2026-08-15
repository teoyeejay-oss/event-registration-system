#include <iostream>
#include <string>
#include "tournament.h"
using namespace std;
void add();
void update();
void search();

void tournamentMenu()
{
    int choice;

    do
    {
        cout << "\n----------------------" << endl;
        cout << "   Tournament Menu" << endl;
        cout << "----------------------" << endl;
        cout << "1. Add Tournament" << endl;
        cout << "2. Update Tournament" << endl;
        cout << "3. Search Tournament" << endl;
        cout << "4. Display All Tournament" << endl;
        cout << "5. Back" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1)
        {
            add();
        }
        else if (choice == 2)
        {
            update();
        }
        else if (choice == 3)
        {
            search();
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
        {
            cout << "Back to Main Menu" << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 5);
}

void add(){
    string tournamentID;
	int tournamentCount = 0;

    cout << "Please enter tournament ID: ";
    cin.ignore();
    getline(cin, tournamentID);

    // Check if the tournament ID is empty
    if (tournamentID.empty()) {
        cout << "Tournament ID cannot be empty!" << endl;
    }

    // Check if the tournament ID already exists
    for (int i = 0; i < tournamentCount; i++)
    {
        if (tournamentID == tournamentIDs[i])
        {
            cout << "Tournament ID already exists!" << endl;
        }
        else {
            tournamentIDs[tournamentCount] = tournamentID;
            cout << "Tournament ID accepted" << endl;
        }
    }
    cout << "Tournament ID: " << tournamentID << endl;

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