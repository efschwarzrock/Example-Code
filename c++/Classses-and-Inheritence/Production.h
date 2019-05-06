/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Grid.h"

class Production {
private:
	int size;
	int initdbs;
	int initants;
	int timestepsLeft;
	int seed;
	bool pause;
	bool goodArgs;
	Grid* myGrid;
	void initalizeGrid(int n, int dbs, int ants, int s);
	int myRand(int min, int max);
	int count(occupationStatus o);
public:
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();

};

#endif /* PRODUCTION_H_ */
