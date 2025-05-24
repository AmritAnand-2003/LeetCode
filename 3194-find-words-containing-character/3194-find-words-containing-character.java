class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> li = new ArrayList<>();
        for(int i = 0;i < words.length; i++){
            for(char y: words[i].toCharArray()){
                if(y == x){
                    li.add(i);
                    break;
                }
            }
        }
        return li;
    }
}