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

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		lli a,b,c,c1,c2,ans1,ans2,ans3;
		cin>>a>>b>>c;
		lli ans = inf;
		lli temp;

		rep(A,2*a+1,1){
			for(int B=A;B <= 2*b; B+=A){
				c1 = ((c+B)/B)*B;
				c2 =c1 - B;
				if(c2<0)c2=c1;

				// cout<<A<<" "<<B<<" "<<c1<<" "<<c2<<endl;

				if(c1 >= B && ans > abs(A-a)+abs(B-b) + abs(c-c1)){
					ans=abs(A-a)+abs(B-b) + abs(c-c1);
					ans1 = A;
					ans2 = B;
					ans3 = c1;
				}

				if(c2 >= B && ans > abs(A-a)+abs(B-b) + abs(c-c2)){
					ans=abs(A-a)+abs(B-b) + abs(c-c2);
					ans1 = A;
					ans2 = B;
					ans3 = c2;
				}
			}
		}
	
		cout<<ans<<endl;
		cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
	}
}