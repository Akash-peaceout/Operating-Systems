// C program to generate odd sized magic squares
 #include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
 
// Driver program to test above function
int main()
{
    int n = 7; // Works only when n is odd
    int magicSquare[n][n];
 
    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));
 
    // Initialize position for 1
    int i = n/2;
    int j = n-1;
    pid_t pid;        
    pid = vfork();

    // One by one put all values in magic square
    if(pid==0)
    {
    for (int num=1; num <= n*n; )
    {
        if (i==-1 && j==n) //3rd condition
        {
            j = n-2;
            i = 0;
        }
        else
        {
            //1st condition helper if next number 
            // goes to out of square's right side
            if (j == n)
                j = 0;
            //1st condition helper if next number 
            // is goes to out of square's upper side
            if (i < 0)
                i=n-1;
        }
        if (magicSquare[i][j]) //2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; //set number
 
        j++; i--; //1st condition
    }
    exit(0);
  }
  else
  {
    // Print magic square
    wait(NULL);
    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n",
            n, n*(n*n+1)/2);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}
    return 0;
}