/*================================================================
*   
*   file_name  ：5510.cc
*   author     ：siyuanwong
*   create_date：2020/09/06
*
================================================================*/

/*
 * Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：
 *
 * 类型 1：只能由 Alice 遍历。
 * 类型 2：只能由 Bob 遍历。
 * 类型 3：Alice 和 Bob 都可以遍历。
 * 给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi
 * 之间存在类型为 typei 的双向边。请你在保证图仍能够被 Alice和 Bob
 * 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob
 * 都可以到达所有其他节点，则认为图是可以完全遍历的。
 *
 * 返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。
 *
 *  
 *
 *  示例 1：
 *
 *
 *
 *  输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
 *  输出：2
 *  解释：如果删除 [1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob
 *  仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所以可以删除的最大边数是
 *  2 。
 *  示例 2：
 *
 *
 *
 *  输入：n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
 *  输出：0
 *  解释：注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
 *  示例 3：
 *
 *
 *
 *  输入：n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
 *  输出：-1
 *  解释：在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob
 *  也不能达到节点 1 。因此，图无法完全遍历。
 *   
 *
 *   提示：
 *
 *   1 <= n <= 10^5
 *   1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
 *   edges[i].length == 3
 *   1 <= edges[i][0] <= 3
 *   1 <= edges[i][1] < edges[i][2] <= n
 *   所有元组 (typei, ui, vi) 互不相同
 *
 *   https://leetcode-cn.com/contest/weekly-contest-205/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 *
 */

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      std::set<vector<int>> s;
      vector<int> cnt(4, 0);
      for (int i = 0; i < edges.size(); i++) {
        const std::vector<int>& line = edges[i];
        
        if (line[0] == 3) {
          s.insert(line);
        }
        cnt[line[0]] += 1;
      }
      
      UnionCls uni(n + 1);
      int take = 0;
      for (auto it = s.begin(); it != s.end(); ++it) {
        const std::vector<int>& line = *it;
        
        int u = line[1];
        int v = line[2];
        
        if (uni.Find(u) == uni.Find(v))
          continue;
        uni.Union(u, v);
        take += 1;
      }
      
      {
        UnionCls tmp(uni); 
        for (int i = 0; i < edges.size(); i++) {
          const std::vector<int>& line = edges[i];
          if (line[0] != 1)
            continue;
          
          int u = line[1];
          int v = line[2];
          if (tmp.find(u) == tmp.find(v))
            continue;
          tmp.Union(u, v);
          take += 1;
        }
        
        int root = tmp.find(1);
        for (int i = 2; i <= n; i++)
          if (tmp.find(i) != root)
            return -1;
      }
      
      {
        UnionCls tmp(uni); 
        for (int i = 0; i < edges.size(); i++) {
          const std::vector<int>& line = edges[i];
          if (line[0] != 2)
            continue;
          
          int u = line[1];
          int v = line[2];
          if (tmp.find(u) == tmp.find(v))
            continue;
          tmp.Union(u, v);
          take += 1;
        }
        
        int root = tmp.find(1);
        for (int i = 2; i <= n; i++)
          if (tmp.find(i) != root)
            return -1;
      }
      
      return cnt[1] + cnt[2] + cnt[3] - take;
    }
private:
  class UnionCls {
   public:
    UnionCls(int32_t sz) : m_sz(sz), m_root(sz) {
      std::iota(m_root.begin(), m_root.end(), 0);
    }
    
    int find(int x) {
      return Find(x);
    }
    int Find(int x) {
      if (m_root[x] == x)
        return x;
      m_root[x] = Find(m_root[x]);
      return m_root[x];
    }
    
    void Union(int u, int v) {
      int ru = Find(u);
      int rv = Find(v);
      
      m_root[rv] = ru;
    }
    
   private:
    int32_t m_sz; 
    std::vector<int> m_root;
  };  
};
