#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
       return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main()
{
   fastio;
   int t;
   cin>>t;
   while(t--)
   {
       lli num=0,den=1,ze;
       char s[20];
       cin>>s;
       int l=strlen(s);

       rep(i,l,0)
       {
           if(s[i]=='.')
           ze=i;
           else
           {
               num=num*10+s[i]-'0';
           }
       }
       den=pow(10,l-ze-1);

    //    cout<<num<<" "<<den<<endl;
    lli x=gcd(num,den);
    if(x)
    cout<<den/x<<endl;
    else
    cout<<"0"<<endl;

   }   
}