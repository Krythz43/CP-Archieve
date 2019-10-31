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
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'
map<string,int> m;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char c;
		cin >> c;
		if(c == '+' || c == '-')
		{
			string a;
			cin >> a;
			string s(18,'0');
			for(int i = a.length() - 1 ,j = 17 ; i >= 0; i--,j--)
			{
				if((a[i] - '0') % 2 == 1)
				s[j] = '1';
			}
			if(c == '+')
			m[s]++;
			else 
			m[s]--;
		}
		else if(c == '?')
		{
			string a,t(18,'0');
			cin >> a;
			for(int i = a.length() - 1,j = 17; i >= 0; i--,j--)
			t[j] = a[i];
			cout << m[t] << endl;
		}
	}
}