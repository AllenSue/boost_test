#include "BoostTester.hpp"

int main(int argc, char *argv[])
{
  BoostTester tester;

  tester.start();

  while (1) {
    sleep(10);
  }
  
  return 0;
}
