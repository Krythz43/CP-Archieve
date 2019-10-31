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
    int n,q;
    cin>>n>>q;

    if(n<100 && q<100)
    {
        vi a(5500,0);
        int x,y;
        int ters=0;
        vector<ipair> sec;
        rep(i,q,0)
        {
            cin>>x>>y;
            sec.pb(mp(x,y));
            a[x]++;
            a[y+1]--;
            ters=max(ters,y-x);
        }

        if(q==3)
        {
            cout<<ters+1<<endl;
            return 0;
        }
    

        lli c=0;
        rep(i,n+5,0)
        {
            c+=a[i];
            a[i]=c;
        }

        int ans=0;

        rep(i,n+1,1)
        if(a[i])
        ans++;

        int mans=0;

        

        for(int i=0;i<q;i++)
        {
            for(int j=i+1;j<q;j++)
            {
                int tans=ans;

                x=sec[i].ff;
                y=sec[i].ss;

                for(int k=x;k<=y;k++)
                {
                    a[k]--;
                    if(a[k]==0)
                    tans--;
                }

                x=sec[j].ff;
                y=sec[j].ss;

                for(int k=x;k<=y;k++)
                {
                    a[k]--;
                    if(a[k]==0)
                    tans--;
                }

                x=sec[i].ff;
                y=sec[i].ss;

                for(int k=x;k<=y;k++)
                {
                    a[k]++;
                }

                x=sec[j].ff;
                y=sec[j].ss;

                for(int k=x;k<=y;k++)
                {
                    a[k]++;
                }
                mans=max(mans,tans);
            }
        }

        cout<<mans<<endl;
        return 0;
    }

    vi a(5500,0);
    int x,y;
    vector<ipair> sec;
    int ters=0;
    rep(i,q,0)
    {
        cin>>x>>y;
        sec.pb(mp(x,y));
        a[x]++;
        a[y+1]--;
        ters=max(ters,y-x);
    }

    if(q==3)
    {
        cout<<ters+1<<endl;
        return 0;
    }
    

    lli c=0;
    rep(i,n+5,0)
    {
        c+=a[i];
        a[i]=c;
    }
    

    vector<pair<ipair,int>> eff;

    for(int i=0;i<q;i++)
    {
        x=sec[i].ff;
        y=sec[i].ss;
        c=0;
        int l=y-x;
        for(;x<=y;x++)
        {
            if(a[x]==1)
            c++;
        }

        eff.pb(mp(mp(c,l),i));
    }

    SO(eff);
    x=sec[eff[0].ss].ff;
    y=sec[eff[0].ss].ss;

    for(;x<=y;x++)
    a[x]--;

    int ig=eff[0].ss;
    eff.clear();

    // cout<<"first ignore "<<ig<<endl;

    for(int i=0;i<q;i++)
    {
        if(i==ig)
        continue;
        x=sec[i].ff;
        y=sec[i].ss;
        c=0;
        int l=y-x;
        for(;x<=y;x++)
        {
            if(a[x]==1)
            c++;
        }

        eff.pb(mp(mp(c,l),i));
    }

    SO(eff);
    x=sec[eff[0].ss].ff;
    y=sec[eff[0].ss].ss;

    for(;x<=y;x++)
    a[x]--;

    // cout<<"second ignore "<<eff[0].ss<<endl;

    int ans=0;

    // printarray(a,n+1)
    rep(i,n+1,1)
    if(a[i])
    ans++;

    cout<<ans<<endl;
}