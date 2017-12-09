
#include <iostream>
#include "srt.h"

using namespace std;


int main()
{
	srt s;

	s.readData();
	s.Init();
	s.computeSRT();


	return 0;

}