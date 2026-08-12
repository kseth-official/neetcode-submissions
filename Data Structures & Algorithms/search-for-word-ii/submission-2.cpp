class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;

    ~TrieNode() {
        for (auto& pair: children) {
            delete pair.second;
        }
    }
};

class Trie {    

public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
        root->isWord = false;
    }

    void insert(string word) {
        auto* temp = root;
        for (const char& c: word) {
            if (temp->children.find(c) == temp->children.end()) 
                temp->children[c] = new TrieNode();
            temp = temp->children[c];
        }
        temp->isWord = true;
    }

    bool search(string word) {
        auto* temp = root;
        for (const char& c: word) {
            if (temp->children.find(c) == temp->children.end()) 
                return false;
            temp = temp->children[c];
        }
        return temp->isWord;
    }

    bool startsWith(string prefix) {
        auto* temp = root;
        for (const char& c: prefix) {
            if (temp->children.find(c) == temp->children.end()) 
                return false;
            temp = temp->children[c];
        }
        return true;
    }

    ~Trie() {
        delete root;
    }
};


class Solution {
public:
    int ROWS;
    int COLS;
    vector<string> result;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (const auto& word: words) {
            trie.insert(word);
        }

        ROWS = board.size();
        COLS = board[0].size();

        for (int i=0;i<ROWS;i++) {
            for (int j=0;j<COLS;j++) {
                dfs(board, i, j, trie.root, "");
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        if (r < 0 || r == ROWS || c < 0 || c == COLS || board[r][c] == '#' || !node->children.count(board[r][c]))
            return;
        
        char ch = board[r][c];
        word += ch;

        node = node->children[ch];
        if (node->isWord) {
            result.push_back(word);

            // to prevent duplicate additions
            node->isWord = false;
        }
            

        // Using in-place visit markings that are more space efficient
        board[r][c] = '#';

        dfs(board, r+1, c, node, word);
        dfs(board, r, c+1, node, word);
        dfs(board, r-1, c, node, word);
        dfs(board, r, c-1, node, word);


        // Resetting the board on completion
        board[r][c] = ch;
    }
};
