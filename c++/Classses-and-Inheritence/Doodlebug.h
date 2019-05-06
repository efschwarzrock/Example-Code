/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
public:
	int starveCounter;
	Doodlebug();
	Doodlebug(int r = 0, int c = 0, Grid* g = nullptr);
	bool move();
	Doodlebug* breed();
	bool eat(int numAnts);
	bool starved();
	virtual ~Doodlebug();
};

#endif /* DOODLEBUG_H_ */
