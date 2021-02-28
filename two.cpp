#include<bits/stdc++.h>
using namespace std;
int computeLPSArray(string pat, int M, int lps[]) 
{ 
    int j = 0; 
    lps[0] = 0;
    int i = 1; 
    while (i < M) 
    { 
        if (pat[i] == pat[j]) 
        { 
            j++;
            lps[i] = j; 
            i++; 
        } 
        else 
        {
            if (j != 0) 
            { 
                j = lps[j-1]; 
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    return lps[M-1]; 
}  

int main()
{
string txt="AACECAAAA";
string rev=txt;
reverse(rev.begin(),rev.end());
string concat=txt+"$"+rev;
int n=concat.length();
    
int lps[n]={0};

cout<<"Minimum characters to add in beginning of string is "<<txt.length()-computeLPSArray(concat,n,lps);

}