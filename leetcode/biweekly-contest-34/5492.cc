/*================================================================
*   
*   file_name  ：5492.cc
*   author     ：siyuanwong
*   create_date：2020/09/06
*
================================================================*/

/*
 * 给你一个二进制串 s  （一个只包含 0 和 1 的字符串），我们可以将 s 分割成 3 个
 * 非空 字符串 s1, s2, s3 （s1 + s2 + s3 = s）。
 *
 * 请你返回分割 s 的方案数，满足 s1，s2 和 s3 中字符 '1' 的数目相同。
 *
 * 由于答案可能很大，请将它对 10^9 + 7 取余后返回。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：s = "10101"
 * 输出：4
 * 解释：总共有 4 种方法将 s 分割成含有 '1' 数目相同的三个子字符串。
 * "1|010|1"
 * "1|01|01"
 * "10|10|1"
 * "10|1|01"
 * 示例 2：
 *
 * 输入：s = "1001"
 * 输出：0
 * 示例 3：
 *
 * 输入：s = "0000"
 * 输出：3
 * 解释：总共有 3 种分割 s 的方法。
 * "0|0|00"
 * "0|00|0"
 * "00|0|0"
 * 示例 4：
 *
 * 输入：s = "100100010100110"
 * 输出：12
 *  
 *
 * 提示：
 *
 * s[i] == '0' 或者 s[i] == '1'
 * 3 <= s.length <= 10^5
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/number-of-ways-to-split-a-string
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */

class Solution {
public:
    int numWays(string s) {
      int n = s.length();

      int all = 0;
      for (int i = 0; i < n; i++)
        all += (s[i] == '1');
      
      if (all % 3)
        return 0;

      if (!all) {
        return c(n - 1, 2, m_mod); 
      } else {
        int u = 0;
        int cnt = (s[u] == '1');
        while (cnt < all / 3) {
          u += 1;
          cnt += (s[u] == '1');
        } 
        
        int v = n - 1;
        cnt = (s[v] == '1');
        while (cnt < all / 3) {
          v -= 1;
          cnt += (s[v] == '1');
        }
        
        int uu = u + 1;
        while (s[uu] != '1')
          uu += 1;
        
        int vv = v - 1;
        while (s[vv] != '1')
          vv -= 1;
        
        return 1LL * (uu - u) * (v - vv) % m_mod;
      }
    }
  
private:
  const int64_t m_mod = 1e9 + 7;
  int64_t qp(int64_t a, int64_t b, int64_t m) {
    if (!b) return 1;
    
    if (b & 1) {
      return a * qp((a * a) % m, b >> 1, m) % m;
    } else {
      return qp((a * a) % m, b >> 1, m) % m;
    }
  }
  
  int64_t fac(int64_t n, int64_t m) {
    int64_t result = 1;
    
    while (n) {
      result = (result * n) % m;
      n -= 1;
    }
    
    return result;
  }
  
  int64_t c(int64_t a, int64_t b, int64_t m) {
    int64_t result = 1;
    for (int i = 0; i < b; i++, a--)
      result = (result * a) % m;
    
    result = (result * qp(b, m - 2, m)) % m;
    
    return result;
  }
};
