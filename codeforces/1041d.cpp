#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 200 * 1000 + 555;

int n, h;
pt a[N];

inline bool read() {
	if(!(cin >> n >> h))
		return false;
	fore(i, 0, n)
		assert(scanf("%d%d", &a[i].x, &a[i].y) == 2);
	sort(a, a + n);
	return true;
}

int ps[N];

int getH(int lf, int rg) {
	int l = int(lower_bound(a, a + n, pt(lf, -1)) - a);
	int r = int(lower_bound(a, a + n, pt(rg, -1)) - a);
	
	int sum = ps[r] - ps[l];
	if(l > 0)
		sum += max(0, a[l - 1].y - lf);
	
	assert(rg - lf - sum >= 0);
	return rg - lf - sum;
}

inline void solve() {
	ps[0] = 0;
	fore(i, 0, n)
		ps[i + 1] = ps[i] + (a[i].y - a[i].x);	
	
	int ans = 0;
	fore(i, 0, n) {
		int lx = a[i].y + 1;
		
		int lf = -(h + 1), rg = lx;
		while(rg - lf > 1) {
			int mid = (lf + rg) / 2;
			if(getH(mid, lx) > h)
				lf = mid;
			else
				rg = mid;
		}
		assert(getH(rg, lx) == h);
		ans = max(ans, lx - rg);
	}
	cout << ans << endl;
}

int main() {
	if(read()) {
		solve();
	}
	return 0;
}