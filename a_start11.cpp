#include <vector>
#include <iostream>

using namespace std;

void printMap(vector<vector<char>> &map) {
    for (auto raw : map) {
        for (auto x:raw) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

enum class Type {
    UNKNOWN,
    CLOSED,
    OPENED,
    BARRIER
};

class node;

#define point shared_ptr<node>


class A_Star {

    struct node {
        int x, y, f = 0, g = 0, h = 0;
        point parent;
        Type type;

        inline bool operator==(const node &n) const { return x == n.x && y == n.y; }

        node(int x, int y, Type t) : x(x), y(y), type(t) {
            cout << "node ctor :x=" << x << " y=" << y << endl;
        }

        node() = delete;

        ~node() {
            cout << "node dtor :x=" << x << " y=" << y << endl;
        }
    };


private:
    vector<vector<point>> all_points;
    vector<point > opened, closed;
    point begin, end, curr;
public:
    A_Star(vector<vector<char>> data) : all_points(data.size(), vector<point >(data[0].size())) {
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                all_points[i][j] = std::make_shared<node>(i, j, data[i][j] == '0' ? Type::BARRIER : Type::UNKNOWN);
            }
        }
    }

    A_Star() = delete;

    inline int getF(point p) { return (p->g + getH(p)); };

    inline int getH(point p) {
        return (abs(end->y - p->y) + abs(end->x - p->x)) * 10;
    };

    point findWayTest() {
        begin = all_points[0][0];
        end = all_points[9][9];

        begin->type = Type::OPENED;
        begin->f = getF(begin);
        opened.push_back(begin);

        do {
            curr = opened[0];
            curr->type = Type::CLOSED;
            opened.erase(opened.begin());

            if (curr == end) {
                cout << "have find way" << endl;
                return curr;
            }

            auto neighbors = getNeighboringPoint(curr);
            for (auto neighbor : neighbors) {
                if (neighbor->type == Type::CLOSED) continue;

                if (neighbor->type != Type::OPENED) {
                    neighbor->type = Type::OPENED;
                    neighbor->parent = curr;
                    neighbor->g = curr->g + 10;
                    neighbor->h = getH(neighbor);
                    opened.push_back(neighbor);
                } else {
                    if (neighbor->h < curr->h) {
                        neighbor->parent = curr;
                        neighbor->g = curr->g + 10;
                    }
                }
            }

        } while (opened.size() > 0);


        cout << "---can not find way---" << endl;
        return nullptr;
    };

    vector<point > getNeighboringPoint(point p) {
        vector<point > result;
        if (p->x < all_points[0].size() - 1) {
            if (all_points[p->x + 1][p->y]->type != Type::BARRIER) {
                result.push_back(all_points[p->x + 1][p->y]);
            }
        }
        if (p->x > 0) {
            if (all_points[p->x - 1][p->y]->type != Type::BARRIER) {
                result.push_back(all_points[p->x - 1][p->y]);
            }
        }
        if (p->y < all_points.size() - 1) {
            if (all_points[p->x][p->y + 1]->type != Type::BARRIER) {
                result.push_back(all_points[p->x][p->y + 1]);
            }
        }
        if (p->y > 0) {
            if (all_points[p->x][p->y - 1]->type != Type::BARRIER) {
                result.push_back(all_points[p->x][p->y - 1]);
            }
        }
        return result;
    }
};


int main() {

    cout << "---map---" << endl;
    //初始化地图矩阵 0代表障碍
    vector<vector<char>> map =
            {
                    {' ', '0', '0', ' ', '0', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' '},
                    {'0', '0', '0', ' ', '0', ' ', ' ', ' ', ' ', ' '},
                    {' ', '0', '0', ' ', '0', ' ', ' ', ' ', ' ', '0'},
                    {' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', '0', '0', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', '0', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', '0', '0', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', '0', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            };

    printMap(std::ref(map));

    auto star = std::make_shared<A_Star>(map);
    auto header = star->findWayTest();

    while (header) {
        map[header->x][header->y] = '*';
        header = header->parent;
    }


    star.reset();

    printMap(std::ref(map));


    cout << "--------" << endl;


    return 0;
}