#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  const int len = 4;
  const int len2 = 30;
  char matrix[len][len];
  int arrAd2[len2];

  printf("Addition 1\n");
  printf("Array without changes:");
  for (int i = 0; i < len; i++){
    printf("\n\t%d. ", i+1);
    for(int j = 0; j < len; j++) {
      *(*(matrix+i)+j) = (char)(rand()%21+97);
      printf("%c; ", *(*(matrix+i)+j));
    }
  }
  char buf;
  for (int i = 0, k = len-1; i < len; i++, k--) {
    for(int j = 0, z = len-1; j < len; j++, z--) {
      if (j >= k) {
        continue;
      }
      buf = *(*(matrix+i)+j);
      *(*(matrix+i)+j) = *(*(matrix+z)+k);
      *(*(matrix+z)+k) = buf;
    }
  }

  printf("\nModificated array array:");
  for (int i = 0; i < len; i++) {
    printf("\n\t%d. ", i+1);
    for(int j = 0; j < len; j++) {
      printf("%c; ", *(*(matrix+i)+j));
    }
  }

  printf("\n\nAddition 2\n");
  int grans[2];
  *grans = rand()%(len2-2);
  *(grans + 1) = *grans+rand()%(len2-*grans);

  
  printf("Unsorted array:\n");
  for (int i = 0; i < len2; i++) {
    *(arrAd2 + i) = rand()%100;
    printf("%d ", arrAd2[i]);
  }
  printf("\nArray will be sorted between these indexes: %d and %d\n", grans[0], grans[1]);

  printf("Sorted array:\n");
  int temp;
  for (int i = *grans; i < *(grans+1); i++){
    for (int j = *grans; j < *(grans+1) - i - 1; j++){
      if (*(arrAd2+j) > *(arrAd2+j+1) ){
        temp = arrAd2[j];
        *(arrAd2+j) = *(arrAd2+j + 1);
        *(arrAd2+j + 1) = temp;
      } 
    }
  }
  for (int i = 0; i < len2; i++) {
    printf("%d, ", *(arrAd2 + i));
  }
  return 0;
}

