//  7. 整数反转
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	
	int findRotateSteps(string ring, string key) {
		// n是字符串长度，m是秘钥长度 
		int n =ring.size(),m=key.size();
		// idx 存储了字符串中，每个字符的位置，dp是状态转移矩阵（m，要转移两次，n，每次搜索的长度=字符串长度，INT_MAX，将初始的值设为最大） 
		vector<vector<int> > idx(26),dp(m,vector<int>(n,INT_MAX));
		// idx 位置列表初始化 
		for(int i=0;i<n;i++) idx[ring[i]-'a'].push_back(i);
		// 动态规划 m次 
		for(int i=0;i<m;i++){
			//对当前位置做遍历 
			for(int &j:idx[key[i]-'a']){
				//如果是第一轮初始化，将dp中，第一行状态的长度，全部初始化为(顺位到达，逆位达到)的最小值 
				if(i==0) dp[0][j]=min(j,n-j);
				//不是第一轮了 
				else{		
					//从位置矩阵中，取出上一次的字符值的位置，然后看从当前位置，到哪一个上一个位置，更近			
					for(int &k:idx[key[i-1]-'a']){
						//如果是之前遍历的位置更近，就不变，如果是(顺位到达，逆位达到)更近，就更新矩阵 
						dp[i][j]=min(dp[i][j],dp[i-1][k]+min(abs(j-k),n-abs(j-k)));
					}
				}
			}
		}
		//获取dp之后一行中的最小值 + 按照key长度进行拼写的的步数 
		return *min_element(begin(dp.back()),end(dp.back()))+m;
    }
	
};


int main(){
	
	Solution s = Solution();
	
	cout<<s.findRotateSteps("godding","gd")<<endl;
	return 0;
} 
