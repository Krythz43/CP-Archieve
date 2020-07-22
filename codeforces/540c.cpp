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
    int n,m;


bool isvalid(int x,int y){
    return x < n and x >= 0 and y < m and y >= 0;
}

int main()
{
    fastio;
    cin>>n>>m;
    vector<string> s(n);
    rep(i,n,0)cin>>s[i];
    ipair st,end;
    cin>>st.ff>>st.ss>>end.ff>>end.ss;
    st.ff--;
    st.ss--;
    end.ff--;
    end.ss--;

    
    vector<ipair> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    // Is end adjacent to start?

    bool isadj = false;
    for(auto d: dir){
        isadj |= (isvalid(st.ff+d.ff,st.ss+d.ss) and end == mp(st.ff+d.ff,st.ss+d.ss));
    }

    if(isadj or st == end){
        int c = 0;

       
        for(auto d: dir)
        if(isvalid(end.ff+d.ff,end.ss+d.ss) and s[end.ff+d.ff][end.ss+d.ss] == '.')c++;
        if(st != end)if(s[end.ff][end.ss] == 'X')return cout<<"YES"<<endl,0;

        if(c)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        return 0;
    }

    // No?

    map<ipair,int> vis;

    queue <ipair> Q;
    Q.push(st);
    
    int f = 0;
    int x,y;
    while(!Q.empty()){
        auto X = Q.front();
        Q.pop();
        if(vis[X])continue;
        vis[X]++;
        tie(x,y) = X;
        if(X == end){
            f = 1;
            break;
        }
        // cout<<x<<" "<<y<<endl;

        for(auto d: dir){
            // cout<<"Enq of "<<x+d.ff<<" "<<y+d.ss<<" ";
            if(isvalid(x+d.ff,y+d.ss) and !vis[{x+d.ff,y+d.ss}] and (s[x+d.ff][y+d.ss] == '.' || mp(x+d.ff,y+d.ss) == end)){
                Q.push({x+d.ff,y+d.ss});
            }
            // else cout<<"failed";
            // nl;
        }
    }

    // cout<<"moment of truth"<<endl;

    if(f){
        // cout<<"path detected"<<endl;
        if(s[end.ff][end.ss] == 'X')cout<<"YES"<<endl;
        else{

            int c = 0;
            for(auto d: dir)
            if(isvalid(x+d.ff,y+d.ss) and s[x+d.ff][y+d.ss] == '.')c++;
            if(c > 1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }   
    else cout<<"NO"<<endl;
}