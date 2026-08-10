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
        pm();
    }
    else if (choice == 2) {
        tm();
    }
    else if (choice == 3) {
        rm();
    }
    else if (choice == 4) {
        rp();
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