#include <bits/stdc++.h>
#include <sstream>
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

lli S;
int n;
vector <lli> a;

struct data
{
	//Use required attributes
	lli mn;

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
	vector<lli> lazy;

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
			st[node].mn = a[L];
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
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
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}



	data query(int l, int r){return Query(1, 1, N, l, r);}
	void update(int l, int r, int val){Update(1, 1, N, l, r, val);}
	void clear(){N =0;S=0;st.clear();cLazy.clear();lazy.clear();}
};

vi parse(string s) {
    stringstream ss(s);
    int x;
    vi v;
    while (ss >> x){
        v.pb(x);
    }
    return v;
}

int main()
{
	fastio;
	SegTree tree;
	cin>>n;  
	tree.init(n); 
	a.resize(n); 
	rep(i,n,0) {
		cin>>a[i];
	}
	int t;
	tree.build(1,0,n-1);

	cin>>t;
	string s;
	getline(cin,s);

    rep(T,t,0){
        int l,r,c;
		string s;
		getline(cin,s);
		auto qu = parse(s);

        if(qu.size() == 3){
			// cout<<"here 2"<<endl;
			l = qu[0];
			r = qu[1];
			c = qu[2];
			l++, r++;
			// cout<<l<<' '<<r<<" "<<c<<endl;
			if(l <= r)tree.update(l,r,c);
			else{
				tree.update(l,n,c);
				tree.update(1,r,c);
			}
		}
		else{
			// cout<<"here 1"<<endl;
			l = qu[0];
			r = qu[1];
			l++;
			r++;
			// cout<<l<<' '<<r<<" "<<endl;
			if(l <= r)cout<<tree.query(l,r).mn<<endl;
			else{
				lli x = tree.query(l,n).mn;
				lli y = tree.query(1,r).mn;
				cout<<min(x,y)<<endl;
			}
		}
		// for(int i = 1;i<= 5;i++) cout<<tree.st[i].mn<<' ';
		// nl;
    }
}

// 1 1 0
// 0 0 -1
// 0 1 0
// 2 0
// 2 2
// 0 1
// 0 0 1
// 1 1
// 2 2
// 2 0 1
// 0 1
// 1 2
// 2 0 0
// 1 2
// 2 0
// 2 2
// 0 0
// 2 2 0
// 0 0
// 2 2