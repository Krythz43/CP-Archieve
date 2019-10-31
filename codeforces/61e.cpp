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

lli S;
int n;
vector <int> a;

struct data
{
	//Use required attributes
	int mn;

	//Default Values
	data(){
		mn = 0;
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
		S = 4 * n + 5;
		st.resize(S);
		cLazy.assign(S, false);
		lazy.assign(S, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = l.mn + r.mn;
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
        lazy[node]=0;
		cLazy[node] = 0;
	}

	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
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

	data query(int pos){return pQuery(1, 1, N, pos);}
	void update(int l, int r, int val){Update(1, 1, N, l, r, val);}

	void clear(){N =0;S=0;st.clear();cLazy.clear();lazy.clear();}
};

int main()
{
	fastio;
	SegTree tree;
	cin>>n;
	a.resize(n); 

    vector<pair<ipair,int> > b(n);

    rep(i,n,0){
        cin>>b[i].ff.ff;
        b[i].ff.ss=i;
    }

    SO(b);
    rep(i,n,0){
        b[i].ss=i+1;
        swap(b[i].ff.ff,b[i].ff.ss);
    }
    SO(b);
    rep(i,n,0)a[i]=b[i].ss;

    int Ns=1e6+5;

    tree.init(Ns);
    vector <lli> gre,les;
    int t;
    rep(i,n,0){
        t=tree.query(a[i]).mn;
        gre.pb(t);
        tree.update(0,a[i]-1,1);
    }

    tree.clear();
    tree.init(Ns);
    rrep(i,n-1){
        t=tree.query(a[i]).mn;
        les.pb(n-i-1-t);
        tree.update(0,a[i]-1,1);
    }
    reverse(all(les));
    // rep(i,n,0)cout<<les[i]<<" ";
    // nl;

    lli ans=0;
    rep(i,n,0)ans+=gre[i]*les[i];
    cout<<ans<<endl;
}