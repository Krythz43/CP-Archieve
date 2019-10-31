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

lli llmax(lli a,lli b){if(a>b)return a; return b;}
lli llmin(lli a,lli b){if(a<b)return a; return b;}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        stack <int> s;
        int n,t;
        cin>>n;
        rep(i,n+1,1)
        s.push(i);

        while(s.size()>6)
        {
            vi z;
            rep(i,5,0)
            {
                t=s.top();
                s.pop();
                z.pb(t);
            }
            cout<<"? ";
            rep(i,z.size(),0)
            cout<<z[i]<<" ";
            nl;
            cout<<flush;
            int x,y;
            cin>>x>>y;

            rep(i,z.size(),0)
            {
                if(z[i]!=x && z[i]!=y)
                s.push(z[i]);
            }

            if(s.size()<6)
            s.push(x);
        }

        vi z(6);
        rep(i,6,0)
        z[i]=s.top(),s.pop();
        int q[105][105];
        memset(q,0,sizeof q);

        vector<pair<ipair,int>>w;
        rep(k,6,0)
        {
            cout<<"? ";
            rep(i,6,0)
            {
                if(i!=k)
                cout<<z[i]<<" ";
            }
            nl;
            cout<<flush;

            int x,y;
            cin>>x>>y;
            w.pb(mp(mp(x,y),z[k]));
            q[x][y]++;
            q[y][x]++;

        }
        int x,y,f=0;

        rep(i,101,0)
        {
            rep(j,101,0)
            {
                if(q[i][j]==2)
                {
                    f=1;
                    x=i;
                    y=j;
                    break;
                }
            }

            if(f)
            break;
        }

        int ans1=0,ans2=0,ans;
        f=0;


        rep(i,w.size(),0)
        {
            if(w[i].ff.ff==x && w[i].ff.ss==y || w[i].ff.ff==y && w[i].ff.ss==x)
            {
                if(ans1)
                {
                    ans2=w[i].ss;
                }
                else
                ans1=w[i].ss;
            }
        }

        rep(i,w.size(),0)
        {
            if(w[i].ff.ff==ans1 || w[i].ff.ss==ans1)
            {
                ans=ans2;
                break;
            }

            if(w[i].ff.ff==ans2 || w[i].ff.ss==ans2)
            {
                ans=ans1;
                break;
            }
        }

        cout<<"! "<<ans<<endl;
        cout<<flush;

    }
}