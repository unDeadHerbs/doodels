#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>
using std::atoi;
#include <string>
using std::string;
using std::to_string;

template <typename T>
auto generator(T prevous,string s,int mod){
  return [prevous,mod,s](int n,string term){
    if(0==n%mod)
      return prevous(n,"")+s;
    else
      return prevous(n,term);
  };
}

int main(int argc,char* argv[]){
  if(argc!=2){
    cerr<<"Usage "<<argv[0]<<" Number."<<endl;
    exit(1);
  }
  auto count=atoi(argv[1]);

  auto base=[](int,string s){return s;};
  auto fizz=generator(base,"Fizz",3);
  auto buzz=generator(fizz,"Buzz",5);
  auto fizzbuzz=[buzz](int n){return buzz(n,to_string(n));};

  for(int i=1;i<=count;i++)
    cout<<fizzbuzz(i)<<endl;
}
