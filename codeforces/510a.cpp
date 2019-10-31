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

void line(int n)
{
    rep(i,n,0)
    cout<<"#";
    nl;
}

void leftie(int n)
{
    cout<<"#";
    rep(i,n,0)
    cout<<".";
    nl;
}

void rightie(int n)
{
    rep(i,n,0)
    cout<<".";
     cout<<"#";
     nl;
}
int main()
{
    fastio;
    int n,m;
    cin>>n>>m;

    rep(i,n,0)
    {
        if(i%2==0)
        line(m);
        else
        if((i+1)%4==0)
        leftie(m-1);
        else
        rightie(m-1);
    }
}