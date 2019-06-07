#include <iostream>

int main(){
	if(((1<<2)>>2%1)%1)
		std::cout<<">> is before %"<<std::endl;
	else
		std::cout<<"% is before >>"<<std::endl;
	return 0;
}
