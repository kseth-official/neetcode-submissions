class PrefixTreeNode {
public:
    unordered_map<char, PrefixTreeNode*> children;
    bool isWord;

    ~PrefixTreeNode() {
        for (auto& pair: children)
            delete pair.second;
    }
};

class PrefixTree {
public:
    PrefixTreeNode* root;

    PrefixTree() {
        root = new PrefixTreeNode();
        root->isWord = false;
    }
    
    void insert(string word) {
        auto* temp = root;
        for (char c: word) {
            if (temp->children.find(c) == temp->children.end()) 
                temp->children[c] = new PrefixTreeNode();
            temp = temp->children[c];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        auto* temp = root;
        for (char c: word) {
            if (temp->children.find(c) == temp->children.end()) 
                return false;
            temp = temp->children[c];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        auto* temp = root;
        for (char c: prefix) {
            if (temp->children.find(c) == temp->children.end()) 
                return false;
            temp = temp->children[c];
        }
        return true;
    }

    ~PrefixTree() {
        delete root;
    }
};
