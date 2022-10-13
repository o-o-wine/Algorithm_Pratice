#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N 1001

int vertex_num, edge_num, start_vertex, edge[MAX_N][MAX_N];
bool visited_vertex[MAX_N];

void dfs(int vertex);
void bfs(int vertex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp_a, temp_b;

	memset(edge, 0, sizeof(edge));
	memset(visited_vertex, 0, sizeof(visited_vertex));

	cin >> vertex_num >> edge_num >> start_vertex;

	for (int i = 0; i < edge_num; i++)
	{
		cin >> temp_a >> temp_b;

		edge[temp_a][temp_b] = edge[temp_b][temp_a] = 1;
	}

	dfs(start_vertex);
	cout << "\n";

	memset(visited_vertex, 0, sizeof(visited_vertex));
	bfs(start_vertex);

	return 0;
}

void dfs(int vertex)
{
	visited_vertex[vertex] = true;
	cout << vertex << " ";

	for (int next = 1; next <= vertex_num; ++next)
	{
		if (!visited_vertex[next] && edge[vertex][next])
			dfs(next);
	}
}

void bfs(int vertex)
{
	queue <int> bfsq;
	int cur = vertex;

	bfsq.push(cur);
	visited_vertex[cur] = true;
	
	while (!bfsq.empty())
	{
		cur = bfsq.front();

		for (int next = 1; next <= vertex_num; ++next)
		{
			if (!visited_vertex[next] && edge[cur][next])
			{
				bfsq.push(next);
				visited_vertex[next] = true;
			}
		}

		cout << cur << " ";
		bfsq.pop();
	}
}
