#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <int,int>
#define pq priority_queue
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

lli multi (lli x,int n)
{
    if(n==0)
    return 1;
    if(n==1)
    return x;
    if(n%2==0)
    return multi(x*x,n/2);
    else
    return x*multi(x*x,n/2);
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m,c=0;
        cin>>n>>m;
        vi a(n);
        rep(i,n,0)
        {
            cin>>a[i];
            if(a[i]%m==0)
            c++;
        }
        cout<<multi(2,c)-1<<endl;
    }
} 