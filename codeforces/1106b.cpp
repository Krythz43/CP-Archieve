#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define rep(i,n,z) for(int i=z;i<n;i++)
#define rrep(i,z) for(int i=z;i>=0;i--)
#define lli long long int
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(lli i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vi a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'


bool comp(pair<ipair,lli> a, pair<ipair,lli> b)
{
    return a.ff.ss<b.ff.ss;
}

int main()
{
    fastio;
    lli n,m;
    cin>>n>>m;
    vinput(a,n);
    vinput(c,n);

    vector <pair<ipair,lli> > serve,hash;
    rep(i,n,0)
    {
        serve.pb(mp(mp(a[i],c[i]),i));
        hash.pb(serve[i]);
    }
    lli t,d;

    SOP(hash,comp);
    lli f=0;

    while(m--)
    {
        cin>>t>>d;

        lli ans=0;
        lli hc=0;

        if(serve[t-1].ff.ff>=d)
        {
            // cout<<"serving "<<d<<" dishes of kind "<<t<<endl;
            ans=d*serve[t-1].ff.ss;
            serve[t-1].ff.ff-=d;
            cout<<ans<<endl;
        }
        else
        {
            // cout<<"serving "<<serve[t-1].ff.ff<<" dishes of kind "<<t<<endl;
            ans=serve[t-1].ff.ff*serve[t-1].ff.ss;
            lli left=d-serve[t-1].ff.ff;
            serve[t-1].ff.ff=0;
            
            for(lli i=hc;i<n;)
            {
                hash[i].ff.ff=serve[hash[i].ss].ff.ff;
                if(hash[i].ff.ff>=left)
                {
                    // cout<<"serving "<<left<<" dishes of kind1 "<<hash[i].ss+1<<endl;
                    ans+=left*hash[i].ff.ss;
                    hash[i].ff.ff-=left;
                    left=0;
                    serve[hash[i].ss].ff.ff=hash[i].ff.ff;
                    break;
                }
                else
                {
                    // cout<<"serving "<<hash[i].ff.ff<<" dishes of kind2 "<<hash[i].ss+1<<endl;
                    ans+=hash[i].ff.ff*hash[i].ff.ss;
                    left-=hash[i].ff.ff;
                    hash[i].ff.ff=0;
                    serve[hash[i].ss].ff.ff=hash[i].ff.ff;
                    hc++;
                }
                if(left==0)
                break;
                i++;
            }

            if(left)
            {
                f=1;
                cout<<0<<endl;
            }
            else
            cout<<ans<<endl;
        }
    }
}