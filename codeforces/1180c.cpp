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
    int n,q;
    cin>>n>>q;
    vinput(a,n);
    deque<lli> dq;
    rep(i,n,0)
    dq.push_back(a[i]);
    vector<ipair> query;
    lli f,s;
    rep(i,n-1,0){
        f=dq.front();
        dq.pop_front();
        s=dq.front();
        dq.pop_front();
        // cout<<f<<" "<<s<<endl;

        query.pb(mp(f,s));
        if(f>s){
            dq.push_front(f);
            dq.pb(s);
        }
        else{
            dq.push_front(s);
            dq.pb(f);
        }
    } 

    vlli q2;
    lli fa;
    fa=dq.front();
    dq.pop_front();
    rep(i,n-1,0){
        q2.pb(dq.front());
        dq.pop_front();
    }

    // rep(i,n-1,0)
    // cout<<q2[i]<<" ";
    // nl;
    while(q--){
        lli m;
        cin>>m;
        if(m<n)
        cout<<query[m-1].ff<<" "<<query[m-1].ss<<endl;
        else{
            m-=n;
            m%=n-1;
            cout<<fa<<" "<<q2[m]<<endl;
        }
    }
}