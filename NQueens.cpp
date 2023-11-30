#include<bits/stdc++.h>

using namespace std;

int issafe(int result[],int x2,int y2)
{
    for(int i=0;i<x2;i++)
    {
        if(result[i]==y2 || abs(i-x2)==abs(result[i]-y2))
        {
            return 0;
        }
        
    }
    return 1;
}
void placequeens(int result[],int x,int size)
{
    for(int i=0;i<size;i++)
    {
        if(issafe(result,x,i)==1)
        {
            result[x]=i;
            if(size-1==x)
            {
                printf("Solution found   ");
                for(int i=0;i<size;i++)
                {
                    cout<<result[i]<<" ";
                }
                cout<<endl;
            }
            placequeens(result,x+1,size);
        }
    }
}

int main()
{
    int result[5];
    placequeens(result,0,5);
    return 0;
}