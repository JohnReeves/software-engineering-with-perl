// sample c program to test the scripts
// kernighan & richie p108-110

// read input lines
// sort them
// display them in order

#include <stdio.h>
#include <string.h>

#define MAXLINES 100
#define MAXLEN 100

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[],int left, int right);

int getline(char *, int);
char * alloc(int);

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

int readlines(char *lineptr[], int maxlines){
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0){
    if (nlines == maxlines || (p = alloc(len)) == NULL){
      return -1;

    } else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines){
  int i;
  
  for (i=0;i<nlines;i++){
    printf("%s\n",lineptr[i]);
  }
}