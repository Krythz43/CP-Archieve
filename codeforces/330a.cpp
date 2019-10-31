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
    fastio;
    int r,c,a[15][15];
    char ch[11];
    cin>>r>>c;
    rep(i,r,0)
    {
        cin>>ch;
        rep(j,c,0)
        {
            if(ch[j]=='S')
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;
            }
        }
    }

    rep(i,r,0)
    {
        int f=1;
        rep(k,c,0)
        {
            if(a[i][k]==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            rep(k,c,0)
            {
                a[i][k]=2;
            }
        }   

    }

    rep(j,c,0)
    {
        int f=1;
        rep(i,r,0)
        {
            if(a[i][j]==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {
            rep(i,r,0)
            {
                a[i][j]=2;
            }
        }   

    }

    int co=0;

    rep(i,r,0)
    rep(j,c,0)
    if(a[i][j]==2)
    co++;
    cout<<co;
}