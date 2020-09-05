/*================================================================
*   
*   file_name  ：5491.cc
*   author     ：siyuanwong
*   create_date：2020/09/06
*
================================================================*/

/*
 * 给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
 *
 * 请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
 *
 *
 * 输入：mat = [[1,2,3],
 *             [4,5,6],
 *             [7,8,9]]
 * 输出：25
 * 解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
 * 请注意，元素 mat[1][1] = 5 只会被计算一次。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/matrix-diagonal-sum
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int n = mat.size();
      
      int32_t iResult = 0;
      for (int i = 0; i < n; i++)
        iResult += mat[i][i];
      
      for (int i = 0; i < n; i++) {
        int j = n - i - 1;
        if (i == j)
          continue;
        iResult += mat[i][j];
      }
      
      return iResult;
    }
};
