vector<int> adj[sz];
set<int> vec[sz];
//count distinct colors in subtree - O(log^2 n)
vector<int> col(sz);
vector<int> ans(sz);
void dfs(int u, int v){
    int bigchild = -1, maxsz = 0;
    for(int i:adj[u]){
        if(i==v)continue;
        dfs(i, u);
        if(maxsz < vec[i].size()){
            bigchild = i;
            maxsz = vec[i].size();
        }
    }
    if(bigchild!=-1){
        swap(vec[u], vec[bigchild]);
    }
    vec[u].insert(col[u]);
    for(int i:adj[u]){
        if(i==v || i==bigchild)continue;
        for(auto x:vec[i]){
            vec[u].insert(x);
        }
    }
    ans[u] = vec[u].size();
}
