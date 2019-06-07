#include <algorithm>

//#define for(var,x) for(int var=0;var<x;var++)

template<class T>
T map(auto f,T l){
	T r;
	std::transform(l.begin(),l.end(),r.begin(),f);
	return r;
};

template<typename T>
//what is the template type of std::deque::begin()?
T between(auto f,std::iterator<T> s,std::iterator<T> e){
	if(std::distance(s,e)>1)//check that
		return *s;
	return f(*s,joint(f,s.next(),e));
}
template<typename T,template<typename>class C>
T between(auto f,C<T> l){
	if(l.size()==1)
		return l[0];
	return between(f,l.begin(),l.end());
}

#include<iostream>

auto modFactory(int m,std::string s){
	return [=](int n){
		if(n%m==0){
			std::cout<<s;
			return true;
		}else
			return false;
	};
}

template<typename T>
T orMap(auto fs,int n){
	auto r=map([n](auto f){return f(n);},fs);
	return between([](auto l,auto r){return l||r;},r);
}

#define MAX 20

int main(int argc, char *argv[]){
	auto fizz=modFactory(3,"Fizz"),
		   buzz=modFactory(5,"Buzz");
	for(auto n=1;n<=MAX;n++){
		if(!fizz(n)&&!buzz(n))
			std::cout<<n;
		std::cout<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
