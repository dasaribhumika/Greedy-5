// https://leetcode.com/problems/wildcard-matching/description/

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)

class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.length();
            int m = p.length();
            vector<vector<bool>> dp (n+1, vector<bool> (m+1, false));
            dp[0][0]=true;
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[0][j] = dp[0][j-1];
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(s[i-1] == p[j-1] || p[j-1] == '?'){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1] == '*'){
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                }
            }
            return dp[n][m];
            
        }
    };

// Time Complexity: O(n*m)
// Space Complexity: O(m)

class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.length();
            int m = p.length();
            vector<bool> dp (m+1, false);
            dp[0]=true;
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[j] = dp[j-1];
                }
            }
            for(int i=1; i<=n; i++){
                bool prev = dp[0]; // dp[i-1][j-1]
                dp[0] = false;
                for(int j=1; j<=m; j++){
                    bool temp = dp[j]; // dp[i-1][j];
                    if(s[i-1] == p[j-1] || p[j-1] == '?'){
                        dp[j] = prev;
                    }
                    else if(p[j-1] == '*'){
                        dp[j] = dp[j] || dp[j-1];
                    }
                    else{
                        dp[j] = false;
                    }
                    prev = temp;
                }
                
            }
            return dp[m];
            
        }
    };

// Greedy 
// Time Complexity: O(n + m)
// Space Complexity: O(1)


class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.length();
            int m = p.length();
            int i=0; int j=0; int ss=-1; int ps=-1;
            while(i < n){
                if((j<m) && (s[i] == p[j] || p[j] == '?')){
                    i++;
                    j++;
                }
                else if(j<m && p[j] == '*'){
                    ps = j;
                    ss = i;
                    j++;
                }
                else if(ps == -1) return false;
                else{
                    ss++;
                    i = ss;
                    j = ps+1;
                    
                }
            }
            while(j<m){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }
    };