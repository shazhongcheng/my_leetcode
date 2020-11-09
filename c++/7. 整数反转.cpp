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
	
	/**
	自己写的丑陋的代码 
	*/
	/* 
	int reverse(int x) {
		if(x==0){
			return 0;
		}
		bool flag=x>0?true:false;
		long long temp=0;
		x=abs(x);
		while(x>0){
			temp=temp*10+x%10;
			x/=10;
			if(temp<0){
				return 0;
			}
		}
		if(flag){
			return (int)temp==temp?temp:0;
		}else{
			return (int)(-1*temp)==-1*temp?-1*temp:0;
		}
    }
    */
    /*
    参考的评论 
    */ 
    int reverse(int x) {
		long long n = 0;
        while(x != 0) {
            n = n*10 + x%10;
            x = x/10;
        }
        return (int)n==n? (int)n:0;
    }
	
};


int main(){
	
	Solution s = Solution();
	int res = s.reverse(-1563847412);
	cout<<res<<endl;
	return 0;
} 
