class Trie {
public:
    struct Node {
        bool isEnd;
        char letter;
        std::vector<Node*> children;
        Node() :isEnd(false), letter(0) {}
    };
    Node* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* current = root,
            * last=nullptr;
        for (auto c : word) {
            if (!c) break;
            last = current;
            current = nullptr;
            for (auto child : last->children) {
                if (child->letter == c) {
                    current = child;
                    break;
                }
            }
            if (!current) {
                Node* some = new Node();
                some->letter = c;
                last->children.push_back(some);
                current = some;
            }
        }
        current->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* current = root,
            * last;
        for (auto c : word) {
            if (!c) break;
            last = current;
            current = nullptr;
            for (auto child : last->children) {
                if (child->letter == c) {
                    current = child;
                    break;
                }
            }
            if (!current) return false;
        }
        if (current->isEnd) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* current = root,
            * last;
        for (auto c : prefix) {
            if (!c) break;
            last = current;
            current = nullptr;
            for (auto child : last->children) {
                if (child->letter == c) {
                    current = child;
                    break;
                }
            }
            if (!current) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */