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


lli ma(lli a,lli b)
{
    if(a>b)
    return a;
    return b;
}

int main()
{
    fastio;
    lli n;
    cin>>n;
    vlli t(n);
    rep(i,n,0)
    {
        cin>>t[i];
    }

    sort(t.begin(),t.end());

    vector<llipair > a;
    lli c=0,size=0;

    rep(i,n-1,0)
    {
        c+=t[i];
        if(t[i]!=t[i+1])
        {
            a.pb(mp(t[i],c));
            c=0;
        }
    }
    c+=t[n-1];
    a.pb(mp(t[n-1],c));
    vector<lli> ans(a.size());
    // cout<<"size "<<a.size()<<endl;
    lli maxe =0;
    if(a.size()==1)
    cout<<a[0].ss;
    else
    {
        ans[0]=a[0].ss;
        if(a[0].ff==a[1].ff-1)
        ans[1]=a[1].ss;
        else
        ans[1]=a[1].ss+a[0].ss;

        maxe=ans[0];
        rep(i,a.size(),2)
        {
            if(maxe<ans[i-2])
            maxe=ans[i-2];

            if(a[i].ff==a[i-1].ff+1)
            ans[i]+=a[i].ss+maxe;
            else
            ans[i]+=a[i].ss+ma(maxe,ans[i-1]);
        }

        // printarray(ans,a.size())
        // rep(i,a.size(),0)
        // cout<<a[i].ff<<" "<<a[i].ss<<endl;
        cout<<ma(ans[a.size()-1],ans[a.size()-2]);
    }
}