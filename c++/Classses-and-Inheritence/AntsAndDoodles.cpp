//============================================================================
// Name        : Ants.cpp
// Author      : Therese building on Ciaraldi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests2.h"
#include "Production.h"
class Tests;
class Production;


int main(int argc, char* argv[])
{//gridSize #doodlebugs #ants #time_steps seed pause
	std::cout << "!!!Hello the classmates, it's time for fun with C++!!!" << std::endl;
    Tests2 ts = Tests2();//see page 291
    if(ts.doTests())
	{
		Production ps = Production(argc, argv);
		bool ok = ps.runProduction();
		if(ok)
		{
			puts("Production worked.");
		}
		else
		{
			puts("Production did not work.");
		}
		ps.~Production(); //done with production
	}
    ts.~Tests2(); //done with tests


	return 0;
}
