#include <bits/stdc++.h> 
using namespace std; 
#define lli long long int
lli fact(lli n); 
  

lli nCr(lli n, lli r) 
{ 
  
    long long p = 1, k = 1; 
    if (n - r < r) 
        r = n - r; 
  
    if (r != 0) 
    { 
        while (r) 
        { 
            p*=n; 
            k*=r; 
            lli m=__gcd(p, k); 
            p/=m; 
            k/=m; 
            n--; 
            r--; 
        } 
    } 
  
    else
        p = 1; 
    return p;
} 
int main() 
{ 
    lli t;

    cin>>t;
    while(t--)
    {
        lli n,r;
        cin>>n>>r;
        cout << nCr(n-1, r-1)<<endl;
    } 
    return 0; 
} 