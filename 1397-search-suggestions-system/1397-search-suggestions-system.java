class Trie {
    static class Node {
        Node[] links = new Node[26];
        List<String> suggestion = new ArrayList<>();
        boolean flag = false;
        boolean containsKey(char ch) {
            return links[ch - 'a'] != null;
        }

        void put(char ch, Node node) {
            links[ch - 'a'] = node;
        }

        Node get(char ch) {
            return links[ch - 'a'];
        }
        void setEnd() {
            flag = true;
        }
        boolean isEnd() {
            return flag;
        }
    }

    private Node root;

    public Trie() {
        root = new Node();
    }

    public void insert(String word) {
        Node node = root;
        for(int i = 0;i < word.length();i++) {
            if(!node.containsKey(word.charAt(i))) {
                node.put(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
            if(node.suggestion.size() < 3){
                node.suggestion.add(word);
            }
        }
        node.setEnd();
    }

    public boolean search(String word) {
        Node node = root;
        for(int i = 0;i < word.length(); i++) {
            if(!node.containsKey(word.charAt(i))) {
                return false;
            }
            node = node.get(word.charAt(i));
        }
        return node.isEnd();
    }

    public List<List<String>> suggest(String word) {
        Node node = root;
        List<List<String>> suggestions = new ArrayList<>();
        for(int i = 0; i < word.length(); i++){
            char ch = word.charAt(i);
            node = node.get(ch);
            if(node == null){
                while(i < word.length()){
                    suggestions.add(new ArrayList<>());
                    i++;
                }
                return suggestions;
            }
            suggestions.add(node.suggestion);
        }
        return suggestions;
    }
}


class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        Arrays.sort(products);
        Trie trie = new Trie();
        for(int i = 0;i < products.length; i++) {
            trie.insert(products[i]);
        }
        return trie.suggest(searchWord);
    }
}