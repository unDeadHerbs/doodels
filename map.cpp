#include <map>
#include <iostream>

int main(){
	std::map<int,int> m1;
	m1[2]=3;
	for(auto& v:m1){
		v.second++;
	}
	for(auto& v:m1){
		std::cout<<v.second;
		std::cout<<std::endl;
	}
	return 0;
}
