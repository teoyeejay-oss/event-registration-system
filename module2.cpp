#include <iostream>
#include <string>
#include "tournament.h"
using namespace std;
// Function prototypes
void add();
void update();
void search();

// Global variables
string tournamentIDs[100];
string gameNames[100];
int days[100];
int months[100];
int years[100];
int tournamentCount = 0;

void tournamentMenu()
{
    int choice;

	// Display the tournament menu and handle user input
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
	// Declare variables 
    string tournamentID;
    bool duplicate;
	cin.ignore(); // Clear the input buffer

	// Let the user to enter a tournament ID and check for duplicates
    while (true) {
        cout << "Please enter tournament ID (e.g., T001): ";
        getline(cin, tournamentID);

     // Check if the tournament ID is empty
        if (tournamentID.empty()) {
            cout << "Tournament ID cannot be empty!" << endl;
            continue;
        }

        duplicate = false;
     // Check if the tournament ID already exists
        for (int i = 0; i < tournamentCount; i++){
            if (tournamentID == tournamentIDs[i]){
                cout << "Tournament ID already exists!" << endl;
				duplicate = true;
				break;
            }
        }

	// If the tournament ID is a duplicate, let the user to enter a new one
        if (duplicate){
            continue;
        }

	// If the tournament ID is valid, store it in the array
        tournamentIDs[tournamentCount] = tournamentID;
        cout << "Tournament ID accepted" << endl;
        
        break;
    }

	// Declare variable to store the game name and game choice
	string game_name;
	int game_choice;

	// Let the user to select a game from the list
    while (true){
		cout << "Please select a game from the following list:" << endl;
		cout << "1. Valorant" << endl;
		cout << "2. Mobile Legends" << endl;
		cout << "3. PUBG" << endl;
		cout << "4. EA FC" << endl;
        cout << "Please enter your game choice (1-4): ";
        cin >> game_choice;

	// Validate the game choice input
        switch (game_choice)
        {
        case 1:
            game_name = "Valorant";
            break;

        case 2:
            game_name = "Mobile Legends";
            break;

        case 3:
            game_name = "PUBG";
            break;

        case 4:
            game_name = "EA FC";
            break;

        default:
            cout << "Invalid choice!" << endl;
            continue;
        }

        gameNames[tournamentCount] = game_name;
        cout << "Game name accepted!" << endl;

        break;
    }
   
	// Declare variables to store the tournament date
	int day, month, year;

	// Let the user to enter the tournament date and validate the input
    while (true) {
        cout << "Please enter the tournament date!";
        cout << "Enter the day (1-31): ";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Invalid day! Please enter a valid day (1-31)." << endl;
            continue;
        }
        break;
    }

    while (true) {
        cout << "Enter the month (1-12): ";
        cin >> month;
        if (month < 1 || month > 12) {
            cout << "Invalid month! Please enter a valid month (1-12)." << endl;
            continue;
        }
        break;
    }

    while(true){
        cout << "Enter the year (2026 or 2027): ";
        cin >> year;
        if (year != 2026 && year != 2027) {
            cout << "Invalid year! Please enter either 2026 or 2027." << endl;
            continue;
        }
        break;
    }

	// Store the tournament date in the arrays
        Days[tournamentCount] = day;
        Months[tournamentCount] = month;
        Years[tournamentCount] = year;

    // Increment the tournament count
        tournamentCount++;

	// Display success messages
        cout << "Tournament date accepted!" << endl;
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