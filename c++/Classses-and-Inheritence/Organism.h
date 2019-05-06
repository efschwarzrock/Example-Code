/*
 * Organism.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_

#include "Grid.h"
class Grid;

class Organism {
private:
	bool isFood;
	occupationStatus me  = empty;
protected:
	int row;
	int col;
	Grid* world;
	int gridSize;
	int breedCounter;
public:
	Organism();
	void moveTo(int r, int c);
	Organism(bool b, int r, int c, Grid* g, occupationStatus o);
	bool isPrey();
	int myRand(int min, int max);
	int numAdjacentOccupationStatus(occupationStatus o);
	virtual bool move()=0;
	virtual Organism* breed()=0;
	void setAmAnt(bool b);
	void die();
	virtual ~Organism();
};

#endif /* ORGANISM_H_ */
