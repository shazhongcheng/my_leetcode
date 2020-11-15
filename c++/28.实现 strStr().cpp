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
	// 0ms 
	int strStr(string haystack, string needle) {
		// 如果 需要查找的字符串为空，就返回0 
		if(needle==""){
			return 0;
		}	
		// 遍历目标字符串	
		for(int i=0;i<haystack.length();i++){
			int j=0;
			//如果剩下的字符串，不足查找的字符串的长度，就跳出 
			if(i+needle.length()>haystack.length()){
				break;
			}
			//开始进行逐字符的匹配 
			for(;j<needle.length();j++){
				if(needle[j]!=haystack[i+j]){
					break;
				}
			}
			//匹配成功 
			if(j==needle.length()){
				return i;
			}
		} 
		return -1;
    }
};


int main(){
	Solution s = Solution();
	int res = s.strStr("hello","ll");
	cout<<res<<endl;
	
	return 0;
} 
