#include <string>
#include <iostream>
using namespace std;
class Event {
private:
	string EvName;
	int hour;
	int minute;
	int day;
	int month;
	int year;
	string locationID;
public:
	Event()
	{
		EvName = "Unknown";
	}
	Event(string name, int hour, int minute, int day, int month, int year, string locationID)
	{
		this->EvName = name;
		this->hour = hour;
		this->minute = minute;
		this->day = day;
		this->month = month;
		this->year = year;
		this->locationID = locationID;
	}
	Event(const Event& ev)
	{
		this->EvName = ev.EvName;
		this->hour = ev.hour;
		this->minute = ev.minute;
		this->day = ev.day;
		this->month = ev.month;
		this->year = ev.year;
		this->locationID = ev.locationID;

	}
	Event operator =(Event ev)
	{
		if (this != &ev)
		{
			this->EvName = ev.EvName;
			this->hour = ev.hour;
			this->minute = ev.minute;
			this->day = ev.day;
			this->month = ev.month;
			this->year = ev.year;
			this->locationID = ev.locationID;

		}
		return *this;
	}
	int getHour()
	{
		return this->hour;
	}

	int getMinute()
	{
		return this->minute;
	}
	int getDay()
	{
		return this->day;
	}
	int getMonth()
	{
		return this->month;
	}
	int getYear()
	{
		return this->year;
	}

	string getLocationID()
	{
		return this->locationID;
	}

	string getEvName()
	{
		return this->EvName;
	}

	void setEvName(string name)
	{
		if (name.length() < 5)
		{
			throw "Event name is not valid. Try again!";
		}
		else this->EvName = name;
	}
	void setHour(int hour)
	{
		if (hour <= 24 && hour >= 0)
			this->hour = hour;
		else
			throw "Hour value is invalid. Try again!";
	}

	void setMinute(int minute)
	{
		if (minute <= 60 && minute >= 0)
		{
			this->minute = minute;
		}
		else
			throw "Minute value is invalid. Try again";
	}
	void setDay(int day)
	{
		if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12)
		{
			if (day <= 31)
				this->day = day;
			else
				throw "Day value is invalid. Try again!";
		}
		else
			if (this->month == 2)
			{
				if (this->year % 4 == 0)
				{
					if(day <= 29)
						this->day = day;
					else
						throw "Day value is invalid. Try again!";
				}
				else
				{
					
					if(day <= 28)
						this->day = day;
					else
						throw "Day value is invalid. Try again!";
				
				}
			
			}
			else
			{
				if (day <= 30)
					this->day = day;
				else
					throw "Day value is invalid. Try again!";
			}
	}
	void setMonth(int month)
	{
		if (month >= 1 && month <= 12)
			this->month = month;
		else
			throw "Month value is invalid. Try again!";
	}
	void setYear(int year)
	{
		if(year >= 2022)
			this->year = year;
		else
			throw "Year value is invalid. Try again!";

	}

	void setLocationID(string locationID)
	{
		this->locationID = locationID;
	}

	friend ostream& operator<<(ostream& out, Event a)
	{
		out << "Event details" << endl;
		out << "Name: " << a.EvName << endl;
		out << "Year: " << a.year << endl;
		out << "Month: " << a.month << endl;
		out << "Day: " << a.day << endl;
		out << "Hour: " << a.hour << endl;
		out << "Minute: " << a.minute << endl;
		out << "Location ID: " << a.locationID << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Event& a)
	{
		cout << "Event name: ";
		in >> a.EvName;
		cout << "Location ID: ";
		in >> a.locationID;
		cout << "Year: ";
		in >> a.year;
		cout << "Month: ";
		in >> a.month;
		cout << "Day: ";
		in >> a.day;
		cout << "Hour: ";
		in >> a.hour;
		cout << "Minute: ";
		in >> a.minute;
		return in;
	}

	bool operator<(Event ev) {
		return this->month < ev.month;
	}

	Event operator+(int i)
	{
		Event copie = *this;
		copie.minute = copie.minute + i;
		return copie;
	}
	string event()
	{
		string ev;
		ev += "This event takes place on ";
		ev += to_string(this->day);
		ev += ".";
		ev += to_string(this->month);
		ev += ".";
		ev += to_string(this->year);
		ev += " at ";
		ev += to_string(this->hour);
		ev += ":";
		ev += to_string(this->minute);
		ev += ".";
		return ev;
	}

	string eventLoc()
	{
		string ev;
		ev += this->EvName;
		ev += " takes place at ";
		ev += this->EvName;
		ev += ".";
	}

	~Event()
	{

	}
	friend class Ticket;

};
