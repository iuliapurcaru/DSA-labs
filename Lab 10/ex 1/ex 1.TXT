#include <stdio.h>

int sudoku[9][9] = {0, 0, 0, 0, 0, 0, 0, 0, 8,
                    1, 8, 0, 0, 0, 2, 3, 0, 0,
                    0, 6, 0, 0, 5, 7, 0, 0, 1,
                    0, 7, 0, 9, 6, 0, 0, 0, 0,
                    0, 9, 0, 7, 0, 4, 0, 1, 0,
                    0, 0, 0, 0, 8, 1, 0, 4, 0,
                    6, 0, 0, 2, 4, 0, 0, 8, 0,
                    0, 0, 4, 5, 0, 0, 0, 9, 3,
                    5, 0, 0, 0, 0, 0, 0, 0, 0
                   };

void print_sudoku()
{
    int i, j;

    for(i = 0; i < 9; i++)
    {

        for(j = 0; j < 9; j++)
        {
            if(j == 2 || j == 5)
                printf("%d   ", sudoku[i][j]);
            else
                printf("%d ", sudoku[i][j]);
        }
        if(i == 2 || i == 5)
            printf("\n");
        printf("\n");
    }
}

int check(int row, int col, int n)
{
    int i, j;

    for(i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == n)
            return 0;
    }

    for(j = 0; j < 9; j++)
    {
        if(sudoku[j][col] == n)
            return 0;
    }

    row -= row % 3;
    col -= col % 3;

    for(i = row; i < row + 3; i++)
        for(j = col; j < col + 3; j++)
        {
            if(sudoku[i][j] == n)
                return 0;
        }

    return 1;
}

int solve_sudoku(int row, int col)
{

    if(row == 8 && col == 9)
        return 1;

    int n;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    if(sudoku[row][col] > 0)
        return solve_sudoku(row, col + 1);

    for(n = 1; n <= 9; n++)
    {
        if(check(row, col, n) == 1)
        {
            sudoku[row][col] = n;
            if(solve_sudoku(row, col + 1))
                return 1;
        }

        sudoku[row][col] = 0;

    }
    return 0;
}

int main()
{

    if (solve_sudoku(0, 0) == 1)
        print_sudoku(sudoku);
    else
        printf("Nu exista rezolvare\n");

}
