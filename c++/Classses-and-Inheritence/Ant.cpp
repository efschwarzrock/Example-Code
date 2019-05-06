/*
 * Ant.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Erich Schwarzrock
 */

#include "Ant.h"



/**
 * Defauls constructor, shouldn't use
 */
Ant::Ant()
//:Organism(true)
{

}

/**
 * Constructor
 * @param r the row the ant is on
 * @param c the column the ant is on
 * @param g the world the ant is located on
 */
Ant::Ant(int r, int c, Grid* g)
:Organism(true, r, c, g, ant)
{
	//sets itself on the board and initalizes arguments
	g->setCellOccupant(r, c, ant, this);
}

/**
 * Tryes to move the ant to a random adjacent, not diaganal, unocupied space and increments the breedcounter, does not call breed
 * @return true if it sucessfuly runs false if it hit an error, it should not return false
 */
bool Ant::move()
{
	breedCounter++;
	//gets the number of open spaces
	int numOpenSpaces = this->numAdjacentOccupationStatus(empty);
	if(numOpenSpaces == 0){
		//can't move
		return true;
	}
	//gets where it will move
	int m = myRand(0, numOpenSpaces);
	int x = 0;
	//goes around and moves to the mth open space it findes
	if(row>0 && world->getCellOccupant(row-1, col) == empty){
		if(m == x){
			this->moveTo(row-1, col);
			return true;
		}
		x++;
	}
	if(row<gridSize-1 && world->getCellOccupant(row+1, col) == empty){
		if(m == x){
			this->moveTo(row+1, col);
			return true;
		}
		x++;
	}
	if(col>0 && world->getCellOccupant(row, col-1) == empty){
		if(m == x){
			this->moveTo(row, col-1);
			return true;
		}
		x++;
	}
	if(col<gridSize-1 && world->getCellOccupant(row, col+1) == empty){
		if(m == x){
			this->moveTo(row, col+1);
			return true;
		}
		x++;
	}

	return false;
}

/**
 * Tryes to breed.  This happens if it hasn't bread in at least 3 turns and it has an open spot to place the new ant.
 * This creats a new ant in a random adjacent, not diaganal, cell
 * @return the pointer to the new ant or nullptr if it didn't
 */
Ant* Ant::breed()
{
	//checks if it bread recently
	if(breedCounter>2){
		//checks the number of open spaces
		int numOpenSpaces = this->numAdjacentOccupationStatus(empty);
		if(numOpenSpaces == 0){
			//can't breed
			return nullptr;
		}
		//gets where it will breed
		int m = myRand(0, numOpenSpaces);
		int x = 0;
		//goes around and breeds in the mth open space it findes then sets the breedcounter to 0
		if(row>0 && world->getCellOccupant(row-1, col) == empty){
			if(m == x){
				breedCounter = 0;
				return new Ant(row-1, col, world);
			}
			x++;
		}
		if(row<gridSize-1 && world->getCellOccupant(row+1, col) == empty){
			if(m == x){
				breedCounter = 0;
				return new Ant(row+1, col, world);
			}
			x++;
		}
		if(col>0 && world->getCellOccupant(row, col-1) == empty){
			if(m == x){
				breedCounter = 0;
				return new Ant(row, col-1, world);
			}
			x++;
		}
		if(col<gridSize-1 && world->getCellOccupant(row, col+1) == empty){
			if(m == x){
				breedCounter = 0;
				return new Ant(row, col+1, world);
			}
			x++;
		}
	}
	return nullptr;
}

/**
 * The destructor for the ant
 */
Ant::~Ant() {
	// TODO Auto-generated destructor stub

}

