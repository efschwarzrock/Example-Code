#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define stringsize 20
void main(int argc, char* argv){
  char userinputstr[stringsize];
  bool badinput;
  if(fgets(userinputstr, stringsize, stdin) == NULL || strcmp(userinputstr, "\n") == 0){
      badinput = true;
  }else{
    dostuff();
  }
}
