#include <stdio.h>
#include <stdlib.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
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
    
    // Pick each process and find a suitable block according to its size and assign it
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;
                
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                
                break;
            }
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
    scanf("%d", &m);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for blockSize and processSize arrays
    int *blockSize = (int *)malloc(m * sizeof(int));
    int *processSize = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (blockSize == NULL || processSize == NULL) {
        printf("Memory allocation failed");
        if (blockSize != NULL) free(blockSize);
        if (processSize != NULL) free(processSize);
        return 1;
    }

    // Get the block sizes from the user
    printf("Enter the sizes of the blocks:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Get the process sizes from the user
    printf("Enter the sizes of the processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call the firstFit function
    firstFit(blockSize, m, processSize, n);

    // Free the allocated memory
    free(blockSize);
    free(processSize);

    return 0;
}

