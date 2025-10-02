class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, emptyBottles = 0;
        while(numBottles > 0) {
            ans += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;
            while(emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                numBottles++;
                numExchange++;
            }
        }
        return ans;
    }
}