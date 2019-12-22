// sample c program to test the scripts
// kernighan & richie p108-110

// read input lines
// sort them
// display them in order

#include <stdio.h>
#include <string.h>

#define MAXLINES 5
#define MAXLEN 100
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[],int left, int right);

int zgetline(char *, int);
char * zalloc(int);

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
  while ((len = zgetline(line, MAXLEN)) > 0){
    if (nlines == maxlines || (p = zalloc(len)) == NULL){
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

void qsort(char *v[], int left, int right){
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left+right)/2);
  last = left;
  for (i = left+1; i <= right; i++){
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
  }
}

void swap(char *v[], int i, int j){
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int zgetline(char s[], int lim){
  int c, i;
  i = 0;

  while (--lim > 0 && (c=getchar()) != EOF && c)
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

char *zalloc(int n){
   
   if (allocbuf + ALLOCSIZE - allocp >= n){
      allocp += n;
      return allocp - n;
   } else
      return 0;
}