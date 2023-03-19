#include<bits/stdc++.h>

const int not_visited = 0;
const int dx[]{ 1,-1,0,0 };
const int dy[]{ 0, 0,1,-1};

std::vector<std::vector<int>> map;
std::vector<std::vector<int>> dp;

int dfs(int i,int j) 
{
	int& cost = dp[i][j];

	if (cost != not_visited)
		return cost;

	cost = 1;

	for (int dir = 0; dir < 4; dir++)
	{
		int ni = i + dx[dir];
		int nj = j + dy[dir];

		if (map[i][j] < map[ni][nj])
			cost = std::max(cost, 1 + dfs(ni,nj));
	}

	return cost;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	map.resize(n+2, std::vector<int>(n+2, -1));
	dp.resize(n+2, std::vector<int>(n+2, not_visited));

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		std::cin >> map[i][j];

	int cost = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		cost = std::max(cost,dfs(i,j));

	std::cout << cost;

	return 0;
}