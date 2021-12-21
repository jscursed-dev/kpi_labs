#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
  
  const char* help_notification="Use key -h or help for more information";

  if(argc>1){
    double x, a, b, y;

    if((strcmp(argv[1], "help")==0) || (strcmp(argv[1], "-h")==0)){
      printf("\nThis programm counts y.\nIf x<3, y=a*lg(x)\nIf 3<x<7, y=x+a\nIf x>7, y=|a*b+x|\n\nmain [KEYS] [value x] [value a] [value b]\nx, a, b are double variables\n\n[KEYS]\n-c - count with value from console\n-k - enter from keyboard\n-s - use standart values x=8 a=4, b=2\n\n");
      return 0;
    }
    if(strcmp(argv[1], "-k")==0){
      printf("x = ");
      scanf("%lf", &x);
      printf("a = ");
      scanf("%lf", &a);
      printf("b = ");
      scanf("%lf", &b);
    }
    else if(strcmp(argv[1], "-s")==0){
      x=8;
      a=4;
      b=2;
    }
    else if(strcmp(argv[1], "-c")==0){
      x=atof(argv[2]);
      a=atof(argv[3]);
      b=atof(argv[4]);
    }
    else{
      printf("\n%s\n\n", help_notification);
      return 0;
    }

    if(x<3){
      y = a*log10(x);
    }
    if((x>=3)&&(x<=7)){
      y = x+a;
    }
    if(x>7){
      y = fabs((a*b+x));
    }

    printf("y = %lf\n", y);
  }
  else{
    printf("\n%s\n\n", help_notification);
    return 0;
  }


  return 0;
}