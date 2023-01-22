#include <stdio.h>
#include <stdlib.h>
/*
    dynamicMatrix struct
    ---------------------
    Defines a struct that holds a pointer to pointers that builds a dynamic matrix
    It holds the value of rows and cols too
*/
typedef struct dynamicMatrix
{
    int rows;
    int cols;
    int** Matrix;
    
}dMatrix;

/*Prototyping of the functions*/
dMatrix createMatrix(int rows, int columns);
void printMatrix(dMatrix matrix);
int* matrixSize(int** arr);
void populateMatrix(dMatrix *matrix);
int sumAllValueInMatrix(dMatrix *matrix);

/*Code Entrypoint*/
int main()
{
    dMatrix myMatrix;
    int rows, cols, sum;
    char pFlag;
    
    printf("Please enter the number of rows of the matrix: ");
    scanf("%d", &rows);

    printf("Please enter the number of cols of the matrix: ");
    scanf("%d", &cols);

    myMatrix = createMatrix(rows,cols);

    printf("Whishes to fill the matrix with values ? Y or N: ");
    scanf(" %c", &pFlag);

    switch (pFlag)
    {
    case 'Y':
        populateMatrix(&myMatrix);
        break;
    case 'N':
        printf("Inserting '0' as default values... \n");
        break;
    default:
        printf("Invalid response: Inserting '0' as default values...\n");
        break;
    }
    system("cls");    
    printf("--------------------------------------------------------------------\n");
    printMatrix(myMatrix);
    printf("--------------------------------------------------------------------\n");
    sum = (int)sumAllValueInMatrix(&myMatrix);
    printf("Matrix rows: %d\nMatrix columns: %d\nSum of all ellements: %d\nMatrix area: %d\n", myMatrix.rows, myMatrix.cols
    ,sum, myMatrix.rows*myMatrix.cols);
    printf("--------------------------------------------------------------------\n");
    char fFlag;
    FILE *filePointer;
    printf("Whish to print array into a file ? Y or N: ");
    scanf(" %c", &fFlag);

    switch (fFlag)
    {
    case 'Y':
        filePointer = fopen("array.txt", "w");
        for(int i = 0; i < myMatrix.rows; i++)
        {
            for(int j = 0; j < myMatrix.cols; j++)
            {
                fprintf(filePointer,"%5d ", myMatrix.Matrix[i][j]);
            }
            fprintf(filePointer, "\n");
        }
        fclose(filePointer);
        break;
    default:
        break;
    }
    system("cls");
    return 0;
}

/*
    Create matrix function
    ----------------------
    Returns a dMatrix struct (def: line 10)
    It gets rows and columns as parameters
    Alocates memory for the rows, and iterates 
    trough every row alocating memory for the columns
*/
dMatrix createMatrix(int rows, int columns)
{
    int** temp;
    dMatrix matrix;

    matrix.rows = rows;
    matrix.cols = columns;

    temp = (int**)malloc(rows*sizeof(int*));
    if(temp != NULL)
    {
        matrix.Matrix = temp;
        
        for (int i = 0; i < rows; i++)
        {
            matrix.Matrix[i] = (int*)malloc(columns*sizeof(int));
            for(int j = 0; j < columns; j++)
            {
                matrix.Matrix[i][j] = 0;
            }
        } 
        printf("Matrix created succesfully\n");
        return matrix;
    }else{
        printf("Error allocating memory for the matrix\n");
        matrix.rows = 0;
        matrix.cols = 0;
        matrix.Matrix = NULL;
        return matrix;
    }
}

/*
    printMatrix function
    --------------------
    Gets a dMatrix struct (def: line 10) as parameter
    iterates trough the matrix inside the struct and 
    prints its values.
*/
void printMatrix(dMatrix matrix)
{
    for(int i = 0; i < matrix.rows; i++)
    {
        for(int j = 0; j < matrix.cols; j++)
        {
            printf("%5d ", matrix.Matrix[i][j]);
        }
        printf("\n");
    }
}

/*
    populateMatrix function
    -----------------------
    gets a pointer to the dMatrix struct (def: line 10)
    and populates its values by iterating trough them
    asking the user to insert a value that will inserted 
    in the specific matrix position
*/
void populateMatrix(dMatrix *matrix)
{
    int val;
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j<matrix->cols; j++)
        {
            printf("Enter a value to the [%d][%d] position in the matrix: ", i, j);
            scanf("%d", &val);

            matrix->Matrix[i][j] = val;
        }
    }
}

/*
    sumAllValueInMatrix Function
    ----------------------------
    Gets the pointer of a dMatrix struct (def: line 10)
    iterates trough all of its values, adding all of its values
    on a sum variable, returning this value.
*/
int sumAllValueInMatrix(dMatrix *matrix)
{
    int sum = 0;

    for (int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < matrix->cols; j++)
        {
            sum = sum + matrix->Matrix[i][j];
        }
    }

    return sum;
}