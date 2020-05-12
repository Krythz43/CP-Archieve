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

vector<int> bit(32,0);
vector<int> nbit(32,0);
vector<int> ans(32,0);

int fans = 0;

void conv(int x){
    int l = 0;
    while(x){
        if(x%2)bit[l]++;
        else nbit[l]++;
        x /= 2;
        l++;
    }
    while(l<32)nbit[l++]++;
}

void solve(){
    lli cur,carry = 0;

    rep(i,32,0){
        cur = bit[i]*nbit[i]+carry;
        ans[i] = cur%2;
        carry = (bit[i] > 1)*(bit[i]*(bit[i]-1))/2 + carry*(bit[i]*nbit[i]);
        cout<<i<<" "<<bit[i]<<" "<<carry<<endl;
    }

    cur = 1;
    rep(i,32,0){
        if(ans[i])fans+=cur;
        cur*=2;
    }
}

long long int sumXOR(int arr[], int n) 
{ 
    long long int sum = 0; 
    for (int i = 0; i < 32; i++)  
    { 
        //  Count of zeros and ones 
        int zc = 0, oc = 0;  
          
        // Individual sum at each bit position 
        long long int idsum = 0;  
        for (int j = 0; j < n; j++) 
        { 
            if (arr[j] % 2 == 0) 
                zc++; 
            else
                oc++; 
            arr[j] /= 2; 
        } 
          
        // calculating individual bit sum  
        idsum = oc * zc * (1 << i);  
  
        // final sum     
        sum += idsum;  
    } 
    return sum; 
} 
  
  
int main()
{
    fastio;
    int n;
    cin>>n;
    vinput(a,n);
    rep(i,n,0)conv(a[i]);
    solve();
    cout<<fans<<endl;
}