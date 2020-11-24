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
	// 暴力遍历，耗时 32ms 
//	int mySqrt(int x) {
//		for(long long i=0;i<=x;i++){
//			if((i+1)*(i+1)>x){
//				return int(i);
//			}
//		} 
//		return 0;
//    }
	 
	// 牛顿迭代法  0ms 
//	int mySqrt(int x) {
//		if(x<=1){
//			return x;
//		}
//		long long r=x;
//		while(r>x/r){
//			r=(r+x/r)/2;
//		}
//		return (int)r;
//    }
	
	
	// 对暴力迭代法的优化，时间从n 降低为 long(n) 耗时 0ms 
	int mySqrt(int x) {
		if(x==1){
			return 1;
		} 
		int min=0;
		int max=x;
		while(max-min>1){
			int m=(max+min)/2;
			if(x/m<m){
				max=m;
			}else{
				min=m;
			}
		} 
		return min;
		
    }
};


int main(){
	 
	Solution s = Solution();
	int  res = s.mySqrt(4);
	cout<<res;
	
	return 0;
}  
