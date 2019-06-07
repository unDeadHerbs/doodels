#include <iostream>
#include <deque>

int main(int argc, char *argv[]){
	std::deque<int> list = {1,2,3,4,5};

	for(int& value : list)
		std::cout << value << " ";
	std::cout << std::endl;

	return 0;
}
