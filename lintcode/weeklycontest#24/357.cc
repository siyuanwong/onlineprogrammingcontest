/*================================================================
*   
*   file_name  ：357.cc
*   author     ：siyuanwong
*   create_date：2020/09/05
*
================================================================*/

/*
 * 描述
 * You're given a string ss.
 * We call the weight of a string is the length the longest symmetry prefix and
 * postfix of the substrings.
 * Please calculate the sum weight of all the substrings of ss.
 * For example, the length the longest symmetry prefix and postfix of
 * "abcxyzcba" is 33, because "abc" is symmetry to "cba",
 *
 * The string is of length nn, 1 \le n \le 3 * 10^31≤n≤3∗10
 * ​3
 * ​​ .
 * The string is filled with lowercase English characters.
 *
 * 您在真实的面试中是否遇到过这个题？  
 * 说明
 * In the example, the weight of a single character substring is 11, their sum
 * is 77.
 * The other weights are：
 * "bacb" -> 1
 * "bacbdab" -> 2
 * "bdab" -> 1
 * "acbda" -> 1
 * So the output should be 1212.
 *
 * 样例
 * Input：
 * "bacbdab"
 * Output：
 * 12
 *
 * https://www.lintcode.com/problem/symmetrical-suffix/description?_from=contest&&fromId=103
 *
 */

class Solution {
  using vi = std::vector<int64_t>;
  using vii = std::vector<vi>;
public:
    /**
     * @param s: a string.
     * @return: return the values of all the intervals.
     */
    long long suffixQuery(string &s) {
        // write your code here
        
        int n = s.length();
        
        vii rec(n, vi(n, -1));
        
        vi last(n, -1);
        
        for (int i = 0; i < n; i++) {
          for (int j = i - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
              last[i] = j;
              break;
            }
          }
        }
        
        int64_t result = 0;
        for (int i = 0; i < n; i++) {
          int j = i;
          while (j >= 0) {
            result += FillRec(s, rec, j, i, j, i); 
            
            //std::cerr << i << ", " << j << ", " << result << "\n";
            
            j = last[j];
          }
        }
        
        return result;
        
    }
    
private:
    int64_t FillRec(const string& s, vii& rec, int u, int v, int i, int j) {
      if (i > v || j < u)
        return 0;
        
      if (rec[i][j] != -1)
        return rec[i][j];
        
      if (s[i] == s[j]) {
        
        int64_t inner = FillRec(s, rec, i, j, i + 1, j - 1);
        if (inner == (j - 1) - (i + 1) + 1) {
          rec[i][j] = 2LL + inner;
        } else {
          rec[i][j] = 1LL + inner;
        }
        
      } else {
        rec[i][j] = 0;
      }
      
      return rec[i][j];
    }
};
