#include <string>
class ZoneEX : public std::exception
{
public:
	ZoneEX(std::string ending) : exception(ending.c_str()){}
};

