#include <iostream>
#include <vector>

// Input: m, n, *matrix
// 0, 1, 2, 3
// 4, 5, 6, 7
// 8, 9, 10, 11
// Output:
// 0,  4, 1,  8
// 5,  2, 9,  6
// 3, 10, 7, 11

using namespace std;

void printDiagonally(const vector<vector<int> > &matrix)
{
    if (matrix.empty())
        return;

    int m = matrix.size();
    int n = matrix[0].size();

    // 遍历所有对角线
    for (int s = 0; s < m + n - 1; ++s)
    {
        // 对于每一条对角线，计算起始点
        int x = s < m ? s : m - 1;
        int y = s < m ? 0 : s - m + 1;

        // 沿对角线打印元素
        while (x >= 0 && y < n)
        {
            cout << matrix[x][y] << " ";
            x--;
            y++;
        }
        cout << endl;
    }
}

int main()
{
    int m = 3, n = 4;

    vector<vector<int> > matrix(m, vector<int>(n, 0));

    for (int i = 0; i < m * n; ++i)
    {
        matrix[i / n][i % n] = i;
    }

    printDiagonally(matrix);
}
