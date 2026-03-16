#include <iostream>
#include <queue>
using namespace std;

bool visited[5];

// DFS
void DFS(int graph[5][5], int v){
    visited[v] = true;
    cout << v << " ";

    for(int i = 0; i < 5; i++){
        if(graph[v][i] == 1 && !visited[i]){
            DFS(graph, i);
        }
    }
}

// BFS
void BFS(int graph[5][5], int start){
    bool visit[5] = {false};
    queue<int> q;

    visit[start] = true;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        cout << v << " ";
        q.pop();

        for(int i = 0; i < 5; i++){
            if(graph[v][i] == 1 && !visit[i]){
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int graph[5][5] = {
        {0,1,1,0,0},
        {0,0,0,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    cout << "DFS: ";
    DFS(graph,0);

    cout << endl;

    cout << "BFS: ";
    BFS(graph,0);

    return 0;
}