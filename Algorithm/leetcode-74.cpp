#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        m = matrix.size();
        n = matrix[0].size();

        return search(matrix, target, 0, m * n - 1);
    }

    bool search(vector<vector<int>> &matrix, int target, int left, int right)
    {
        if (left > right)
            return false;

        int mid = (left + right) / 2;

        int i = mid / n;
        int j = mid % n;

        if (target == matrix[i][j])
            return true;
        else if (target < matrix[i][j])
            right = mid - 1;
        else
            left = mid + 1;
        return search(matrix, target, left, right);
    }

public:
    int m, n;
};
