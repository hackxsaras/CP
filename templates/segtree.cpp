template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;
 
  void init(vl& arr) {
    n = arr.size();
    tree = vector<num_t>(4 * n, 0);
    lazy = vector<num_t>(4 * n, 0);
    init(0, 0, n - 1, arr);
  }
 
  num_t init(int i, int l, int r, vl& arr) {
    if (l == r) return tree[i] = arr[l];
 
    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }
  void pointupdate(int q, num_t v){
      pointupdate(0, 0, n-1, q, v);
  }
  num_t pointupdate(int i, int tl, int tr, int q, num_t v){
    
    if (tl > tr || tr < q || q < tl) return tree[i];
    
    if(tl == q && tr == q)return tree[i].val = tree[i].val + v.val;
    
    int mid = (tl + tr)/2;
    num_t a = pointupdate(2 * i + 1, tl, mid, q, v),
          b = pointupdate(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = a.op(b);
  }
  void update(int l, int r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }
  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];
 
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }
 
  num_t query(int l, int r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }
 
  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;
 
    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
 
  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
 
    lazy[i] = num_t();
  }
};