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


int main()
{
    int n,k;
    cin>>n>>k;
    vi a(n),hash(110,0);

    rep(i,n+1,1)
    {
        cin>>a[i];
    }      

    int team=0,t;
    t=k;

    rep(i,n+1,1)
    {
        if(k)
        {
            if(hash[a[i]]==0)
            {
                hash[a[i]]=1;
                k--;
            }
        }
        else
        break;
    }

    if(k)
    cout<<"NO";
    else
    {
        cout<<"YES"<<endl;
        for(int i=1;i<n+1;i++)
        {
            if(hash[a[i]]==1)
            {
             cout<<i<<" ";
             hash[a[i]]=0;
            }
        }
    }
    nl;
}