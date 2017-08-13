/*
用递归解题的关键在于构造出递归函数，如本例：
void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res)
含义是：对于给定的字符digits，字典dict，求出digits中从第level个字母开始的字母组合并接在out后面形成字符串，存储在res里
可能有点表述不准确，但是必须确定了递归函数的功能才能写出递归函数
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string digits, string dict[], int level, string out, vector<string> &res) {
        if (level == digits.size()) res.push_back(out);
        else {
            string str = dict[digits[level] - '2'];
            for (int i = 0; i < str.size(); ++i) {
                out.push_back(str[i]);
                letterCombinationsDFS(digits, dict, level + 1, out, res);
                out.pop_back();
            }
        }
    }
};
