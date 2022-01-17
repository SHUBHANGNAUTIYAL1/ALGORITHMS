#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int u)
{
    int i=l;
    int j=m+1;
    int k=l;
    int b[8];
    while(i<=m && j<=u)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>m)
    {
        while(j<=u)
        {
        b[k]=a[j];
        j++;
        k++;
        }
    }
    else
    {
        while(i<=m)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    for(k=l;k<=u;k++)
    a[k]=b[k];
    
}
void mergesort(int a[],int l,int u)
{
    
    if(l<u)
    {
       int m= l + (u - l) / 2;
        mergesort(a,l,m);
        mergesort(a,m+1,u);
        merge(a,l,m,u);
    }
}
int main()
{
    int a[]={9,3,7,5,6,4,8,2};
    mergesort(a,0,7);
    for(int i=0;i<=7;i++)
    cout<<a[i]<<" ";
    
}