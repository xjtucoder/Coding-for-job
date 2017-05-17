/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s ="leetcode",
dict =["leet", "code"].
Return true because"leetcode"can be segmented as"leet code".
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        //状态矩阵，dp[i]记录到字符串s的第i个字符能否用字典表示
        vector<bool> dp(len+1,false);
        //初始化，前0个字符可以用字典表示
        dp[0]=true;
        
        for(int pos=0;pos<len;++pos)
            //在当前已找到的词后一个字符开始下一轮检索
            for(int i=pos;dp[pos] && i<len;++i)
                if (dict.find(s.substr(pos,i-pos+1))!=dict.end())
                    dp[i+1]=true;
        return dp[len];
    }
};
