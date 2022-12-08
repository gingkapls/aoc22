#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 50

int main(void)
{

  FILE *calList;
  char *dataBuf = malloc(sizeof(char) * BUF_SIZE);
  int elvesCal[50] = {0};
  int elvesCount, idx, most_cal, most_cal_idx;

  idx = 0;

  if ( (calList = fopen("day1.txt", "r")) == NULL )
  {
    printf("File does not exist\n");
    exit(1);
  }

  while ( (fgets(dataBuf, BUF_SIZE, calList) != NULL) )
  {
    elvesCal[idx] += atoi(dataBuf);
    if (*dataBuf == '\n')
      ++idx;
  }

  fclose(calList);

  elvesCount = idx;
  most_cal = elvesCal[0];

  for(idx = 0; idx <= elvesCount; ++idx)
  {
   if (elvesCal[idx] > most_cal)
   {
     most_cal = elvesCal[idx];
     most_cal_idx = idx;
   }
  }

  free(dataBuf)

  printf("The elf carrying most calories is elf %d carrying %d calories\n", most_cal_idx+1, most_cal);

}
