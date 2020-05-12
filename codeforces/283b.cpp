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

map<lli,lli> M;

vlli E[400001];
int n,w[200001],i,j,a,Q[400001],h,t,x,o;
lli D[400001];
bool v[400001];

int main()
{
    fastio;
    int n;
    cin>>n;

	for(i=2;i<=n;i++){
		cin>>w[i];

		if(0<i+w[i] && i+w[i]<=n){
			E[i+w[i]+n].push_back(i);
		}

		if(0<i-w[i] && i-w[i]<=n){
			E[i-w[i]].push_back(i+n);
		}
	}

	for(i=2;i<=n;i++){
		if(i<=w[i])D[i+n]=w[i],v[n+i]=true,Q[++t]=n+i;
		if(i+w[i]>n)D[i]=w[i],v[i]=true,Q[++t]=i;
	}

	while(h<t){
		x=Q[++h];
		for(i=0;i<E[x].size();i++){
			o=E[x][i];
			if(!v[o]){
				if(o<=n)D[o]=D[x]+w[o];
				else D[o]=D[x]+w[o-n];
				v[o]=true;
				Q[++t]=o;
			}
		}
	}
	for(i=1;i<n;i++){
		if(!v[n+i+1])cout<<-1<<endl;
		else cout << i+D[n+i+1]<<endl;
	}
}