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
	constexpr int AB_MAX = 2, A = 0, B = 0;
	int N, M, a, b, tmp, ans;
	vector<vector<int>> ab;
	int dp[AB_MAX] = {-1,10000000};

	scanf("%d %d", &N, &M);
	int i, j, k;
	rep(i, M) {
		scanf("%d %d", &a, &b);
		vector<int> t;
		t.push_back(a);
		t.push_back(b);
		ab.push_back(t);
	}
	sort(ab.begin(), ab.end());
	ans = 1;
	rep(i, M) {//全部の要望
		a = ab.at(i).at(0);//一旦保持
		b = ab.at(i).at(1);

		//最善を求めていく→dpへ格納
		//前方比較
		if (a >= dp[0]) {//最善より大きい
			if (a >= dp[1]) {//最善の後方と一緒または大きい
				ans++;//最善を一つ進める
				dp[0] = a;
				dp[1] = b;
			}
			//後方比較
			if (b < dp[1]) {//最善より小さい
				dp[1] = b;//最善を狭める
			}
		}
	}

	printf("%d", ans);

	return 0;
}