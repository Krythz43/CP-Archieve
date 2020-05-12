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
    lli n,m,k;
    cin>>n>>m>>k;
    vinput(a,n);
    vinput(b,m);

    vector <lli> facts;
    for(int i=1; i<=sqrt(k); i++)if(k%i == 0)facts.pb(i);

    map<lli,lli> R,C;

    int cc=0;
    rep(i,n,0){
        if(a[i] == 1)cc++;
        else{
            if(cc){
                R[cc]++;
                // cout<<"updating "<<cc<<endl;
            }
            cc = 0;
        }
    }   

    if(cc)R[cc]++;
    cc = 0;

    rep(i,m,0){
        if(b[i] == 1)cc++;
        else{
            if(cc){
                C[cc]++;
            }
            cc=0;
        }
    }
    if(cc)C[cc]++;

    // cout<<"fators"<<endl;
    // printarray(facts,facts.size())

    lli ans = 0,tans;
    lli X,Y;
    for(auto x: R)for(auto y: C){
        X = x.ff,Y = y.ff;
        for(auto i: facts){
            tans = 0;
            if(i <= X && k/i <= Y) tans += (X-i+1)*(Y - k/i+1);
            if(i <= Y && k/i <= X && i!=k/i) tans += (Y-i+1)*(X - k/i+1);
            tans*=x.ss*y.ss;
            ans+=tans;
        }
        // cout<<X <<"X"<<Y<<"  occurance "<<x.ss*y.ss<<" curr_anss:"<<ans<<endl;
    }
    cout<<ans<<endl;
}