
//nextfit
#include <stdio.h>
#include <stdlib.h>

void nextFit(int blockSize[], int m, int processSize[], int n) {
    // Allocate memory for the allocation array dynamically
    int *allocation = (int *)malloc(n * sizeof(int));
    
    // Check if memory allocation was successful
    if (allocation == NULL) {
        printf("Memory allocation failed");
        return;
    }

    // Initially, no block is assigned to any process
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // The starting index for the next fit allocation
    int j = 0;

    // Pick each process and find the next fit block according to its size
    for (int i = 0; i < n; i++) {
        int k=0;
        int jinit=j;
        // Start from the last allocated block
        while (j < m) {
            if (k>m){
              j=jinit;
              break;
            }
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            k++;
            j = (j + 1) % m;
        }
    }
    
    // Print the allocation results
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    // Free the allocated memory
    free(allocation);
}

int main() {
    int m, n;

    // Get the number of blocks and processes from the user
    printf("Enter the number of blocks: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Invalid number of blocks\n");
        return 1;
    }
    
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes\n");
        return 1;
    }

    // Allocate memory for blockSize and processSize arrays
    int *blockSize = (int *)malloc(m * sizeof(int));
    int *processSize = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (blockSize == NULL || processSize == NULL) {
        printf("Memory allocation failed");
        free(blockSize);
        free(processSize);
        return 1;
    }

    // Get the block sizes from the user
    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        if (scanf("%d", &blockSize[i]) != 1 || blockSize[i] <= 0) {
            printf("Invalid block size\n");
            free(blockSize);
            free(processSize);
            return 1;
        }
    }

    // Get the process sizes from the user
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        if (scanf("%d", &processSize[i]) != 1 || processSize[i] <= 0) {
            printf("Invalid process size\n");
            free(blockSize);
            free(processSize);
            return 1;
        }
    }

    // Call the nextFit function
    nextFit(blockSize, m, processSize, n);

    // Free the allocated memory
    free(blockSize);
    free(processSize);

    return 0;
}

