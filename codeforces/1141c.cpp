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
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
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
    vlli ans;
    ans.pb(0);
    lli s=0,x,maxi=-INT_MAX;
    rep(i,n-1,0)
    {
        cin>>x;
        s+=x;
        ans.pb(s);
        maxi=max(maxi,s);
    }
    maxi=max(0LL,maxi);

    maxi=n-maxi;
    // cout<<"maxi "<<maxi<<endl;

    rep(i,n,0)
    ans[i]+=maxi;

    vi hash(n+1,0);

    // rep(i,n,0)
    // cout<<ans[i]<<" ";
    // nl;

    rep(i,n,0)
    {
        if(ans[i]<1 || ans[i]>n)
        {
            cout<<-1<<endl;
            return 0;
        }
        hash[ans[i]]++;
    }



    rep(i,n+1,1)
    {
        if(hash[i]==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    rep(i,n,0)
    cout<<ans[i]<<" ";
    nl;
}