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
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    vinput(b,n);
    unordered_map<int,int> M;
    rep(i,n,0)
    {
        if(a[i])
        M[a[i]]=-1;
    }
    rep(i,n,0)
    {
        if(b[i])
        M[b[i]]=i+1;
    }
    int ans=0;
    int f=1;
    int c=1;

    if(M[1]>0)
    {
        for(int i=M[1]-1;i<n;i++)
        {
            if(b[i]!=c)
            {
                f=0;
                break;
            }
            c++;
        }
        if(f)
        {
            for(int i=c;i<=n;i++)
            {
                if(M[c]<=ans)
                {
                    ans++;
                    c++;
                }
                else
                {
                    cout<<n+M[1]<<endl;
                    return 0;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }

    ans=0;
    c=1;
    int wait=0;
    for(int i=1;i<=n;i++)
    {
        if(M[c]<=ans)
        {
            c++;
            ans++;
        }
        else{
            ans=M[c]+1;
            c++;
        }
    }
    cout<<ans<<endl;
}
