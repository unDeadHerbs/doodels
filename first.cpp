#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>

int main(int argc,char* argv[]){
  if(argc!=2){
    cerr<<"Usage "<<argv[0]<<" Number."<<endl;
    exit(1);
  }
  auto count=atoi(argv[1]);
  for(int i=1;i<=count;i++){
    if(0==i%3)
      if(0==i%5)
	cout<<"FizzBuzz"<<endl;
      else
	cout<<"Fizz"<<endl;
    else
      if(0==i%5)
	cout<<"Buzz"<<endl;
      else
	cout<<i<<endl;
  }
}
