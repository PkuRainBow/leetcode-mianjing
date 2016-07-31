class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        if(n>30000)    return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0]=true;
        for(int i=1; i<=m; i++){
            dp[i][0] = false;
        }
        for(int i=1; i<=n; i++){
            dp[0][i] = (p[i-1]=='*') && dp[0][i-1];
        }
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[j-1]!='*')
                    dp[i][j]=(p[j-1]=='?'||p[j-1]==s[i-1]) && dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};