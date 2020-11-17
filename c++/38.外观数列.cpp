#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
	//递归  8ms
	// 思路，对上一轮的数据做处理 
	string countAndSay(int n) {
		// 如果递归到头，就返回 "1" 
		if(n==1) return "1";
		// 获取上一轮的结果 ，并处理 
		string num=countAndSay(n-1);
		string temp="";
		// 对上一轮的结果做遍历 
		for(int i=0;i<num.size();i++){
			// 对上一轮的当前数字做统计 
			int count=1;
			// 统计相同的数字出现了几次 
			while(i<num.length()-1 && num[i]==num[i+1]){
				count++;
				i++;
			}
			// 拼接到结尾 
			temp+=tostr(count);
			temp+=num[i];
		}
		//返回 
		return temp;
	}
	// 数字转字符串 
	string tostr(int count){
		string res="";
		while(count){
			res=(char)(count%10+'0')+res;
			count/=10;
		}
		return res;
	}
};


int main(){
	Solution s = Solution();
	string res = s.countAndSay(4);
	cout<<res;
	
	return 0;
} 
