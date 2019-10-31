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
string s;

struct data
{
	//Use required attributes
	int clo,opl,opr;

	//Default Values
	data(){
		clo=opl=opr=0;
	}

    data operator+(data const & right){
        data res;

        res.clo = clo + right.clo;
        int t=(opr>right.opl)?right.opl:opr;
        res.clo += t;
        res.opl = opl + right.opl-t;
        res.opr = opr + right.opr-t;

        return res;
    }
};

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
		cur = l + r;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node*2]+lazy[node];
			lazy[node*2 + 1] = lazy[node*2 + 1]+lazy[node]; 
            lazy[node].clo= lazy[node].opr=lazy[node].opl=0;
		}
		st[node] = lazy[node];
		cLazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].clo = 0;
            if(s[L]=='('){
                st[node].opr=1;
                st[node].opl=0;
            }
            else{
                st[node].opr=0;
                st[node].opl=1;
            }

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

	data query(int l, int r){return Query(1, 1, N, l, r);}
	void clear(){N =0;S=0;st.clear();cLazy.clear();lazy.clear();}
};

int main()
{
	fastio;
	SegTree tree;
	cin>>s;  
    n=s.length();

	tree.init(n); 
	tree.build(1,0,n-1);

    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        data ans = tree.query(l,r);
        cout<<2*ans.clo<<endl;
    }
}