#include <bits/stdc++.h>
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
	char t[101];
    fastio;
    cin>>t;
    int l=strlen(t);
    int zc=0,oc=0;
    int f=0;
    rep(i,l,0)
    {
        if(t[i]=='1')
        {
            zc=0;
            oc++;
        }
        else
        {
            oc=0;
            zc++;
        }
        if(zc==7 || oc==7)
        {
            f=1;
            break;
        }

    }
    if(f)
    cout<<"YES";
    else
    cout<<"NO";
}

