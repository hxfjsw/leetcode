//
// Created by lion on 2019/4/24.
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
#include <queue>


using namespace std;


class Solution {
public:
    vector<string> topKFrequent(const vector<string> &words, int k) {
        vector<string> result = {};
        unordered_map<string, int> my_map;

        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> my_queue(comp);


        for (auto word : words) {
            my_map[word]++;
        }

        for (auto word : my_map) {
            my_queue.emplace(word.first, word.second);
            if (my_queue.size() > k) my_queue.pop();
        }

        while (!my_queue.empty()) {
            result.insert(result.begin(), my_queue.top().first);
            my_queue.pop();
        }
        return result;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> result;
        map<int, int> my_map;

        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> my_queue(comp);

        for (auto n:nums)++my_map[n];

        for (auto pair : my_map) {
            my_queue.emplace(pair.first, pair.second);
            if (my_queue.size() > k) my_queue.pop();
        }

        while (!my_queue.empty()) {
            result.insert(result.begin(), my_queue.top().first);
            my_queue.pop();
        }

        return result;
    }

    string frequencySort(string s) {
        string result = "";
        map<char, int> my_map;
        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> my_queue(comp);

        for (auto c:s)++my_map[c];

        for (auto pair : my_map) {
            my_queue.emplace(pair.first, pair.second);
        }

        while (!my_queue.empty()) {
            for (int i = 0; i < my_queue.top().second; ++i) {
                result += my_queue.top().first;
            }
            my_queue.pop();
        }

        return result;
    }

    int kthSmallest(vector<vector<int>> &matrix, int k) {
        multiset<int> s;
        for (auto row:matrix) {
            for (int i :row) {
                s.insert(i);
            }
        }
        auto it = s.begin();
        while (k) {
            it++;
            k--;
        }
        return *it;
    }

    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> result;

        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> my_queue(comp);

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                //pair<int, int> p = {nums1[i], nums2[j]};
                cout << nums1[i] << ":" << nums2[j] << endl;
                my_queue.emplace(nums1[i], nums2[j]);
                if (my_queue.size() > k) my_queue.pop();
            }
        }

        while (!my_queue.empty()) {
            result.insert(result.begin(), my_queue.top());
            my_queue.pop();
        }

        return result;
    }

    int findContentChildren(vector<int> &children, vector<int> &cookies) {
        sort(children.begin(), children.end());
        sort(cookies.begin(), cookies.end());
        int result = 0;
        for (auto i = children.begin(); i != children.end();) {
            for (auto j = cookies.begin(); j != cookies.end();) {
                if (*j >= *i) {
                    i = children.erase(i);
                    j = cookies.erase(j);
                    result++;
                } else {
                    i++;
                    j++;
                }
            }
        }
        return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a,b;
        while(l1){
            a+= (l1->val+'0');
            l1=l1->next;
        }
        while(l2){
            b+=(l2->val+'0');
            l2=l2->next;
        }

        cout<<a<<endl;
        cout<<b<<endl;





        return nullptr;
    }
};

int main() {
    Solution solution;
    //solution.topKFrequent({"i", "love", "leetcode", "i", "love", "coding"}, 2);

    vector<int> children = {1, 2, 3};
    vector<int> cookies = {1, 1};
    solution.findContentChildren(children, cookies);

    return 0;
}