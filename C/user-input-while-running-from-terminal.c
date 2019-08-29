int shell(){
	//number of arguments passed in
	int argc;
	//itorator
	int x;
	//is the user done typing
	bool go;
	//another itorator
	int i;
	//arguments typed in
	char argvShell[32][129];

		argc = 0;
		x = 0;
		go = true;
		//take the users input
		printf("%s", prompt);
		while(argc<32 && x < 129 && go){
			argvShell[argc][x] = getc(stdin);
			//is it a new word or is it the end of the line
			if(argvShell[argc][x] == ' '){
				argvShell[argc][x] = '\0';
				argc++;
				x = -1;
			}else if(argvShell[argc][x] == '\n'){
				go = false;
				argvShell[argc][x] = '\0';
				argc++;
			}
			x++;
		}
	
		}
    }
