#include <iostream>
#include <vector>

enum param_type{typeA,typeB};

template <param_type PT>
struct Container{
  int value;
  Container(int v):value(v){}
};

void f(Container<typeA> param){
  std::cout<<"Got typeA with value "<<param.value<<std::endl;
}
void f(Container<typeB> param){
  std::cout<<"Got typeB with value "<<param.value<<std::endl;
}

template <typename...T>
void f(T... params){
  // f(params);...
  // f(params)...;    // Fail to compile
  (f(params),...);
   //std::vector<int> v={f(params)...}; // Works
}


void g(){}
template <typename T,typename...R>
void g(T param,R...rest){
  f(param);
  g(rest...);
}

int main(){
  auto a=Container<typeA>(5);
  auto b=Container<typeB>(10);
  f(a,b);
  g(a,b);
  return 0;
}
