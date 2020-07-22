#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
#define rep(i,n,z) for(lli i=z;i<n;i++)
#define rrep(i,z) for(lli i=z;i>=0;i--)
#define nl cout<<endl
#define vi vector<lli>
#define vlli vector<long long int>
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ipair pair <lli,lli>
#define llipair pair <lli,lli>
#define pq priority_queue
#define displaymatrix(a,m,n) for(lli i=0;i<m;i++){for(lli j=0;j<n;j++)cout<<a[i][j]<<" ";cout<<endl;}
#define printarray(a,n) for(lli i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

vector <lli> a;

lli S;
const lli SIZE = 4e5 + 5;

vector <lli> euler,first,last;
vector <lli> adj[SIZE];


void dfs(lli x,  lli p = -1){
    euler.push_back(x);
    for(auto to: adj[x]){
        if(to == p) continue;
        dfs(to,x);
        euler.push_back(x);
    }
}


struct data
{
	//Use required attributes
	lli col;

	//Default Values
	data(){
		col = 0;
	}
};

struct SegTree
{
	lli N;
	vector<data> st;
	vector<bool> cLazy;
	vector<lli> lazy;

	void init(lli n)
	{
		N = n;
		S = 4 * n + 5;
		st.resize(S);
		cLazy.assign(S, false);
		lazy.assign(S, 0);
	}

	void merge(data &cur, data &l, data &r) 
	{
		cur.col = (l.col|r.col);
	}
	
	void propagate(lli node, lli L, lli R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].col = lazy[node];
		cLazy[node] = 0;
	}

	void build(lli node, lli L, lli R)
	{
		if(L==R)
		{
			st[node].col = (1LL<<a[euler[L]]);
			return;
		}
		lli M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(lli node, lli L, lli R, lli i, lli j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		lli M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}


	void Update(lli node, lli L, lli R, lli i, lli j, lli val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		lli M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}



	data query(lli l, lli r){return Query(1, 1, N, l, r);}
	void update(lli l, lli r, lli val){Update(1, 1, N, l, r, val);}
};

int main()
{
	fastio;

    lli n,m;
    cin>>n>>m;
    a.resize(n + 1);
    rep(i, n + 1,1)cin>>a[i];

    lli x,y;

    first.resize(n+1,-1);
    last.resize(n+1,0);


    for(lli i = 0; i < n-1; i++){
        cin>>x>>y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    dfs(1);

    for(lli i = 0; i < euler.size() ; i++){
        last[euler[i]] = i;
        if(first[euler[i]] != -1)continue;
        first[euler[i]] = i;
    }

    lli N = euler.size();

	SegTree tree;
    tree.init(N);
    tree.build(1,0,N - 1);

    // for(auto x: euler)cout<<x<<" ";
    // cout<<endl;
    // for(auto x: first)cout<<x<<" ";
    // cout<<endl;
    // for(auto x: last)cout<<x<<" ";
    // cout<<endl;

    // for(auto x: tree.st)cout<<x.col<<" ";
    // cout<<endl;

    while(m--){
        lli K,l,r,c;
        cin>>K;
        if(K == 1){
            cin>>r>>c;
            l = first[r];
            r = last[r];
            tree.update(l + 1,r + 1,(1LL<<c));
        }
        else{
            cin>>r;
            l = first[r];
            r = last[r];
            auto ans = tree.query(l + 1,r + 1);
            cout<<__builtin_popcountll(ans.col)<<endl;
        }
    }
}