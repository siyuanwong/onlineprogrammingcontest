/*================================================================
*   
*   file_name  ：358.cc
*   author     ：siyuanwong
*   create_date：2020/09/05
*
================================================================*/

/*
 * 描述
 * On a straight road, there are nn trees, and each tree has a coordinate that
 * represents their distance from the beginning of the road.
 * If the interval between every two adjacent trees is not less than dd, then we
 * consider that these trees are beautiful.
 * Please calculate the minimum number of trees should to be removed to make
 * these trees beautiful.
 *
 * The number of trees is nn, 1 \le n \le 10^51≤n≤10
 * ​5
 * ​​ .
 * The positions of tree is represent by treestrees, 0 \le trees_i \le
 * 10^90≤trees
 * ​i
 * ​​ ≤10
 * ​9
 * ​​ .
 * The least beautiful interval is dd, 1 \le d \le 10^91≤d≤10
 * ​9
 * ​​ .
 * It's ensured that the input positions are sorted, and they are pairwisely
 * distinct.
 *
 * 您在真实的面试中是否遇到过这个题？  
 * 说明
 * In the example, remove the tree on postion 22 and 66, it is beautiful for the
 * rest [1,3,5][1,3,5].
 *
 * 样例
 * Input：
 * [1,2,3,5,6]
 * 2
 * Output：
 * 2
 *
 * https://www.lintcode.com/problem/treeplanning/description?_from=contest&&fromId=103
 *
 */

class Solution {
public:
    /**
     * @param trees: the positions of trees.
     * @param d: the minimum beautiful interval.
     * @return: the minimum number of trees to remove to make trees beautiful.
     */
    int treePlanning(vector<int> &trees, int d) {
        // write your code here.
        int n = trees.size();
        
        std::vector<int> dp(n, 0);
        
        for (int i = 1; i < n; i++) {
          
          int j = trees[i] - d;
          int idx = std::upper_bound(trees.begin(), trees.end(), j) - trees.begin() - 1;
          
          if (idx < 0) {
            dp[i] = i;
          } else {
            dp[i] = dp[idx] + i - idx - 1;
          }
        } 
        
        return dp[n - 1];
    }
};
