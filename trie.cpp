#include <iostream>
#include <unordered_map>
using namespace std;

// Cấu trúc của một node trong Trie
struct TrieNode {
    unordered_map<char, TrieNode*> children;  // Bản đồ con
    bool isEndOfWord;  // Đánh dấu nếu đây là điểm kết thúc của một từ
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    // Constructor: Tạo Trie
    Trie() {
        root = new TrieNode();
    }

    // Hàm chèn một từ vào Trie
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            // Nếu ký tự chưa có trong con của node hiện tại, thì tạo mới
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];  // Tiến đến node tiếp theo
        }
        node->isEndOfWord = true;  // Đánh dấu kết thúc từ
    }

    // Hàm tìm kiếm một từ trong Trie
    bool search(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // Hàm kiểm tra xem có từ nào bắt đầu bằng tiền tố cho trước không
    bool startsWith(const string &prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    // Hàm xóa một từ khỏi Trie
    bool remove(const string &word) {
        return deleteHelper(root, word, 0);
    }

    // Helper để hỗ trợ việc xóa từ
    bool deleteHelper(TrieNode* node, const string &word, int depth) {
        if (!node) return false;

        // Nếu đã đi hết từ
        if (depth == word.size()) {
            // Nếu node không phải là điểm kết thúc của từ, trả về false
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            // Nếu node không có con, thì có thể xóa
            return node->children.empty();
        }

        char c = word[depth];
        // Tiến hành đệ quy xóa ký tự tiếp theo
        if (deleteHelper(node->children[c], word, depth + 1)) {
            delete node->children[c];
            node->children.erase(c);
            // Nếu node không phải là điểm kết thúc của từ và không còn con, xóa
            return !node->isEndOfWord && node->children.empty();
        }
        return false;
    }
};

int main() {
    Trie trie;

    // Chèn các từ vào Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");

    // Tìm kiếm các từ trong Trie
    cout << "Tìm từ 'apple': " << (trie.search("apple") ? "Tìm thấy" : "Không tìm thấy") << endl;
    cout << "Tìm từ 'app': " << (trie.search("app") ? "Tìm thấy" : "Không tìm thấy") << endl;
    cout << "Tìm từ 'banana': " << (trie.search("banana") ? "Tìm thấy" : "Không tìm thấy") << endl;
    cout << "Tìm từ 'orange': " << (trie.search("orange") ? "Tìm thấy" : "Không tìm thấy") << endl;

    // Kiểm tra tiền tố trong Trie
    cout << "Có từ nào bắt đầu bằng 'ban'? " << (trie.startsWith("ban") ? "Có" : "Không") << endl;
    cout << "Có từ nào bắt đầu bằng 'app'? " << (trie.startsWith("app") ? "Có" : "Không") << endl;

    // Xóa từ khỏi Trie
    trie.remove("apple");
    cout << "Tìm từ 'apple' sau khi xóa: " << (trie.search("apple") ? "Tìm thấy" : "Không tìm thấy") << endl;
    
    return 0;
}
