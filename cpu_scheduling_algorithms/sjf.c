#include<stdio.h>
#include<stdlib.h>
void main(){ 
  int n;
  printf("Enter the number of process:");
  scanf("%d",&n);
// Matrix for storing Process Id, Burst
// Time, Average Waiting Time & Average
// Turn Around Time.
  int** A=(int **)calloc(n, sizeof(int*));
  int i=0;
  for(i=0;i<n;i++){
    A[i]=(int*)calloc(4, sizeof(int));
  }
  int total = 0;
  float avg_wt, avg_tat;
  printf("Enter Burst Time:\n");
  for (int i = 0; i < n; i++) {
// User Input Burst Time and alloting
// Process Id.
    printf("P%d:" ,(i + 1));
    scanf("%d",&A[i][1]);
    A[i][0] = i + 1;
  }
  for (int i = 0; i < n; i++) {
// Sorting process according to their
// Burst Time.
    int index = i;
    for (int j = i + 1; j < n; j++) {
      if (A[j][1] < A[index][1]) {
        index = j;
      } 
    }
    int temp = A[i][1];
    A[i][1] = A[index][1];
    A[index][1] = temp;
    temp = A[i][0];
    A[i][0] = A[index][0];
    A[index][0] = temp;
  }
  A[0][2] = 0;
// Calculation of Waiting Times
  for (int i = 1; i < n; i++) {
    A[i][2] = 0;
    for (int j = 0; j < i; j++) {
      A[i][2] += A[j][1];
    }
    total += A[i][2];
  }
  avg_wt = (float)total / n;
  total = 0;
// Calculation of Turn Around Time and printing the
// data.
  printf("P\tBT\tWT\tTAT\n");
  for (int i = 0; i < n; i++) {
     A[i][3] = A[i][1] + A[i][2];
     total += A[i][3];
     printf("P%d\t%d\t%d\t%d\n" ,A[i][0], A[i][1], A[i][2], A[i][3]);
   }
   avg_tat = (float)total / n;
   printf("Average Waiting Time= %g\n", avg_wt);
   printf("Average Turnaround Time= %g\n", avg_tat);
}
