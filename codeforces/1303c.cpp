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
        int st = 250,end = 250,cur = 250;
        map<char,int> M;
        string a;
        cin>>a;

        int n = a.length();
        int f = 1;
        vector<char> ans(500,1);

        ans[250] = a[0];
        M[a[0]]++;

        rep(i,n,1){
            // cout<<i+1<<" of "<<n<<" : "<<st<<" "<<end<<" "<<cur<<endl;
            if(!M.count(a[i])){
                if(cur != st && cur != end){
                    f = 0;
                    break;
                }

                if(cur == st){
                    cur--;
                    st--;
                }
                else{
                    cur++;
                    end++;
                }
                ans[cur] = a[i];
                M[a[i]]++;
            }
            else{
                if(ans[cur+1] == a[i])cur++;
                else if(ans[cur-1] == a[i])cur--;
                else{
                    f = 0;
                    break;
                }
            }
        }

        if(!f){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;

        for(char ch = 'a';ch <= 'z'; ch++){
            if(!M.count(ch)){
                end++;
                ans[end] = ch;
            }
        }

        for(int i = st; i<= end; i++){
            cout<<ans[i];
        }
        nl;
    }
}