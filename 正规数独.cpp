#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>

#define all(x) (x).begin(), (x).end();

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef map<int, int> mii;

using namespace std;

const int N = 10;
int f[N][N];
int b1[N][N], b2[N][N], b3[N][N];
int n, cnt = 0;

void dfs(int x) {
	if (x > 81) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << f[i][j] << " ";
				if (j % 3 == 0) {
					cout << "|";
				}
			}
			if (i % 3 == 0) {
				cout << '\n' << "-------------------";
			}
			cout << '\n';
		}
		return;
	}
	int row = (x - 1) / 9 + 1;
	int col = (x - 1) % 9 + 1;
	int block = (row - 1) / 3 * 3 + (col - 1) / 3 + 1;
	if (f[row][col] != 0) {
		dfs(x + 1);
	} else { 
		for (int i = 1; i <= 9; i++) {
			if (b1[row][i] == 0 && b2[col][i] == 0 && b3[block][i] == 0) {
				f[row][col] = i;
				b1[row][i] = 1;
				b2[col][i] = 1;
				b3[block][i] = 1;
				dfs(x + 1);
				f[row][col] = 0;
				b1[row][i] = 0;
				b2[col][i] = 0;
				b3[block][i] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> f[i][j];
			if (f[i][j] != 0) {
				cnt++;
			}
			b1[i][f[i][j]] = 1;
			b2[j][f[i][j]] = 1;
			int block = (i - 1) / 3 * 3 + (j - 1) / 3 + 1;
			b3[block][f[i][j]] = 1;
		}
	}
	dfs(1);
#ifdef LOCAL
	cerr << "TIME ELAPSED: " << clock() << " ms" << endl;
#endif
	return 0;
}