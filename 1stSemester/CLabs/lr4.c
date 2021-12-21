#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <time.h>

int main(int argc, char* argv[]){
  
  srand(time(NULL));
  const char* help_notification="Use key -h or help for more information";
  char * pEnd;
  int basicLength = 0;
  int dAmount = 0;
  int temp = 0;

  if(argc>1){

    if((strcmp(argv[1], "help")==0) || (strcmp(argv[1], "-h")==0)){
      printf("\nThis programm modificates arrays.\nTask 1: add element to the top of the array.\nTask 2: remove row number K\n\nmain [KEYS] [length] [amount of dimensions] [values]\nvalues of the array must be of double type\n\n[KEYS]\n-c - count with value from console\n-s - count with standart(random values< where arrays are array1[5] and array2[5][5])\n-k - enter values from keyboard.\n\n");
      return 0;
    }
    if(strcmp(argv[1], "-k")==0){
      printf("\nEnter plese basic length of array: ");
      scanf("%d", &basicLength);
      printf("\nEnter plese amount of dimensions: ");
      scanf("%d", &dAmount);

      if(((dAmount>=512) || (basicLength>=512))||((dAmount<=0)||(basicLength<=0))){
        printf("Error: you have taken too much of memory");
        return -1;
      }

    }
    
    else if(strcmp(argv[1], "-s")==0){
      basicLength = 5;
      dAmount=5;
    }

    else if(strcmp(argv[1], "-c")==0){
      dAmount = strtol(argv[3], NULL, 10);
      basicLength = strtol(argv[2], NULL, 10);
      if(((dAmount>=512) || (basicLength>=512))||((dAmount<=0)||(basicLength<=0))){
        printf("Error: you have taken too much of memory");
        return -1;
      }
    }

    else{
      printf("\n%s\n\n", help_notification);
      return 0;
    }

    double array1[basicLength]; 
    double array2[dAmount][basicLength]; 
    
    if(strcmp(argv[1], "-k")==0){
      printf("Array from the task1:\n");
      for(int i=0; i<basicLength; i++){  
        printf("elem #%d = ", i+1);  
        scanf("%lf", &array1[i]);                            
      }

      printf("\nArray from the task2:\n");
      for(int i=0; i<dAmount; i++){
        for(int j=0; j<basicLength; j++){  
          printf("elem #%d.%d = ", i+1, j+1);  
          scanf("%lf", &array2[i][j]);                            
        }
      }
    }

    else if(strcmp(argv[1], "-s")==0){
      for(int i=0; i<basicLength; i++){
        array1[i]=1 + rand() % 100;     
      }
      for(int i=0; i<dAmount; i++){
        for(int j=0; j<basicLength; j++){
          array2[i][j]=1 + rand() % 100;     
        }
      }
    }

    else if(strcmp(argv[1], "-c")==0){
      int counter = 0;      
      
      for(int i=0; i<basicLength; i++){
        array1[i]=atof(argv[i+4]);
      }
      for(int i=0; i<dAmount; i++){
        for(int j=0; j<basicLength; j++){
          array2[i][j]=atof(argv[j+4+counter]);
        }
        counter+=basicLength;
      }    
    }

    for(int i=0; i<2; i++){
      printf("\nYour array %d: ", i+1);
      if(i>0){
        for(int j=0; j<dAmount; j++){
          printf("\n\t%d. ", j+1);
          for(int k=0; k<basicLength; k++){
            printf("%.2lf ", array2[j][k]);
          }
        }
      }
      if(i==0){
        for(int j=0; j<basicLength; j++){
          printf("%.2lf ", array1[j]);
        }
      }
    }
    
    /*
    PART II: MODIFICATING ARRAYS!
    */

    double marray1[basicLength+1];
    double marray2[dAmount-1][basicLength];

    
    int k=0;
    int buf=0;
    printf("\n\nEnter please which row you want to delete: ");
    scanf("%d", &k);
    


    // TASK 2 
    for(int i=0; i<dAmount; i++){
      if(i==k-1){
        buf = 1+buf;
      }
      if(i==dAmount-1){
        break;
      }
      for(int j=0; j<basicLength; j++){
        marray2[i][j]=array2[i+buf][j];
      }
    }
    
    //TASK 1
    printf("Enter please elem, which you want to add to the top: ");
    scanf("%lf", &marray1[0]);
    for(int i=0; i<basicLength; i++){
      marray1[i+1]=array1[i];
      printf("%.2lf ", marray1[i+1]);
    }

    //OUTPUT
    printf("\n\nModificated:\nArray 1: ");
    for(int i=0; i<basicLength+1; i++){
      printf("%.2lf; ", marray1[i]);
    }
    printf("\nArray 2: ");
    
    for(int i=0; i<dAmount-1; i++){
      printf("\n\t%d. ", i+1);
      for(int j=0; j<basicLength; j++){
        printf("%.2lf; ", marray2[i][j]);
      }  
    }
  }

  else{
    printf("\n%s\n\n", help_notification);
    return 0;
  }

  printf("\n\n");
  return 0;
}

