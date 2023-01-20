#include "Scale.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cstdlib>
int main( int ac, char **av)
{
  if (ac != 2)
  {
    std::cout << "Wrong number of arguments" << std::endl;
    return (1);
  }
  std::string value = av[1];
  Scale scale(value);
  std::cout << scale;
  // // char array[] = 
  // // Character end pointer
  // char* pend;
  // // f1 variable to store float value
  // long f1 = std::strtol(array.c_str(), &pend, 10);
  // // f2 variable to store float value
  // // Printing parsed float values of f1 and f2
  // std::cout << f1 << " with end value " << *pend <<  " of length " << ((std::string) pend).length() << std::endl;
  // std::cout << "element suivant du end " << *(pend + 1) <<std::endl;
  // float f2 = std::strtof(array.c_str(), &pend);
  // std::cout << f2 << " with end value " << *pend <<  " of length " << ((std::string) pend).length()  << std::endl;
  // std::cout << "element suivant du end " << *(pend + 1) <<std::endl;

  // long double f3 = std::strtold(array.c_str(), &pend);
  // std::cout << f3 << " with end value " << *pend <<  " of length " << ((std::string) pend).length()  << std::endl;
  // std::cout << "element suivant du end " << (*(pend + 1) == '\0' )<<std::endl;
  // std::cout << true;
  return 0;
}