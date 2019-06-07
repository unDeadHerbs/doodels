#include <string>
#include <map>

template <class T>
class config{
private:
	std::map<std::string,config> s;
	T v;
public:
	config();
	config(std::string fileName);
	void save(std::string fileName);
	bool operator=(const T& rhs);
	bool operator==(const T& rhs) const;
	bool operator==(const config& rhs)const;
	config&operator[](const int index);
};
