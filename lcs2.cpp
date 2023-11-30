#include<iostream>
using namespace std;

int lcs(int **mat, int row, int &col, string &a, string &b)
{
    for(int i=1; i<row; i++)
    {
        for(int j=1; j<col; j++)
        {
            // cout<<i<<" "<<j<<endl;
            if(a[j-1]==b[i-1]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
        }
    }
    return mat[row-1][col-1];
}




int main()
{
    
string a,b; //a is badi wali string
cin>>a>>b;

int col=a.size()+1, row= b.size()+1;

int **mat=new int*[row];
for(int i=0; i<row; i++) mat[i]=new int[col];

for(int i=0; i<col; i++) mat[0][i]=0;
for(int i=0; i<row; i++) mat[i][0]=0;

cout<<"length of lcs is "<<lcs(mat,row,col,a,b)<<endl;

int i=row-1, j=col-1;

string s="";
while(j>0 && i>0)
{
    cout<<i<<" "<<j<<endl;
    if(mat[i][j]!=max(mat[i-1][j], mat[i][j-1])) 
    {
        s=s+a[j-1];
        i--;
        j--;
    }
    else j--;

    if(j==0 && i>1)
    {
        i--;
        j=col-1;
    }
}

string t="";
for(int i=s.size()-1; i>=0; i--) t+=s[i];

cout<<" The lcs is: "<<t;



return 0;
}