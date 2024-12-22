class Node {
public:
    Node() {
        this->word = false;

        for (int i = 0; i < 26; i++) {
            this->children[i] = nullptr;
        }
    }

    Node* children[26];
    bool word = false;

    Node* find(char c) {
        return this->children[c - 'a'];
    }

    Node* upsert(char c) {
        Node* found = this->find(c);
        if (found != nullptr) return found;
        Node* new_node = new Node();
        this->children[c - 'a'] = new_node;
        return new_node;
    }
};


class Trie {
public:
    Node* head;

    Trie() {
        this->head = new Node();    
    }
    
    void insert(string word) {
        Node* current = this->head;
        for (char c : word) {
            current = current->upsert(c);
        }
        current->word = true;
    }
    
    bool search(string word) {
        Node* current = head;
        for (char c : word) {
            current = current->find(c);
            if (current == nullptr) return false;
        }
        return current->word;
    }
    
    bool startsWith(string prefix) {
        Node* current = head;
        for (char c : prefix) {
            current = current->find(c);
            if (current == nullptr) return false;
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