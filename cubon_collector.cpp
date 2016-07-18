#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

int cnt[10];
double prob[10];
bool visit[10];
double ans_color;
int g_level;

double dfs(int level, double sum_prob) {
	if (level == g_level-1) {
		for (int i = 0; i < g_level; i++) {
			if (!visit[i])
				return 1 / prob[i];
		}
	}
	double result = 0;
	for (int i = 0; i < g_level; i++) {
		if (!visit[i]) {
			visit[i] = true;
			result += prob[i] / (1 - sum_prob) * (1 / (1 - sum_prob) + dfs(level + 1, sum_prob + prob[i]));
			visit[i] = false;
		}
	}
	return result;
}

double solver_color() {
	cin >> g_level;
	memset(cnt, 0, 10);
	memset(visit, false, 10);
	double sum = 0;
	ans_color = 0;
	for (int i = 0; i < 10; i++) {
		cin >> cnt[i];
		sum += cnt[i];
	}
	for (int i = 0; i < 10; i++) prob[i] = cnt[i] / sum;
	return dfs(0, 0);
}


int main_color() {
	int test_large = 0;
	if (test_large) {
		freopen("D-large.in", "r", stdin);
		freopen("D-large-practice.out", "w", stdout);
	}
	else {
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
	}

	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ":" << endl;
		cout << solver_color() << endl;
	}
	return 1;
}