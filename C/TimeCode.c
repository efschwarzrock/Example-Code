/* doit.c
 * Erich Schwarzrock
 * */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>

#include <string.h>


//Main function
int main(int argc, char *argv[]){
/* argc - num of arguments
 * argv - an array of strings
*/
	
	//worldclock start and end times
	struct timeval wcStart;
	struct timeval wcEnd;
	
	//start time
	gettimeofday(&wcStart, NULL);
	//code
	
	//code
        //end timer
	gettimeofday(&wcEnd, NULL);
	printf("World-clock time : %ld\n", ((wcEnd.tv_sec*1000000 + wcEnd.tv_usec) - (wcStart.tv_sec * 1000000 + wcStart.tv_usec)));	
			
		
}
