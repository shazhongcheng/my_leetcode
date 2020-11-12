//  7. ������ת
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
	// ����ʱ�� 48ms �ڴ����� 22.9MB
	// �Լ���һ�۵��뷨 �ȹ��˳�������ż����Ȼ����˳����ӵ������� 
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
	
	// ����ʱ�� 32ms �ڴ����� 20.4MB
	// �ƶ�����������˫��������������������������������ͺͲ�����������˫���������� 
	vector<int> sortArrayByParityII(vector<int>& A) {
		int j=1;
		for(int i=0;i<A.size()-1;i=i+2){
			// �ȼ��� A[i]%2!=0 
			// ���������ٶ�Ҫ��ö࣬�ĳ������ ��ʱΪ 44ms 
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
