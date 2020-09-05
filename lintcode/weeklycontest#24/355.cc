/*================================================================
*   
*   file_name  ：355.cc
*   author     ：siyuanwong
*   create_date：2020/09/05
*
================================================================*/

/*
 * 描述
 * Spider-Man is shuttling between the buildings. The height of the building can
 * be seen as an array from left to right.
 * Now Spider-Man is standing on the first building, and he wants to jump to the
 * last one.
 * Spiderman's field of vision is kk, he can spend xx points energy, use the
 * spider silk to move to the right side of the kk building, which is the first
 * building higher than the current location.
 * Or Spider-Man can spend yy points energy and jump to one of the next two
 * buildings on the right.
 * Please calculate the least energy he should use to the last building.
 *
 * The height of the building is the array heightsheights, there are nn
 * buildings, 2 \le n \le 10^52≤n≤10
 * ​5
 * ​​ , 1 \le heights_i \le 10^91≤heights
 * ​i
 * ​​ ≤10
 * ​9
 * ​​ .
 * Spiderman's vision is kk, 1 \le k \le n1≤k≤n.
 * The energy cost of the two actions satisfies 1 \le x, y \le 10^91≤x,y≤10
 * ​9
 * ​​ 
 *
 * 您在真实的面试中是否遇到过这个题？  
 * 说明
 * In the example, spend 66 points energy to the third building, then spend 1010
 * to the last one.
 *
 * 样例
 * Input：
 * heights = [1,5,4,3,3,5]
 * k = 3
 * x = 10
 * y = 6
 * Output：
 * 16
 *
 * https://www.lintcode.com/problem/shuttleinbuildings/description?_from=contest&&fromId=103
 *
 */

class Solution {
  using vi = std::vector<int64_t>;
public:
    /**
     * @param heights: the heights of buildings.
     * @param k: the vision.
     * @param x: the energy to spend of the first action.
     * @param y: the energy to spend of the second action.
     * @return: the minimal energy to spend.
     */
    long long shuttleInBuildings(vector<int> &heights, int k, int x, int y) {
        // write your code here.
        int n = heights.size();
        
        vi dp(n, INT64_MAX); 
        std::deque<int> q;
        
        dp[0] = 0;
        q.push_back(0);
        for (int i = 1; i < n; i++) {
          
          while (!q.empty() && q.front() + k < i) {
            q.pop_front();
          }
          
          while (!q.empty() && heights[q.back()] < heights[i]) {
            int j = q.back();
            q.pop_back();
            
            dp[i] = std::min(dp[i], dp[j] + x);
          }
            
          if (i == 1) {
            dp[i] = std::min(dp[i], dp[i - 1] + y);
          } else {
            dp[i] = std::min(dp[i], std::min(dp[i - 1], dp[i - 2]) + y);
          }
          
          q.push_back(i);
        } 
        
        return dp[n - 1];
    }
};
