class Trie {
private:
    vector<Trie*> v = vector<Trie*>(26, NULL);
    bool end = false;
public:
    void markEnd() {
        end = true;
    }

    bool isEnd() {
        return this->end;
    }

    void set(int index, Trie* node) {
        v[index] = node;
    }

    Trie* get(int index) {
        return v[index];
    }
};

class WordDictionary {
private:
    Trie *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
//        cout << "dic->addWord(\"" + word + "\");" << endl;
        Trie *node = root;
        for (int i = 0; i < word.size(); i++) {
            int val = word[i] - 97;
            if(node->get(val) != NULL) node = node->get(val);
            else {
                node->set(val, new Trie());
                node = node->get(val);
            }
        }
        node->markEnd();
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
//        cout << "cout << dic->search(\"" + word + "\") << endl;" << endl;
        return recursiveSearch(word, 0, root);
    }

    bool recursiveSearch(string word, int index, Trie *node) {
        if (index == word.size()) {
            return node->isEnd();
        }
        else if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->get(i) != NULL && recursiveSearch(word, index + 1, node->get(i))) return true;
            }
        } else {
            int val = word[index] - 97;
            if (node->get(val) != NULL) return recursiveSearch(word, index + 1, node->get(val));
        }
        return false;
    }
};