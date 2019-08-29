int main(int argc, char *argv[]){
/* argc - num of arguments
 * argv - an array of strings
*/
	//pid of child
	int pid;
	//itorator
	int i;
	//array of arguments passed into execvp
	char *argvNew[argc-1];
		//initalize the arguments
		for(i = 1; i < argc; i++){
			argvNew[i-1] = argv[i];
		}
	
		//fork the process
		if((pid = fork()) < 0){
			fprintf(stderr, "Fork error\n");
			exit(1);
		}else if(pid == 0){
			//child
			//execute
			if(execvp(argvNew[0], argvNew) < 0){
				printf("execute error\n");
				exit(1);
			}
		}else{
			//parent
			wait(0);
			}
		}
	}
}
