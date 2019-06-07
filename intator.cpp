#include<iostream>
#include<iterator>
#include<deque>

int main(int argc, char *argv[]){
	std::deque<int> l={1,2,3,4,5};
	std::cout<<"l.size()="<<l.size()<<std::endl;
	auto m=l.begin();
	std::cout<<"dist(1.b,l.e)="<<std::distance(m,l.end())<<std::endl;
	m++;
	std::cout<<"dist(1.b+1,l.e)="<<std::distance(m,l.end())<<std::endl;
	return 0;
}
