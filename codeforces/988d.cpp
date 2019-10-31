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
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    map<lli,lli> M;

    rep(i,n,0){
        M[a[i]]++;
    }

    ipair to={inf,inf};

    SO(a);
    rep(i,n,0){
        rep(j,32,0){
            if(M.count(a[i]+(1<<j))){
                to=mp(a[i],a[i]+(1<<j));

                if(M.count(a[i]+2*(1<<j))){
                    cout<<3<<endl;
                    cout<<a[i]<<" "<<a[i]+(1<<j)<<" "<<a[i]+2*(1<<j)<<endl;
                    return 0;
                }
            }
        }
    }

    if(to.ff != inf){
        cout<<2<<endl;
        cout<<to.ff<<" "<<to.ss<<endl;
        return 0;
    }

    cout<<1<<endl<<a[0]<<endl;
}