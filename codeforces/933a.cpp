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

const int N = 2020;
int n;
int a[N];
int ans = 0;

int32_t main()
{
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int z = 0; z <= n; z++) {
		int ans1 = 0, ans2 = 0;
		int sum = 0;
		for (int i = 0; i < z; i++)
			sum += (int)(a[i] == 1);
		ans1 = max(ans1, sum);
		for (int i = z - 1; i >= 0; i--) {
			if (a[i] == 1)
				sum--;
			else
				sum++;
			ans1 = max(ans1, sum);
		}
		sum = 0;
		for (int i = z; i < n; i++)
			sum += (int)(a[i] == 2);
		ans2 = max(ans2, sum);
		for (int i = z; i < n; i++) {
			if (a[i] == 1)
				sum++;
			else
				sum--;
			ans2 = max(ans2, sum);
		}
		ans = max(ans, ans1 + ans2);
	}
	printf("%d\n", ans);
 
	return 0;
}