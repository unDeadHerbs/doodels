#include <deque>
#include <iostream>
#include <string>

template<class T>
std::deque<T>& operator<<(std::deque<T>& stream,T obj){
	stream.push_back(obj);
	return stream;
}

template<class T,class U>
U& operator<<(U& o, std::deque<T> &stream){
	while(stream.size()){
		o<<stream.front();
		stream.pop_front();
	}
	return o;
}

template<class T,class U>
U& operator +=(U& o,std::deque<T> stream){
	for(T v:stream){
		o<<v;
	}
	return o;
}

int main(){
	/*
	//works
	std::deque<int>b1,b2,b3;
	b1<<1;
	std::cout<<b1;
	std::cout<<std::endl;
	b2<<2;
	//std::cout<<b2<<std::endl;//this seg faults
	//(std::cout<<b2)<<std::endl;//this also seg faults
	b3+=b2;
	b3<<b2;
	std::cout<<b3;
	*/

	std::string s1;
	s1=std::string("123");
	s1+=std::string("456");
	std::cout<<s1<<std::endl;
	std::deque<std::string> strng;
	strng<<std::string("test1");
	std::cout<<strng<<std::endl;
	strng<<std::string("t2");
	strng<<std::string("t3");
	strng[strng.size()-1]+=std::string("t4");
	std::cout<<strng<<std::endl;

	std::cout<<std::endl;
}
