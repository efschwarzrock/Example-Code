#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int badfiles = 0;
int directories = 0;
int regfiles = 0;
long regfilebytes = 0;
int txtfiles = 0;
long txtfilebytes = 0;
int specialfiles = 0;
//main function
int main(int argc, char *argv[]){
	//the input string for the file name should be initalized but code isnt here
	char inputstr[strBuffer];
	//stats for the file and the return value of the stat() function
	struct stat filestats;
	int statret = 0;

	//get the stats and edit the variables acordingly
	statret = stat(inputstr, &filestats);
	if(statret != 0){
		//bad file
		badfiles++;
	}else{
		getStats(&filestats, inputstr);
  }

	return 0;
}

void getStats(struct stat *filestats, char *filename){
	if(S_ISDIR(filestats->st_mode) != 0){
		//its a directory
		directories++;
	}else if(S_ISREG(filestats->st_mode) != 0){
		//its a regular file, check if its a text file
		regfiles++;
		regfilebytes = regfilebytes + filestats->st_size;
		testForText(filestats, filename);
	}else{
		//its a special file
		specialfiles++;
	}
}

//checks if the file is a text file
void testForText(struct stat *filestats, char *filename){
	//opens file
	int ifd = open(filename, O_RDONLY);
	//char to test
	char c;
	//the return value of read()
	int readret;
	//is the loop done and is it a text file
	bool done = false;
	bool istextfile = true;
	if(ifd != -1){
		while(!done){
			readret = read(ifd, &c, 1);
			if(readret == 0){
				//reached the end of the file
				done = true;
			}else if(!(isprint(c) || isspace(c))){
				//it isnt a text file
				done = true;
				istextfile = false;
			}
		}
	}else{
		//we couldn't open the file
		istextfile = false;
	}
	//set the variables
	if(istextfile){
		txtfiles++;
		txtfilebytes = txtfilebytes + filestats->st_size;
	}
	close(ifd);		
}
