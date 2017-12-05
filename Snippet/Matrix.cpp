#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 20
using namespace std;

class Matrix
{
private:
    int n, m;
    int x[N][N];

public:
    Matrix(int _n = 0, int _m = 0, int _x = 0) : n(_n), m(_m)
    {
        int i, j;

        for(i = 0;i < n;i ++)
            for(j = 0;j < m;j ++)
                x[i][j] = _x;

        return;
    }

    void Set(int x, int y, int v)
    {
        this -> x[x][y] = v;

        return;
    }

    int Get(int x, int y        ) const
    {
        return this -> x[x][y];
    }

    Matrix operator*(const Matrix &that) const
    {
        int i, j, k, t;
        Matrix r;

        if(m != that.n)
            return Matrix();

        r = Matrix(n, that.m);
        for(i = 0;i < n;i ++)
            for(j = 0;j < that.m;j ++)
            {
                for(k = t = 0;k < m;k ++)
                    t += x[i][k] * that.x[k][j];
                r.x[i][j] = t;
            }

        return r;
    }

    Matrix &operator*=(const Matrix &that)
    {
        return (*this) = (*this) * that;
    }
};

int main()
{
    int n;
    Matrix a, b, c;
    int i;

    a = Matrix(2, 2);
    a.Set(0, 0, 0);
    a.Set(0, 1, 1);
    a.Set(1, 0, 1);
    a.Set(1, 1, 1);

    b = Matrix(1, 2);
    b.Set(0, 0, 1);
    b.Set(0, 1, 1);

    cin >> n;
    for(i = 0, c = a;i < n - 3;i ++)
        c = c * a;
    b = b * c;
    cout << b.Get(0, 1) << endl;

    return 0;
}
