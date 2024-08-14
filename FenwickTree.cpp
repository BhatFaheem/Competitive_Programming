vector<int> bit;
struct FenwickTree {
    int n;

    // Constructor to initialize the Fenwick Tree
    FenwickTree(int size) {
        this->n = size + 1;
        bit.assign(n, 0);
    }

    // Function to add 'delta' to the element at index 'idx'
    void add(int idx, int delta) {
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    // Function to get the sum from index 1 to 'idx'
    int sum(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    // Function to get the sum of elements in the range [l, r]
    int range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
