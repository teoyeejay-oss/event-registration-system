#include<iostream>
#include<iomanip>
#include <string>
using namespace std;
struct Add_participant
{
    string id, gmail;
    int age;
};
Add_participant participants[100];
int participantCount = 0;

// Function declarations
void participantManagement();
void tournamentManagement();
void registrationManagement();
void reports();
void add_participant();         
void Update_participant(Add_participant participants[], int participantCount); 
void Search_participant(Add_participant participants[], int participantCount); 
void Display_all_participant(Add_participant participants[], int participantCount);
int main() {

    int choice = 0;

    while (choice != 5)
    {
        // Display the main menu
        cout << setfill('=') << setw(50) << endl;
        cout << "ESPORTS EVENT REGISTRATION SYSTEM" << endl;
        cout << setfill('=') << setw(50) << endl;
        cout << "1. Participant Management" << endl;
        cout << "2. Tournament Management" << endl;
        cout << "3. Registration Management" << endl;
        cout << "4. Reports" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        // Handle the user's choice

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
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    
        return 0;
}

// Function to manage participants
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
            add_participant();
        }
        else if (choice == 2)
        {
            Update_participant(participants, participantCount);
        }
        else if (choice == 3)
        {
            Search_participant(participants, participantCount);
        }
        else if (choice == 4)
        {
            Display_all_participant(participants, participantCount);
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

void add_participant()
{
    string id;


    cout << "\n--------Add Participant---------" << endl;
    cout << "Enter the Participants ID";
    cin >> id;

    bool idExists = false;
    for (int i = 0;i < participantCount;i++)
    {
        if (participants[i].id == id)
        {
            idExists = true;
            break;
        }
    }
    if (idExists)
    {
        cout << "Error : the participants ID already exists" << endl;
        cout << "Please enter another ID" << endl;
    }
    else
    {
        participants[participantCount].id = id;
        cout << "Enter the age";
        cin >> participants[participantCount].age;

        cout << "Enter the gmail";
        cin >> participants[participantCount].gmail;

        participantCount++;
        cout << "\nSuccessfully Added" << endl;
    }
}

void Update_participant(Add_participant participants[], int participantCount)
{
    string id;
    
    cout << "\n---------Update participant---------" << endl;
    cout << "Enter the participant id";
    cin >> id;

    bool idExists = false;
    int index = -1;
    for (int i = 0;i < participantCount;i++)
    {
        if (participants[i].id == id)
        {
            idExists = true;
            index = i;
            break;
        }
    }
    if (idExists)
    {
        cout << "Enter the new age";
        cin >> participants[index].age;

        cout << "Enter the  new gmail";
        cin >> participants[index].gmail;

        cout << "\nSuccessfully Updated" << endl;
    }
    else
    {
        cout << "Participant id not found" << endl;
        cout << "Please enter id again" << endl;
    }
}
void Search_participant(Add_participant participants[], int participantCount)
{
    string id;

    cout << "\n---------Search participant---------" << endl;
    cout << "Enter the participant id";
    cin >> id;
    bool idExists = false;
    for (int i = 0;i < participantCount;i++)
    {
        if (participants[i].id == id)
        {
            idExists = true;
            cout << "\nParticipants Details" << endl;
            cout << "ID : " << participants[i].id << endl;
            cout << "Age : " << participants[i].age << endl;
            cout << "Gmail : " << participants[i].gmail << endl;
            break;
        }
    }
    if (!idExists)
    {
       cout << "\nParticipant id not found" << endl;
    }
}
void Display_all_participant(Add_participant participants[], int participantCount)
{
    cout << "\n---------Display all participant---------" << endl;
    if (participantCount > 0)
    {
        for (int i = 0; i < participantCount;i++)
        {
            cout << "ID : " << participants[i].id << endl;
            cout << "Age : " << participants[i].age << endl;
            cout << "Gmail : " << participants[i].gmail << endl;
        }
    }
    else
    {
        cout << "No participants" << endl;
    }
    cout << "\nReturning to participant menu" << endl;
}