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

typedef struct data
{
	data* bit[2];
	int cnt = 0;
}trie;

trie* head;

void insert(int x,int v)
{
	trie* cur = head;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i) & 1;
		if(!cur->bit[b]){
			cur->bit[b] = new trie();
        }
		cur = cur->bit[b];
		cur->cnt+=v;
	}
}

int query(int x)
{
	trie* cur = head;
	int ans = 0;
	for(int i=30;i>=0;i--)
	{
		int b = (x>>i)&1;
		int nxt = b ^ 1;
        if(cur->bit[nxt]!=NULL && cur->bit[nxt]->cnt>0){  
            ans+=(1ll << i);
            // cout<<"proceeding to "<<nxt<<" at bit "<<i<<" because mismatch"<<endl;
            cur=cur->bit[nxt];
        }
        else{
            // cout<<"proceeding to "<<b<<" at bit "<<i<<" because match"<<endl;
            cur=cur->bit[b];
        }

        if(cur==NULL)break;
	}
	return max(x,ans);
}

int main()
{
    fastio;
    int q;
    cin>>q;
    head=new trie();
    insert(0,1);
    head->bit[1]=head->bit[0]=NULL;
    while(q--){
        char ch;
        int l;
        cin>>ch>>l;
        if(ch=='+')insert(l,1);
        else if(ch=='-')insert(l,-1);
        if(ch=='?')cout<<query(l)<<endl;
    }
}
