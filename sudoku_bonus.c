#include <stdio.h>
#include <stdlib.h> //for the exit codes

int row_check(int sudoku_array[9][9]);
/****************************************
 * name: row_check
 * input: sudoku_array[9][9]
 * *output: 1 or 0 aka true or false
 * *purpose: to take in sudoku and check 
 * *all the rows to see if there are repeating
 * *number 1-9.
*****************************************/

int column_check(int sudoku_array[9][9]);
/****************************************
 * name: column_check
 * input: sudoku_array[9][9]
 * output: 1 or 0 aka true or false
 * purpose: to take in sudoku and check 
 * all the columns to see if there are 
 * repeating number 1-9.
*****************************************/

int house_check(int sudoku_array[9][9]);
/****************************************
 * name: house_check
 * input: sudoku_array[9][9]
 * output: 1 or 0 aka true or false
 * purpose: to take in sudoku and check 
 * all the houses to see if there are 
 * repeating number 1-9.
*****************************************/

int main(int argc, char* argv[])
{
    /*
    if (argc != 2)
    {
        printf("Please enter sudoku data and run ./a.out again\n");
        exit(33);
    }
    */
    int sudoku_array[9][9];//array to hold sudoku 

    FILE *fptr;
    fptr = fopen(argv[1], "r+"); //reads second line of cmd line args


    
    if (fptr == NULL) 
    {
        printf("File did not open correctly\n");
        exit(4);
    }

    
    for (int i = 0; i < 81; i++) //reads in all 81 numbers in the sudoku
    {
        for (int j = 0; j < 81; j++)
        {
            fscanf(fptr, "%d", &sudoku_array[i][j]);
        }
    }
    
    
    for (int i = 0; i < 9; i++) //displays the sudoku
    {
        for (int j = 0; j < 9; j++) 
        {
            printf("%d ", sudoku_array[i][j]);
        }
        printf("\n");
    }

   //row_check(sudoku_array); if you have these  
   //column_check(sudoku_array); individually run it will repeat
   //house_check(sudoku_array); the error 2 times


    // this prints out whether the solution is valid or not, and what is wrong when invalid
   if (row_check(sudoku_array) == 1 && column_check(sudoku_array) == 1 && house_check(sudoku_array) == 1) 
    {
        printf("this is a valid solution\n");
    }
    else
    printf("this is a invalid solution\n");


    return 0;
}


int row_check(int sudoku_array[9][9]) 
{
    int c[10]={0,0,0,0,0,0,0,0,0,0};// place holder array to check if there are repeated values
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            c[sudoku_array[i][j]]++; // used to check each row
        }
        for (int k = 1; k <= 9; k++)
        {
            if (c[k] != 1)
            {
                printf("the value %d came %d times in row #%d\n", k, c[k], i+1);
                return 0;
            }
        }
        for (int k = 1; k <= 9; k++)
            {
                c[k]= 0; //resets c array to loop back and check another row
            }
    }
    return 1;
}

int column_check(int sudoku_array[9][9])
{
    int c[10] = {0};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            c[sudoku_array[j][i]]++; //same thing as row function but swapped i and j for the columns
        }
        for (int k = 1; k <= 9; k++)
        {
            if (c[k] != 1)
            {
                printf("the value %d came %d times in columns #%d\n", k, c[k], i+1);
                return 0;
            }
            
            
        }
        for (int k = 1; k <= 9; k++)
            {
                c[k]=0;
            }  
    }
    return 1;
}

int house_check(int sudoku_array[9][9])
{
    int c[10]= {0}, count = 0; // count is for counting the houses
    for (int m = 0; m < 9; m+=3)
    {
        for (int b = 0; b < 9; b+=3) // m and b variables counts by 3's for the spaces between houses
        {
            for (int i = m; i < m+3; i++)
            {
                for (int j = b; j < b+3; j++)
                {
                    c[sudoku_array[i][j]]++; //checks inside the house
                }
            }
            count++; //finished 1st house
            for (int k = 1; k <= 9; k++)
            {
                if (c[k] != 1)
                {
                    printf("the value %d came %d times in house #%d\n", k, c[k], count);
                    return 0;
                }
            }
            for (int k = 1; k <= 9; k++)
                {
                    c[k] = 0; //resets the check array
                }
        }
        
    }
    return 1;
}