#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string id, gmail, game_or_team;
	int age,choice = 0;

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
		else if(choice == 4)
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