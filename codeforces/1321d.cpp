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

int tc_dist;
int src,dest;

void BFS(vector<int> adj[], int src, int dist[], 
                           int paths[], int n) 
{ 
    bool visited[n]; 
    for (int i = 0; i < n; i++) 
        visited[i] = false; 
    dist[src] = 0; 
    paths[src] = 1; 
  
    queue <int> q; 
    q.push(src); 
    visited[src] = true; 
    while (!q.empty()) 
    { 
        int curr = q.front(); 
        q.pop(); 
  
        // For all neighbors of current vertex do: 
        for (auto x : adj[curr]) 
        { 
            // if the current vertex is not yet 
            // visited, then push it to the queue. 
            if (visited[x] == false) 
            { 
                q.push(x); 
                visited[x] = true; 
            } 
  
            // check if there is a better path. 
            if (dist[x] > dist[curr] + 1) 
            { 
                dist[x] = dist[curr] + 1; 
                paths[x] = paths[curr]; 
            } 
  
            // additional shortest paths found 
            else if (dist[x] == dist[curr] + 1) 
                paths[x] += paths[curr]; 
        } 
    } 

    tc_dist = dist[dest];
} 

vector<int> findShortestPaths(vector<int> adj[], 
                       int s, int n) 
{ 
    int dist[n], paths[n]; 
    for (int i = 0; i < n; i++) 
        dist[i] = INT_MAX; 
    for (int i = 0; i < n; i++) 
        paths[i] = 0; 
    BFS(adj, s, dist, paths, n); 
    // cout << "Numbers of shortest Paths are: "; 
    vector<int> path_count;
    for (int i = 0; i < n; i++) 
        path_count.pb(paths[i]);

} 


int main()
{
    fastio;
    int n,m;
    cin>>n>>m;
    vector<int> a[n+5];
    int x,y;
    rep(i,m,0){
        cin>>x>>y;
        a[x].pb(y);
    }
    int l;
    cin>>n;
    vinput(route,l);
    vector<int> path;
    lli mx=0,mn=0;
    dest = route[l-1];
    rep(i,l-1,0){
        path = findShortestPaths(a,i+1,route[l-1]);
        src = route[i];
        if(tc_dist == l-i){
            mx+=path[route[l-1]]-1;
        }
        else{
            mx++;
            mn++;
        }
    }

    cout<<mn<<" "<<mx<<endl;
}