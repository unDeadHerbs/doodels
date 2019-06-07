#include "config.hpp"

template <class T>
config::config(std::string fileName){
}

template <class T>
bool config::operator==(const T rhs) const{
	return v==rhs;
}

template <class T>
config& config::operator[](const std::string index){
	return s[index];
}

int main(int argc,char*argv[]){
	
}
