#include <iostream>
#include <vector>
#include <memory>

using namespace std;

#define MAX_X 10
#define MAX_Y 10

enum class AType {
    ATYPE_UNKNOWN,
    ATYPE_CLOSED,
    ATYPE_OPENED,
    ATYPE_BARRIER   //障碍
};


class APoint {
public:
    APoint() : x(0), y(0), h(0), f(0), g(0), parent(nullptr), type(AType::ATYPE_UNKNOWN) {};

    ~APoint() {};
    int x;
    int y;
    AType type;   //类型:障碍、开放列表、关闭列表
    int f;  //f = g+h
    int g;
    int h;
    APoint *parent;

    bool operator==(const APoint &po) {
        if (x == po.x && y == po.y) {
            return true;
        }
        return false;
    }
};


class CAstar {
    vector<APoint *> _openList;      //开放列表
    vector<APoint *> _closeList;     //关闭列表
    vector<APoint *> _neighbourList; //周边节点
    APoint *_endPoint;
    APoint *_curPoint;
    vector<vector<APoint *> > _allPoints;
public:
    CAstar() : _endPoint(nullptr), _curPoint(nullptr) {};

    ~CAstar() {
        _openList.clear();
        _closeList.clear();
        _neighbourList.clear();
        _allPoints.clear();
    };

    APoint *findWay(APoint *beginPoint, APoint *endPoint, vector<vector<APoint *> > &allPoints);
//    APoint* findWay(int beginX,int beginY,int endX,int endY);
private:
    inline int getF(APoint *point) { return (point->g + getH(point)); };

    inline int getH(APoint *point) {
        return (abs(_endPoint->y - point->y) + abs(_endPoint->x - point->x)) * 10;
    };

    vector<APoint *> getNeighboringPoint(APoint *point);
};

vector<APoint *> CAstar::getNeighboringPoint(APoint *point) {
    _neighbourList.clear();
    if (point->x < MAX_X - 1) {
        if (_allPoints[point->x + 1][point->y]->type != AType::ATYPE_BARRIER) {
            _neighbourList.push_back(_allPoints[point->x + 1][point->y]);
        }
    }
    if (point->x > 0) {
        if (_allPoints[point->x - 1][point->y]->type != AType::ATYPE_BARRIER) {
            _neighbourList.push_back(_allPoints[point->x - 1][point->y]);
        }
    }
    if (point->y < MAX_Y - 1) {
        if (_allPoints[point->x][point->y + 1]->type != AType::ATYPE_BARRIER) {
            _neighbourList.push_back(_allPoints[point->x][point->y + 1]);
        }
    }
    if (point->y > 0) {
        if (_allPoints[point->x][point->y - 1]->type != AType::ATYPE_BARRIER) {
            _neighbourList.push_back(_allPoints[point->x][point->y - 1]);
        }
    }
    return _neighbourList;
}

APoint *CAstar::findWay(APoint *beginPoint, APoint *endPoint, vector<vector<APoint *> > &allPoints) {
    //传递地图
    _allPoints = allPoints;

    _endPoint = endPoint;

    if (_endPoint->type == AType::ATYPE_BARRIER) {
        cout << "终点是障碍" << endl;
        return nullptr;
    }

    if (*_endPoint == *beginPoint) {
        cout << "起始点相同" << endl;
        return nullptr;
    }

    _openList.push_back(beginPoint);
    beginPoint->type = AType::ATYPE_OPENED;
    beginPoint->f = getF(beginPoint);

    do {
        //获取最小值的节点
        _curPoint = _openList[0];
        _openList.erase(_openList.begin());
        _curPoint->type = AType::ATYPE_CLOSED;
        _closeList.push_back(_curPoint);

        if (*_curPoint == *_endPoint) {
            cout << "have find way" << endl;
            return _curPoint;
        }

        //获取相邻的节点
        vector<APoint *> neVec = getNeighboringPoint(_curPoint);
        for (int i = 0; i < neVec.size(); i++) {
            auto tmpoint = neVec[i];
            if (tmpoint->type == AType::ATYPE_CLOSED) {
                continue;
            }
            //是否在开放列表里
            if (tmpoint->type != AType::ATYPE_OPENED) {
                tmpoint->parent = _curPoint;
                tmpoint->g = _curPoint->g + 10;
                tmpoint->h = getH(tmpoint);
                tmpoint->type = AType::ATYPE_OPENED;
                _openList.push_back(tmpoint);
            } else {
                //已经在开放列表里
                if (tmpoint->h < _curPoint->h) {
                    tmpoint->parent = _curPoint;
                    tmpoint->g = _curPoint->g + 10;
                }
            }
        }

        sort(_openList.begin(), _openList.end(), [](const APoint *p1, const APoint *p2) { return p1->f < p2->f; });

    } while (_openList.size() > 0);

    cout << "---can not find way---" << endl;
    return nullptr;
}


void printMap(char map[MAX_X][MAX_Y], int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%c\t", map[i][j]);
        }
        printf("\n");
    }
}

int main() {

    cout << "---map---" << endl;
    //初始化地图矩阵 0代表障碍
    char mapdata[MAX_X][MAX_Y] =
            {
                    {'1', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
                    {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
                    {'0', '0', '0', '1', '0', '1', '1', '1', '1', '1'},
                    {'1', '0', '0', '1', '0', '1', '1', '1', '1', '0'},
                    {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
                    {'1', '1', '0', '0', '1', '1', '1', '1', '1', '1'},
                    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                    {'1', '0', '0', '1', '1', '1', '1', '1', '1', '1'},
                    {'1', '1', '0', '0', '1', '1', '1', '1', '1', '1'},
                    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '1'},
            };


    printMap(mapdata, MAX_X, MAX_Y);

    //创建地图
    using std::weak_ptr<APoint> ww
    vector<vector<APoint *> > map;
    for (int i = 0; i < MAX_X; i++) {
        vector<APoint *> tmp;
        for (int j = 0; j < MAX_Y; j++) {
            auto point = std::make_shared<APoint>();
            point->x = i;
            point->y = j;
            if (mapdata[i][j] == '0') {
                point->type = AType::ATYPE_BARRIER;
            }
            tmp.push_back(point);
        }
        map.push_back(tmp);
    }

    auto star = std::make_shared<CAstar>();

    auto point = star->findWay(map[0][0], map[9][9], map);
    if (!point) {
        return -1;
    }
    cout << "---下面是路径点(倒序)---" << endl;
    while (point) {
        mapdata[point->x][point->y] = '*';
        //cout << point->x << "," << point->y << endl;
        point = point->parent;
    }
    cout << "---打印路径---" << endl;
    printMap(mapdata, MAX_X, MAX_Y);

    //-------------释放内存----------

    for (int i = 0; i < MAX_X; i++) {
        for (int j = 10; j < MAX_Y; j++) {
            delete map[i][j];
            map[i][j] = nullptr;
        }
    }

    return 0;
}