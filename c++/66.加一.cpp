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
	// 逻辑很简单，从后往前，加1如果超过了10，就变为0，继续在高一位+1，重复，直到不会超过10
	// flag检查是否是因为最后一次增加超过10返回，是的话，数组前面加一位 
	vector<int> plusOne(vector<int>& digits) {
		bool flag=false;
		for(int j=digits.size()-1;j>=0;j--){
			if(digits[j]+1<10){
				flag=false;
				digits[j]++;
				break;
			}else{
				flag=true;
				digits[j]=0;
			}
		}
		if(flag){
			digits.insert(digits.begin(),1);
		} 
		return digits;
    }
};


int main(){
	vector<int> digits={0,0};
	 
	Solution s = Solution();
	vector<int>  res = s.plusOne(digits);
	for(auto& r:res){
		cout<<r<<" ";
	}
	
	return 0;
}  
