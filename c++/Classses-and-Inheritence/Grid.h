/*
 * Grid.h
 *
 *  Created on: Feb 9, 2019
 *      Author: Erich Schwarzrock
 */

#ifndef GRID_H_
#define GRID_H_

#include "Cell.h"
#include "Organism.h"

class Organism;

class Grid {
private:
	int n;
	int totNumAnts;
	int totNumDb;
public:
	int getNumAntsBorn();
	int getNumDbsBorn();
	Grid();
	Grid(int nSquaresOnASide);
	void setCellOccupant(int r, int c, occupationStatus g, Organism* o);
	occupationStatus getCellOccupant(int r, int c);
	void removeCellOccupant(int r, int c);
	void printGrid();
	int getSize();
	bool timeStep(void);
	virtual ~Grid();
};

#endif /* GRID_H_ */
