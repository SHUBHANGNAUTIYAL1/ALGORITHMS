#include<bits/stdc++.h>
using namespace std;
void countsort(int a[],int n,int k)
{
    int count[k+1]={0};
    int b[n];
    for(int i=0;i<n;i++)// counting frequency of each element and storing in count array
    {
        ++count[a[i]];
    }
    for(int i=1;i<=k;i++)// calculating the actual positions of element
    count[i]=count[i]+count[i-1];
    
    for(int i=n-1;i>=0;i--)//building the output array using original array as well as count array
    b[--count[a[i]]]=a[i];
    
    for(int i=0;i<n;i++)
    a[i]=b[i];
}
int main()
{
    int a[]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    countsort(a,17,9);
    for(int i=0;i<17;i++)
    cout<<a[i]<<" ";
}