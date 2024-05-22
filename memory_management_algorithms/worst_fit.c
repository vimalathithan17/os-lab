//worstfit

#include <stdio.h>
#include <stdlib.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
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

    // Pick each process and find the worst fit block according to its size
    for (int i = 0; i < n; i++) {
        // Find the worst fit block for the current process
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[worstIdx] < blockSize[j]) {
                    worstIdx = j;
                }
            }
        }

        // If a suitable block was found, allocate it to the process
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
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

    // Call the worstFit function
    worstFit(blockSize, m, processSize, n);

    // Free the allocated memory
    free(blockSize);
    free(processSize);

    return 0;
}

