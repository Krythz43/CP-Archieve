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


string s;

struct data
{
	//Use required attributes
	vector<int> a;

	//Default Values
	data(){
		a.resize(26,0);
	}
};
lli S;

struct SegTree
{
	int N;
	vector<data> st;
	vector<bool> cLazy;
	vector<data> lazy;

	void init(int n)
	{
		N = n;
		S = 4 * n + 5;
		st.resize(S);
		cLazy.assign(S, false);
		lazy.resize(S);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
        rep(i,26,0)
		cur.a[i]= l.a[i]+ r.a[i];
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			merge(lazy[node*2],lazy[node*2],lazy[node]);
			merge(lazy[node*2+1],lazy[node*2+1],lazy[node]);
		}
		st[node] = lazy[node];
		cLazy[node] = 0;
        rep(i,26,0)lazy[node].a[i]=0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].a[s[L]-97] = 1;
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


	void pUpdate(int node, int L, int R, int pos, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node].a[val-97] = 1;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos){return pQuery(1, 1, N, pos);}
	data query(int l, int r){return Query(1, 1, N, l, r);}
    void update(int pos, int val){pUpdate(1, 1, N, pos, val);}
	void clear(){N =0;S=0;st.clear();cLazy.clear();lazy.clear();}
};


int main()
{
    fastio;
    cin>>s;
    int t;
    cin>>t;

    SegTree tree;
    int n=s.length();
    tree.init(n);
    tree.build(1,0,n-1);

    while(t--){
        int c;
        cin>>c;
        int x,y;
        char val;
        if(c==1){
            cin>>x>>val;
            tree.update(x,val);
        }
        else{
            cin>>x>>y;
            data p=tree.query(x,y);
            lli ans=0;
            rep(i,26,0)if(p.a[i])ans++;
            cout<<ans<<endl;
        }
    }
}