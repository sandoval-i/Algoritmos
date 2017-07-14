vector<vector<int>> g;
bitset<MAX_N> visited, used;
int n,k,matching[MAX_K];
// n = numero de nodos en izquierda
// k = numero de nodos en la derecha
// matching[i] = nodo de la izquierda que matchea con i
bool kuhn(int u) {
    if(visited[u])  return false;
    visited[u] = true;
    for(const auto& v: g[u])
        if(matching[v] == -1 || kuhn(matching[v])) {
            matching[v] = u;
            return true;
        }
    return false;
}
int kuhn() { // O(VE)
    int max_matching = 0;
    memset(matching, -1, sizeof matching);
    used.reset();
    foi(u,0,n) // greedy matching
        for(const auto& v: g[u])
            if(matching[v] == -1) {
                ++max_matching;
                matching[v] = u;
                used[u] = true;
                break;
            }
    foi(i,0,n) { // kuhn's algo
        if(used[i]) continue;
        visited.reset();
        max_matching += kuhn(i);
    }
    return max_matching;
}
