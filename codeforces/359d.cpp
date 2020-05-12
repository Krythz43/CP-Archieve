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
// #define endl '\n'

//template credits: https://github.com/Ashishgup1/Competitive-Coding/blob/master/Segment%20Tree.cpp

lli S;
int n;
vector <int> a;

struct data
{
	//Use required attributes
	int mn,gcd;

	//Default Values
	data(){
		mn = 1e9;
        gcd = 0;
	}
};

struct SegTree
{
	int N;
	vector<data> st;

	void init(int n)
	{
		N = n;
		S = 4 * n + 5;
		st.resize(S);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
        cur.gcd = __gcd(l.gcd,r.gcd);
	}
	
	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = a[L];
			st[node].gcd = a[L];

            // cout<<"Building Node "<<node<<" with params mn="<<st[node].mn<<" gcd="<<st[node].gcd<<endl;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
        // cout<<"Building Node "<<node<<" with params mn="<<st[node].mn<<" gcd="<<st[node].gcd<<endl;

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

    int hi = n,lo=1,mid;
    data F;
    while(hi-lo>1){
        mid = (hi+lo)/2;
        int f = 0;
        rep(i,n-mid+1,0){
            F = tree.query(i+1,i+mid);
            if(F.mn == F.gcd){
                f=1;
                break;
            }
        }
        if(f)lo=mid;
        else hi=mid;
    }

    int ans = hi;
    int f = 0;
    rep(i,n-hi+1,0){
        F = tree.query(i+1,i+hi);
        if(F.mn == F.gcd){
            f=1;
            break;
        }
    }
    if(!f)ans=lo;

    vi sp;
    rep(i,n-ans+1,0){
        F = tree.query(i+1,i+ans);
        if(F.mn == F.gcd){
            sp.pb(i+1);
        }
    }

    cout<<sp.size()<<' '<<ans-1<<endl;
    printarray(sp,sp.size());

    // while(1){
    //     int l,r;
    //     cin>>l>>r;
    //     data F = tree.query(l,r);
    //     cout<<"mn="<<F.mn<<" gcd="<<F.gcd<<endl;
    // }
}