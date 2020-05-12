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
	int mn,gcd,cnt;

	//Default Values
	data(){
		mn = 2e9;
        gcd = 0;
        cnt = 0;
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
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		if(l.mn == r.mn){
            cur.mn = l.mn;
            cur.cnt = l.cnt + r.cnt;
        }
        else if(l.mn < r.mn){
            cur.mn = l.mn;
            cur.cnt = l.cnt;
        }
        else{
            cur.mn = r.mn;
            cur.cnt = r.cnt;
        }

		cur.gcd = __gcd(l.gcd, r.gcd);
	}
	

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = a[L];
			st[node].gcd = a[L];
            st[node].cnt = 1;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
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
};

int main()
{
	fastio;
	SegTree tree;
	cin>>n;  
	tree.init(n); 
	a.resize(n); 
	rep(i,n,0)cin>>a[i];

	tree.build(1,0,n-1);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        auto x = tree.query(l,r);

        // cout<<x.gcd<<" "<<x.mn<<endl;
        if(x.gcd == x.mn)cout<<r-l+1-x.cnt<<endl;
        else cout<<r-l+1<<endl;
    }
}