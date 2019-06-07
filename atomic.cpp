#include <atomic>
#include <deque>
#include <iostream>

int main(){
	std::atomic<std::deque<int> > q;
	std::cout<<std::endl;
}
