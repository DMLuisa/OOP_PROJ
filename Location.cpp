#include <string>
#include "Exceptions.cpp"
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
			strcpy_s(this->zone, strlen(l.zone) + 1, zone);
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

	int getSeat()
	{
		return seat;
	}

	int getRow()
	{
		return regnrrow;
	}

	char* getZone()
	{
		return zone;
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
			char p[30];
			strcpy_s(p, 30, "Zone is not valid. Try again!");
			throw ZoneEX(p);
		}
		else
		{
			this->zone = new char[strlen(zone) + 1];
			strcpy_s(this->zone, strlen(zone) + 1, zone);
		}
	}

	void setName(string Name)
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
		string buffer;
		in >> buffer;
		a.setName(buffer);
		cout << "Zone: ";
		string buffer2;
		in >> buffer2;
		int n = buffer2.length();
		char* v = new char[n + 1];
		strcpy_s(v, n + 1, buffer2.c_str());
		a.setZone(v);
		delete[] v;
		cout << "Number of regular zone rows: ";
		in >> a.regnrrow;
		cout << "Number of seats per row: ";
		in >> a.seat;
		return in;
	}


	~Location() {
		if (this->zone != nullptr)
			delete[] this->zone;
	}
	friend class Event;
};
string Location::Name = "Unknown";