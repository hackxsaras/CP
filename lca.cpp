ll maxk = 20;
vvi up(sz, vi(maxk, -1));
vi adj[sz];
int timer = 0;
vi tin(sz), tout(sz);

void pre(int node, int par){
    tin[node] = timer++;
    up[node][0] = par;
    for(int i=1;i<=18;i++){
        int p = up[node][i-1];
        up[node][i] = up[p][i-1];
    }
    for(int i:adj[node]){
        if(i != par){
            pre(i, node);
        }
    }
    tout[node] = timer++;
}
bool isancestor(int u,int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v){
    if(isancestor(u, v))return u;
    if(isancestor(v, u))return v;
    for(int i = 18;i >= 0; i--){
        if(!isancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}