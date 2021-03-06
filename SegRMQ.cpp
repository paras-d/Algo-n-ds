    #include "iostream"
    #include "vector"
    #include "climits"
    #define int long long
    using namespace std;
    struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
     
    struct segtree
    {
    	int n;
    	vector <int> array, tree;
    	segtree(vector <int> &a)
    	{
    		array=a, n=a.size();
    		tree.resize(4*n+1);
    		build(1, 0, n-1);
    	}
    	void build(int node, int left, int right)
    	{
    		if (left==right)
    		{
    			tree[node]=array[left];
    			return;
    		}
    		build(2*node, left, (left+right)/2);
    		build(2*node+1, (left+right)/2+1, right);
    		tree[node]=min(tree[2*node], tree[2*node+1]);
    	}
    	int query(int node, int left, int right, int qleft, int qright)
    	{
    		if (left>qright or right<qleft) return INT_MAX;
    		else if (left>=qleft and right<=qright) return tree[node];
    		else return min( query(2*node, left, (left+right)/2, qleft, qright), query(2*node+1, (left+right)/2+1, right, qleft, qright) );
    	}
    };
     
    int main()
    {
    	int n, q; cin >> n >> q;
    	vector <int> a(n);
    	for (int i=0; i<n; i++) cin >> a[i];
    	segtree s(a);
    	while(q--) {
    	int i, j; cin >> i >> j;
    	cout << s.query(1, 0, n-1, i-1, j-1) << '\n';
    }} 
