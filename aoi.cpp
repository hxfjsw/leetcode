#include <string>
#include <iostream>
#include <a>

using namespace std;

class DoubleNode {
public:
    DoubleNode(const string &key, int x, int y) {
        this->key = key;
        this->x = x;
        this->y = y;
    }
public:
    DoubleNode *xPrev;
    DoubleNode *xNext;
    DoubleNode *yPrev;
    DoubleNode *yNext;
public:
    string key;
    int x;
    int y;
};

class Map {
public:
    Map() {
        this->_head = new DoubleNode("[head]", 0, 0);
        this->_tail = new DoubleNode("[tail]", 0, 0);
        _head->xNext = _tail;
        _head->yNext = _tail;
        _tail->xPrev = _head;
        _tail->yPrev = _head;
    }

    DoubleNode* Add(string name ,int x, int y);

    void Leave(DoubleNode *node);

    void Move(DoubleNode *node,int x , int y);

    void PrintAOI(DoubleNode *node,int xAreaLen,int yAreaLen);

    void ConsoleDump(){

        DoubleNode * curr = _head->xNext;
        if(curr != _tail){
            cout << (curr->key)<<"(" <<curr->x <<","<<curr->y<<" )-> ";
            curr=curr->xNext;
        }
        cout << "end"<<endl;

        curr = _head->yNext;
        if(curr != _tail){
            cout << (curr->key)<<"(" <<curr->x <<","<<curr->y<<" )-> ";
            curr=curr->yNext;
        }
        cout << "end"<<endl;
    }

private:
    DoubleNode *_head;
    DoubleNode *_tail;
    void _add(DoubleNode * node);
};

DoubleNode* Map::Add(string name, int x, int y) {
    DoubleNode * node = new DoubleNode(name, x, y);
    _add(node);
    return node;
}

void Map::Leave(DoubleNode *node) {
    node->xPrev->xNext = node->xNext;
    node->xNext->xPrev = node->xPrev;
    node->yPrev->yNext = node->yNext;
    node->yNext->yPrev = node->yPrev;

    node->xPrev = NULL;
    node->xNext = NULL;
    node->yPrev = NULL;
    node->yNext = NULL;
}

void Map::Move(DoubleNode *node, int x, int y) {
    Leave(node);
    node->x=x;
    node->y=y;
    _add(node);
}

void Map::PrintAOI(DoubleNode *node, int xAreaLen, int yAreaLen) {

}

void Map::_add(DoubleNode *node) {
    // x轴处理
    DoubleNode * cur = _head->xNext;
    while(cur != NULL)
    {
        if((cur->x > node->x) || cur==_tail) // 插入数据
        {
            node->xNext = cur;
            node->xPrev = cur->xPrev;
            cur->xPrev->xNext = node;
            cur->xPrev = node;
            break;
        }
        cur = cur->xNext;
    }

    // y轴处理
    cur = _head->yNext;
    while(cur != NULL)
    {
        if((cur->y > node->y) || cur==_tail) // 插入数据
        {
            node->yNext = cur;
            node->yPrev = cur->yPrev;
            cur->yPrev->yNext = node;
            cur->yPrev = node;
            break;
        }
        cur = cur->yNext;
    }
}

int main(){

    Map map;
    map.Add("a",1,5);
    map.Add("b",2,2);
    map.Add("c",3,1);

    DoubleNode * node = map.Add("d", 3, 3);

    map.ConsoleDump();


    return 0;
}