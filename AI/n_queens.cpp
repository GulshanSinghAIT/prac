#include<bits/stdc++.h>
using namespace std;


bool isSafe(vector<vector<int>>&mat,int row,int col)
{
    // check this col on upper side
    
    int n=mat.size();
    
    for(int i=0;i<row;i++)
    {
        if(mat[i][col])
        {
            return false;
        }
    }
    
    // check upper left diagnal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(mat[i][j])
        return false;
    }
    
    // check upper right diagonal
    
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(mat[i][j])return false;
    }
    
    return true;
}

int place_queens(vector<vector<int>>&mat,int row)
{
    // base case
    int n=mat.size();
    
    if(row==n) return 1;
    
    // checking for multiple recurrences , use for loop
    
    for(int i=0;i<n;i++)
    {
       if(isSafe(mat,row,i))
       {
           mat[row][i]=1;
           
           if(place_queens(mat,row+1))return 1;
           
           
           mat[row][i]=0;
       }
    }
    
    return 0;
}

signed main()
{
   int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    int ans = place_queens(mat, 0);

    if (ans) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}