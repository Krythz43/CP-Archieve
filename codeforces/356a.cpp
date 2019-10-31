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
map<int,int> Map;

struct data
{
	int mn;
	data(){
		mn = 0;
	}
};

struct SegTree
{
	int N;
	vector<data> st;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
	}

    void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = L+1;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
	}
	
	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(j<L || i>R)
			return;
		int M = (L + R)/2;
		if(i<=L && R<=j)
		{
			// cout<<"here for "<<L<<" to "<<R<<endl;
			if(st[node].mn){
				// cout<<"Entering area currently conquered by "<<st[node].mn<<" and to be conquered by "<<val<<endl;
                if(st[node].mn!=val && !Map[st[node].mn]){
                    Map[st[node].mn]=val;
                    st[node].mn=val;
                }
                else if(st[node].mn!=val) st[node].mn = val;
            }
            else{
                st[node].mn=val;
                Update(node*2, L, M, i, j, val);
	        	Update(node*2 + 1, M + 1, R, i, j, val);
            }
			return;
		}
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
	}


	void update(int l, int r, int val)
	{
		Update(1, 1, N, l, r, val);
	}
};

int main()
{
	fastio;
	SegTree tree; // Defining the structure
	cin>>n;
    int m;
    cin>>m;  // i1nput the size of the array to be worked upon
	tree.init(n); //Initializing the structure for size of S, remember your require a size of 4S for the actual nodes

    int l,r,val;
    tree.build(1,0,n-1);
    while(m--){
        cin>>l>>r>>val;
        tree.update(l,r,val);
    }
    rep(i,n,0)cout<<Map[i+1]<<" ";
    nl;
}