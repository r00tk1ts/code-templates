struct TrieNode {
    gg count = 0;  //该结点代表的单词个数,count>0表示这是一个单词结点
    array<TrieNode*, 128> children{};
};
TrieNode* root = new TrieNode();
//插入一个单词
void insert(TrieNode* root, string word) {
    auto i = root;
    for (char c : word) {
        if (not i->children[c])
            i->children[c] = new TrieNode();
        i = i->children[c];
    }
    ++i->count;
}
//查找一个单词
bool search(TrieNode* root, string word) {
    auto i = root;
    for (char c : word) {
        if (not i->children[c])
            return false;
        i = i->children[c];
    }
    return i->count > 0;  //如果是查找前缀把这条语句换成return true;就可以了
}