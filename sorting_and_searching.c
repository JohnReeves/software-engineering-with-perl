// k&r c program to test the scripts
// 

#include <stdio.h>
#include <string.h>

void shellsort(int[], int);
int binsearch(int, int[], int);

int main(){
  int list_of_numbers[6] = {1,27,3,4,5,6};

  shellsort(list_of_numbers, 6);
  int found = binsearch(3, list_of_numbers, 6);
  if (found != -1)
     printf("3 found at: %d\n", found);
  else
     printf("not found in the list of numbers \n");

  return 0;
}

void shellsort(int v[], int n){
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j++){
        temp = v[j];
        v[j] = v[j+gap];
        v[j+gap] = temp;
      }
}

int binsearch(int x, int v[], int n){
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high){
    mid = (low+high)/2;
    if (x < v[mid]) high = mid - 1; else
    if (x > v[mid]) low = mid + 1; else
    return mid;
  }
  return -1;
}
