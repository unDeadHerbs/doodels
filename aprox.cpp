#include <iostream>
float f(float x){return x*x*x-5*x;}

int main(){
	float a=1,b=0;
	for(;f(a)*f(b++)>=0;){}
	for(;.00001<a-b||a-b<-.00001;
		f(a)*f((a+b)/2)>0?a=(a+b)/2:b=(a+b)/2)
		if(f((a+b)/2)==0)break;
	std::cout<<"final guess: "<<(a+b)/2<<std::endl;
	return 0;
}