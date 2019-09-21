#ifndef __SING_HPP__
#define __SING_HPP__

template <typename T>
class SingletonDestroyer
{
 public:
  SingletonDestroyer(T* s = 0):_singleton(s){}
  ~SingletonDestroyer(){if(_singleton) delete _singleton;}
  void SetSingleton(T *s){_singleton=s;}
 private:
   T *_singleton;
};

class sing{
protected:
  sing(sing const&){}
  sing operator=(sing const&){return *this;}
  sing(){}
  ~sing(){}
  static sing* m_pInstance;
public:
  static sing* Get(){
    if(!m_pInstance)
      m_pInstance = new sing;
    return m_pInstance;
  }
};

#endif

