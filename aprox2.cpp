#include <iostream>
#include <new>

int d;
float * c;

float f(float x){
	float v=0;
	for (int i=0;i<d;++i){
		int t=1;
		for(int j=i;j--;){
			t*=x;
		}
		v+=t* *(c+d-i);
	}
	return v;
}

float df(float x){
	float v=0;
	for (int i=0;i<d-1;++i){
		int t=1;
		for(int j=i-1;j--;){
			t*=x;
		}
		v+=t* *(c+d-i)*(d-i);
	}
	return v;
}

float nm(float x){
	float n=x-f(x)/(df(x));
	return (.00001>n-x&&n-x>-.00001)?n:nm(n);
}

void synthDiv(float r){
	
}

int main(){
	std::cout<<"What degree is the polynoimial: ";std::cin>>d;
	
	c=new (std::nothrow) float[d];
	if(c==0){
		std::cout << "Error: memory could not be allocated";
		return 1;
	}

	std::cout<<"What are the coefecents of the polynoimial (decending order, space seperated): ";
	for(int i=d;i--;)std::cin>>*(c+i);

	std::cout<<"Thinking..."<<std::endl;
	
	//remove zeros
	for(;*(c+d-1)==0;){
		std::cout<<"found zero at: 0"<<std::endl;
		d--;
	}

	nrm();
	return 0;
}