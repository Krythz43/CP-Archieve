#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define mp make_pair

const int N = 505;
int n, m, a[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    int row = -1;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)cin>>a[i][j];
        bool check = false;

        for(int j=1;j<m;++j)if(a[i][j] != a[i][0])check = true;

        if(check)row = i;
    }

    vector<int> res(n); 

    int xr = 0;
    for(int i=0;i<n;++i)if(i != row){
        xr ^= a[i][0]; 
        res[i] = 0; 
    }

    if(row == -1 && xr == 0){
        cout<<"NIE\n"; return 0;
    }
    for(int j=0;j<m;++j)if(xr != a[row][j]){
        res[row] = j; break;
    }

    cout<<"TAK\n";
    for(int i=0;i<n;++i)cout<<res[i] + 1<<" ";
    cout<<"\n";

    return 0;
}   