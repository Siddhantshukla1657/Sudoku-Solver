#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function prototypes
void printGrid(int grid[SIZE][SIZE]);
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int grid[SIZE][SIZE]);
void inputGrid(int grid[SIZE][SIZE]);

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a number
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) { // Find an empty cell
                for (int num = 1; num <= SIZE; num++) { // Try numbers 1-9
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num; // Place number
                        if (solveSudoku(grid)) { // Recur
                            return true;
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; // Trigger backtrack
            }
        }
    }
    return true; // Solved
}

// Function to input the Sudoku grid from user
void inputGrid(int grid[SIZE][SIZE]) {
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int grid[SIZE][SIZE];

    inputGrid(grid);

    printf("\nOriginal Sudoku Puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku Puzzle:\n");
        printGrid(grid);
    } else {
        printf("No solution exists!\n");
    }

    return 0;
}
