#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false)
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
#define priority_queue pq;
#define displaymatrix(a,m,n) for(int i=0;i<m;i++){for(int j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}

#define mod 1000003


int main()
{
    fastio;
    char s[101],d[101];
    cin>>s>>d;
    int l1=strlen(s),l2=strlen(d);

    rep(i,l1,0)
    {
        if(s[i]>96)
        s[i]=(char)(s[i]-32);
    }
    rep(i,l2,0)
    {
        if(d[i]>96)
        d[i]=(char)(d[i]-32);
    }

    if(strcmp(s,d)==0)
    cout<<"0";
    else if( strcmp(s,d)>0)
    cout<<"1";
    else cout<<"-1";
}