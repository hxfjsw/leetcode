//
// Created by lion on 2019/4/24.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <numeric>
#include <string>c
#include <sstream>
#include <limits>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <queue>


using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, const vector<string> &words) {
        string result;
        vector<int> license_pattern(26, 0);
        for (char l:licensePlate)
            if (isalpha(l))license_pattern[tolower(l) - 'a']++;
        for (string word:words) {
            bool complate = true;
            vector<int> word_pattern(26, 0);
            for (char c:word)
                if (isalpha(c))word_pattern[tolower(c) - 'a']++;
            for (int i = 0; i < 26; i++) {
                if (word_pattern[i] < license_pattern[i]) {
                    complate = false;
                    break;
                }
            }
            if (complate && (result.empty() || word.size() < result.size()))result = word;
        }
        return result;
    }
};

int main() {

    Solution solution;
    cout << solution.shortestCompletingWord("1s3 PSt", {"step", "steps", "stripe", "stepple"});

    return 0;
}