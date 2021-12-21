#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define M_PI 3.14159265358979323846

int main(int argc, char* argv[]) {

const char* help_notification="Use key -h or help for more information";
  double z=0;
  int acc = 0;
  double a = 0;
  double p=0;
  
  if(argc>1){


    if((strcmp(argv[1], "help")==0) || (strcmp(argv[1], "-h")==0)){
      printf("\nThis programm counts mathematical series from this function.\n\nmain [KEYS] [accuracy] [degrees] [a number]\nPS: accuracy is unsigned int\n\n[KEYS]\n-c - count with value from console\n-k - enter from keyboard\n-s - use standart values accuracy = 5, degrees = 45, a = 3\n\n");
      return 0;
    }
    if(strcmp(argv[1], "-k")==0){
      printf("accuracy = ");
      scanf("%d", &acc);
      printf("degrees = ");
      scanf("%lf", &p);
      printf("a number = ");
      scanf("%lf", &a);
    }
    else if(strcmp(argv[1], "-s")==0){
      acc = 5;
      p=45;
      a = 3;
    }
    else if(strcmp(argv[1], "-c")==0){
      acc=atof(argv[2]);
      p=atof(argv[3]);
      a=atof(argv[4]);
    }
    else{
      printf("\n%s\n\n", help_notification);
      return 0;
    }
  }
  else{
    printf("\n%s\n\n", help_notification);
    return 0;
  }  


  a = fabs(a);
  p=p*M_PI/180;

  for(int k=0; k<=5; k++){
    z+=pow(-1, k)*(pow(3*p, 2*k))/(fact(2*k));
  }
  z=a*z;

  printf("%lf\n",z);
}

int fact(int n){
  if(n==0){
    return 1;
  }
  else{
    return n*fact(n-1);
  }
}