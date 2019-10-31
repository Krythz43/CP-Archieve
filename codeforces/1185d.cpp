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
    int n;
    cin>>n;
    vector<llipair> a;
    lli x;
    rep(i,n,0){
        cin>>x;
        a.pb(mp(x,i));
    }
    SO(a);

    vlli z;
    rep(i,n,1)
    z.pb(a[i].ff-a[i-1].ff);
    SO(z);
    if(z[0]==z[n-2]){
        cout<<a[0].ss+1<<endl;
        return 0;
    }
    set<lli> s;
    rep(i,n-1,0)s.insert(z[i]);
    if(s.size()>3){
        cout<<-1<<endl;
        return 0;
    }

    set<lli> eo;
    rep(i,n-1,1)
    eo.insert(a[i+1].ff-a[i].ff);
    if(eo.size()==1){
        cout<<a[0].ss+1<<endl;
        return 0;
    }

    for(auto d:s){
        int c=0;
        lli lf=a[0].ff;
        rep(i,n,0){
            if(a[i].ff==lf){
                lf+=d;
            }
            else
            c++;
        }

        if(c==1){
            lf=a[0].ff;
            rep(i,n,0){
                if(a[i].ff==lf){
                    lf+=d;
                }
                else{
                    cout<<a[i].ss+1<<endl;
                    return 0;
                }
            }
        }
    }


    cout<<-1<<endl;
}