#include <string>
#include <iostream>
#include "Event.cpp"
#include "Location.cpp"
#include <cstdlib>
using namespace std;
class Ticket {
private:
	int* ticketID;
	string personName;
	Event ev;
	Location loc;
public:
	Ticket()
	{
		ticketID = new int[1];
		ticketID[0] = 0;
		personName = "Unknown";
	}
	Ticket(string person, Location loc, Event ev)
	{
		this->personName = person;
		this->ev = Event(ev);
		this->loc = Location(loc);
	}
	Ticket(const Ticket& tic)
	{
		this->personName = tic.personName;
		this->loc = tic.loc;
		this->ev = tic.ev;
	}

	Ticket operator =(Ticket tic)
	{
		if (this != &tic)
		{
			this->personName = tic.personName;
			this->loc = tic.loc;
			this->ev = tic.ev;
		}
		return *this;
	}
	string getPName()
	{
		return this->personName;
	}

	int* getTicketID()
	{
		return this->ticketID;
	}

	void setPName(string name)
	{
		if (name.length() < 7)
		{
			throw "The name is not valid. Try again!";
		}
		else this->personName = name;
	}



	friend ostream& operator<<(ostream& out, Ticket a)
	{
		out << "Ticket details" << endl;
		out << "Person name: " << a.personName << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Ticket& a)
	{
		cout << "Ticket details" << endl;
		cout << "Person name: ";
		string buffer;
		in >> buffer;
		a.setPName(buffer);
		return in;
	}
	int createRand()
	{
		srand((unsigned)time(NULL));
		int rnd = 1000 + (rand() % 9999);
		return rnd;
	}

	int* createID()
	{
		int* code;
		code = loc.seatcodeGen(loc.seat, loc.regnrrow, loc.zone);
		int* final;
		final[0] = createRand();
		final[1] = ev.minute;
		final[2] = ev.hour;
		final[3] = ev.day;
		final[4] = ev.month;
		final[5] = ev.year;
		final[6] = code[0];
		final[7] = code[1];
		final[8] = code[2];
		delete[]code;
		return final;
	}

	explicit operator bool() {
		if (ev.locationID == loc.Name)
			return true;
		else
			return false;
	}
	void operator+=(string s)
	{
		this->personName += s;
	}

	~Ticket()
	{
		this->loc.~Location();
		this->ev.~Event();
	}
};
