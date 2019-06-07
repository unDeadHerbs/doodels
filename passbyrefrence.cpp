#include <iostream>
void f(int*);

int main(){
	int t=0;
	f(&t);
	std::cout<<t<<std::endl;
	return 0;
}

void f(int*t){
	(*t)++;
}
