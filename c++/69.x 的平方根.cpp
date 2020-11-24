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
	// ������������ʱ 32ms 
//	int mySqrt(int x) {
//		for(long long i=0;i<=x;i++){
//			if((i+1)*(i+1)>x){
//				return int(i);
//			}
//		} 
//		return 0;
//    }
	 
	// ţ�ٵ�����  0ms 
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
	
	
	// �Ա������������Ż���ʱ���n ����Ϊ long(n) ��ʱ 0ms 
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
