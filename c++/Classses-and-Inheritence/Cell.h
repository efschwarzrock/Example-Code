/*
 * Cell.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef CELL_H_
#define CELL_H_

enum occupationStatus { empty, ant, doodlebug};

#include "Organism.h"
class Organism;

class Cell {
private:
	occupationStatus guest;
	Organism *org;
public:
	Cell();
	void setOccupant(occupationStatus g, Organism *o);
	void removeOccupant();
	occupationStatus getOccupant();
	Organism* getOrganism();
	virtual ~Cell();
};

#endif /* CELL_H_ */
