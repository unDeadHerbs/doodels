#include <iostream>
#include <iomanip>

void bubble(int *a,int l){
	int t;
	int e=0;
	for(int i=0;i!=l-1;i++){
		if(a[i]>a[i+1]){
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
			e=1;
		}
	}
	if(e)bubble(a,l);
}

int main (){
	const int l=10;
	int a[l];
	for(int i=0;i<l;i++)
		a[i]=l-i;
	for(int i=0;i<l;i++)
		std::cout<<std::setw(3)<<a[i];
	std::cout<<std::endl;
	bubble(a,l);
	for(int i=0;i<l;i++)
		std::cout<<std::setw(3)<<a[i];
	std::cout<<std::endl;
}
