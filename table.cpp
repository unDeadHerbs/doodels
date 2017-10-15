#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
#include <cstdlib>
#include <string>
using std::string;
#include <map>
using std::map;

int main(int argc,char* argv[]){
  if(argc!=2){
    cerr<<"Usage "<<argv[0]<<" Number."<<endl;
    exit(1);
  }
  auto count=atoi(argv[1]);

  auto fizzbuzz=map<int,string>({{3, "Fizz"},
                                 {5, "Buzz"}});

  for(int i=1;i<=count;i++){
    bool found=false;
    for(auto p : fizzbuzz){
      if(i%p.first)
	continue;
      found=true;
      cout<<p.second;
    }
    if(!found)
      cout<<i;
    cout<<endl;
  }
}
