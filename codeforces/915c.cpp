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


 
string s,b,ans="";
int pos = 0;
bool cho[20];
inline bool check() {
	string ok="";
	int len1 = s.length(); 
	for(int i=0;i<len1;i++)
		if(!cho[i])
			ok+=s[i];
	int len2 = ok.length();
	for(int i=0;i<len2;i++) {
		if(ok[i]<b[i+pos+1])
			return 0;
		if(ok[i]==b[i+pos+1])
			continue;
		if(ok[i]>b[i+pos+1])
			return 1;
	}
	return 0;
}

int main() {
	cin>>s>>b;
	sort(s.begin(),s.end());
	if(b.length()>s.length()) {
		reverse(s.begin(),s.end());
		cout<<s<<endl;
		return 0;
	}
	for(int i=s.length()-1;~i;i--) {
		//cout<<i<<" "<<s[i]<<" "<<b[pos]<<" "<<ans<<" "<<cho[i]<<endl;
		if(cho[i])
			continue;
		if(s[i]<b[pos]) {
			ans+=s[i];
			cho[i]=1;
			pos++;
			break;
		}
		else if(s[i]==b[pos]) {
			cho[i]=1;
			if(check()) {
				cho[i]=0;
				continue;
			}
			ans+=s[i];
			i=s.length();
			pos++;
			continue;
		}
	}
	for(int i=s.length()-1;~i;i--)
		if(!cho[i])
			ans+=s[i];
	cout<<ans<<endl; 
}
