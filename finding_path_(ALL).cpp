/*
We have to find a path from starting position to ending position,
by visiting all the cells only once, we can't visit a cell twice.

This code will print all the paths if exist.
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int flag=0;
void printPath(vector<int> temp)
{
    flag=1;
    cout<<endl;
    for(auto it: temp)
        cout<<it<<"-";
}

void dfs(vector<vector<int>> ar, int row, int col, int i, int j,int end,vector<int>temp)
{
   temp.push_back(ar[i][j]);
   //if all cells are visited and we are on the ending cell then return true
   if(ar[i][j]==end && temp.size()==row*col)
       {printPath(temp);
       return;}
   
   //if we reach ending cell first and other cells are not visited return false
   else if(ar[i][j]==end)
     return;
   
   //marking cells as visited - 0
   int x = ar[i][j];
   ar[i][j]=0;
   
   //top
   if(i-1>=0 && ar[i-1][j]!=0)
      dfs(ar, row,col, i-1, j,end,temp);
        
   
   //left
   if(j-1>=0 && ar[i][j-1]!=0)    
      dfs(ar,row,col, i, j-1,end,temp);
    
    //right
   if(j+1<col && ar[i][j+1]!=0)
      dfs(ar, row, col, i, j+1,end,temp);
        
    
    //down
    if(i+1 < row && ar[i+1][j]!=0)
        dfs(ar, row, col, i+1, j,end,temp);
       
    temp.pop_back();
    ar[i][j]=x;
}


int main() 
{
   vector<vector<int>> ar;
   vector<int> temp;
   ar={
     {1,2,3,4},
     {5,6,7,8},
     {9,10,11,12},
     {13,14,15,16}
   };
   int row = ar.size();
   int col = ar[0].size();
   
   int start,end;
   cout<<"Enter Starting Position : ";
   cin>>start;
   cout<<"Enter Ending Position : ";
   cin>>end;
   
   int s_i,s_j;  
   
   // finding the location of the starting position 
   for(int i=0; i<row; i++)
     for(int j=0; j<col; j++)
        if(ar[i][j] == start)
            {s_i=i;
            s_j=j;}
            
   dfs(ar,row,col, s_i, s_j,end,temp);
   if(!flag)
    cout<<endl<<"No Path Found";
}
