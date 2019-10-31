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


const lli S = 1e5+5;

int main()
{
    fastio;
    lli n,m;
    cin>>n>>m;

    set <lli> v1,v2,v3;
    vector<ipair> el1,el2;

    int x,y;
    vi a[S];

    rep(i,m,0){
        cin>>x>>y;
        if(x>y)swap(x,y);
        el1.pb(mp(x,y));
        a[x].pb(y);
        a[y].pb(x);
    }

    SO(el1);

    rep(i,n+1,1){
        if(a[i].size()<2){
            cout<<-1<<endl;
            return 0;
        }
    }

    v1.insert(1);
    v2.insert(a[1][0]);

    x=1;
    y=a[1][0];

    // cout<<"initial "<<x<<" "<<y<<endl; 

    map<int,int> M;

    for(auto i: a[x]){
        if(binary_search(all(a[y]),i))v3.insert(i);
        else v2.insert(i);
    }

    if(v3.size()==0){
        cout<<-1<<endl;
        return 0;
    }

    for(auto i: a[y]){
        if(binary_search(all(a[x]),i)){}
        else v1.insert(i);
    }   

    // cout<<"a ";
    for(auto i : v1){
        M[i]=1;
        // cout<<i<<" ";
        for(auto j: v2){
            x=i;
            y=j;
            if(x>y)swap(x,y);
            el2.pb(mp(x,y));
        }
    }

    // nl;
    // cout<<"b ";
    for(auto i : v2){
        M[i]=2;
        // cout<<i<<" ";

        for(auto j: v3){
            x=i;
            y=j;
            if(x>y)swap(x,y);
            el2.pb(mp(x,y));
        }
    }

    // nl;
    // cout<<"c ";
    for(auto i : v3){
        M[i]=3;
        // cout<<i<<" ";

        for(auto j: v1){
            x=i;
            y=j;
            if(x>y)swap(x,y);
            el2.pb(mp(x,y));
        }
    }
    // nl;

    // for(auto p: el2){
    //     // cout<<p.ff<<" "<<p.ss<<endl;
    // }
    if(el1.size() != el2.size()){
        cout<<-1<<endl;
        return 0;
    }


    SO(el2);

    rep(i,el1.size(),0){
        if(el1[i].ff!= el2[i].ff || el1[i].ss!= el2[i].ss){
            cout<<-1<<endl;
            return 0;
        }
    }

    rep(i,n,0)cout<<M[i+1]<<" ";
    nl;
}