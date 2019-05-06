/*
 * Doodlebug.cpp
 *
 *  Created on: Feb 10, 2019
 *      Author: Erich Schwarzrock
 */

#include "Doodlebug.h"


/**
 * Counts how many timesteps it has been since the doodlebug ate
 */
int starveCounter;

/**
 * Defauls constructor, shouldn't use
 */
Doodlebug::Doodlebug() {
	// TODO Auto-generated constructor stub

}

/**
 * Constructor
 * @param r the row the ant is on
 * @param c the column the ant is on
 * @param g the world the ant is located on
 */
Doodlebug::Doodlebug(int r, int c, Grid* g)
:Organism(true, r, c, g, doodlebug)
{
	g->setCellOccupant(r, c, doodlebug, this);
	starveCounter = 0;
}

/**
 * Tryes to eat a random adjacent, not diaganal, ant by moving onto there cell.  It also sets starvecounter to 0
 * If it can't do that it returns false.
 * @param numAnts the number of ajacent ants
 * @return true if it sucessfuly eats an ant and false otherwise
 */
bool Doodlebug::eat(int numAnts){
	//gets who it will eat
	int m = myRand(0, numAnts);
	int x = 0;
	//goes around and eats to the mth ant it findes then sets the starvecounter to 0
	if(row>0 && world->getCellOccupant(row-1, col) == ant){
		if(m == x){
			starveCounter = 0;
			this->moveTo(row-1, col);
			return true;
		}
		x++;
	}
	if(row<gridSize-1 && world->getCellOccupant(row+1, col) == ant){
		if(m == x){
			starveCounter = 0;
			this->moveTo(row+1, col);
			return true;
		}
		x++;
	}
	if(col>0 && world->getCellOccupant(row, col-1) == ant){
		if(m == x){
			starveCounter = 0;
			this->moveTo(row, col-1);
			return true;
		}
		x++;
	}
	if(col<gridSize-1 && world->getCellOccupant(row, col+1) == ant){
		if(m == x){
			starveCounter = 0;
			this->moveTo(row, col+1);
			return true;
		}
		x++;
	}

	return false;
}

/**
 * Tryes to move the doodlebug to a random adjacent, not diaganal, cell that contains an ant.  If it can't do that it tryes to
 * move to a random adjacent, not diaganal, unocupied space.  Eather way the function increments the breedcounter and starve
 * counter, does not call breed or starve
 * @return true if it sucessfuly runs false if it hit an error, it should not return false
 */
bool Doodlebug::move()
{
	//increments the counters
	breedCounter++;
	starveCounter++;
	//checks if there is an ant
	int numAnts = this->numAdjacentOccupationStatus(ant);
	if(numAnts > 0){
		//there are ants so eat them
		return this->eat(numAnts);
	}
	//get the number of open spaces
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
 * Tryes to breed.  This happens if it hasn't bread in at least 8 turns and it has an open spot to place the new ant.
 * This creats a new doodlebug in a random adjacent, not diaganal, cell
 * @return the pointer to the new doodlebug or nullptr if it didn't
 */
Doodlebug* Doodlebug::breed()
{
	//checks if it bread recently
	if(breedCounter>7){
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
				return new Doodlebug(row-1, col, world);
			}
			x++;
		}
		if(row<gridSize-1 && world->getCellOccupant(row+1, col) == empty){
			if(m == x){
				breedCounter = 0;
				return new Doodlebug(row+1, col, world);
			}
			x++;
		}
		if(col>0 && world->getCellOccupant(row, col-1) == empty){
			if(m == x){
				breedCounter = 0;
				return new Doodlebug(row, col-1, world);
			}
			x++;
		}
		if(col<gridSize-1 && world->getCellOccupant(row, col+1) == empty){
			if(m == x){
				breedCounter = 0;
				return new Doodlebug(row, col+1, world);
			}
			x++;
		}
	}
	return nullptr;
}

/**
 * Checks if the doodlebug starved and if it did it kills it and deletes the object
 */
bool Doodlebug::starved(){
	if(starveCounter>2){
		//deletes the object
		this->die();
		return true;
	}
	return false;
}

/**
 * The destructor for the doodlebug
 */
Doodlebug::~Doodlebug() {
	// TODO Auto-generated destructor stub
}

