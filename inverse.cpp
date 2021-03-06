#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
using namespace std;
 
int main(){
    int mat[3][3], i, j;
    float determinant = 0;
    
    cout<<"Enter elements of matrix:\n";
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
           cin>>mat[i][j];
    
     

    pid_t pid=vfork();
    
    if(pid==0)
    
   {
    //finding determinant
    for(i = 0; i < 3; i++)
        determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    
    cout<<"\n\ndeterminant: "<<determinant;
    
  exit(0);   
}


    else

   {
    
    wait(NULL);
    cout<<"\n\nInverse of matrix is: \n";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            cout<<((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant<<"\t";
        
        cout<<"\n";
    }
  }
 
   return 0;
}
