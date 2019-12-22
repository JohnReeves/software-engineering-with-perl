// sample c program to test the scripts
// kernighan & richie p108-110

// read input lines
// sort them
// display them in order

#include <stdio.h>
#include <string.h>

#define 10

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[],int left, int right);

int main(){

int nlines;
int ret;

if ((nlines  = readlines(lineptr, MAXLINES)) >= 0){
  qsort(lineptr, 0, nlines-1);
  writelines(lineptr, nlines);
  ret = 0;

} else {
  printf("error: input to big to sort\n");
  ret = 1;

}

return ret;
}