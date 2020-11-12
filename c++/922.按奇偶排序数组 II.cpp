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
	// 运算时间 48ms 内存消耗 22.9MB
	// 自己第一眼的想法 先过滤出奇数和偶数，然后按照顺序添加到新数组 
	/* 
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> temp1;
		vector<int> temp2;
		for(auto &n:A){
			if(n%2==1){
				temp1.push_back(n);
			}else{
				temp2.push_back(n);
			}
		}
		vector<int> res;
		for(int i=0;i<A.size();i++){
			if(i%2==0){
				res.push_back(temp2[i/2]);
			}else{
				res.push_back(temp1[i/2]);
			}
		}
		return res;
    }
	*/
	
	// 运算时间 32ms 内存消耗 20.4MB
	// 制定单数索引和双数索引，如果单数索引不符合条件，就和不符合条件的双数索引互换 
	vector<int> sortArrayByParityII(vector<int>& A) {
		int j=1;
		for(int i=0;i<A.size()-1;i=i+2){
			// 等价于 A[i]%2!=0 
			// 但是运行速度要快得多，改成上面的 耗时为 44ms 
			if((A[i]&1)!=0){
				while((A[j]&1)!=0){
					j=j+2;
				}
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
		return A;
    }
	
};


int main(){
	vector<int> A;
	A.push_back(4);
	A.push_back(2);
	A.push_back(5);
	A.push_back(7);
	
	Solution s = Solution();
	vector<int> res = s.sortArrayByParityII(A);
	for(auto &n:res){
		cout<<n<<" "<<endl;
	}
	return 0;
} 
