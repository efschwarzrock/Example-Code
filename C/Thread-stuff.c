#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include "mailbox.h"
#include "threads.h"



int main(int argc, char *argv[]){
	//number of threads
	int threads;
	pthread_t tid[MAXTHREAD + 1];
	void *adder(void *);
  //creates threads
	i = 1;
	while(i <= threads){
		if(pthread_create(&tid[i], NULL, adder, (void *)(i)) !=0){
			perror("pthread_create");
			exit(1);
		}
		i++;
	}
}


//send a message
void SendMsg(int iTo, struct msg *pMsg){
	sem_wait(&open[iTo]);
	mailboxes[iTo] = *pMsg;
	sem_post(&occupied[iTo]);
}

//receive a message
void RecvMsg(int iRecv, struct msg *pMsg){
	sem_wait(&occupied[iRecv]);
	*pMsg = mailboxes[iRecv];
	sem_post(&open[iRecv]);
}

//send a message with out blocking, if it cant send a message 
//it returns -1
int NBSendMsg(int iTo, struct msg *pMsg){
	int try = sem_trywait(&open[iTo]);
	if(try >=0){
		mailboxes[iTo] = *pMsg;
		sem_post(&occupied[iTo]);
	}
	return try;
}

//the thread controling function
void *adder(void *arg){
	//timer values
	struct timeval wcStart;
	struct timeval wcEnd;
	//return values
	int threadId = (long)arg;
	int total = 0;
	int ops = 0;
	long int longtime = 0;
	int time = 0;
	//messages
	struct msg recivedMessage;
	struct msg returnMessage;
	//controle variables
	bool done = false;
	bool startTimer = false;
	while(!done){
		RecvMsg(threadId, &recivedMessage);
		//first message so start the timer
		if(!startTimer){
			gettimeofday(&wcStart, NULL);
			startTimer = true;
		}
		//termination message so exit loop
		if(recivedMessage.value == -1){
			done = true;
		}else{
			//add to the total
			total = total + recivedMessage.value;
			ops++;
			sleep(1);
		}
	}
	//time calculations
	gettimeofday(&wcEnd, NULL);
	longtime = wcEnd.tv_sec - wcStart.tv_sec;	
	time = (int)longtime;
	//initalize the return message
	returnMessage.iFrom = threadId;
	returnMessage.value = total;
	returnMessage.cnt = ops;
	returnMessage.tot = time;
	//send it
	SendMsg(0, &returnMessage);
}
