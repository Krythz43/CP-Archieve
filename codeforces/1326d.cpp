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


int check(vi a){
    int ans = 1;
    rep(i,a.size(),0){
        if(i + 1 == a[i])ans=max(ans,a[i] - 1);
    }
    return ans;
}

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int X;
        int n=s.length();
        int f = 1;

        for(int i=0;i<n/2;i++){
            if(s[i] == s[n-i-1]){
                continue;
            }
            else {
                X = i;
                f = 0;
                break;
            }
        }

        if(f){
            cout<<s<<endl;
            continue;
        }

        string T = "1";
        // cout<<X<<endl;
        string fstr="";
        for(int i=X;i<n-X;i++){
            T += s[i];
            T += "1";
            fstr += s[i];
        }
        // cout<<T<<endl;
        
        vector<int> P(T.size());

        int C = 0, R = -1, rad; 
        for (int i = 0; i < T.length(); ++i) {
            if (i <= R) {
                rad = min(P[2*C-i], R-i); 
            } else {
                rad = 0; 
            }
            // Try to extend
            while (i+rad < T.length() && i-rad >= 0 && T[i-rad] == T[i+rad]) {
                rad++; 
            }
            P[i] = rad;
            if (i + rad - 1 > R) {
                C = i; 
                R = i + rad - 1; 
            }
        }

        // printarray(P,T.size())

        int f1 = check(P);
        reverse(all(P));
        int f2 = check(P);

        // cout<<"Forward pass "<<f1<<endl;
        // cout<<"Backward pass "<<f2<<endl;


        //front
        // cout<<"Case"<<endl;
        rep(i,X,0)cout<<s[i];


        //palin

        if(f1 >= f2){
            rep(i,f1,0)cout<<fstr[i];
        }

        else{
            for(int i = fstr.length()-f2;i<fstr.length();i++)cout<<fstr[i];
        }

        // abck
        for(int i=n-X;i<n;i++){
            cout<<s[i];
        }
        nl;
    }
}