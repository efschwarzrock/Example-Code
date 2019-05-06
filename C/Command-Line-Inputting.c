void main(int argc, char* argv[]) {
	bool goodArgs = true;
	int size = 20;
	int initdbs = 5;
	int initants = 100;
	int timestepsLeft = 1000;
	int seed = 1;
	bool pause = false;
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
}
