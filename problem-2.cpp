// https://leetcode.com/problems/campus-bikes/description/
// Time Complexity: O(n*m) 
// Space Complexity: O(n*m)

class Solution {
    public:
        vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
            int n = workers.size(); int minVal = INT_MAX; int maxVal = INT_MIN;
            int m = bikes.size();
            unordered_map <int, vector<pair<int,int>> > mp;
            for(int i=0; i<n; i++){
                auto w = workers[i];
                for(int j=0; j<m; j++){
                    auto b = bikes[j];
                    int dist = abs(w[0] - b[0]) + abs(w[1] - b[1]);
                    minVal = min(minVal, dist);
                    maxVal = max(maxVal, dist);
                    mp[dist].push_back({i,j});
                }
            }
            vector<bool> assigned (n, false);
            vector<bool> occupied (m, false);
            vector<int> res(n,0);
            int cnt=0;
            for(int i=minVal; i<=maxVal && cnt < n; i++){
                vector<pair<int,int>> curr = mp[i];
                if(!curr.empty()){
                    for(auto it:curr){
                        if(!assigned[it.first] && !occupied[it.second]){
                            res[it.first] = it.second;
                            assigned[it.first] = true;
                            occupied[it.second] = true;
                            cnt++;
                        } 
                    }
                }
            }
            return res;
        }
    };