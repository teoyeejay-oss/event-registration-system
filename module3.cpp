#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

// Registration struct
struct Add_registration
{
    string regID;
    string participantID;
    string tournamentID;
    string status;
};

const int MAX_REGISTRATIONS = 100;
Add_registration registrations[MAX_REGISTRATIONS];
int registrationCount = 0;
bool dataLoaded = false;

// Function declarations
void registrationMenu();
void create_registration();
void cancel_registration();
void modify_registration();
void search_registration();
void display_registration_summary();
void loadRegistrations();
void saveRegistrations();
int readMenuChoice();

void registrationMenu()
{
    if (!dataLoaded)
    {
        loadRegistrations();
        dataLoaded = true;
    }

    int choice = 0;

    do
    {
        cout << "\n----------------------" << endl;
        cout << "   Registration Menu" << endl;
        cout << "----------------------" << endl;
        cout << "1. Create Registration" << endl;
        cout << "2. Cancel Registration" << endl;
        cout << "3. Modify Registration" << endl;
        cout << "4. Search Registration" << endl;
        cout << "5. Display Registration Summary" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";

        choice = readMenuChoice();

        if (choice == 1)
        {
            create_registration();
        }
        else if (choice == 2)
        {
            cancel_registration();
        }
        else if (choice == 3)
        {
            modify_registration();
        }
        else if (choice == 4)
        {
            search_registration();
        }
        else if (choice == 5)
        {
            display_registration_summary();
        }
        else if (choice == 6)
        {
            cout << "Back" << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);
}


int readMenuChoice()
{
    int choice;

    while (!(cin >> choice))
    {
        cin.clear();                                         
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number: ";
    }

    return choice;
}


void loadRegistrations()
{
    ifstream inFile("registrations.txt");

    if (!inFile)
    {
        return; // no saved file yet, nothing to load
    }

    registrationCount = 0;

    while (registrationCount < MAX_REGISTRATIONS &&
           inFile >> registrations[registrationCount].regID >>
                     registrations[registrationCount].participantID >>
                     registrations[registrationCount].tournamentID >>
                     registrations[registrationCount].status)
    {
        registrationCount++;
    }

    inFile.close();
}

void saveRegistrations()
{
    ofstream outFile("registrations.txt");

    for (int i = 0; i < registrationCount; i++)
    {
        outFile << registrations[i].regID << " "
                << registrations[i].participantID << " "
                << registrations[i].tournamentID << " "
                << registrations[i].status << endl;
    }

    outFile.close();
}

void create_registration()
{
    if (registrationCount >= MAX_REGISTRATIONS)
    {
        cout << "\nCannot create registration: maximum of "
             << MAX_REGISTRATIONS << " registrations reached!" << endl;
        return;
    }

    string regID, participantID, tournamentID;

    cout << "\n--------Create Registration---------" << endl;

    while (true)
    {
        cout << "Enter the Registration ID: ";
        cin >> regID;

        if (regID.empty())
        {
            cout << "Registration ID cannot be empty!" << endl;
            continue;
        }

        bool duplicate = false;
        for (int i = 0; i < registrationCount; i++)
        {
            if (registrations[i].regID == regID)
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            cout << "Registration ID already exists! Please enter another ID." << endl;
            continue;
        }

        break;
    }

    // Enter Participant ID
    cout << "Enter the Participant ID: ";
    cin >> participantID;

    // Enter Tournament ID
    cout << "Enter the Tournament ID: ";
    cin >> tournamentID;

    for (int i = 0; i < registrationCount; i++)
    {
        if (registrations[i].participantID == participantID &&
            registrations[i].tournamentID == tournamentID &&
            registrations[i].status == "Active")
        {
            cout << "\nThis participant is already registered for this tournament!" << endl;
            return;
        }
    }

    // Store the registration
    registrations[registrationCount].regID = regID;
    registrations[registrationCount].participantID = participantID;
    registrations[registrationCount].tournamentID = tournamentID;
    registrations[registrationCount].status = "Active";

    registrationCount++;
    saveRegistrations();

    cout << "\nRegistration created successfully!" << endl;
}

void cancel_registration()
{
    string regID;

    cout << "\n--------Cancel Registration---------" << endl;
    cout << "Enter the Registration ID to cancel: ";
    cin >> regID;

    bool idExists = false;
    int index = -1;

    for (int i = 0; i < registrationCount; i++)
    {
        if (registrations[i].regID == regID)
        {
            idExists = true;
            index = i;
            break;
        }
    }

    if (idExists)
    {
        if (registrations[index].status == "Cancelled")
        {
            cout << "This registration is already cancelled." << endl;
        }
        else
        {
            registrations[index].status = "Cancelled";
            saveRegistrations();
            cout << "\nRegistration cancelled successfully!" << endl;
        }
    }
    else
    {
        cout << "Registration ID not found!" << endl;
    }
}

void modify_registration()
{
    string regID;

    cout << "\n--------Modify Registration---------" << endl;
    cout << "Enter the Registration ID to modify: ";
    cin >> regID;

    bool idExists = false;
    int index = -1;

    for (int i = 0; i < registrationCount; i++)
    {
        if (registrations[i].regID == regID)
        {
            idExists = true;
            index = i;
            break;
        }
    }

    if (idExists)
    {
        cout << "Registration found!" << endl;
        cout << "Only Participant ID and Tournament ID can be modified." << endl;

        string newParticipantID, newTournamentID;

        cout << "Enter the new Participant ID: ";
        cin >> newParticipantID;

        cout << "Enter the new Tournament ID: ";
        cin >> newTournamentID;

        for (int i = 0; i < registrationCount; i++)
        {
            if (i != index &&
                registrations[i].participantID == newParticipantID &&
                registrations[i].tournamentID == newTournamentID &&
                registrations[i].status == "Active")
            {
                cout << "\nThat participant is already registered for that tournament!" << endl;
                return;
            }
        }

        registrations[index].participantID = newParticipantID;
        registrations[index].tournamentID = newTournamentID;
        saveRegistrations();

        cout << "\nRegistration updated successfully!" << endl;
    }
    else
    {
        cout << "Registration ID not found!" << endl;
    }
}

void search_registration()
{
    string regID;

    cout << "\n--------Search Registration---------" << endl;
    cout << "Enter the Registration ID to search: ";
    cin >> regID;

    bool idExists = false;

    for (int i = 0; i < registrationCount; i++)
    {
        if (registrations[i].regID == regID)
        {
            idExists = true;
            cout << "\nRegistration Details" << endl;
            cout << "Registration ID : " << registrations[i].regID << endl;
            cout << "Participant ID  : " << registrations[i].participantID << endl;
            cout << "Tournament ID   : " << registrations[i].tournamentID << endl;
            cout << "Status          : " << registrations[i].status << endl;
            break;
        }
    }

    if (!idExists)
    {
        cout << "Registration ID not found!" << endl;
    }
}

void display_registration_summary()
{
    cout << "\n--------Registration Summary---------" << endl;

    if (registrationCount == 0)
    {
        cout << "No registrations available." << endl;
        return;
    }

    for (int i = 0; i < registrationCount; i++)
    {
        cout << "Registration ID : " << registrations[i].regID << endl;
        cout << "Participant ID  : " << registrations[i].participantID << endl;
        cout << "Tournament ID   : " << registrations[i].tournamentID << endl;
        cout << "Status          : " << registrations[i].status << endl;
        cout << "----------------------" << endl;
    }
}
