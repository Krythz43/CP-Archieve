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
#define printaay(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}nl;
#define vinput(a,n) vlli a(n);rep(i,n,0)cin>>a[i]
#define ainput(a,n) rep(i,n,0)cin>>a[i]
#define SO(a) sort(a.begin(),a.end())
#define all(x) (x).begin(),(x).end()
#define SOP(a,comp) sort(a.begin(),a.end(),comp)
#define inf INT_MAX
#define endl '\n'

vlli a;
int n;

lli merge(lli temp[], int left, int mid, int right)  
{  
    int i, j, k;  
    lli inv_count = 0;  
  
    i = left;
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right))  
    {  
        if (a[i] <= a[j]) 
        {  
            temp[k++] = a[i++];  
        }  
        else 
        {  
            temp[k++] = a[j++];
            inv_count = inv_count + (mid - i);  
        }  
    }  

    while (i <= mid - 1)  
        temp[k++] = a[i++];  
  
    
    while (j <= right)  
        temp[k++] = a[j++];  
  
    for (i = left; i <= right; i++)  
        a[i] = temp[i];  
  
    return inv_count;  
} 

lli solve(lli temp[], int l,int r){
    int inv=0,mid;

    if(r>l){
        mid=(l+r)/2;
        inv = solve(temp,l, mid);  
        inv += solve(temp,mid + 1, r);
        inv += merge(temp, l, mid + 1, r);  
    }

    return inv;
}


int main()
{
    fastio;
    cin>>n;
    lli temp[n];
    a.resize(n);
    ainput(a,n);
    int inv=solve(temp,0,n-1);

    if((inv&1)^(n&1))
    cout<<"Um_nik"<<endl;
    else cout<<"Petr"<<endl;
}