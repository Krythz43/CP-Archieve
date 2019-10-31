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

vector <vi > a(1000,vector <int> (1000));
vector <vi > ans(1000,vector <int> (1000));

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        string s;
        rep(i,n,0)
        {
            cin>>s;
            rep(j,m,0)
            {a[i][j]=s[j]-48;
            ans[i][j]=(a[i][j]==1?0:-1);}
        }

        //1s
        int f=0;

        // displaymatrix(a,m,n)
        rep(i,n,0)
        rep(j,m,0)
        {
            if(a[i][j]==1)
            {
                rep(k,n,0)
                {
                    if(ans[k][j]==-1)
                    {ans[k][j]=1;f=1;}
                }

                rep(k,m,0)
                {
                    if(ans[i][k]==-1)
                    {ans[i][k]=1;f=1;}
                }
            }
        }

        if(f)
        {
            rep(i,n,0)
            rep(j,m,0)
            if(ans[i][j]==-1)
            ans[i][j]=2;
        }

        displaymatrix(ans,n,m)
    }
}