struct Node {
    Node * links[26];
    bool flag = false;
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch , Node * node)
    {
        links[ch - 'a'] = node;
    }
    Node * getWord(char ch) {
        return links[ch - 'a'];
    }
    bool setEnd()
    {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node * root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node * node = root;
        for (auto w : word)
        {
            if ((!node->containsKey(w)))
            {
                node->put(w , new Node());
            }
            node = node->getWord(w);
        }
        node->setEnd();
    }
    bool searchWord(string word)
    {
        Node * node = root;
        // cout << word << endl;
        for (auto w : word)
        {
            if (!(node->containsKey(w))) return false;
            // cout << node << endl;
            node = node->getWord(w);
        }
        // cout << node->isEnd() << endl;
        return node->isEnd();
    }
    bool startsWith(string word)
    {
        Node * node = root;
        for (auto w : word)
        {
            if (!(node->containsKey(w))) return false;
            node = node->getWord(w);
        }
        return true;
    }
};
