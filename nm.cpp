#include <iostream>
float f(float x){return x*x*x-x-1;}
float df(float x){return 3*x*x-1;}

float nm(float x){
	float n=x-f(x)/(df(x));
	return (.00001>n-x&&n-x>-.00001)?n:nm(n);
}
int main(){
	float x;
	std::cin>>x;
	std::cout<<nm(x)<<std::endl;
	return 0;
}
