#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>
#include <string>
using std::string;

#define cycle(x,s) [](int n){if(0==n%x)return string(s);return string("");}
#define combind(a,b) [a,b](int n){return a(n)+b(n);}

int main(int argc,char* argv[]){
  if(argc!=2){
    cerr<<"Usage "<<argv[0]<<" Number."<<endl;
    exit(1);
  }
  auto count=atoi(argv[1]);

  auto fizz=cycle(3,"Fizz");
  auto buzz=cycle(5,"Buzz");
  auto fb=combind(fizz,buzz);
  auto choose=[](string s,int n){if(s!="")return s;return std::to_string(n);};
  auto fizzbuzz=[choose,fb](int n){return choose(fb(n),n);};
  
  for(int i=1;i<=count;i++)
    cout<<fizzbuzz(i)<<endl;
}
