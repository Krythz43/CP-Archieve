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

bool comp(string a,string b){
    if(a.length() == b.length())return a > b;
    else return a.length() > b.length();
}

int main()
{
    fastio;
    int n;
    int t;
    cin>>n;
    map<string,vector<string>> M,ans;
    map<string,int> inclu;

    string s;
    string x;
    rep(i,n,0){
        cin>>s;
        cin>>t;
        while(t--){
            cin>>x;
            M[s].pb(x);
        }
    }

    for(auto &it: M){
        SOP(it.ss,comp);
    }

    for(auto it: M){
        inclu.clear();
        // cout<<"stuck"<<endl;
        rep(i,it.ss.size(),0){
            if(inclu.count(it.ss[i]))continue;
            ans[it.ff].pb(it.ss[i]);
            for(int j=0;j<it.ss[i].length();j++){
                for(int k=0;k<it.ss[i].length();k++){
        // cout<<"stuck"<<endl;

                    if(j+k<it.ss[i].length())
                    inclu[it.ss[i].substr(j,k)]++;
                }
            }
        }
        cout<<"hiting for "<<it.ff<<endl;
        for(auto woo: inclu){
            cout<<woo.ff<<" "<<woo.ss<<endl;
        }
    }

    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.ff<<" "<<it.ss.size()<<" ";
        for(auto v: it.ss)cout<<v<<" ";
        nl;
    }
}