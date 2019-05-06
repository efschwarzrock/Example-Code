void func(){
    strcpy(filename, argv[4]);
		//now we have the command line
		//Let's read the input file
		FILE* fp = fopen(filename, "r"); //we try to read it
		if (fp != false)
		{//it opened, yay!
			printf("Opened %s.\n",filename);
			ok2 = true;
			//can we read the data?
			char oRow[100];
			//Let's find out how many lines there are, and
			//find out the maximum width
			bool doneReadingFile = false;
			while(!doneReadingFile)
			{
				oRow[0]='\0';
				fscanf(fp, "%s", oRow);
				if(strlen(oRow)!=0)//there was something there
				{
					//increase row count
					howManyLinesInFile++;
					//check for the max cols
					if(strlen(oRow)> maximumWidth){
						maximumWidth = strlen(oRow);
					}
				}
				else
				{
					doneReadingFile = true;
					fclose(fp);
				}
			}


		}else{
			puts("Cannot find that file,");
			done = true;
		}
    if(!done)
		{
			char boards[3][nRows][nCols];
			char* old_p=&boards[0][0][0];
			//Initialize boards
			createBoards(nRows, nCols, boards);

			FILE* fp = fopen(filename, "r");//we read it before, we expect we can read it again
			//add the pattern into the first board
			readFileIntoArray(nRows, nCols, howManyLinesInFile,  maximumWidth, old_p, fp);
			//play the game
			playGame(nRows, nCols, gens, boards, printGens, stopBetweenGens);
		}
    }
    
   
   
   
void readFileIntoArray(int nRows, int nCols, int howManyLinesInFile, int maximumWidth, char* ar_p, FILE* fp)
{
	for(int row = 0; row< nRows; row++)
	{
		for(int col = 0; col<nCols; col++)
		{
			*(ar_p+(row*nCols)+col) = 'o';

		}
	}

	for(int frow=0; frow< howManyLinesInFile; frow++)
	{
		char fromFile[maximumWidth];

		for(int i = 0; i<maximumWidth; i++)
		{
			fromFile[i]='o';
		}
		fscanf(fp, "%s", fromFile);
		for(int fcol=0; fcol<maximumWidth; fcol++)
		{
			if(fromFile[fcol]=='x')
			{
				int targetRow = frow+(nRows-howManyLinesInFile)/2;
				int targetCol = fcol+(nCols-maximumWidth)/2;
				*(ar_p+(targetRow*nCols)+targetCol) = 'x';
			}
		}
	}
}
