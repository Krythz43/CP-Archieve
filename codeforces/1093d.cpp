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

#define S 300005
lli mod=998244353;


vi a[S];
vector<bool> vis(S,false);
vi col(S,0);
vlli pe,qe;
lli p,q;
vi checker;

lli multi(lli x,lli y)
{
    x%=mod;
    if(y==0) return 1;
    if(y==1) return x;
    if(y%2) return (x*(multi((x*x)%mod,y/2)%mod))%mod;
    else return multi((x*x)%mod,y/2)%mod;
}

void dfs(int i,int co)
{
    if(vis[i])
    return;
    vis[i]=true;
    col[i]=co;
    checker.pb(i);
    
    if(co)
    p++;
    else
    q++;

    rep(j,a[i].size(),0)
    {
        if(vis[a[i][j]]==false)
        {
            dfs(a[i][j],(co+1)%2);
        }
    }
}
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m;
        cin>>n>>m;
        rep(i,n+1,1)
        {
            a[i].clear();
            vis[i]=false;
            col[i]=0;
            pe.clear();
            qe.clear();
        }

        int x,y;
        rep(i,m,0)
        {
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }

        int f,fo=1;
        vi jacuzi;

        rep(i,n+1,1)
        {
            p=q=0;
            checker.clear();
            f=0;
            if(vis[i]==false)
            {
                dfs(i,0);
                // cout<<"cycle length "<<checker.size()<<endl;
                rep(k,checker.size(),0)
                {
                    rep(j,a[checker[k]].size(),0)
                    {
                        if(col[checker[k]]==col[a[checker[k]][j]])
                        {
                            f=1;
                            break;
                        }
                    }

                    if(f)
                    break;
                }

                jacuzi.pb(f);

                if(f)
                fo=0;

                pe.pb(p);
                qe.pb(q);
            }
        }






        if(fo==0)
        {
            // cout<<"ans=";
            cout<<0<<endl;
        }
        else
        {
            vlli fans;
            // cout<<p<<" "<<q<<endl;
            rep(i,pe.size(),0)
            {
                if(jacuzi[i]==0)
                 {
                     lli ans=0;
                    if(pe[i]==0 || qe[i]==0)
                    {
                        fans.pb(3);
                    }
                    else
                    {
                        if(qe[i]>0)
                        ans=(ans+(multi(2,qe[i])%mod))%mod;
                        if(pe[i]>0)
                        ans=(ans+(multi(2,pe[i])%mod))%mod;
                        fans.pb(ans);
                    }
                }
            }

            lli tans=1;
            rep(i,fans.size(),0)
            {
                // cout<<i<<":"<<fans[i]<<endl;
                tans=(tans*fans[i])%mod;
            }
            // cout<<"ans=";
            cout<<tans<<endl;
        }
    }
}