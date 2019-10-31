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
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}


int nextele(int x)
{
 
 int r;
 int rp1;
 int r1p;
 int next = 0;
 
  if(x)
  {
    r = x & -(signed)x;
    rp1 = x + r;
    r1p = x ^ rp1;
    r1p = (r1p)/r;
    r1p >>= 2;
    next = rp1 | r1p;
  }
 
  return next;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d;
        cin>>a;
        b=a;
        int ans1=0,ans2=0;

        if(__builtin_popcount(a)==1)
        {
            if(a==1)
            cout<<2;
            else
            cout<<1;
        }
        else if(__builtin_popcount(a)==2)
        {
            cout<<0;
        }
        else
        {
            c=a;
            int n=__builtin_popcount(a);
            
            rep(i,n-1,0)
            {
                b=(b)&(b-1);
            }
            c-=b;
            d=b;
            b=a;
            rep(i,n-2,0)
            {
                b=(b)&(b-1);
            }
            b-=d;
            c-=b;
            ans1=a-c;
            ans2=nextele(ans1);
            cout<<min(a-ans1,ans2-a);
        }
        nl;
    }
}