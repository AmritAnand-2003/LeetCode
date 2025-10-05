class Solution {
    static class Pair {
        char val;
        int count;
        Pair(char val, int count){
            this.val = val;
            this.count = count;
        }
    }
    public String removeSubstring(String s, int k) {
        Stack<Pair> stack = new Stack<>();
        int n = s.length();
        for(int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if(stack.isEmpty() || stack.peek().val != c) {
                stack.push(new Pair(c, 1));
            }
            else {
                stack.peek().count++;
            }
            if(stack.size() >= 2) {
                Pair top = stack.pop();
                Pair prev = stack.pop();
                if (prev.val == '(' && prev.count >= k && top.val == ')' && top.count >= k) {
                    prev.count -= k;
                    top.count -= k;
                    if(prev.count > 0) {
                        stack.push(prev);
                    }
                    if(top.count > 0) {
                        stack.push(top);
                    }
                }
                else {
                    stack.push(prev);
                    stack.push(top);
                }
            }
        }
        StringBuilder res = new StringBuilder();
        for(Pair p : stack) {
            for(int i = 0; i < p.count; i++) {
                res.append(p.val);
            }
        }
        return res.toString();
    }
}