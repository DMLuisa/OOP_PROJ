#include <string>
#include "Exceptions.h"
class Location {
private:
	int seat;
	int regnrrow;
	char* zone;
	static string Name;
public:
	Location() {
		Name = "Necunoscut";
		seat = 0;
		regnrrow = 0;
		zone = new char[1];
		strcpy_s(zone, 1, "");
	}

	Location(string name, int seat, int regnrrow, char* zone) {
		this->Name = name;
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
		if (strlen(a) != b.size())
			return false;
		else
			for (int i = 0; i < strlen(a); i++)
				if (toupper(a[i]) != b[i])
					return false;
		return true;
	}

	int* seatcodeGen(int seat, int row, char* zone)
	{
		int zonecode;
		if (comparezone(zone, "VIP") == true)
			zonecode = 0;
		if (comparezone(zone, "LAWN") == true)
			zonecode = 1;
		if (comparezone(zone, "TRIBUNE") == true)
			zonecode = 2;
		if (comparezone(zone, "REGULAR") == true)
			zonecode = 3;

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
			throw ZoneEX("Zone is not valid. Try again!");
		else
		{
			this->zone = new char[strlen(zone) + 1];
			strcpy_s(this->zone, strlen(zone) + 1, zone);
		}
	}

	void setName(string name)
	{
		this->Name = name;
	}
	
	~Location() {
		if (this->zone != nullptr)
			delete[] this->zone;
	}
};










