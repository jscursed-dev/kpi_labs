#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int* digitEncryptor(char *text, int alphabetType) {
  int* cryptedText = malloc(sizeof(int*) *strlen(text)); 
  int alphabetShift; 

  switch(alphabetType) {
    case 1:
      alphabetShift = 96;
      break;
    case 2:
      alphabetShift = 223;
      break;
    default:
      alphabetShift = 223;
      break;
  }

  for (int i = 0; i < strlen(text); i++) {
    cryptedText[i] = (int)text[i] - alphabetShift;
  }

  return cryptedText;
}

int** createKey(char *keyText, int alphabetType) {
  int keySizes[] = {
    strlen(keyText), // length of keyText;
    (int)sqrt(keySizes[0]) // rows and pillars for the matrix; 
  };

  int *cryptedKey = digitEncryptor(keyText, alphabetType);
  
  int** cryptedKeyMatrix = malloc(sizeof(int*) * keySizes[1]);
  for (int i = 0; i < keySizes[1]; i++) {
    cryptedKeyMatrix[i] = malloc(sizeof(int*) * keySizes[1]);
  }

  int globalCounter = 0;
  for (int i = 0; i < keySizes[1]; i++) {
    for (int j = 0; j < keySizes[1]; j++) {
      cryptedKeyMatrix[i][j] = *(cryptedKey+globalCounter);
      printf("%d ", cryptedKeyMatrix[i][j]);
      globalCounter++;
    }                             
  }
  return cryptedKeyMatrix;
}

int** digitsToBlocks(int* digitsArr, double textlen, double matrixSize) {
  int** blocks = malloc(sizeof(ceil(textlen/matrixSize))*sizeof(int*));
  for (int i = 0; i < textlen/matrixSize; i++) {
    blocks[i] = malloc(sizeof(int*) * matrixSize);
  }
  int globalCounter = 0;
  for (int i = 0; i < ceil(textlen/matrixSize); i++) {
    printf("\n");
    for (int j = 0; j < matrixSize; j++) {
      if (textlen <= globalCounter) {
        blocks[i][j] = 27;
        continue;
      }
      blocks[i][j] = digitsArr[globalCounter];
      globalCounter++;
    }
  }

  return blocks;
}

int* multMatrixAndBlock(int* block, int** matrix, int matrixSize) {
  int* result = malloc(matrixSize*sizeof(int*));
  for (int i = 0; i < matrixSize; i++) {      
    for (int j = 0; j < matrixSize; j++) {

      result[i]+=matrix[j][i]*block[j];
    }
  }

  return result;
}

void encryptor(char* text, char* keyText, int alphabetType, char* alphabet) {
  const int textlen = strlen(text);
  const int matrixSize = sqrt(strlen(keyText)); 

  char* encrypted = malloc(
    (int)(matrixSize*ceil((double)(strlen(text)/(double)matrixSize)))
  );

  // to crypt
  int* digitsArr = digitEncryptor(text, alphabetType);
  int** blocks = digitsToBlocks(digitsArr, textlen, matrixSize);
  // for crypt
  int** key = createKey(keyText, alphabetType);
  //crypt
  int globalCounter = 0;
  for (int i = 0; i < ceil((double)(strlen(text)/(double)matrixSize)); i++) {
    int cryptedBlock[matrixSize];
    for (int k = 0; k < matrixSize; k++) {
      cryptedBlock[k] = *(multMatrixAndBlock(blocks[i], key, matrixSize)+k)%26;
    }
    for (int j = 0; j < matrixSize; j++) {
      encrypted[globalCounter] = alphabet[cryptedBlock[j]-1]; 
      printf("%c", encrypted[globalCounter]);
      globalCounter++;
    }
  }
} 

int main(void) {
  const char *alphabet[] = {
    "abcdefghijklmnopqrstuvwxyz", //26 ENG
    "абвгдеёжзийклмнопрстуфхцчшщъыьэюя;? ", // 37 RUS
  };
  char *keyText = "adci";
  char *text = "jv";

  encryptor(text, keyText, 1, alphabet[0]);
  return 0;
}

/* Resources, I used:
  1. https://followtutorials.com/2011/08/returning-two-dimensional-array-from-a-function-in-c.html
  2. https://habr.com/ru/post/332714/
  3. http://www.c-cpp.ru/content/malloc
 */