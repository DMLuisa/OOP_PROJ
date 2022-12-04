#include "Event.cpp"
class Ticket {
private:
	int* ticketID;
	string personName;
public:
	Ticket()
	{
		ticketID = new int[1];
		ticketID[0] = 0;
		personName = "Unknown";
	}
	Ticket(string person)
	{
		this->personName = person;
	}
	Ticket(const Ticket& tic)
	{
		this->personName = tic.personName;
	}
	Ticket operator =(Ticket tic)
	{
		if (this != &tic)
		{
			this->personName = tic.personName;
		}
		return *this;
	}
	string getPName()
	{
		return this->personName;
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
};
