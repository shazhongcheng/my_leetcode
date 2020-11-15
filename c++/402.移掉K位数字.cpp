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
	// 16ms
	// 思路不太好理解，以一个后移num.size()-k次的窗口，每轮遍历寻找当前窗口的最小值 
	/* 
	 string removeKdigits(string num, int k) {
		const int N = num.size();
		string result;
		// 每一轮搜索的窗口头 
		int from=0;
		//每一轮搜索的窗口尾 
		int to=k;
		// 保留的数字个数 
		int last=N-k;
		bool start=false;
		//搜索的轮数为需要保留的数字个数 
		while(last--){
			//搜索范围内找到最小的数字 
			int min=from;
			for(int current=from;current<=to;current++){
				if(num[current]<num[min]){
					min=current;
				}
			}
			// 每一轮搜索的窗口头后移到当前的最小的后面一个 
			from=min+1;
			// 判断是不是第一个不是0的数 
			if(!start){
				if(num[min]!='0'){
					start=true;
					result+=num[min];
				}
			}else{
				result+=num[min];
			}
			// 每一轮搜索的窗口尾巴后移一位 
			to++;
		}
		// 因为都是取的0，没有进判断的添加，result为空 
		if(!result.size()){
			return "0";
		}
		return result;
    }
    */
    // 0ms
    // 思路，遍历数字字符串，如果当前要添加的，比已经有的小，就替换，否则就加进去 
    string removeKdigits(string num, int k) {
        vector<int> S;
        string result="";
        // 遍历 
        for(int i=0;i<num.length();i++){
            //提取数字 
			int number=num[i]-'0';
			//暂存的集合不为0，且当前的数字比集合里面的最后一个数字要小，还可以再删数字 
            while(S.size()!=0 &&number<S[S.size()-1]&&k>0){
            	//末尾的较大的数字弹出
                S.pop_back();
                //弹出了一个数字 
                k--;
            }
            //数字不为0就可以添加 或者数字为0的时候长度不为0也可以添加 
			if(number!=0 || S.size()!=0){
                //添加数字 
				S.push_back(number);
            }
        }
        //末尾都是递增的数字 
        while(S.size()!=0 && k>0){
            S.pop_back();
            k--;
        }
        //遍历集合，然后添加到字符串中 
        for(int i=0;i<S.size();i++){
            result.append(1,'0'+S[i]);
        }
        //如果字符串为空，就返回 "0" 
        if(result==""){
            result="0";
        }
        return result;
    }
};


int main(){
	Solution s = Solution();
	string res = s.removeKdigits("1432219",3);
	cout<<res<<endl;
	
	return 0;
} 
