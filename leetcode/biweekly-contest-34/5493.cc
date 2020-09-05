/*================================================================
*   
*   file_name  ：5493.cc
*   author     ：siyuanwong
*   create_date：2020/09/06
*
================================================================*/

/*
 * 给你一个整数数组 arr ，请你删除一个子数组（可以为空），使得
 * arr 中剩下的元素是 非递减 的。
 *
 * 一个子数组指的是原数组中连续的一个子序列。
 *
 * 请你返回满足题目要求的最短子数组的长度。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：arr = [1,2,3,10,4,2,3,5]
 * 输出：3
 * 解释：我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组
 * [1,2,3,3,5] 。
 * 另一个正确的解为删除子数组 [3,10,4] 。
 * 示例 2：
 *
 * 输入：arr = [5,4,3,2,1]
 * 输出：4
 * 解释：由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4
 * 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
 * 示例 3：
 *
 * 输入：arr = [1,2,3]
 * 输出：0
 * 解释：数组已经是非递减的了，我们不需要删除任何元素。
 * 示例 4：
 *
 * 输入：arr = [1]
 * 输出：0
 *  
 *
 * 提示：
 *
 * 1 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^9
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
      int n = arr.size();
      
      std::vector<int> left;
      left.push_back(arr[0]);
      for (int i = 1; i < n; i++) {
        if (arr[i] >= left.back())
          left.push_back(arr[i]); 
        else
          break;
      }
      
      std::vector<int> right;
      right.push_back(arr.back());
      for (int i = n - 2; i >= 0; i--) {
        if (arr[i] <= right.back())
          right.push_back(arr[i]);
        else
          break;
      }
      
      int32_t iResult = n - left.size();
      for (int i = 0; i < right.size(); i++) {
        int v = n - i - 1;
        int u = std::lower_bound(left.begin(), left.end(), arr[v] + 1) - left.begin() - 1;
        
        //printf("%d %d %d %d\n", u, v, arr[u], arr[v]);
        
        if (u < v)
          iResult = std::min(iResult, v - u - 1);
        else
          iResult = std::min(iResult, 0);
      }
      
      return iResult;

    }
};
