class Solution {
    public boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }

    public int maxFreqSum(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        for(int i = 0;i < s.length(); i++) {
            char c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            char c = entry.getKey();
            int count = entry.getValue();
            if(isVowel(c)) {
                maxVowelFreq = Math.max(count, maxVowelFreq);
            }
            else {
                maxConsonantFreq = Math.max(count, maxConsonantFreq);
            }
        }
        return maxVowelFreq + maxConsonantFreq;
    }
}