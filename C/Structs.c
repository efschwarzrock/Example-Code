/**
*  A struct that houses the final amount of hits, misses, and evictions for the cache
*/
typedef struct Output{
  int numMiss; /* The number of misses */
  int numHits; /* The number of hits */
  int numEvic; /* The number of evictions */
}output;

/**
*  The line struct for the cache
*/
typedef struct Line{
  bool v; /* Valid bit */
  unsigned long tag; /* Tag */
  int b; /* 2^b is the number of bytes to store data */
  int lastUsed; /* The last time the data was used */
}line;

/**
*  The set struct for the cache
*/
typedef struct Set{
  int E; /* The number of lines in the set */
  line* lines; /* The lines in the set */
}set;

/**
*  The cache simulation struct
*/
typedef struct Cache{
  int s; /* 2^s is the number of sets in the cache */
  int numMiss; /* The curent number of misses experienced by the cache */
  int numHits; /* The curent number of hits experienced by the cache */
  int numEvic; /* The curent number of evictions experienced by the cache */
  set* sets; /* The sets in the cache */
}cache;

/**
* Sets up the cache and file for simulate to simulate
* @param v wheather to print verbose trace information
* @param s the number of set index bits
* @param E the number of lines per set
* @param b the number of block bits
* @param t name of the valgrind trace to replay
* @param results the pointer to the place to put the number of hits, misses, and evictions
*/
void readFile(bool v, int s, int E, int b, char* t, output* results){
  //Let's read the input file
  FILE* fp = fopen(t, "r"); //we try to read it
  if (fp != false){
    //array of lines
    struct Line lines[1<<s][E];
    int S = 1<<s;
    //array of sets
    struct Set sets[S];
    int i = 0;
    //set the lines to their sets
    while(i<S){
      sets[i].lines = lines[i];
      sets[i].E = E;
      int y = 0;
      //initalize the lines
      while(y<E){
        lines[i][y].v = false;
        lines[i][y].b = b;
        lines[i][y].lastUsed = E;
        y++;
      }
      i++;
    }
    //the cache
    struct Cache myCache = {s, 0, 0, 0, sets};
    cache* myCachePtr = &myCache;
    //simulate the cache
    simulate(v, s, E, b, fp, myCachePtr);
    //set the number of hits, misses, and evictions
    results->numHits = myCachePtr->numHits;
    results->numMiss = myCachePtr->numMiss;
    results->numEvic = myCachePtr->numEvic;
  }else{
    //error message
    printf("%s: No such file or directory\n", t);
  }

}

