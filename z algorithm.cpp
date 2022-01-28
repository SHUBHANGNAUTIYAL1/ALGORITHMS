
#include<bits/stdc++.h>
using namespace std;
void calcarray(string s,int ls[],int c)
                                       
{
    int l=0;
    int r=0;
    int i;
    int a=s.length();
    for( i=1;i<a;i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while(i<a && s[r]==s[r-l])
            r++;
            ls[i]=r-l;
            r--;
            
        }
        else
        {
           int  k=i-l;
            if(ls[k]<=r-i+1)
            {
                ls[i]=ls[k];
            }
          
            else 
                l=i;
                 while(i<a && s[r]==s[r-l])
                  r++;
            ls[i]=r-l;
            r--;
            }
        }
    }
    
}
void z(string s, string p)
{
    string k=p+"$"+s;
    int a=p.length();
    int len=k.length();
    int ls[len];
    calcarray(k,ls,a);
    for(int i=0;i<len;i++)
    {
        if(ls[i]==a)
        cout<<"pattern found at index"<<i-(a+1);
    }
    
}
int main()
{
    string s="aaaa";
    string p="aaa";
    z(s,p);
    
}
