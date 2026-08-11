#include<iostream>
#include<iomanip>
using namespace std;

int main() {

    int choice;

    cout << setw(10) << setfill("=") << endl;
    cout << "ESPORTS EVENT REGISTRATION SYSTEM" << endl;
    cout << setw(10) << setfill("=") << endl;
    cout << "1. Participant Management" << endl;
    cout << "2. Tournament Management" << endl;
    cout << "3. Registration Management" << endl;
    cout << "4. Reports" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;

    if (choice == 1) {
        participantManagement();
#include <iostream>
#include <iomanip>
#include <string>
		using namespace std;

		int main()
		{
			string id, gmail, game_or_team;
			int age, choice = 0;

			cout << "\n----------------------" << endl;
			cout << "   Participant menu  " << endl;
			cout << "------------------------" << endl;
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
				else
				{
					cout << "Invalid choice " << endl;
				}
				cout << "Enter choice";
				cin >> choice;
			}
			return 0;
		}
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