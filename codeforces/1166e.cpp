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
    int n,m;
    cin>>m>>n;
    vector<int> a[m];
    vector<int> hash(n+1,0);
    int t,x;
    rep(i,m,0)
    {
        cin>>t;
        // cout<<"s1"<<endl;
        vector<int> hash1(n+1,0);
        rep(j,t,0)
        {
            cin>>x;
            a[i].pb(x);
            hash1[x]++;
        }
        rep(j,n+1,0)
        {
            if(hash1[j]==0)
            hash[j]++;
        }
    }

    rep(i,m,0)
    {
        int f=0;

        // cout<<"s2"<<endl;
        rep(j,a[i].size(),0)
        {
            if(hash[a[i][j]]==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"impossible"<<endl;
            return 0;
        }
    }

    cout<<"possible"<<endl;
}
