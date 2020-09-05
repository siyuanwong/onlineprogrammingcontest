/*================================================================
*   
*   file_name  ：359.cc
*   author     ：siyuanwong
*   create_date：2020/09/05
*
================================================================*/

/*
 * 描述
 * You're giving nn wood sticks, by each cut, you can cut a stick into 22 parts.
 * Please calculate the minimum number of cuts you need, that you are able to
 * choose 33 of the sticks, to make a equilateral triangle.
 *
 * At the beginning, there are nn sticks, 3 \le n \le 10003≤n≤1000.
 * All the lengths of sticks is represent by an integer array lengthslengths, 1
 * \le lengths_i \le 10^91≤lengths
 * ​i
 * ​​ ≤10
 * ​9
 * ​​ .
 * Each cut must split a stick into 22 sticks with integer length, and their sum
 * should be equal to the original length.
 *
 * 您在真实的面试中是否遇到过这个题？  
 * 说明
 * You can cut 22 sticks of length 33 for the stick of length 77, the sticks
 * should be [2,3,1,3,3,5][2,3,1,3,3,5], you can make equilateral triangle of
 * length 33 sticks.
 *
 * 样例
 * Input：
 * [2,3,7,5]
 * Output：
 * 2
 *
 * https://www.lintcode.com/problem/makeequilateraltriangle/description
 *
 */

class Solution {
 public:
	/**
	 * @param lengths: the lengths of sticks at the beginning.
	 * @return: return the minimum number of cuts.
	 */
	int makeEquilateralTriangle(vector<int> &lengths) {
		// write your code here.
		
		std::sort(lengths.begin(), lengths.end());
		
		int flag = 0;
		
		for (int i = 0; i < lengths.size();) {
			int j = upper_bound(lengths.begin(), lengths.end(), lengths[i]) - lengths.begin();
			
			flag = std::max(flag, j - i);
			
			i = j;
		}
		
		if (flag == 1) {
			
			for (int i = 0; i < lengths.size(); i++) {
				int j = lengths[i] << 1;
				
				int idx = lower_bound(lengths.begin(), lengths.end(), j) - lengths.begin();
				
				if (idx < lengths.size() && lengths[idx] == j)
					return 1;
			}
			
			return 2;
			
		} else if (flag == 2) {
			return 1;
		} else {
			return 0;
		}
	}
};
