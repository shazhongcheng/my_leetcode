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
	
	/**
	 	�����󶥶� 
	 	ʱ�� 415ms 
	*/ 
	/** 
	struct cmp{
		bool operator()(vector<int> &A,vector<int> &B) const{
			return A[0]*A[0]+A[1]*A[1]<B[0]*B[0]+B[1]*B[1];
		}
	};
	
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
		vector<vector<int> > v;
//		v.reserve(K);
		for(vector<int> &point:points){
			if(v.size()<K){
				v.emplace_back(point);
				//����󶥶� 
				push_heap(v.begin(),v.end(),cmp());
			}else if(comOperator(point,v[0])){
				//������ͷ��β�ͻ��� 
				pop_heap(v.begin(),v.end(),cmp());
				v.pop_back();
				v.emplace_back(point);
				// ����󶥶� 
				push_heap(v.begin(),v.end(),cmp());
			}
		}
		return 	v;	
    }
    
    bool comOperator(vector<int> &A,vector<int> &B){
    	return A[0]*A[0]+A[1]*A[1]<B[0]*B[0]+B[1]*B[1];
	}
    */
    /**
    	����map keyΪ���룬Ȼ����ÿ����ľ��뽫����ӵ��ֵ䣬����վ����С�����ֵ䣬ȡָ��K�ĵ� 
    	ʱ�� 468 ms 
	*/
	/* 
    vector<vector<int> > kClosest(vector<vector<int> >& points, int K){
    	map<double,vector<vector<int> > >m;
    	for(auto& i: points){
    		m[sqrt(i[0]*i[0]+i[1]*i[1])].emplace_back(i);
		}
		int cnt=0;
		vector<vector<int> > res;
		for(auto& nums:m){
			for(auto& iter2:nums.second){
				if(cnt++<K){
					res.emplace_back(iter2);
				}else{
					break;
				}
			}
			if(cnt==K) break;
		}
		return res;
	}
	*/
	
	// ʹǰK��Ԫ�صľ�����С 
	// ʱ�� 240ms 
	vector<vector<int> > kClosest(vector<vector<int> >& points, int K){
		// ��ʼ����֤ǰk������β��lambda���ʽ ����ָ��������� 
		nth_element(points.begin(),points.begin()+K,points.end(),[](auto&& l,auto&& r){return l[0]*l[0]+l[1]*l[1]<r[0]*r[0]+r[1]*r[1];});
		points.resize(K);
		return points;
	}
};


int main(){
	vector<vector<int> > v;
	v.push_back(vector<int>());
	v.push_back(vector<int>());
	v.push_back(vector<int>());
	v[0].push_back(1);
	v[0].push_back(1);
	v[1].push_back(2);
	v[1].push_back(2);
	v[2].push_back(3);
	v[2].push_back(3);
	Solution s = Solution();
	vector<vector<int> > res = s.kClosest(v,2);
	for(vector<int> &point:res){
		cout<<point[0]<<" "<<point[1]<<endl;
	}
	return 0;
} 
