#include "htest.hpp"
#include <iostream>

std::string hello(){
	return "Hello, World!";
}

int main(int argc, char *argv[]){
	std::cout<<hello()<<std::endl;
	return 0;
}
