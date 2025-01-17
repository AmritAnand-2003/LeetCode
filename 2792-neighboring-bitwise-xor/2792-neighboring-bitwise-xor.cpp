class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int curOriginal = 0;
        for(auto& d : derived){
            curOriginal ^= d;
        }
        return curOriginal == 0;
    }
};