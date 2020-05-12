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
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        vector<char> ans(n,'-');
        map <char,int> M;
        M['R']=a;
        M['P']=b;
        M['S']=c;

        string s;
        cin>>s;

        vector <char> ops = {'R','P','S'};

        lli score=0;
        rep(i,n,0){
            if(s[i] == 'R'){
                if(M['P']){
                    M['P']--;
                    score++;
                    ans[i]='P';
                }
            }
            else if(s[i] == 'P'){
                if(M['S']){
                    M['S']--;
                    score++;
                    ans[i]='S';
                }
            }
            else{
                if(M['R']){
                    M['R']--;
                    score++;
                    ans[i]='R';
                }
            }
        }

        if(score >= n/2 +n%2){
            cout<<"YES"<<endl;
            rep(i,n,0){
                if(ans[i] == '-'){
                    for(auto x: ops){
                        if(M[x]){
                            ans[i]=x;
                            M[x]--;
                            break;
                        }
                    }
                }
            }
            rep(i,n,0)cout<<ans[i];
            nl;
        }
        else cout<<"NO"<<endl;
    }
}