class Trie {
    static class Node {
        Node[] links;
        boolean isEnd;
        Node() {
            links = new Node[26];
            isEnd = false;
        }
    }
    Node root;
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node cur = root;
        for(int i = 0; i < word.length(); i++) {
            int char_ind = word.charAt(i) - 'a';
            if (cur.links[char_ind] == null) {
                cur.links[char_ind] = new Node();
            }
            cur = cur.links[char_ind];
        }
        cur.isEnd = true;
    }
    
    public boolean search(String word) {
        Node cur = root;
        for(int i = 0; i < word.length(); i++) {
            int char_ind = word.charAt(i) - 'a';
            if (cur.links[char_ind] == null) {
                return false;
            }
            cur = cur.links[char_ind];
        }
        return cur.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        Node cur = root;
        for(int i = 0; i < prefix.length(); i++) {
            int char_ind = prefix.charAt(i) - 'a';
            if (cur.links[char_ind] == null) {
                return false;
            }
            cur = cur.links[char_ind];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */