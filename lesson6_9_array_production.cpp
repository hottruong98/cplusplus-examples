/*Goal: practice using multidimensional arrays.
**Write a program that will accept values for a 4x4 array 
**and a vector of size 4. 
**Use the dot product to multiply the array by the vector. 
**Print the resulting vector. 
*/

#include <iostream>
#include <stdio.h>
int main()
{
    int A[4][4];
    int B[4];
    int C[4] = {0, 0, 0, 0}; //C=A*B
    //TODO: multiply a 4x4 array with vector of size 4.
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i] += A[i][j] * B[j];
        }
    }

    //Print the resultant product vector
    for (int i = 0; i < 4; i++)
    {
        std::cout << "C[" << i << "] = " << C[i] << std::endl;
    }
    return 0;
}