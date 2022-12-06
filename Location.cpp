#include <string>
#include <iostream>
using namespace std;
class Location {
private:
	int seat;
	int regnrrow;
	char* zone;
	static string Name;
public:
	Location() {
		seat = 0;
		regnrrow = 0;
		zone = new char[1];
		strcpy_s(zone, 1, "");
	}

	Location(int seat, int regnrrow, char* zone) {
		this->seat = seat;
		this->regnrrow = regnrrow;
		this->zone = new char[strlen(zone) + 1];
		strcpy_s(this->zone, strlen(zone) + 1, zone);
	}

	Location(const Location& l)
	{
		this->Name = l.Name;
		this->seat = l.seat;
		this->regnrrow = l.regnrrow;
		if (l.zone != nullptr)
		{
			this->zone = new char[strlen(l.zone) + 1];
			strcpy_s(this->zone, strlen(l.zone) + 1, l.zone);
		}
		else {
			this->zone = nullptr;
		}
	}

	Location operator =(Location l)
	{
		if (this != &l)
		{
			this->Name = l.Name;
			this->seat = l.seat;
			this->regnrrow = l.regnrrow;
			if (l.zone != nullptr)
			{
				this->zone = new char[strlen(l.zone) + 1];
				strcpy_s(this->zone, strlen(l.zone) + 1, zone);
			}
			else {
				this->zone = nullptr;
			}
		}
		return *this;
	}

	bool comparezone(char* a, string b)
	{
		if (strlen(a) != b.length())
			return false;
		else
			for (int i = 0; i < strlen(a); i++)
				if (toupper(a[i]) != b[i])
					return false;
		return true;
	}

	int* seatcodeGen(int seat, int row, char* zone)
	{
		if (seat <= this->seat && row <= this->regnrrow)
		{

			int zonecode = 3;

			if (comparezone(zone, "VIP") == true)

				zonecode = 0;

			if (comparezone(zone, "LAWN") == true)

				zonecode = 1;

			if (comparezone(zone, "TRIBUNE") == true)

				zonecode = 2;

			int* code = new int[3];
			code[0] = zonecode;
			code[1] = row;
			code[2] = seat;
			return code;
		}
		else
			throw "Either seat or row values are invalid. Try again!";
	}

	int getSeat()
	{
		return this->seat;
	}

	int getRow()
	{
		return this->regnrrow;
	}

	char* getZone()
	{
		return this->zone;
	}

	static string getName()
	{
		return Name;
	}

	void setSeat(int seat)
	{
		this->seat = seat;
	}

	void setRegNrRow(int regnrrow)
	{
		this->regnrrow = regnrrow;
	}

	void setZone(char* zone)
	{
		if (strlen(zone) < 3)
		{
			throw "Zone is not valid. Try again!";
		}
		else
		{
			this->zone = new char[strlen(zone) + 1];
			strcpy_s(this->zone, strlen(zone) + 1, zone);
		}
	}

	static void setName(string Name)
	{
		Location::Name = Name;
	}

	friend ostream& operator<<(ostream& out, Location a)
	{
		out << "Location details" << endl;
		out << "Name: " << a.Name << endl;
		if (a.zone != nullptr)
		{
			out << "Zones: Regular and " << a.zone << endl;
		}
		else out << "This location has no special zones." << endl;
		out << "Regular zone rows: " << a.regnrrow << endl;
		out << "Seats per row: " << a.seat;
		return out;
	}

	friend istream& operator>>(istream& in, Location& a)
	{
		cout << "Name: ";
		in >> a.Name;
		cout << "Zone: ";
		string buffer;
		in >> buffer;
		int n = buffer.length();
		char* v = new char[n + 1];
		strcpy_s(v, n + 1, buffer.c_str());
		a.setZone(v);
		delete[] v;
		cout << "Number of regular zone rows: ";
		in >> a.regnrrow;
		cout << "Number of seats per row: ";
		in >> a.seat;
		return in;
	}

	Location operator++()
	{
		this->seat++;
		return *this;
	}
	bool operator!()
	{
		bool ok = this->seat > 30 ? true : false;
		return ok;
	}

	~Location() {
		if (this->zone != nullptr)
			delete[] this->zone;
	}
	friend class Ticket;
};

