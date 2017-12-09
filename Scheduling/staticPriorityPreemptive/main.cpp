
#include <iostream>
#include "staticPriority.h"

using namespace std;


int main()
{
	StaticPriority s;

	s.readData();
	s.Init();
	s.computeStaticPriority();


	return 0;

}