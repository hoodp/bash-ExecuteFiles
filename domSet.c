/*
 * Finding the smallest dominating set
 */

#include <stdio.h>
#include <stdlib.h>
// Count how many 1s there are in the binary
// representaiton of a value

int count1s(unsigned int value) {
 unsigned int mask = 1;
 unsigned int size = sizeof(unsigned int)*8;
 int i;
 int result = 0;
 for(i = 0; i < size;i++) {
    if (mask & value) {
	result++;
    }
    mask = mask * 2;
 }
 return result;
}
// Calculate the subset of vertices that
// is encoded by a particular binary value
void calcSubset(int *subset,unsigned int value,int n) {
  int i;
  unsigned int mask = 1;
  for(i = 0;i < n;i++) {
    if (mask & value) {
      subset[i] = 1;
    }
    else {
      subset[i] = 0;
    }
    mask = mask * 2;
  }
}

// Is this particular subset of vertices a dominating set?
// Return 1 if it is
// Return 0 if it is not
int     isDominatingSet(int *subset,int **matrix,int n) 
{
  int covered[n];
  int i,j;
  for(i = 0;i < n;i++) {
    if (subset[i])
      covered[i] = 1;
    else
      covered[i] = 0;
  }
  // Now add to covered, the elements that are adjacent
  // in the graph of the values in the subset
  for(i = 0;i < n;i++) {
    if (subset[i]) {
      for(j = 0;j < n;j++) {
	if (matrix[i][j]) {
	  covered[j] = 1;
	}
      }
    }
  }
  // Now check if all vertices are covered or not
  for(i = 0;i < n;i++) {
    if (covered[i] == 0) {
      return 0;
    }
  }
  // If this point is reached, all vertices were covered.
  return 1;
}



void printMatrix(int **mat,int size) 
{
  int i,j;
  for(i = 0;i < size;i++) {
    for(j = 0;j < size;j++) {
      printf("%d ",mat[i][j]);
    }
    printf("\n");
  }
  return;
}

int main(void)
{

  int n;
  unsigned int i,j;
  // printf("Please enter the size of the matrix: \n");
  scanf("%d",&n);

  int **matrix;
  matrix = (int **) malloc(n * sizeof(int *));
  for(i = 0;i < n;i++) {
    matrix[i] = (int *) malloc(n * sizeof(int));
  }

  for(i = 0;i < n;i++) {
    for(j = 0;j < n;j++) {
      scanf("%d ",&matrix[i][j]);
    }
  }
  // Now print the matrix

  int sizePowerSet = 1;
  for(i = 0;i < n;i++) {
    sizePowerSet = sizePowerSet*2;
  }
  // For debugging: Print the size of the power set
  // printf("The size of the power set is %d\n",sizePowerSet);

  // Now go through all the possible elements in the power set
  // except for the empty set
  int smallestDominatingSet = n;
  for(i = 1;i < sizePowerSet;i++) {
    int subset[n];
    calcSubset(subset,i,n);
    if(isDominatingSet(subset,matrix,n)) {
      int aux = count1s(i);
      if (aux < smallestDominatingSet) 
	smallestDominatingSet = aux;
    }
  }
  printf("%d\n",
	 smallestDominatingSet);
}
