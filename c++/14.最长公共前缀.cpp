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
	// 超时了……
	/* 
	string longestCommonPrefix(vector<string>& strs) {
		string str="";
		bool isAdd=true;
		int j=0;
		char mark;
		while(true){
			for(int i=0;i<strs.size();i++){
				if(i==0){
					if(strs[i].length()>j){
						mark=strs[i][j];
						isAdd=true;
					}else{
						isAdd=false;
						break;
					}
				}else{
					if(strs[i].length()>j){
						if(strs[i][j]!=mark){
							isAdd=false;
							break;
						}
					}else{
						isAdd=false;
						break;
					}
				}
				
			}
			if(isAdd==false){
				break;
			}else{
				j++;
			}
		}
		
		return strs[0].substr(0,j); 
    }
    */
    // 运算时间 0ms
	// 思路：1、将字符串数组从短到长排序
	//       2、将最短的第一个字符串长度，设置为标记 right，之后搜索的数组，就不需要超过right了
	//       3、从1开始遍历字符串数组，只要当前的字符不等于第一个字符串的当前字符，就更新right
	//       4、返回从标记的字符串切分的字符 
	 string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size()==0) return res;
        sort(strs.begin(),strs.end(),cmp);
        int right=strs[0].size()-1;
        for(int j=1;j<strs.size()&&right>=0;j++){
        	int i;
        	for(i=0;i<=right;i++)
				if(strs[j][i]!=strs[0][i]){
        		break;
			}
			right=i-1;
		}
		res=strs[0].substr(0,right+1);
		
		return res; 
    }
    static bool cmp(string &a,string &b){
    	return a.size()<b.size();
	}
};


int main(){
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("floght");
		
	Solution s = Solution();
	string res = s.longestCommonPrefix(strs);
	cout<<res<<" "<<endl;
	
	return 0;
} 
