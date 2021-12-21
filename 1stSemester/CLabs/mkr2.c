#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>


int* digitEncryptor(char *text) {
  int* cryptedText = malloc(sizeof(int*) *strlen(text)); 
  int alphabetShift = 96; 

  for (int i = 0; i < strlen(text); i++) {
    cryptedText[i] = (int)text[i] - alphabetShift;
  }

  return cryptedText;
}
bool checkClear(double val) {
  if (((val == ceil(val)) && (val > 0))) {
    return true;
  }
  else {
    return false;
  }
}

int main(void) {
  int keyMatrix[2][2] = {
    {7, 8},
    {2, 3}
  };

  char* secretWord = "kbqb";
  printf("CRYPTED MESSAGE: %s\n", secretWord); 
  printf("KEY:");
  for (int i = 0; i < 2; i++) {
    printf("\n\t| ");
    for (int j = 0; j < 2; j++) {
      printf("%d ", keyMatrix[i][j]);
    }
    printf("|");
  }
  printf("\n");
  
  int notKeyMatrix[2][2];

  int det = keyMatrix[0][0]*keyMatrix[1][1] - keyMatrix[0][1]*keyMatrix[1][0];
  if (det == 0) {
    printf("ERROR, INVALID KEY, DET = %d", det);
    return -1;
  }
  
  int buf;
  notKeyMatrix[0][0] = keyMatrix[1][1];
  notKeyMatrix[0][1] = -1 * keyMatrix[0][1];
  notKeyMatrix[1][0] = -1 * keyMatrix[1][0]; 
  notKeyMatrix[1][1] = keyMatrix[0][0];
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
  
      if (checkClear(((double)notKeyMatrix[i][j]) / ((double)det))) {
        notKeyMatrix[i][j] = (int)ceil(((double)notKeyMatrix[i][j] / (double)det));
        continue;
      }
      else {
        int k = 1;
        if((double)notKeyMatrix[i][j]/(double)det == ceil((double)notKeyMatrix[i][j]/(double)det)) {
          while ((double)notKeyMatrix[i][j]/(double)det + k*26 < 0) {
            k++;
          }
          notKeyMatrix[i][j] = (int)ceil((double)notKeyMatrix[i][j] / (double)det + k * 26);
          continue;
        }
       
        if (det < 0 && notKeyMatrix[i][j] < 0) {
          notKeyMatrix[i][j] = abs(notKeyMatrix[i][j]);
          while (
            (((double)notKeyMatrix[i][j] + k * 26) / fabs((double)det)) - ceil(((double)notKeyMatrix[i][j] + k * 26) / fabs((double)det)) > 10e-8 
            && 
            (((double)notKeyMatrix[i][j] + k * 26) / (double)det) - ceil(((double)notKeyMatrix[i][j] + k * 26) / (double)det) != 0
          ) {
            k++;
          }
          notKeyMatrix[i][j] = (int)ceil(((double)notKeyMatrix[i][j] + k * 26) / (double)abs(det));
        }
        else {
          int detc = det;
          if (det < 0) {
            detc = abs(det);
            notKeyMatrix[i][j] = -1*notKeyMatrix[i][j];
          }
          
          while (
            (((double)notKeyMatrix[i][j] + k * 26) / (double)detc) - ceil(((double)notKeyMatrix[i][j] + k * 26) / (double)detc) < 10e-8 
            && 
            (((double)notKeyMatrix[i][j] + k * 26) / (double)detc) - ceil(((double)notKeyMatrix[i][j] + k * 26) / (double)detc) != 0
          ) {
            k++;
          }
          notKeyMatrix[i][j] = (int)ceil(((double)notKeyMatrix[i][j] + k * 26) / (double)detc );
        }
      }
    }
  }

  printf("INVERTTED KEY: "); 
  for (int i = 0; i < 2; i++) {
    printf("\n\t| ");
    for (int j = 0; j < 2; j++) {
      printf("%d ", notKeyMatrix[i][j]);
    }
    printf("|");
  }
  printf("\n\n");
  
  //text to blocks
  int amountOfPillars = ceil((double)strlen(secretWord)/2);
  int digitArr[strlen(secretWord)];
  for (int i = 0; i < strlen(secretWord); i++) {
    digitArr[i] = digitEncryptor(secretWord)[i];
  }
  
  int blocks[2][amountOfPillars];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < amountOfPillars; j++) {
      blocks[i][j] = 0;
    }
  }  

  int k = 0;
  while(k < strlen(secretWord)) {
    for (int i = 0; i < amountOfPillars; i++) {
      for (int j = 0; j < 2; j++) {
        blocks[j][i] = digitArr[k];
        k++;
      }
    }
  }

  //decryption
  int encryptedDigits[2*amountOfPillars];
  int result[2][amountOfPillars];
  for (int i = 0; i < 2*amountOfPillars; i++) {
    encryptedDigits[i] = 0;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < amountOfPillars; j++) {
      result[i][j] = 0;
    }
  }



  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < amountOfPillars; j++) {
      for (int k = 0; k < 2; k++) {
        result[i][j] += notKeyMatrix[i][k]*blocks[k][j];
      }
    }
  }
    
  int g = 0;
  for (int i = 0; i < amountOfPillars; i++) {
    for (int j = 0; j < 2; j++) {
      if (g < strlen(secretWord)) {
        encryptedDigits[g] = result[j][i]%26;
        g++;
      }
    }
  }

  //to letters :)
  char encryptedText[2*amountOfPillars];
  for (int i = 0; i < 2*amountOfPillars; i++) {
    if (encryptedDigits[i] == 0) {
      encryptedText[i] = 'z';
      continue;
    }
    encryptedText[i] = (char)(encryptedDigits[i]+96);
  } 
  
  printf("ENCRYPTED MESSAGE: ");
  for (int i = 0; i < 2*amountOfPillars; i++) {
    printf("%c", encryptedText[i]);
  } 
  printf("\n");
  

  return 0;
}