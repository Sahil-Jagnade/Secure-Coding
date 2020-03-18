#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define ARRAY_SIZE 5
#define STRING_LENGTH 100

int read_array(char**, int);
int free_mem(char**);

int main(int argv, char** argc)
{
  char **array = (char**)malloc(1 * sizeof(char*));
  FILE *fp;
  fp = fopen("test_file.txt", "r");

  char c;
  int file_end = 0;
  int count = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    if (file_end) {
      break;
    }
    array = (char**)realloc(array, (i + 1) * sizeof(char*));
    array[i] = malloc(STRING_LENGTH);
    /*snprintf(array[i], STRING_LENGTH, "Test %d", i);*/
    for(int j = 0; j < STRING_LENGTH; j++) {
      c = fgetc(fp);
      if( c == '\n') {
        array[i][j] = '\0';
        count++;
        break;
      }
      if( c == '\0' ) {
        array[i][j] = '\0';
        file_end = 1;
        count++;
        break;
      }
      array[i][j] = c;
    }
  }
  fclose(fp);
  read_array(array, count);
  free_mem(array);

  return 0;
}

int read_array(char **rd_array, int rd_count) {
  for (int i = 0; i < rd_count; i++)
  {
    printf("%s\n", rd_array[i]);
  }
  return 0;
}

int free_mem(char **fr_array) {
  for(int i = 0; i < ARRAY_SIZE; i++) {
    free(fr_array[i]);
  }
  free(fr_array);
  return 0;
}
