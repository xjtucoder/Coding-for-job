/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * For example, given
 * s ="catsanddog",
 * dict =["cat", "cats", "and", "sand", "dog"].
 * A solution is["cats and dog", "cat sand dog"].
 * */
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
        //二维bool数组，dp[i][j]为true，表示s[i,j-i+1]在字典中可以找到
        //dp[0]的维度是s.size(); dp[1]的维度是s.size()-1;...;dp[i]的维度是s.size()-i
        dp = new vector<bool>[s.size()];
        
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                dp[i].push_back(match(s.substr(i, j - i + 1), dict));
            }
        }
        
        output(s.size() - 1, s);
        return result;
    }
    bool match(string s, unordered_set<string> &dict)
    {
        if (dict.find(s) != dict.end()) 
            return true;
        else 
            return false;
    }
    void output(int i, string s)
    {
        if (i == -1)    //递归退出条件
        {
            string str;
            for (int j = mystring.size() - 1; j >= 0; j--)
            {
                str += mystring[j];
                if (j != 0) str += " ";
            }
            result.push_back(str);
        }
        else
        {
            for (int k = 0; k <= i; k++) //error!!!  for (int k = 0; k < i; k++)
            {
                if (dp[k][i - k])       //dp[k][i-k]:偏移为k，截断长度i-k+1
                {
                    mystring.push_back(s.substr(k, i - k + 1));
                    output(k - 1, s);   //递归:dp[0][i]:偏移为0，截断长度i+1      i=k-1,则截断长度为k,与递归前偏移k互补
                    mystring.pop_back();
                }
            }
        }
    }
    vector<string> result;
    vector<string> mystring;
    vector<bool> *dp;
};
