#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>
#include "proj4.h"

//semaphores for accessing global variables
sem_t bad;
sem_t dir;
sem_t reg;
sem_t regb;
sem_t txt;
sem_t txtb;
sem_t spl;


//initalizes the semophores
void initSem(void){
	if(sem_init(&bad, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&dir, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&reg, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&regb, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&txt, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&txtb, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
	if(sem_init(&spl, 0, 1) < 0){
		perror("sem_init");
		exit(1);
	}
}

//destroys the semaphores
void destroySems(void){
	(void)sem_destroy(&bad);
	(void)sem_destroy(&dir);
	(void)sem_destroy(&reg);
	(void)sem_destroy(&regb);
	(void)sem_destroy(&txt);
	(void)sem_destroy(&txtb);
	(void)sem_destroy(&spl);
}

//uses the stat struct to find out what type of file it is and edit the variables
// makeing sure to implement mutual exclution on global variables
void getStatsThreads(struct stat *filestats, char *filename){
	if(S_ISDIR(filestats->st_mode) != 0){
		//is a directory
		sem_wait(&dir);
		directories++;
		sem_post(&dir);
	}else if(S_ISREG(filestats->st_mode) != 0){
		//is a regular file and checks if it is a text file
		sem_wait(&reg);
		regfiles++;
		sem_post(&reg);
		sem_wait(&regb);
		regfilebytes = regfilebytes + filestats->st_size;
		sem_post(&regb);
		testForTextThreads(filestats, filename);
	}else{
		//is a special file
		sem_wait(&spl);
		specialfiles++;
		sem_post(&spl);
	}
}

