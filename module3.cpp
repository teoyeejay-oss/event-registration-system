#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Registration struct
struct Add_registration
{
    string regID;
    string participantID;
    string tournamentID;
    string status;
};

Add_registration registrations[100];
int registrationCount = 0;

// Function declarations
void registrationMenu();
void create_registration();
void cancel_registration();
void modify_registration();
void search_registration();
void display_registration_summary();

void registrationMenu()
{
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
        cin >> choice;

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

void create_registration()
{
    string regID, participantID, tournamentID;

    cout << "\n--------Create Registration---------" << endl;

    // Enter and validate Registration ID
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

    // Enter Participant ID (no cross-check with Module 1 for now)
    cout << "Enter the Participant ID: ";
    cin >> participantID;

    // Enter Tournament ID (no cross-check with Module 2 for now)
    cout << "Enter the Tournament ID: ";
    cin >> tournamentID;

    // Store the registration
    registrations[registrationCount].regID = regID;
    registrations[registrationCount].participantID = participantID;
    registrations[registrationCount].tournamentID = tournamentID;
    registrations[registrationCount].status = "Active";

    registrationCount++;

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

        cout << "Enter the new Participant ID: ";
        cin >> registrations[index].participantID;

        cout << "Enter the new Tournament ID: ";
        cin >> registrations[index].tournamentID;

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
