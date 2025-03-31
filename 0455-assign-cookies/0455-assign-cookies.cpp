class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int indg = 0, inds = 0;
        while(indg < g.size() && inds < s.size()){
            if(g[indg] <= s[inds]){
                indg++, inds++;
            }
            else{
                inds++;
            }
        }
        return indg;
    }
};