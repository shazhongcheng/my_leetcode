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
	// 从最后往前开始统计，当出现第一个非空字符时，开始统计，当出现空字符，且长度不为0时，返回 
	int lengthOfLastWord(string s) {
		if(s.length()<=0){
			return 0;
		}
		int length=0;
		for(int i=s.length()-1;i>=0;i--){
			if(s[i]!=' '){
				length++;
			}else if(length!=0){
				return length;
			}
		}
		return length;
    }
};


int main(){
	Solution s = Solution();
	int length = s.lengthOfLastWord("Hello World");
	cout<<length<<endl;
	
	return 0;
}  
