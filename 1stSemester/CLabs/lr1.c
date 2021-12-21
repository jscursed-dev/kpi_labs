#include <stdio.h> // standart input/output

int main(void) {
  const double double_variable = 5.0;
  const float float_variable = 0.5;
  const int integer_variable = 14;
  const char char_variable = 'z';
  const char *char_array = "Hello World";
  const char *main_string[5][1] = {{"НТУУ КПІ"}, {"АПЕПС"}, {"ТР-"}, {"Михайло Притула"}, {"19.09.2021"}};
  
  printf("\nFloating point digits:\n\tdouble: %f\n\tfloat: %f\nInteger: %d\nChar:\n\tchar: %c\n\tchar array=string: %s", double_variable, float_variable, integer_variable, char_variable, char_array);
  
  printf("\n\nPersonal task:");
  for(int i=0; i<5; i++){
    printf("\n\t%d. ", i+1);
    for(int j=0; j<1; j++){
      if(i==2){
        printf("%s%d", main_string[i][j], integer_variable);
        continue;
    }
      printf("%s", main_string[i][j]);
    }
  }
  printf("\n\n");
  return 0;
}