#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

const uLL MAX_N = 1000000 + 5, MAX_K = 10000 + 5;

int T;
uLL N, K, X1, Y1, C, D, E1, E2, F;

uLL A[MAX_N];


LL quick_pow_with_mod(LL x, LL n, LL m) {
	LL res = 1;
	while (n > 0) {
		if (n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}


/************ solution for small dataset ***********/
uLL solution() {
	uLL ans = 0;
	for (int k = 1; k <= K; ++k)
		for (int L = 1; L <= N; ++L)
			for (int R = L; R <= N; ++R)
				for (int j = L; j <= R; ++j) {
					ans += A[j] * quick_pow_with_mod(j - L + 1, k, MOD);
					ans %= MOD;
				}
	return ans;
}


int main() {
	// redirection
	if (1) {
		freopen("C-small-practice.in", "r", stdin);
		freopen("C-small-practice.out", "w", stdout);
	}

	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		
		cin >> N >> K >> X1 >> Y1 >> C >> D >> E1 >> E2 >> F;
		A[1] = (X1 + Y1) % F;
		uLL xi_1 = X1, yi_1 = Y1, xi, yi;
		for (int i = 2; i <= N; ++i) {
			xi = (C * xi_1 + D * yi_1 + E1) % F;
			yi = (D * xi_1 + C * yi_1 + E2) % F;
			A[i] = (xi + yi) % F;
			xi_1 = xi;
			yi_1 = yi;
		}
		uLL ans = solution();
		cout << "Case #" << t << ": " << ans;
		cout << endl;
	}
}

