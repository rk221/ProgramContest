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
	string S, T, sub, ans;
	int i, j, k, tmp, cnt = 0;
	bool flag = true, ansok = false;

	cin >> S;
	cin >> T;
	//後ろから順番に走査
	for (i = S.length() - T.length(); i >= 0; i--) {
		sub = S.substr(i, T.length());//切り抜き
		flag = true;
		for (j = 0; j < T.length(); j++) {
			if (sub[j] != T[j] && sub[j] != '?') {//一致していない
				flag = false;
				break;
			}
		}
		if (flag) {//文字列Tが入る
			ansok = true;
			cnt = i;//cntに文字列格納する位置を退避
			break;
		}
	}

	if (ansok) {//正解ある
		//？の部分はaにして他はそのまま候補以降は普通に
		for (i = 0; i < S.length(); i++) {
			if (i == cnt) {
				i += T.length() - 1;
				printf("%s", T.c_str());
			}
			else if (S[i] == '?') {
				printf("a");
			}
			else {
				printf("%c", S[i]);
			}
		}
	}
	else {//ない
		printf("UNRESTORABLE\n");
	}




	return 0;
}