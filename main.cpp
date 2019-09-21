#include "sing.hpp"
#include <iostream>
#include <unistd.h>
using std::cout;
using std::endl;

int main() {
  cout << "start main" << endl;
  Singleton::Get();
  sleep(1);
  Singleton::Get();
  cout << "end main" << endl;
}
