#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#define N 120
#define DIS(x1, y1, x2, y2) (abs((x1) - (x2)) + abs((y1) - (y2)))
using namespace std;

typedef struct _BLOCK
{
    int x;
    int y;
    
    int f;
    int g;
    int h;
    
    bool operator< (const _BLOCK &rhs) const
    {
        return (f == rhs.f ? g > rhs.g : f < rhs.f);
    }
}BLOCK;

const int dirx[4] = {1, -1, 0, 0};
const int diry[4] = {0, 0, 1, -1};

int n, m;
int a[N][N];

set<BLOCK>::iterator findinset(const set<BLOCK> &s, int x, int y)
{
    set<BLOCK>::iterator it;
    
    for(it = s.begin();it != s.end();it ++)
        if(it -> x == x && it -> y == y)
            break;
    return it;
}

vector<pair<int, int> > Astar(int sx, int sy, int mx, int my)
{
    set<BLOCK> opened, closed;
    set<BLOCK>::iterator it;
    BLOCK t;
    pair<int, int> p[N][N];
    int i, h, tx, ty, tf, tg, th;
    
    stack <pair<int, int> > road;
    vector<pair<int, int> > ans;
    
    opened.insert((BLOCK){sx, sy, DIS(sx, sy, mx, my), 0, DIS(sx, sy, mx, my)});
    for(h = 0;!opened.empty();)
    {
        t = *opened.begin();
        for(i = 0;i < 4;i ++)
        {
            tx = t.x + dirx[i];
            ty = t.y + diry[i];
            if(tx < 0 || ty < 0 || tx >= n || ty >= m || a[tx][ty] || findinset(closed, tx, ty) != closed.end())
                continue;
            //cout << (findinset(closed, tx, ty) != closed.end());
            cout << "T" << tx << ' ' << ty << endl;
            for(auto is = closed.begin();is != closed.end();is ++)
                cout << is->x<<' '<<is->y<<endl;
            //cout<<closed.count((BLOCK){tx, ty, 0, 0, 0});
            tg = t.g + 1;
            th = DIS(tx, ty, mx, my);
            tf = tg + th;
            if((it = findinset(opened, tx, ty)) == opened.end())
            {
                opened.insert((BLOCK){tx, ty, tf, tg, th});
                p[tx][ty] = make_pair(t.x, t.y);
            }
            else if(tg < it -> g)
            {
                opened.erase(*it);
                opened.insert((BLOCK){tx, ty, tf, tg, th});
                p[it -> x][it -> y] = make_pair(t.x, t.y);
            }
        }
        
        if(t.x == mx && t.y == my)
        {
            h = 1;
            break;
        }
        //cout << "F" << t.x << ' ' << t.y << endl;
        cout << closed.insert(t).second<< endl;
        opened.erase(t);
    }
    
    ans.clear();
    if(h)
    {
        ans.push_back(make_pair(sx, sy));
        while(mx != sx || my != sy)
        {
            tx = mx;
            ty = my;
            mx = p[tx][ty].first ;
            my = p[tx][ty].second;
            road.push(make_pair(tx, ty));
        }
        while(!road.empty())
        {
            ans.push_back(road.top());
            road.pop();
        }
    }
    
    return ans;
}

int main()
{
    int i, j;
    int sx, sy, tx, ty;
    vector<pair<int, int> > u;
    
    cin >> n >> m;
    for(i = 0;i < n;i ++)
        for(j = 0;j < m;j ++)
            cin >> a[i][j];
    cin >> sx >> sy >> tx >> ty;
    
    u = Astar(sx, sy, tx, ty);
    for_each(u.begin(), u.end(), [](pair<int, int> &x) -> void {cout << "[" << x.first << "," << x.second << "] -> ";});
    for_each(u.begin(), u.end(), [](pair<int, int> &x) -> void {a[x.first][x.second] = 2;});
    for(i = 0;i < n;i ++)
    {
        for(j = 0;j < m;j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}
