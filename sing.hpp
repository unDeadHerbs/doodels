#ifndef __SING_HPP__
#define __SING_HPP__

#include <stdio.h>
#include <memory>
using std::shared_ptr;

template <typename T>
class SingletonManager{
 private:
  static shared_ptr<T> _singleton;
 public:
  SingletonManager(){_singleton=T::Get();}
  //~SingletonManager(){if(_singleton) delete _singleton;}
  //void SetSingleton(T *s){_singleton=s;}
};

class sing{
protected:
  sing(sing const&)=delete;
  sing operator=(sing const&)=delete;
  sing(){printf("sing constructor\n");}
  static shared_ptr<sing> m_pInstance;
public:
  ~sing(){printf("sing destructor\n");}
  static shared_ptr<sing> Get(){
    if(!m_pInstance)
      m_pInstance = shared_ptr<sing>(new sing);
    return m_pInstance;
  }
};

//static SingletonManager<sing> SingMan;
static auto SingMan=sing::Get();

#endif

