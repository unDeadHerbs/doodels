#ifndef __SING_HPP__
#define __SING_HPP__

#include <stdio.h>
#include <memory>
using std::unique_ptr;

#include <stdlib.h>

class Singleton{
protected:
  Singleton(Singleton const&)=delete;
  Singleton operator=(Singleton const&)=delete;
  Singleton(){printf("Singleton constructor\n");}
public:
  ~Singleton(){printf("Singleton destructor\n");}
  static Singleton* Get(){
    static unique_ptr<Singleton> m_pInstance;
    if(!m_pInstance)
      m_pInstance = unique_ptr<Singleton>(new Singleton);
    return m_pInstance.get();
  }
};

//static SingletonManager<Singleton> SingletonMan;


#endif

