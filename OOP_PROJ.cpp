#include "Ticket.cpp"
#include <fstream>


using namespace std;
string Location::Name = "Unknown";


int main( )
{
	fstream fileLoc, fileEv, fileTick;
	Location* locVect = nullptr;
	Event* evVect = nullptr;
	Ticket* tickVect = nullptr;

	int opt1, opt2, opt3, locsz = 0, evsz = 0, ticksz = 0;

	do {
		cout << "Welcome to the Ticketing App! What type of user are you?" << endl;
		cout << "For admin, press 1. For client, press 2." << endl;
		cout << "If at any point you want to quit you can do so by typing 0 in any choice statement request." << endl;
		cin >> opt1;
		if (opt1 == 0)
		{
			fileLoc.open("Locations.txt", ios::out, ofstream::trunc);
			fileLoc << locsz;
			locsz--;
			while (locsz)
			{
				fileLoc << locVect[locsz].getName() << endl;
				fileLoc << locVect[locsz].getZone() << endl;
				fileLoc << locVect[locsz].getRow() << endl;
				fileLoc << locVect[locsz].getSeat() << endl;
				locsz--;
			}
			fileLoc.close();
			fileEv.open("Locations.txt", ios::out, ofstream::trunc);
			fileEv << evsz;
			evsz--;
			while (evsz)
			{
				fileEv << evVect[evsz].getEvName() << endl;
				fileEv << evVect[evsz].getLocationID() << endl;
				fileEv << evVect[evsz].getYear() << endl;
				fileEv << evVect[evsz].getMonth() << endl;
				fileEv << evVect[evsz].getDay();
				fileEv << evVect[evsz].getHour() << endl;
				fileEv << evVect[evsz].getMinute() << endl;
				evsz--;
			}
			fileEv.close();
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
					fileLoc.open("Locations.txt", ios::out, ofstream::trunc);
					fileLoc << locsz;
					locsz--;
					while (locsz)
					{
						fileLoc << locVect[locsz].getName() << endl;
						fileLoc << locVect[locsz].getZone() << endl;
						fileLoc << locVect[locsz].getRow() << endl;
						fileLoc << locVect[locsz].getSeat() << endl;
						locsz--;
					}
					fileLoc.close();
					fileEv.open("Locations.txt", ios::out, ofstream::trunc);
					fileEv << evsz;
					evsz--;
					while (evsz)
					{
						fileEv << evVect[evsz].getEvName() << endl;
						fileEv << evVect[evsz].getLocationID() << endl;
						fileEv << evVect[evsz].getYear() << endl;
						fileEv << evVect[evsz].getMonth() << endl;
						fileEv << evVect[evsz].getDay();
						fileEv << evVect[evsz].getHour() << endl;
						fileEv << evVect[evsz].getMinute() << endl;
						evsz--;
					}
					fileEv.close();
					return 0;
				}
				case 1:
				{
					cout << "Order of input: name, zone, rows, seats." << endl;
					Location loc;
					cin >> loc;
					Location* locVect2 = new Location[locsz + 1];
					for (int i = 0; i < locsz; i++)
						locVect2[i] = Location(locVect[i]);
					locsz++;
					locVect = new Location[locsz];
					for (int i = 0; i < locsz; i++)
						locVect[i] = Location(locVect2[i]);
					delete[] locVect2;
					cout << "Location addition done." << endl;
					break;
				}
				case 2:
				{
					fileLoc.open("Locations.txt", ios::in);
					fileLoc >> locsz;
					int sz = locsz;
					locVect = new Location[locsz];
					while (sz > 1)
					{
						string name;
						char zone[10];
						int seat;
						int regnrrow;
						fileLoc >> name;
						locVect[locsz - sz].setName(name);
						fileLoc >> zone;
						locVect[locsz - sz].setZone(zone);
						delete[] zone;
						fileLoc >> regnrrow;
						locVect[locsz - sz].setRegNrRow(regnrrow);
						fileLoc >> seat;
						locVect[locsz - sz].setSeat(seat);
						sz--;
					}
					fileLoc.close();
					cout << "Location load done." << endl;
					break;
				}
				case 3:
				{
					Event ev;
					cin >> ev;
					Event* evVect2 = new Event[evsz + 1];
					for (int i = 0; i < evsz; i++)
						evVect2[i] = Event(evVect[i]);
					evsz++;
					delete[] evVect;
					evVect = new Event[evsz];
					for (int i = 0; i < evsz; i++)
						evVect[i] = Event(evVect2[i]);
					delete[] evVect2;
					cout << "Event addition done." << endl;
					break;
				}
				case 4:
				{
					fileEv.open("Events.txt", ios::in);
					fileEv >> evsz;
					int sz = evsz;
					evVect = new Event[evsz];
					while (sz > 1)
					{
						string EvName;
						int hour;
						int minute;
						int day;
						int month;
						int year;
						string locationID;
						fileLoc >> EvName;
						fileLoc >> locationID;
						fileLoc >> year;
						fileLoc >> month;
						fileLoc >> day;
						fileLoc >> hour;
						fileLoc >> minute;

						evVect[evsz - sz].setEvName(EvName);
						evVect[evsz - sz].setLocationID(locationID);
						evVect[evsz - sz].setYear(year);
						evVect[evsz - sz].setMonth(month);
						evVect[evsz - sz].setDay(day);
						evVect[evsz - sz].setHour(hour);
						evVect[evsz - sz].setMinute(minute);
						sz--;
					}
					fileEv.close();
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
					fileLoc.open("Locations.txt", ios::out, ofstream::trunc);
					fileLoc << locsz;
					locsz--;
					while (locsz)
					{
						fileLoc << locVect[locsz].getName() << endl;
						fileLoc << locVect[locsz].getZone() << endl;
						fileLoc << locVect[locsz].getRow() << endl;
						fileLoc << locVect[locsz].getSeat() << endl;
						locsz--;
					}
					fileLoc.close();
					fileEv.open("Locations.txt", ios::out, ofstream::trunc);
					fileEv << evsz;
					evsz--;
					while (evsz)
					{
						fileEv << evVect[evsz].getEvName() << endl;
						fileEv << evVect[evsz].getLocationID() << endl;
						fileEv << evVect[evsz].getYear() << endl;
						fileEv << evVect[evsz].getMonth() << endl;
						fileEv << evVect[evsz].getDay();
						fileEv << evVect[evsz].getHour() << endl;
						fileEv << evVect[evsz].getMinute() << endl;
						evsz--;
					}
					fileEv.close();
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

