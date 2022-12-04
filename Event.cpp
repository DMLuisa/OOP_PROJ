#include <string>
#include <iostream>
using namespace std;
class Event {
private:
	string EvName;
public:
	Event()
	{
		EvName = "Unknown";
	}
	Event(string name)
	{
		this->EvName = name;
	}
	Event(const Event& ev)
	{
		this->EvName = ev.EvName;
	}
	Event operator =(Event ev)
	{
		if (this != &ev)
		{
			this->EvName = ev.EvName;
		}
		return *this;
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

	friend ostream& operator<<(ostream& out, Event a)
	{
		out << "Event details" << endl;
		out << "Name: " << a.EvName << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Event& a)
	{
		cout << "Event name: ";
		string buffer;
		in >> buffer;
		a.setEvName(buffer);
		return in;
	}
	~Event()
	{

	}
};
