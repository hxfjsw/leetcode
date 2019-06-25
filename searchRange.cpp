//
// Created by lion on 2019/4/22.
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
#include <set>


using namespace std;

class Solution {


public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> s;
        for(auto n:nums)s.(n);
        vector<int> result;
        auto it=s.rbegin();
        for(int i=0;i<k;i++){
            //result.push_back(*it);
            it++;
        }
    }


    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int res = nums.size();
        unordered_map<int, int> startIndex, count;
        int len = nums.size(), fre = 0;
        for (int i = 0; i < nums.size() ;i++) {
            if (startIndex.count(nums[i]) == 0) startIndex[nums[i]] = i;
            count[nums[i]]++;
            if (count[nums[i]] == fre){
                len = min(i - startIndex[nums[i]] + 1, len);
            }
            if (count[nums[i]] > fre){
                len = i - startIndex[nums[i]] + 1;
                fre = count[nums[i]];
            }
        }
        return len;
    }

    int smallestRangeI(vector<int> A, int K) {
        int min{INT_MAX}, max{INT_MIN};
        for (auto c : A)
        {
            if (c > max) max = c;
            if (c < min) min = c;
        }
        int dif = max - min;
        if (dif <= K*2)
            return 0;
        return dif - 2*K;
    }

    int findMin(vector<int> &nums) {
        set<int> s;
        for (auto n:nums)s.insert(n);
        return *s.begin();
    }

    int removeDuplicates(vector<int> &nums) {
        int last = -1;
        int count = 0;
        for (auto it = nums.begin(); it != nums.end();) {
            if (*it != last) {
                last = *it;
                count = 1;
                it++;
            } else {
                count++;
                if (count > 2) {
                    it = nums.erase(it);
                    count--;
                } else {
                    it++;
                }
            }

        }
        return nums.size();
    }

    std::istream &safeGetline(std::istream &is, std::string &t) {
        t.clear();
        std::istream::sentry se(is, true);
        std::streambuf *sb = is.rdbuf();
        for (;;) {
            int c = sb->sbumpc();
            switch (c) {
                case ' ':
                case '.':
                case '!':
                case ',':
                case '?':
                    return is;
                case std::streambuf::traits_type::eof():
                    if (t.empty())
                        is.setstate(std::ios::eofbit);
                    return is;
                default:
                    t += (char) c;
            }
        }
    }
;
    string mostCommonWord(string paragraph, vector<string> &banned) {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        istringstream iss(paragraph);
        string word, trimed;
        map<string, int> my_map;
        while (safeGetline(iss, word)) {
            if (!word.empty() && find(banned.begin(), banned.end(), trimed) == banned.end()) {
                //cout << trimed << endl;
                if (my_map.find(word) != my_map.end()) {
                    my_map[word]++;
                } else {
                    my_map[word] = 0;
                }
            }
        }
        auto max = my_map.begin();
        for (auto it = my_map.begin(); it != my_map.end(); it++) {
            if (it->second > max->second) {
                max = it;
            }
        }
        return max->first;
    }


    char nextGreatestLetter(vector<char> &letters, char target) {
        int left = 0, right = letters.size() - 1, size = letters.size();

        // while(left<=right){
        //     int mid = left+right/2;
        //     //if()
        // }

        return 'a';
    }

    vector<int> intersect(vector<int> nums1, vector<int> nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0)return result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto i1 = nums1.begin(), i2 = nums2.begin();
        while (i1 != nums1.end() && i2 != nums2.end()) {
            if (*i1 == *i2) {
                result.push_back(*i1);
                i1++;
                i2++;
            } else if (*i1 > *i2) {
                i1++;
            } else {
                i2++;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int> nums, int target) {
        vector<int> result = {-1, -1};
        int first_found = -1, last_found = -1;
        int left = 0, right = (int) nums.size() - 1, size = (int) nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                first_found = mid;
                while (mid >= 1 && nums[mid - 1] == target) {
                    mid--;
                    first_found = mid;
                }
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = 0, right = (int) nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                last_found = mid;
                while (mid + 1 < size && nums[mid + 1] == target) {
                    mid++;
                    last_found = mid;
                }
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return {first_found, last_found};
    }
};

int main() {

    Solution solution;
//    vector<int> rst;
//    rst = solution.searchRange({1, 2, 3, 3, 3, 3, 3, 3, 3, 4, 5, 9}, 3);
//    assert(rst[0] == 2 && rst[1] == 8);
//    rst = solution.searchRange({1}, 1);
//    assert(rst[0] == 0 && rst[1] == 0);
//    rst = solution.searchRange({2, 2}, 2);
//    assert(rst[0] == 0 && rst[1] == 1);

//    solution.intersect({1, 2, 2, 1}, {2, 2});
//
//    vector<int> args = {1, 1, 1};
//    solution.removeDuplicates(args);


    solution.smallestRangeI({0,10},2);

    return 0;
}