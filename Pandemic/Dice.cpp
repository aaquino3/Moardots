#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

Dice::Dice()
{
  srand((unsigned)time(0));
  random_num1 = (rand()%10)+1;
  random_num2 = (rand()%10)+1;
  cout<< "You rolled a "<<random_num1<<" and a "<<random_num2<<" ."<<endl;
}
