#include <stdio.h>

int main() {

  FILE *fp;
  fp = fopen("test_file.txt", "r");
  

  char c;
  while(1) {
    c = fgetc(fp);
    if (c == '\n' || c == '\0')
      break;
    printf("%c", c);
  }
  printf("\n");
  fclose(fp);
  return 0;
}
