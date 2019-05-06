/*
 * Organism.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#include "Organism.h"
#include <stdlib.h>



/**
 * Whether or not the organism can be eaten by another organism
 */
bool isFood = false;

/**
 * The counter for how many timestpes it has been since the organism has bread
 */
int breedCounter;

/**
 * The current row of the organism on world
 */
int row = -1;

/**
 * The current column of the organism on world
 */
int col = -1;

/**
 * A pointer to the grid in which the organism is located
 */
Grid* world = nullptr;

/**
 * The side length of world
 */
int gridSize = 0;

/**
 * What type of organism the organism is
 */
occupationStatus me  = empty;

/**
 * default constructor, should never be called
 */
Organism::Organism() {
	// TODO Auto-generated constructor stub

}

/**
 * The constructor
 * @param isfood a boolean of wheather the organism can be eaten
 * @param r the row the organism starts on
 * @param c the column the organism starts on
 * @param g the grid in which the organism is located on
 * @param o the type of organism it is
 */
Organism::Organism(bool isfood, int r, int c, Grid* g, occupationStatus o) {
	isFood = isfood;
	row = r;
	col = c;
	world = g;
	gridSize = world->getSize();
	breedCounter = 0;
	me = o;

}

/**
 * Checks how many cells adjacent, not diaganl, to the organism have the ocupationStatus pased in
 * @param o the ocupationStatus to check for
 * @return the number of cells that are adjacent, not diaganl, to the organism that have the same ocupationStatus as o
 */
int Organism::numAdjacentOccupationStatus(occupationStatus o){
	//checks north, south, east, and west and adds one if it has the same ocupationStatus that was passed in
	int numAjacent = 0;
	if(row>0 && world->getCellOccupant(row-1, col) == o){
		numAjacent++;
	}
	if(row<gridSize-1 && world->getCellOccupant(row+1, col) == o){
		numAjacent++;
	}
	if(col>0 && world->getCellOccupant(row, col-1) == o){
		numAjacent++;
	}
	if(col<gridSize-1 && world->getCellOccupant(row, col+1) == o){
		numAjacent++;
	}
	return numAjacent;
}

/**
 * Moves the organism to the given coardinet on world and changes row and col acordinly, in doing so it deleats any organism that is curently in that cell.
 * @param r the row to move the organism to
 * @param c the column to move the organism to
 */
void Organism::moveTo(int r, int c){
	//deleats the organism in the cell that will be moved to, so there isn't a memory leak, then move this organsim and updates row and col
	world->removeCellOccupant(row, col);
	world->setCellOccupant(r, c, me, this);
	row = r;
	col = c;
}

/**
 * Returns wheather or not the organism can be eaten
 * @return true if it is prey false otherwise
 */
bool Organism::isPrey()
{
	return isFood;
}

/**
 * Sets wheather or not the organism can be eaten
 * @param isPrey wheather or not it is an ant
 */
void Organism::setAmAnt(bool isPrey)
{
	isFood = isPrey;
}

/**  Returns a random number between min and max.  Inclusive of min
 * exclusive of max. i.e. min<= return < max.  If min = max it returns
 * max.
 * @param min the minimum value that can be returned
 * @param max 1 + the maximum value that can be returned
 * @return a random number greater than or equal to min but less than max
 * unless min = max then it returns max
 */
int Organism::myRand(int min, int max){
	if(min == max){
		return max;
	}
	return ((rand()%(max - min)) + min);
}

/**
 * Remmoves the pointers to the organism that world has and sets it's cell to empty and deletes it
 */
void Organism::die(){
	//deletes the object
	world->setCellOccupant(row, col, empty, nullptr);
}

/**
 * The destructor for the organism
 */
Organism::~Organism() {
	world->removeCellOccupant(row, col);
}

