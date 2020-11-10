//  973. ��ӽ�ԭ��� K ����
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
	// 8ms
	/* 
	void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int j = nums.size() - 1; 
        while(j-1>=0 && nums[j-1] >= nums[j]){ --j;}
        if(j == 0){
            for(int i = 0; i < nums.size()/2; ++i){
                swap(nums[i], nums[nums.size() - 1 - i]);
            }
            return ;
        }
        int r = nums.size() - 1;
        while(r >= j){
            if(nums[r] > nums[j-1]) break;
            --r;
        }
        swap(nums[r], nums[j-1]);
        int cnt = (nums.size() - j)/2;
        int i = 0;
        while(cnt > 0){
            swap(nums[j+i], nums[nums.size() - 1 - i]);
            ++i; --cnt;
        }
        return;
    }
	*/
	
	// �޸������� 
	// 12ms 
	/* 
	void nextPermutation(vector<int>& nums) {
		// ����С��2 ֱ�ӷ��� 
		if(nums.size()<=1) return;
		// �ж��Ƿ��ǽ��� 
		int j=nums.size()-1;
		while(j-1>=0 && nums[j-1]>=nums[j]){
			--j;
		}
		//�ǽ��� 
		if(j==0){
//			for(int i=0;i<nums.size()/2;++i){
//				swap(nums[i],nums[nums.size()-1-i]);
//			}
			reverse(nums.begin(),nums.end()); 
			return;
		}
		//��(j,nums.size())���ҵ���һ����j-1���ֵ����Ϊ������ж�ԭ�����ԴӺ���ǰ�ҵ��ĵ�һ�����ڵģ�һ������ӽ��� 
		int r=nums.size()-1;
		while(r>=j){
			if(nums[r]>nums[j-1]) break;
			--r;
		}
		//���� 
		swap(nums[r],nums[j-1]);
		//��[j,nums,size()] ���������� 
//		int cnt=(nums.size()-j)/2;
//		int i=0;
//		while(cnt>0){
//			swap(nums[j+i],nums[nums.size()-1-i]);
//			++i;--cnt;
//		}
		//Ĭ�ϰ����������� 
		sort(nums.begin()+j,nums.end()); 
		return;
    }
    */
    // 8ms
    // ����Χ�ڵ�Ԫ���������е���һ���ֵ��ϵĸ�������� 
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums));
    }
    
	
};


int main(){
	vector<int> v;
	Solution s = Solution();
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	 
	s.nextPermutation(v);
	for(int &n:v){
		cout<<n<<" ";
	}
	cout<<endl;
	
	v.clear();
	
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	 
	s.nextPermutation(v);
	for(int &n:v){
		cout<<n<<" ";
	}
	cout<<endl;
	
	return 0;
} 
