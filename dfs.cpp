#include<bits/stdc++.h>
using namespace std;

bool inRange(int i, int j, int n, int m) {
	if(0 <= i && i < n && 0 <= j && j < m) return true;
	return false;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int visited[10001][10001];

void dfs(int i, int j, int n, int m, int visited[10001][10001], int &count) {
	visited[i][j] = 1;
	count++;
	for(int k = 0; k < 4; k++) {
		int x = i+dx[k];
		int y = j+dy[k];
		if(inRange(x, y, n, m)) {
			if(visited[x][y] == 0) {
				dfs(x, y, n, m, visited, count);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		char arr[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if(arr[i][j] == '.') visited[i][j] = 0;
				else visited[i][j] = 1;
			}
		}

		vector<int> v;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int count = 0;
				if(visited[i][j] == 0) {
					dfs(i, j, n, m, visited, count);
					v.push_back(count);
				}
			}
		}

		cout << v.size() << endl;
		for(int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
