#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <math.h>
#define rep(i,n) for(int i = 0; i <(n); i++)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}


int main(void) {
	int N, K, ans;
	scanf("%d %d", &N, &K);
	ans = K;
	for (int i = 1; i < N; i++) {
		ans *= K - 1;
	}
	printf("%d", ans);

	return 0;
}