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

//template credits: https://github.com/Ashishgup1/Competitive-Coding/blob/master/Segment%20Tree.cpp

const lli S=1e5+5;
int n;
vector <int> a;

struct data
{
	//Use required attributes
	int mn;

	//Default Values
	data(){
		mn = 1e9;
	}
};

struct SegTree
{
	int N;
	vector<data> st;
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
	void merge(data &cur, data &l, data &r,int k) 
	{
		cur.mn = k? (l.mn|r.mn):(l.mn^r.mn);
        // cout<<"merging "<<l.mn<<" and "<<r.mn<<endl;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mn = lazy[node];
		cLazy[node] = 0;
	}

	void build(int node, int L, int R,int k)
	{
        // cout<<"building node "<<node<<" with key "<<k<<endl;
		if(L==R)
		{
			st[node].mn = a[L];
            // cout<<"bulding "<<L<<" to "<<R<<" as "<<st[node].mn<<endl;

			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M,k^1);
		build(node*2 + 1, M + 1, R,k^1);
		merge(st[node], st[node*2], st[node*2+1],k);
        // cout<<"bulding "<<L<<" to "<<R<<" as "<<st[node].mn<<endl;
	}

	data Query(int node, int L, int R, int i, int j, int k)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j,k^1);
		data right=Query(node*2 + 1, M + 1, R, i, j,k^1);
		data cur;
		merge(cur, left, right, k);
		return cur;
	}

	void pUpdate(int node, int L, int R, int pos, int val,int k)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val,k^1);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val,k^1);
		merge(st[node], st[node*2], st[node*2 + 1],k);
	}


	data query(int l, int r,int k)
	{
		return Query(1, 1, N, l, r,k);
	}

	void update(int pos, int val,int k)
	{
		pUpdate(1, 1, N, pos, val,k);
	}
};

int main()
{
	fastio;
	SegTree tree; // Defining the structure
    int m;
	cin>>n>>m;  // input the size of the array to be worked upon
    int k=n%2;
    n=1<<n;

    tree.init(n);
	a.resize(n); 
	rep(i,n,0)cin>>a[i];

	tree.build(1,0,n-1,k);

    while(m--){
        int x,y;
        cin>>x>>y;
        tree.update(x,y,k);
        cout<<tree.st[1].mn<<endl;
    }
}