/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
public:
	Ant();
	Ant(int r=0, int c = 0, Grid* g = nullptr);
	bool move();
	Ant* breed();
	 ~Ant();
};

#endif /* ANT_H_ */
