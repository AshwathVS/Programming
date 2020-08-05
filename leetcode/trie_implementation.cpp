class Trie {
public:
    /** Initialize your data structure here. */

    map<char, Trie*> nodes;
    bool isLeaf;

    Trie(bool isLeaf) {
        this->isLeaf = isLeaf;
        nodes = {};
    }

    Trie() {
        isLeaf = false;
        nodes = {};
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* iter = this;
        for (int i=0; i<word.length(); i++) {
            char c = word[i];
            if (iter->nodes.find(c) != iter->nodes.end()) {
                iter = iter->nodes.at(c);
            } else {
                iter->nodes.insert({c, new Trie});
                iter = iter->nodes[c];
            }
        }
        iter->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* iter = this;
        for(int i=0; i<word.length(); i++) {
            char c = word[i];
            if(iter->nodes.find(c) == iter->nodes.end()) return false;

            iter = iter->nodes[c];
        }
        return iter->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* iter = this;
        for(char i : prefix) {
            if(iter->nodes.find(i) == iter->nodes.end()) return false;
            iter = iter->nodes.at(i);
        }
        return true;
    }
};
