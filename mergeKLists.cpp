//
// Created by lion on 2019/4/26.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multiset<int> s;
        for (auto l : lists) {
            while (l) {
                s.insert(l->val);
                l = l->next;
            }
        }
        ListNode *top = new ListNode(0);
        ListNode *curr = top;
        for (auto it = s.begin(); it != s.end(); ++it) {
            curr->next = new ListNode(*it);
            curr = curr->next;
        }
        return top->next;
    }
};