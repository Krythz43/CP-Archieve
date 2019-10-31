#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define LL long long int
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

#define NN 1000006
struct dataz
{
	//Use required attributes
	int mn;

	//Default Values
	dataz() : mn(1e9) {};
};

struct SegTree
{
	int N;
	vector<dataz> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(dataz &cur, dataz &l, dataz &r) 
	{
		cur.mn = min(l.mn, r.mn);
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] += lazy[node];
			lazy[node*2 + 1] += lazy[node]; 
		}
		st[node].mn += lazy[node];
		cLazy[node] = 0;
		lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = 0;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	int pQuery(int node, int L, int R)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			if(st[node].mn<0)
				return L;
			else
				return -1;
		}
		int M = (L + R)/2;
		if(cLazy[node*2+1])
			propagate(node*2+1, M+1, R);
		
		if(st[node*2+1].mn <0)
			return pQuery(node*2 + 1, M + 1, R);
		else
			return pQuery(node*2, L, M);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] += val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pr()
	{
		for(int i=0;i<=10;i++)
			cout<<i<<" "<<st[i].mn<<endl;
		cout<<endl;
	}
	int query(int l, int r)
	{
		return pQuery(1, 1, N);
	}

	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};


int main()
{
    LL i,j,lt,d,z,v,c,r,l,t1,k,h,n,u,m,q,ts,te,x,y;
    fastio;
    cin>>n>>m;
    SegTree tree;
    tree.init(NN);
    tree.build(1,1,NN);
    LL ar[n+1],br[m+1];
    for(i=1;i<=n;i++)
    {
    	cin>>ar[i];
    	tree.update(1,ar[i],-1);
    }
    for(i=1;i<=m;i++)
    {
    	cin>>br[i];
    	tree.update(1,br[i],1);
    }
    cin>>q;

    while(q--){
    	cin>>z>>x>>y;
    	if(z==1){
    		tree.update(1,ar[x],1);
    		ar[x]=y;
    		tree.update(1,ar[x],-1);
    	}
    	else{
    		tree.update(1,br[x],-1);
    		br[x]=y;
    		tree.update(1,br[x],1);
    	}

    	cout<<tree.query(1,NN-1)<<endl;

    }
}