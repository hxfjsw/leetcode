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
#include <list>

using namespace std;


/**
 * Least Frequently Used (LFU
 * 设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中
 */
class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
    }

    void put(int key, int value) {
        auto it = _map.find(key);

        if(it!=_map.end())_list.erase(it->second);
        _list.push_front({key,value});
        _map[key]=_list.begin();

        if (_map.size() > _capacity) {
            int t = _list.begin()->first;
            _list.erase(_list.begin());
            _map.erase(t);
        }
    }

    int _capacity;
    list<pair<int, int>> _list;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
};

int main() {

    LFUCache cache = LFUCache(2 /* capacity */ );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.get(3);       // returns 3.
    cache.put(4, 4);    // evicts key 1.
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */