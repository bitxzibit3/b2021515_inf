//
// Created by Timur on 04.03.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "dialog_menu.h"

const char *MSGS[] = {"0. Quit", "1. Sum two matrix", "2. Multiple two matrix", "3. Transpose matrix", "4. Change type of variables"};

const char *ERRORS[] = {"Different types of variables!", "Incorrect dimensions!"};

const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int variable_choise (const int COUNT_OF_VARIABLES)
{
    puts("What type of variables do you wanna use?");
    puts("1 - complex");
    puts("2 - integer");
    int choise;
    while ((scanf("%d", &choise) == 0) || ((choise > COUNT_OF_VARIABLES) || (choise < 1)))
        puts("Error, please try again!");
    return choise;
}

int check_dimensions (int a, int b)
{
    if ((a > 0) && (b > 0))
        return 1;
    else
        return 0;
}

void dialog_menu (const int COUNT_OF_VARIABLES) {
    int choise, errorCode = 111, var = variable_choise(COUNT_OF_VARIABLES);
    while (1) {
        puts("What do you wanna do?");
        for (size_t i = 0; i < MSGS_SIZE; i++)
            puts(MSGS[i]);
        while ((scanf("%d", &choise) == 0) && ((choise < 0) || (choise >= MSGS_SIZE)))
            puts("Error, please try again!");
        if ((var == 1) && (choise))
            puts("The complex number is written as \"a b\", and it is equal to (a + bi)");
        switch (choise) {
            case (0): {
                puts("Good bye!");
                return;
            }
            case (1): {
                puts("Enter first matrix's dimensions :");
                int lin1, col1;
                scanf("%d %d", &lin1, &col1);
                puts("Enter second matrix's dimensions :");
                int lin2, col2;
                scanf("%d %d", &lin2, &col2);
                if (!(check_dimensions(lin1, col1) * check_dimensions(lin2, col2)))
                {
                    puts (ERRORS[1]);
                    break;
                }
                puts("Enter first matrix :");
                switch (var) {
                    case (1): {
                        Matrix *rez = sumCMatrix(lin1, col1, lin2, col2, &errorCode);
                        if (errorCode == 111) {
                            puts("Result of sum :");
                            printCMatrix(rez);
                            deleteMatrix(rez);
                        }
                        else
                            puts (ERRORS[errorCode]);
                        break;
                    }
                    case (2): {
                        Matrix *rez = sumIntMatrix(lin1, col1, lin2, col2, &errorCode);
                        if (errorCode == 111) {
                            puts("Result of sum :");
                            printIntMatrix(rez);
                            deleteMatrix(rez);
                        }
                        else
                            puts (ERRORS[errorCode]);
                        break;
                    }
                    default: {
                        puts("You entered a wrong number, try again!");
                        break;
                    }
                }
                break;
            }
            case (2): {
                puts("Enter first matrix's dimensions :");
                int lin1, col1;
                scanf("%d %d", &lin1, &col1);
                puts("Enter second matrix's dimensions :");
                int lin2, col2;
                scanf("%d %d", &lin2, &col2);
                if (!(check_dimensions(lin1, col1) * check_dimensions(lin2, col2)))
                {
                    puts (ERRORS[1]);
                    break;
                }
                puts("Enter first matrix :");
                switch (var) {
                    case (1): {
                        Matrix *rez = multCMatrix(lin1, col1, lin2, col2, &errorCode);
                        if (errorCode == 111) {
                            puts("Result of mult :");
                            printCMatrix(rez);
                            deleteMatrix(rez);
                        }
                        else
                            puts (ERRORS[errorCode]);
                        break;
                    }
                    case (2): {
                        Matrix *rez = multIntMatrix(lin1, col1, lin2, col2, &errorCode);
                        if (errorCode == 111) {
                            puts("Result of mult :");
                            printIntMatrix(rez);
                            deleteMatrix(rez);
                        }
                        else
                            puts (ERRORS[errorCode]);
                        break;
                    }
                    default:{
                        puts("You entered a wrong number, try again!");
                        break;
                    }
                }
                break;
            }
            case (3):
            {
                puts("Enter matrix's dimensions :");
                int lin, col;
                scanf("%d %d", &lin, &col);
                if (!check_dimensions(lin, col))
                {
                    puts (ERRORS[1]);
                    break;
                }
                Matrix *rez = NULL;
                puts ("Enter your matrix :");
                switch (var) {
                    case (2): {
                        Matrix *temp = newIntMatrixValue(lin, col);
                        rez = matrixTranspose(temp);
                        puts("Result of transpose :");
                        printIntMatrix(rez);
                        deleteMatrix(temp);
                        deleteMatrix(rez);
                        break;
                    }
                    case (1): {
                        Matrix *temp = newCMatrix(lin, col);
                        rez = matrixTranspose(temp);
                        puts("Result of transpose :");
                        printCMatrix(rez);
                        deleteMatrix(temp);
                        deleteMatrix(rez);
                        break;
                    }
                    default:{
                        puts("You entered a wrong number, try again!");
                        break;
                    }
                }
                break;
            }
            case (4):
            {
                var = variable_choise(COUNT_OF_VARIABLES);
                choise = 4;
                break;
            }
            default:
            {
                choise = 5;
                puts("You entered a wrong number, try again!");
                break;
            }
        }
    }
}