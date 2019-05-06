/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#include "Production.h"
#include "Grid.h"
#include "Doodlebug.h"
#include "Ant.h"
#include <time.h>
#include <iostream>

/**
 * The size of the grid to be simulated
 */
int size;

/**
 * The inital amount of doodlebugs
 */
int initdbs;

/**
 * The inital amount of ants
 */
int initants;

/**
 * The amount of timesteps left in the simulation
 */
int timestepsLeft;

/**
 * the random seed
 */
int seed;

/**
 * Whether to wait and print between timesteps
 */
bool pause;

/**
 * whether the arguments passed in are valid/usable
 */
bool goodArgs;

/**
 * the grid that the game will be simulated on
 */
Grid* myGrid;

/**
 * Constructor that retrieves the input parameters and checks to make sure they are valid
 * @param argc the number of arguments passed int
 * @param argv[] the arguments
 */
Production::Production(int argc, char* argv[]) {
	goodArgs = true;
	size = 20;
	initdbs = 5;
	initants = 100;
	timestepsLeft = 1000;
	seed = 1;
	pause = false;
	//check each parameter and makes sure they are valid
	if(argc>1){
		char* ptr1=0;
		long nr_l = strtol(argv[1],&ptr1,10);//get the NR
		size = (int)nr_l;
		if(size<1)
		{
			printf("Usage: size should be greater than 0, received %d.\n",size);
			goodArgs = false;
		}
	}
	if(argc>2){
		char* ptr2=0;
		long ib_l = strtol(argv[2],&ptr2,10);//get the NR
		initdbs = (int)ib_l;
		if(initdbs<0)
		{
			printf("Usage: #doodlebugs should be greater than or equal to 0, received %d.\n",initdbs);
			goodArgs = false;
		}
		if(initdbs>size*size)
		{
			printf("Usage: #doodlebugs should be less than or equal to the size of the board, received %d.\n",initdbs);
			goodArgs = false;
		}
	}
	if(argc>3){
		char* ptr3=0;
		long ia_l = strtol(argv[3],&ptr3,10);//get the NR
		initants = (int)ia_l;
		if(initants<0)
		{
			printf("Usage: #ants should be greater than or equal to 0, received %d.\n",initants);
			goodArgs = false;
		}
		if(initdbs + initants>size*size)
		{
			printf("Usage: #ants plus #doodlebugs should be less than or equal to the size of the board, received %d.\n",initants);
			goodArgs = false;
		}
	}
	if(argc>4){
		char* ptr4=0;
		long nts_l = strtol(argv[4],&ptr4,10);//get the NR
		timestepsLeft = (int)nts_l;
		if(timestepsLeft<1)
		{
			printf("Usage: #timesteps should be greater than 0, received %d.\n",timestepsLeft);
			goodArgs = false;
		}
	}
	if(argc>5){
		char* ptr5=0;
		long s_l = strtol(argv[5],&ptr5,10);//get the NR
		seed = (int)s_l;
	}
	if(argc>6){
		char* ptr6=0;
		long p_l = strtol(argv[6],&ptr6,10);//get the NR
		pause = (int)p_l>0;
	}
	myGrid = nullptr;
}

/**
 * Initalizes the grid bby randomly placing the doodlebugs and ants
 * @param n the size of the grid
 * @param dbs the number of doodlebugs to be placed
 * @param ants the number of ants to be placed
 * @param s the random seed
 */
void Production::initalizeGrid(int n, int dbs, int ants, int s){
	myGrid = new Grid(n);
	//set seed
	if(s == 0){
		srand(time(0));
	}else{
		srand(s);
	}
	//place doodlebugs
	int dbPlaced = 0;
	while(dbPlaced<dbs){
		int row = myRand(0,n);
		int col = myRand(0,n);
		if(myGrid->getCellOccupant(row, col) == empty){
			new Doodlebug(row, col, myGrid);
			dbPlaced ++;
		}
	}
	//place ants
	int antPlaced = 0;
	while(antPlaced<ants){
		int row = myRand(0,n);
		int col = myRand(0,n);
		if(myGrid->getCellOccupant(row, col) == empty){
			new Ant(row, col, myGrid);
			antPlaced ++;
		}
	}
}

/**  Returns a random number between min and max.  Inclusive of min
 * exclusive of max. i.e. min<= return < max.  If min = max it returns
 * max.
 * @param min the minimum value that can be returned
 * @param max 1 + the maximum value that can be returned
 * @return a random number greater than or equal to min but less than max
 * unless min = max then it returns max
 */
int Production::myRand(int min, int max){
	if(min == max){
		return max;
	}
	return ((rand()%(max - min)) + min);
}

/**
 * Counts the number of organisms in the grid of type o
 * @param o the occupationStatus to count up
 * @return the number of type o in the grid
 */
int Production::count(occupationStatus o){
	int n = size;
	int num = 0;
	for(int X = 0; X < n; X++){
		for(int Y = 0; Y < n; Y++){
			if(myGrid->getCellOccupant(X, Y) == o){
				num++;
			}
		}
	}
	return num;
}

/**
 * Simulates the game
 * @return true if there wasn't an error
 */
bool Production::runProduction()
{
	if(goodArgs){
		int timestepsLeftinit = timestepsLeft;
		this->initalizeGrid(size, initdbs, initants, seed);
		bool isAlive = initdbs !=0 || initants != 0;
		//run the timesteps
		while(isAlive && timestepsLeft-- > 0)
		{
			//should it print and stop
			if(pause){
				myGrid->printGrid();
				std::cout << "Press enter to continue!" << std::endl;
				getc(stdin);
			}
			//makes sure everything isn't dead
			isAlive = !myGrid->timeStep();
		}
		if(timestepsLeft == -1){
			timestepsLeft = 0;
		}
		//prints the data
		printf("\n/PA5 %d %d %d %d %d %d\n", size, initdbs, initants, timestepsLeftinit, seed, pause);
		printf("The number of steps simulated is %d\n", timestepsLeftinit-timestepsLeft);
		printf("The total number of ants was %d\n", initants + myGrid->getNumAntsBorn());
		printf("The number of ants remaining is %d\n", this->count(ant));
		printf("The total number of doodlebugs was %d\n", initdbs + myGrid->getNumDbsBorn());
		printf("The number of doodlebugs remaining is %d\n", this->count(doodlebug));
		myGrid->printGrid();

	}
	return true;
}

/**
 * the destructor for production.  It destroyes the grid first
 */
Production::~Production() {
	myGrid->~Grid();
}

