#include "Location.cpp"
#include "Event.cpp"
#include "Ticket.cpp"


using namespace std;
string Location::Name = "Unknown";


int main( )
{
	int opt1, opt2, opt3;
	do {
		cout << "Welcome to the Ticketing App! What type of user are you?" << endl;
		cout << "For admin, press 1. For client, press 2." << endl;
		cout << "If at any point you want to quit you can do so by typing 0 in any choice statement request." << endl;
		cin >> opt1;
		if (opt1 == 0)
		{
			return 0;
		}
		else if (opt1 == 1)
		{
			do {
				cout << "What do you want to do?" << endl;
				cout << "To add a location, press 1. To load the current list of locations, press 2." << endl;
				cout << "To add an event, press 3. To load the current list of events, press 4." << endl;
				cout << "To load current ticket list, press 5. To validate a ticket, press 6." << endl;
				cout << "To go back, press 7." << endl;
				cin >> opt2;
				switch (opt2)
				{
				case 0:
				{
					return 0;
				}
				case 1:
				{
					cout << "Location addition done." << endl;
					break;
				}
				case 2:
				{
					cout << "Location load done." << endl;
					break;
				}
				case 3:
				{
					cout << "Event addition done." << endl;
					break;
				}
				case 4:
				{
					cout << "Event load done." << endl;
					break;
				}
				case 5:
				{
					cout << "Ticket load done." << endl;
					break;
				}
				case 6:
				{
					cout << "Ticket validation done." << endl;
					break;
				}
				default:
					break;
				}
			} while (opt2 != 7);
		}
		else {
			do {
				cout << "What do you want to do?" << endl;
				cout << "To view current events, press 1. To get a ticket for an event, press 2." << endl;
				cout << "To go back, press 3." << endl;
				cin >> opt3;
				switch (opt3) {
				case 0:
				{
					return 0;
				}
				case 1:
				{
					cout << "Here is a list of current events:" << endl;
					break;
				}
				case 2:
				{
					cout << "Ticket bought" << endl;
					break;
				}
				default:
					break;
				}
			} while (opt3 != 3);
		}
	} while (opt1 != 0);
	

}

