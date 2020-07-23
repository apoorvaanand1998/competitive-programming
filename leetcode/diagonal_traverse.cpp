class Solution {
public:
    void diag_elems(vector<vector<int>>& inp, int& m, int& n, vector<int>& sol, int dir, long long& sum)
    {
      if (dir == 0) {
        if (sum < n) { // up-left
          int y = sum;
          int x = 0;

          while ((y >= 0) && (x < m)) {
            sol.push_back(inp[x++][y--]);
          }
        }
        else { // right-down
          int y = n - 1;
          int x = sum - y;

          while ((x < m) && (y >= 0)) {
            sol.push_back(inp[x++][y--]);
          }
        }
      }
      else {
        if (sum < m) { // left-up
          int x = sum;
          int y = 0;

          while ((x >= 0) && (y < n)) {
            sol.push_back(inp[x--][y++]);
          }
        }
        else {
          int x = m - 1;
          int y = sum - x;

          while ((y < n) && (x >= 0)) {
            sol.push_back(inp[x--][y++]);
          }
        }
      }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        
        int m = matrix.size();      
        if (m == 0) 
            return sol;
        int n = matrix[0].size();         
        if (n == 0) 
            return sol;

        int max_sum = m + n - 2;
        int dir = 1;
        long long curr_sum = 0;
        
        while (curr_sum <= max_sum) {
            diag_elems(matrix, m, n, sol, dir%2, curr_sum);
            ++dir;
            ++curr_sum;
        }
        return sol;
    }
};
