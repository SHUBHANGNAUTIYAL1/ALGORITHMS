#include<bits/stdc++.h>
using namespace std;
void list1(string s,int *ls,int m)
{
    int i=1;
    int len=0;
    ls[len]=0;
    
    while(i<m)
    {
        if(s[i]==s[len])
        {
            len++;
            ls[i]=len;
            i++;
        }
        if(s[i]!=s[len])
        {
            if(len!=0)
            {
                len=ls[len];
            }
            else
            {
            ls[i]=0;
            i++;
            }
            
        }
    }
   
}
void kmp(string s,string p)
{
    vector<int>v;
    int temp;
    int n=s.length();
    int m=p.length();
    int ls[m];
    list1(p,ls,m);
    int i=0;
    int j=0;
    while(i<n)
    {
         
        
        if(s[i]==p[j])
        {
            i++;
            j++;
        }
        else if(i<n && s[i]!=p[j])
        {
            if(j==0)
            {
                i++;
                
            }
            else 
            j=ls[j-1];
        
        }
        if(j==m)
        {
            cout<<"Found pattern at index ==>"<< i-j;
            j = ls[j - 1];
            
        }
       
    }
    
   
}
int main()
{
    string s="ababcabcabababd";
    string p="ababd";
    kmp(s,p);
}