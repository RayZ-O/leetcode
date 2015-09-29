// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...

// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.

// Note: The sequence of integers will be represented as a string.

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = countAndSay(n - 1);
        string res;
        int i = 0;
        while (i < s.size()) {
            int count = 0;
            char last = s[i];
            while (s[i] == last && i < s.size()) {
                count++;
                i++;
            }
            res += to_string(count) + last;
        }
        return res;
    }
};