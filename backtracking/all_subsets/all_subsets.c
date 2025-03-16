#include <stdio.h>

// Function to print the current subset
void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Backtracking function to generate subsets
void backtrack(int arr[], int n, int index, int subset[], int subsetSize) {
    // Print the current subset
    printSubset(subset, subsetSize);

	printf("before loop\n");
    // Explore further subsets
    for (int i = index; i < n; i++) {
        // Include arr[i] in the current subset
        subset[subsetSize] = arr[i];
	    printf("assign subset\n");
	    printf("i: %d, size: %d\n", i, subsetSize);

        // Recur with the next element
        backtrack(arr, n, i + 1, subset, subsetSize + 1);
	    printf("backtracking\n");
	    printf("i+1: %d, size+1: %d\n", i+1, subsetSize+1);
    }
}

int main() {
    int arr[] = {1, 2, 3};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int subset[n];  // Temporary array to store a subset

    // Call backtrack to generate subsets starting from index 0
    backtrack(arr, n, 0, subset, 0);

    return 0;
}

