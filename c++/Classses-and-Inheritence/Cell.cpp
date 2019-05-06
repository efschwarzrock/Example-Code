/*
 * Cell.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Erich Schwarzrock
 */

#include "Cell.h"

/**
 * The type of Organism that is in that cell
 */
occupationStatus guest  = empty;

/**
 * The pointer to that Organism
 */
Organism* org = nullptr;

/**
 * Constructor
 */
Cell::Cell() {
	org = nullptr;
	guest = empty;
}

/**
 * Sets the occupant of the cell and deleats anything that was previously in this cell
 * @param g the occupationStatus of the cell, i.e. what type of organism that is in the cell or if its empty
 * @param o the pointer to the organism that is in the cell
 */
void Cell::setOccupant(occupationStatus g, Organism* o)
{
	if(guest != empty){
		delete org;
	}
	guest = g;
	org = o;

}

/**
 * Removes the organism from the cell without deleting it
 */
void Cell::removeOccupant(){
	guest = empty;
	org = nullptr;
}

/**
 * Getter method for the occupationStatus of the cell
 * @return the occupationStatus of the cell
 */
occupationStatus Cell::getOccupant()
{
	return guest;
}

/**
 * Getter method for the org of the cell
 * @return the org of the cell
 */
Organism* Cell::getOrganism()
{
	return org;
}

/**
 * the destructor for the cell.  Destroys the organism inside the cell first, if there is one
 */
Cell::~Cell() {
	if(guest != empty){
		delete org;
	}
}

