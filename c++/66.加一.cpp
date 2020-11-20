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
	// �߼��ܼ򵥣��Ӻ���ǰ����1���������10���ͱ�Ϊ0�������ڸ�һλ+1���ظ���ֱ�����ᳬ��10
	// flag����Ƿ�����Ϊ���һ�����ӳ���10���أ��ǵĻ�������ǰ���һλ 
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
