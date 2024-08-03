static class DSU {
    vector<int> Parent, Rank;
    public:
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};
// Size Based
class DSU {
    vector<int> Parent, size;
public:
    DSU(int n) {
        Parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            if (size[xset] < size[yset])
            {
                swap(xset , yset);
            }
            Parent[yset] = xset;
            size[xset] += size[yset];
        }
        return false;
    }
};
