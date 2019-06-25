//
// Created by lion on 2019/5/16.
//



#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>
#include <limits>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        if (s.length() <= 1)return s;
        int left = 0, right = (int) s.length() - 1;
        int find_left = -1, find_right = -1;
        while (left < right) {
            if (is_vowel(s[left]))find_left = left;
            if (is_vowel(s[right])) find_right = right;
            if (find_left != -1 && find_right != -1) {
                char temp = s[find_left];
                s[find_left] = s[find_right];
                s[find_right] = temp;
                find_left = -1, find_right = -1;
            }
            if (find_left == -1)left++;
            if (find_right == -1)right--;
        }
        return s;
    }
};

int main() {

    Solution solution;
    //cout << solution.reverseVowels("leetcode")<<endl;
    cout << solution.reverseVowels("Euston saw I was not Sue.") << endl;


    return 0;
}