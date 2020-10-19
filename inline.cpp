

template <typename num_t> struct segtree {  int n, depth;  vector<num_t> tree, lazy;   void init(vl& arr) {    n = arr.size();    tree = vector<num_t>(4 * n, 0);    lazy = vector<num_t>(4 * n, 0);    init(0, 0, n - 1, arr);  }   num_t init(int i, int l, int r, vl& arr) {    if (l == r) return tree[i] = arr[l];     int mid = (l + r) / 2;    num_t a = init(2 * i + 1, l, mid, arr),          b = init(2 * i + 2, mid + 1, r, arr);    return tree[i] = a.op(b);  }  void pointupdate(int q, num_t v){      pointupdate(0, 0, n-1, q, v);  }  num_t pointupdate(int i, int tl, int tr, int q, num_t v){        if (tl > tr || tr < q || q < tl) return tree[i];        if(tl == q && tr == q)return tree[i].val = tree[i].val + v.val;        int mid = (tl + tr)/2;    num_t a = pointupdate(2 * i + 1, tl, mid, q, v),          b = pointupdate(2 * i + 2, mid + 1, tr, q, v);    return tree[i] = a.op(b);  }  void update(int l, int r, num_t v) {	if (l > r) return;    update(0, 0, n - 1, l, r, v);  }  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {    eval_lazy(i, tl, tr);		if (tl > tr || tr < ql || qr < tl) return tree[i];    if (ql <= tl && tr <= qr) {      lazy[i] = lazy[i].val + v.val;      eval_lazy(i, tl, tr);      return tree[i];    }        if (tl == tr) return tree[i];     int mid = (tl + tr) / 2;    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);    return tree[i] = a.op(b);  }   num_t query(int l, int r) {	if (l > r) return num_t::null_v;    return query(0, 0, n-1, l, r);  }   num_t query(int i, int tl, int tr, int ql, int qr) {    eval_lazy(i, tl, tr);        if (ql <= tl && tr <= qr) return tree[i];    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;     int mid = (tl + tr) / 2;    num_t a = query(2 * i + 1, tl, mid, ql, qr),          b = query(2 * i + 2, mid + 1, tr, ql, qr);    return a.op(b);  }   void eval_lazy(int i, int l, int r) {    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));    if (l != r) {      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;    }     lazy[i] = num_t();  }};

struct max_t {  long long val;  static const long long null_v = -9223372036854775807LL;  max_t(): val(0) {}  max_t(long long v): val(v) {}  max_t op(max_t& other) {    return max_t(max(val, other.val));  }    max_t lazy_op(max_t& v, int size) {    return max_t(val + v.val);  }};

struct min_t {  long long val;  static const long long null_v = 9223372036854775807LL;  min_t(): val(0) {}  min_t(long long v): val(v) {}  min_t op(min_t& other) {    return min_t(min(val, other.val));  }    min_t lazy_op(min_t& v, int size) {    return min_t(val + v.val);  }};

struct sum_t {  long long val;  static const long long null_v = 0;  sum_t(): val(0) {}  sum_t(long long v): val(v) {}  sum_t op(sum_t& other) {    return sum_t(val + other.val);  }    sum_t lazy_op(sum_t& v, int size) {    return sum_t(val + v.val * size);  }};


/* <LCA> */
ll maxk = 20;
vvi up(sz, vi(maxk, -1));
vi adj[sz];
int timer = 0;
vi tin(sz), tout(sz);
void pre(int node, int par){    tin[node] = timer++;    up[node][0] = par;    for(int i=1;i<=18;i++){        int p = up[node][i-1];        up[node][i] = up[p][i-1];    }    for(int i:adj[node]){        if(i != par){            pre(i, node);        }    }    tout[node] = timer++;}bool isancestor(int u,int v){    return tin[u] <= tin[v] && tout[u] >= tout[v];}int lca(int u, int v){    if(isancestor(u, v))return u;    if(isancestor(v, u))return v;    for(int i = 18;i >= 0; i--){        if(!isancestor(up[u][i], v)){            u = up[u][i];        }    }    return up[u][0];}
/* </LCA> */



/* <OSET> */
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

template <typename num_t> using oset = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
/* </OSET> */



/* <KRUSKAL MST> */
vector<int> par(sz), ran(sz, 1);
int findi(int i){    if(par[i] == i)return i;    return par[i] = findi(par[i]);}void unio(int a, int b){    int ar = findi(a);    int br = findi(b);    if(ran[ar] < ran[br])        par[ar] = br;    else  if(ran[ar] > ran[br])        par[br] = ar;    else        par[br] = ar, ++ran[ar];}
/* </KRUSKAL MST> */

template <typename num_t> struct segtree {  int n, depth;  vector<num_t> tree, lazy;   void init(vl& arr) {    n = arr.size();    tree = vector<num_t>(4 * n, 0);    lazy = vector<num_t>(4 * n, 0);    init(0, 0, n - 1, arr);  }   num_t init(int i, int l, int r, vl& arr) {    if (l == r) return tree[i] = arr[l];     int mid = (l + r) / 2;    num_t a = init(2 * i + 1, l, mid, arr),          b = init(2 * i + 2, mid + 1, r, arr);    return tree[i] = a.op(b);  }  void pointupdate(int q, num_t v){      pointupdate(0, 0, n-1, q, v);  }  num_t pointupdate(int i, int tl, int tr, int q, num_t v){        if (tl > tr || tr < q || q < tl) return tree[i];        if(tl == q && tr == q)return tree[i].val = tree[i].val + v.val;        int mid = (tl + tr)/2;    num_t a = pointupdate(2 * i + 1, tl, mid, q, v),          b = pointupdate(2 * i + 2, mid + 1, tr, q, v);    return tree[i] = a.op(b);  }  void update(int l, int r, num_t v) {	if (l > r) return;    update(0, 0, n - 1, l, r, v);  }  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {    eval_lazy(i, tl, tr);		if (tl > tr || tr < ql || qr < tl) return tree[i];    if (ql <= tl && tr <= qr) {      lazy[i] = lazy[i].val + v.val;      eval_lazy(i, tl, tr);      return tree[i];    }        if (tl == tr) return tree[i];     int mid = (tl + tr) / 2;    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);    return tree[i] = a.op(b);  }   num_t query(int l, int r) {	if (l > r) return num_t::null_v;    return query(0, 0, n-1, l, r);  }   num_t query(int i, int tl, int tr, int ql, int qr) {    eval_lazy(i, tl, tr);        if (ql <= tl && tr <= qr) return tree[i];    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;     int mid = (tl + tr) / 2;    num_t a = query(2 * i + 1, tl, mid, ql, qr),          b = query(2 * i + 2, mid + 1, tr, ql, qr);    return a.op(b);  }   void eval_lazy(int i, int l, int r) {    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));    if (l != r) {      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;    }     lazy[i] = num_t();  }};