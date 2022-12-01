#include <string>
using namespace std;
class ZoneEX : public exception
{
private:
    char* message;
public:
    ZoneEX(char* msg) : message(msg) {}
    char* what() {
        return message;
    }
};
class EvEX : public exception
{
private:
    char* message;
public:
    EvEX(char* msg) : message(msg) {}
    char* what() {
        return message;
    }
};
class NameEX : public exception
{
private:
    char* message;
public:
    NameEX(char* msg) : message(msg) {}
    char* what() {
        return message;
    }
};

