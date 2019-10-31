#include<bits/stdc++.h>
#pragma GCC diagnostic warning "-std=c++17"
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,m,mx=0,mn=100000000000000,a[100005],b[100005],ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    
    for(int i=1; i<=m; i++){
        cin >> b[i];
        mn = min(mn,b[i]);
    }
    
    if(mn < mx){
        cout << -1;
        return 0;
    }
    
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    
    
    for(int i=2; i<=m; i++){
        ans += b[i];
    }
    if(b[1] == a[n]){
        ans += b[1];
        for(int i=1; i<n; i++)ans += m * a[i];
        cout << ans;
    }
    else {
        ans += a[n];
        ans += b[1];
        ans += (m - 1) * a[n - 1];
        for(int i=1; i<=n-2; i++)ans += m * a[i];
        cout << ans;
    }
    
    
    
    
    return 0;
}
