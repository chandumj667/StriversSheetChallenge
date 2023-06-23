/*
    M – Coloring Problem
    Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.


    Example 1:
    Input:
    N = 4
    M = 3
    E = 5
    Edges[] = {
        (0, 1),
        (1, 2),
        (2, 3),
        (3, 0),
        (0, 2)
    }
    Output: 1
    Explanation: It is possible to colour the given graph using 3 colours.

    Example 2:
    Input:
    N = 3
    M = 2
    E = 3
    Edges[] = {
        (0, 1),
        (1, 2),
        (0, 2)
    }
    Output: 0
    Explanation: It is not possible to color.

    Approach: By checking each color for each node and checking its adjacent nodes if possible then we can return true if not return false

    Time complexity: O(N^m)
    Space complexity: O(N)
*/

#include<bits/stdc++.h>
using namespace std;


bool is_safe(int node, int colors[], bool graph[101][101], int n, int col){
    for (int k = 0; k < n; k++){
        if(k!=node && graph[k][node]==1 && colors[k]==col){
            return false;
        }
    }
    return true;
}

bool solve(int node, int colors[], int m, int n, bool graph[101][101]){
    if(node == n){
        return true;
    }
    for (int i = 1; i <= m; i++){
        if(is_safe(node, colors, graph, n, i)){
            colors[node] = i;
            if(solve(node+1, colors, m, n, graph))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

bool graph_col(bool graph[101][101], int m, int n){
    int colors[n] = {0};
    if(solve(0, colors, m, n, graph))
        return true;

    return false;
}


int main(){
    int n = 4;
    int m = 3;
    bool graph[101][101];
    memset(graph, false, sizeof graph);
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[3][0] = 1;
    graph[0][3] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;

    graph_col(graph, m, n)?cout<<"Possible to color 'm' colors":cout<< "Impossible to color 'm' colors";
    return 0;
}