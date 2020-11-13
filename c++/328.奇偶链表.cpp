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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	// 分别额外定义一个标记奇数的结尾节点，偶数的头节点、尾节点 
	ListNode* oddEvenList(ListNode* head) {
		//长度为0或1就返回 
        if(head==nullptr || head->next==nullptr){
        	return head;
		}
		//奇数的尾巴节点 
		ListNode* o=head;
		//偶数的头节点 
		ListNode* p=head->next;
		//偶数的尾巴节点 
		ListNode* e=p;
		//后面没有了，就返回 
		while(o->next!=nullptr && e->next!=nullptr){
			//奇数尾巴节点的下一个，安排为偶数的下一个 
			o->next=e->next;
			//奇数尾巴节点更新 
			o=o->next;
			//偶数的下一个指向奇数尾巴节点的下一个 
			e->next=o->next;
			//更新偶数尾巴节点 
			e=e->next;
		}
		//奇数的后面，接上欧数节点的头 
		o->next=p;
		return head;
	}
};


int main(){
	ListNode *head = new ListNode(1);
	ListNode *tail=head;
	for(int i=2;i<6;i++){
		tail->next= new ListNode(i);
		tail=tail->next;
		tail->next=nullptr;
	}
		
	Solution s = Solution();
	ListNode *res = s.oddEvenList(head);
	while(head){
		cout<<res->val<<" "<<endl;
		res=res->next;
	}
	
	return 0;
} 
