class PrefixTreeNode {
public:
    unordered_map<char, PrefixTreeNode*> children;
    bool isWord;

    ~PrefixTreeNode() {
        for (auto& pair: children)
            delete pair.second;
    }
};

class WordDictionary {
    PrefixTreeNode* root;
public:

    WordDictionary() {
        root = new PrefixTreeNode();
        root->isWord = false;
    }
    
    void addWord(string word) {
        auto* temp = root;
        for (char c: word) {
            if (temp->children.find(c) == temp->children.end()) 
                temp->children[c] = new PrefixTreeNode();
            temp = temp->children[c];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }

    bool searchHelper(string word, int index, PrefixTreeNode* node) {
        if (!node) return false;
        if (index == word.size()) return node->isWord;
        if (word[index] == '.') {
            for (auto pair: node->children) {
                if (searchHelper(word, index+1, pair.second))
                    return true;
            }
            return false;
        }
        if (node->children.find(word[index]) != node->children.end()) {
            return searchHelper(word, index+1, node->children[word[index]]);
        }
        return false;
    }

    ~WordDictionary() {
        delete root;
    }
};
