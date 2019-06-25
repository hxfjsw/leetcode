//
// Created by lion on 2019/4/19.
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

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int size = 0;
        ListNode *curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }

        if (n > size)return head;
        if (n == 1 && size == 1)return nullptr;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        curr=dummy;
        for(int i=0;i<size-n;++i){
            curr=curr->next;
        }

        cout << size-n<<endl;
        cout<<curr->val;
        curr->next = curr->next->next;
        return dummy->next;
    }
};

int main() {

    Solution so;

    ListNode *list = stringToListNode("[1,2,3]");
    so.removeNthFromEnd(list, 2);

    return 0;
}