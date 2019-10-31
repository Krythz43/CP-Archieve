#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    map <ipair,int> M;
    vector<string> a(n);
    rep(i,n,0)
    cin>>a[i];

    int f=0;
    rep(i,n-1,1)
    {rep(j,m-1,1)
    if(a[i][j]=='*' && a[i+1][j]=='*' && a[i-1][j]=='*' && a[i][j+1]=='*' && a[i][j-1]=='*')
    {
        f=1;
        M[mp(i,j)]++;
        for(int k=i+1;k<n;k++)
        {
            if(a[k][j]=='*')
            M[mp(k,j)]++;
            else
            break;
        }

        for(int k=i-1;k>=0;k--)
        {
            if(a[k][j]=='*')
            M[mp(k,j)]++;
            else
            break;
        }

        for(int k=j+1;k<m;k++)
        {
            if(a[i][k]=='*')
            M[mp(i,k)]++;
            else
            break;
        }

        for(int k=j-1;k>=0;k--)
        {
            if(a[i][k]=='*')
            M[mp(i,k)]++;
            else
            break;
        }
        break;
    }
    if(f)
    break;
    }

    rep(i,n,0)
    rep(j,m,0)
    {
        if(a[i][j]=='*' && M.count(mp(i,j))==0)
        {
            f=0;
            break;
        }
    }

    if(f)
    cout<<"YES";
    else
    cout<<"NO";
    nl;
}