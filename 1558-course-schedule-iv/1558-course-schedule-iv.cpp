class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dist(numCourses, vector<int>(numCourses, INT_MAX));
        for(auto& pre : prerequisites){
            dist[pre[0]][pre[1]] = 1;
        }
        for(int i = 0;i < numCourses;i++){
            dist[i][i] = 0;
        }
        for(int i = 0;i < numCourses;i++){
            for(int j = 0;j < numCourses;j++){
                for(int k = 0;k < numCourses;k++){
                    if(dist[j][i] != INT_MAX && dist[i][k] != INT_MAX){
                        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
        vector<bool> ans;
        for(auto q : queries){
            if(dist[q[0]][q[1]] != INT_MAX){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};