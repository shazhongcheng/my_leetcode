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
	// 先统计字符，然后不停顺位逆位找，并拼接  //44ms
//	string sortString(string s) {
//        int res[26];
//		for(int i=0;i<26;i++){
//			res[i]=0;
//		}
//		for(int i=0;i<s.length();i++){
//			res[(s[i]-'a')]++;
//		}
//		string resstr="";
//		bool flag=true;
//		while(flag){
//			flag=false;
//			for(int i=0;i<26;i++){
//				if(res[i]!=0){
//					resstr=resstr+(char)(i+'a');
//					flag=true;
//					res[i]--;
//				}
//				
//			}
//			if(flag){
//				flag=false;
//			}else{
//				break;
//			}
//			for(int i=25;i>=0;i--){
//				if(res[i]!=0){
//					resstr=resstr+(char)(i+'a');
//					flag=true;
//					res[i]--;
//				}
//				
//			}
//			
//		}
//		return resstr;
//    }
	
	//4ms 使用vector来优化 并通过被拼接的字符串长度，来判定是否终止循环 
	string sortString(string s) {
		vector<int> tmp(26);
		for(int i=0;i<s.size();i++){
			tmp[s[i]-'a']++;
		}
		string ret;
		while(ret.size()<s.size()){
			for(int i=0;i<26;i++){
				if(tmp[i]){
					ret+=i+'a',tmp[i]--;
				}
			}
			for(int i=25;i>=0;i--){
				if(tmp[i]){
					ret+=i+'a',tmp[i]--;
				}
			}
			
		}
		return ret;
	}  

};


int main(){
	 
	Solution s = Solution();
	string  res = s.sortString("aaaabbbbcccc");
	cout<<res;
	
	return 0;
}  
