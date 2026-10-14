#include <chrono>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using namespace chrono;

bool dfs(const vector<vector<bool>> &graph, int start, int end) {

  int N = graph.size();
  vector<bool> vector(N);
  stack<int> stack;

  stack.push(start);
  vector[start] = true;
  for (int current; !stack.empty();) {

    current = stack.top();
    if (current == end) return true;

    stack.pop();
    for (int i = 0; i < N; i++)
      if (graph[current][i] == 1 && !vector[i]) {

        stack.push(i);
        vector[i] = true;
      }
  }

  return false;
}

int main() {

  ifstream in("test7.txt");
  if (!in)
  {
    cout << "No file" << endl;
    return 1;
  }

  int start, end, N, M;
  in >> N >> M;
  vector<vector<bool>> graph1(N, (vector<bool>(N)));

  for (int i = 0, a, b; i < M; i++) {
    in >> a >> b;
    graph1[a - 1][b - 1] = true;
  }
  in >> start >> end;
  in.close();

  auto clockStart = high_resolution_clock::now();
  bool isTherePath = dfs(graph1, start - 1, end - 1);
  auto time = duration_cast<milliseconds>(high_resolution_clock::now() - clockStart).count();

  cout << (isTherePath ? "Путь существует" : "Путь не сущетсвует") << endl << "Time: " << time << "ms" << endl;

  return 0;
}
