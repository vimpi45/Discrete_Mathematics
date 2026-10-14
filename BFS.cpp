#include <chrono>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using namespace chrono;

bool bfs(const vector<vector<bool>> &graph, int start, int end)
{

  vector<bool> visited(graph.size(), false);
  visited[start] = true;

  queue<int> que;
  que.push(start);

  for (int current; !que.empty();)
  {

    current = que.front();
    if (current == end)
      return true;

    que.pop();
    for (int i = 0; i < graph.size(); i++)
      if (graph[current][i] == 1 && !visited[i])
      {
        visited[i] = true;
        que.push(i);
      }
  }

  return false;
}

int main()
{
  ifstream in("test7.txt");
  if (!in)
  {
    cout << "No file" << endl;
    return 1;
  }

  int N, M, start, end;
  in >> N >> M;
  vector<vector<bool>> graph(N, vector<bool>(N));

  for (int a, b, i = 0; i < M; i++)
  {
    in >> a >> b;
    graph[a - 1][b - 1] = true;
  }
  in >> start >> end;
  in.close();

  auto clockStart = high_resolution_clock::now();
  bool isTherePath = bfs(graph, start - 1, end - 1);
  auto time = duration_cast<milliseconds>(high_resolution_clock::now() - clockStart).count();

  cout << (isTherePath ? "Путь существует" : "Путь не сущетсвует") << endl << "Time: " << time << "ms" << endl;

  return 0;
}
