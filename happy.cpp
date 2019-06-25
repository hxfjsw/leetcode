//
// Created by lion on 2019/4/18.
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
    static inline bool is_not_alnum(char c) {
        return !(isalpha(c) || isdigit(c));
    }

    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), is_not_alnum), s.end());
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            int r = size - 1 - i;
            //cout << s[r] << ":" << s[i] << endl;
            if (s[r] != s[i]) {
                return false;
            }
        }
        return true;
    }

    inline bool is_valid(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return is_valid(s, left + 1, right) || is_valid(s, left, right - 1);
            } else {
                left++;
                right--;
            }
        }
        return true;
    }

    string convertToTitle(int n) {
        string rst = "";
        while (n > 0) {
            n--;
            rst += ((char) (n % 26 + 'A'));
            n = n / 26;
        }
        reverse(rst.begin(), rst.end());
        return rst;
    }


    int titleToNumber(string s) {
        int result = 0;
        for (char c:s) {
            int num = c - 'A' + 1;
            result*=26;
            result+=num;
        }
        return result;
    }


};

int main() {

    Solution so;
    //so.convertToTitle(701);
    so.titleToNumber("ZY");
//    assert(so.validPalindrome("edeee") == 1);
//    assert(so.validPalindrome("aba") == 1);
//    assert(so.validPalindrome("abca") == 1);
//    assert(so.validPalindrome("abc") == 0);
//    assert(so.validPalindrome("atbbga") == 0);
//    assert(so.validPalindrome("eeccccbebaeeabebccceea") == 0);
    return 0;
}