#include <iostream>
int main(){
	int a=0,m;
	std::cin >> m;
	for(;m;)a+=m--;
	std::cout<<a<<std::endl;
	return 0;
}