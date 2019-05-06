/*
 * Grid.cpp
 *
 *  Created on: Feb 9, 2019
 *      Author: Erich Schwarzrock
 */
#include <iomanip>
#include <queue>
#include "Grid.h"
#include "Cell.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"

/**
 * The side length of the grid
 */
int n = 0; //this initial value will be changed when the program is invoked

/**
 * The 2 dimentional array of cells in the grid
 */
Cell** myGridCells_ptr_array = (Cell**)nullptr;

/**
 * the total number of ants that were born through the breed function in the life cycle of this grid
 */
int totNumAnts = 0;

/**
 * the total number of doodlebugs that were born through the breed function in the life cycle of this grid
 */
int totNumDb = 0;

/**
 * Default constructor
 */
Grid::Grid() {
	// TODO Auto-generated constructor stub
	Grid(10); //calls general constructor with default value
	n = 10;
	totNumAnts = 0;
	totNumDb = 0;
}

/**
 * Constructor
 * @param nSquaresOnASide the side length of the grid
 */
Grid::Grid(int nSquaresOnASide)
{
	n = nSquaresOnASide; //initialize size of grid
	//we do not want automatic storage for the grid
	myGridCells_ptr_array = new Cell* [n];  //first allocate array of row pointers

	for(int i=0 ; i < n ; i++)
	{
		myGridCells_ptr_array[i] = new Cell[n]; // allocate memory for columns in each row
	}
	totNumAnts = 0;
	totNumDb = 0;
}

/**
 * Sets the specified cells ocupant to the given organism and deleats anything that was previously in that cell
 * @param r the row of the cell
 * @param c the column of the cell
 * @param g the ocupationStatus to be assigned to that cell
 * @param o the pointer to the orginism to put in the cell
 */
void Grid::setCellOccupant(int r, int c, occupationStatus g, Organism* o)
{
	myGridCells_ptr_array[r][c].setOccupant(g, o);
}

/**
 * Removes the organism from the specifyed cell without deleting it
 * @param r the row of the cell
 * @param c the column of the cell
 */
void Grid::removeCellOccupant(int r, int c)
{
	myGridCells_ptr_array[r][c].removeOccupant();
}

/**
 * Returns the occupationStatus of the specifyed cell
 * @param r the row of the cell
 * @param c the column of the cell
 * @return the occupationStatus of the specifyed cell
 */
occupationStatus Grid::getCellOccupant(int r, int c)
{
	return myGridCells_ptr_array[r][c].getOccupant();
}

/**
 * Prints the grid out to the counsel, with Xs representing ants and Os representing doodlebugs
 */
void Grid::printGrid(){
	for(int r=0; r < n; r++){
		for(int c=0; c < n; c++){
			if(this->getCellOccupant(r, c) == ant){
				printf("x");
			}else if(this->getCellOccupant(r, c) == doodlebug){
				printf("o");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
}

/**
 * Runs one timestep of the grid.  It first moves, checks if they starved, then breeds all the doodlebugs individualy.
 * i.e. moves, checks if they starved, then breeds one doodlebug then moves to the next one. Then it does the same to
 * the ants minus checking if they starved. It also keeps track of how many ants and doodle bugs were born and adds
 * that to that the totNumAnts and totNumDbs.  It also returns true if something is still alive.
 * @return true if at least one organism is alive, false otherwise
 */
bool Grid::timeStep(void){
	bool isDead = true;
	//get the doodle bugs into a queue
	std::queue<Doodlebug*> doodlebugs;
	for(int dbX = 0; dbX < n; dbX++){
		for(int dbY = 0; dbY < n; dbY++){
			if(this->getCellOccupant(dbX, dbY) == doodlebug){
				doodlebugs.push((Doodlebug*)(myGridCells_ptr_array[dbX][dbY].getOrganism()));
			}
		}
	}
	//traverse the queue
	while(doodlebugs.size() !=0){
		Doodlebug* d = doodlebugs.front();
		d->move();
		if(!d->starved()){
			isDead = false;
			if(d->breed() != nullptr){
				totNumDb ++;
			}
		}
		doodlebugs.pop();
	}
	//get the ants into a queue
	std::queue<Ant*> ants;
	for(int antX = 0; antX < n; antX++){
		for(int antY = 0; antY < n; antY++){
			if(this->getCellOccupant(antX, antY) == ant){
				ants.push((Ant*)(myGridCells_ptr_array[antX][antY].getOrganism()));
			}
		}
	}
	//go through the queue
	while(ants.size() !=0){
		Ant* a = ants.front();
		a->move();
		isDead = false;
		if(a->breed() != nullptr){
			totNumAnts ++;
		}
		ants.pop();
	}
	return isDead;
}

/**
 * Returns the number of ants born
 * @return the number of ants born
 */
int Grid::getNumAntsBorn(){
	return totNumAnts;
}

/**
 * Returns the number of doodlebugs born
 * @return the number of doodlebugs born
 */
int Grid::getNumDbsBorn(){
	return totNumDb;
}

/**
 * Returns the side length of the grid
 * @return the side length of the grid
 */
int Grid::getSize(){
	return n;
}

/**
 * The destructor for the grid. Destroys the cells befor it destroys itself.
 */
Grid::~Grid() {
	for(int r=0; r < n; r++)
	{
		for(int c=0; c < n; c++)
		{
			myGridCells_ptr_array[r][c].~Cell(); // free memory for columns in each row
		}
	}
}

