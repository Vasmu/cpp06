#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"


Base *generate(void) {
  
  int random_value = std::rand() % 3;
  
  // std::cout << "value : " << random_value << std::endl;
  if (random_value == 0)
  {
    A *a = new A();
    std::cout << "A has been instanciated with succes" << std::endl;
    return (a);
  }
  else if (random_value == 1)
  {
    B *a = new B();
    std::cout << "B has been instanciated with succes" << std::endl;
    return (a);
  }
  else
  {
    C *a = new C();
    std::cout << "C has been instanciated with succes" << std::endl;
    return (a);
  }
}

void identify(Base* p) {
  A *a = dynamic_cast<A*>(p);
  B *b = dynamic_cast<B*>(p);
  C *c = dynamic_cast<C*>(p);

  if (a != NULL)
    std::cout << "type A detected by identify *" << std::endl;
  else if (b != NULL)
    std::cout << "type B detected by identify *" << std::endl;
  else if (c != NULL)
    std::cout << "type C detected by identify *" << std::endl;
  else
    std::cout << "Very weird case" << std::endl;
}

void identify(Base& p) {
  A a;
  B b;
  C c;

  try 
  {
    a = dynamic_cast<A&>(p);
    std::cout << "type A detected by identify &" << std::endl;
  }
  catch (...)
  {
  }
  try 
  {
    b = dynamic_cast<B&>(p);
    std::cout << "type B detected by identify &" << std::endl;

  }
  catch (...)
  {
  }
  try 
  {
    c = dynamic_cast<C&>(p);
    std::cout << "type C detected by identify &" << std::endl;
  }
  catch (...)
  {
  }
}

int main(void)
{
  std::srand(std::time(0));
  Base *base = generate();
  identify(base);
  identify(*base);

  delete base;
  


}