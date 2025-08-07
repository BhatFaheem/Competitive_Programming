struct Node{
    int max_ind = -1;
    int min_ind = INF;
};
vector<Node>segtree;
class SegmentTree {
public:
    int n;
    SegmentTree(int n)
    {
        this->n = n;
        segtree.resize(4 * n + 1);
    }
    Node merge(Node & a , Node & b)
    {
        Node node;
        node.max_ind = max(a.max_ind , b.max_ind);
        node.min_ind = min(a.min_ind , b.min_ind);
        return node;
    }
    void build(vector<int>& arr , int start , int end , int ind)
    {
        if (start == end)
        {
            segtree[ind].min_ind = segtree[ind].max_ind = start;
            return;
        }
        int left = 2 * ind , right = 2 * ind + 1;
        int mid = (start + end) / 2;
        build(arr , start , mid , left);
        build(arr , mid + 1 , end , right);
        segtree[ind] = merge(segtree[left] , segtree[right]);
    }
    void update(int start , int end , int ind , int pos)
    {
        if (start == end)
        {
            segtree[ind].max_ind = -1;
            segtree[ind].min_ind = INF;
            return;
        }
        int left = 2 * ind , right = 2 * ind + 1;
        int mid = (start + end) / 2;
        if (mid >= pos) update(start , mid , left , pos );
        else update(mid + 1 , end , right ,  pos );
        segtree[ind] = merge(segtree[left] , segtree[right]);
    }
    Node query(int start  , int end , int ind , int l , int r)
    {
        if (start >= l && end <= r) return segtree[ind];
        if (l > end || r < start) return Node();
        int mid = (start + end) / 2;
        Node leftans = query(start , mid , 2 * ind , l , r);
        Node rightans = query(mid + 1 ,  end , 2 * ind + 1 , l , r);
        return merge(leftans , rightans);
    }
    void build(vector<int>& arr){
        build(arr , 0 , n-1 , 1);
    }
    void update(int pos){
        update(0 , n-1 , 1 , pos);
    }
    Node query(int l , int r){
        return query(0 , n-1 , 1 , l , r);
    }
 
};
