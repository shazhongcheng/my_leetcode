//  973. 最接近原点的 K 个点
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
	bool isPalindrome(int x) {
		if(x<0){
			return false;
		}
		int temp=x;
		long long y=0;
		while(temp>0){
			y=y*10+temp%10;
			temp/=10;
		}
		if(y==x){
			return true;
		}else{
			return false;
		}
    }
    
	
};


int main(){
	
	Solution s = Solution();
	cout<<s.isPalindrome(121)<<endl;
	cout<<s.isPalindrome(-121)<<endl;
	cout<<s.isPalindrome(10)<<endl;
	
	
	return 0;
} 
