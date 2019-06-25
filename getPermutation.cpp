
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
#include <cctype>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        for(int i=1;i<=n;++i){
            result += to_string(i);
        }
        while(k){
            std::next_permutation(result.begin(),result.end());
            --k;
        }
        return result;
    }
};
