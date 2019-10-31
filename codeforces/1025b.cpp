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
// #define endl '\n'

set <int> check;

void cal(lli x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0){
            check.insert(i);
            while(x%i ==0)x/=i;
        }
    }
    if(x>1)check.insert(x);
}

int main()
{
    fastio;
    int n;
    cin>>n;
    vector <ipair> a(n);
    rep(i,n,0){
        cin>>a[i].ff>>a[i].ss;
    }

    cal(a[0].ff);
    cal(a[0].ss);

    vi tbe;

    rep(i,n,1){
        if(check.empty()){
            cout<<-1<<endl;
            return 0;
        }
        tbe.clear();
        for(auto x : check){
            if(a[i].ff%x != 0 && a[i].ss%x != 0){
                tbe.pb(x);
            }
        }

        for(auto x: tbe){
            check.erase(x);
        }
    }

    if(check.empty()){
        cout<<-1<<endl;
    }
    else{
        for(auto x: check){
            cout<<x<<endl;
            break;
        }
    }
}