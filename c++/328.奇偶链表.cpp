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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	// �ֱ���ⶨ��һ����������Ľ�β�ڵ㣬ż����ͷ�ڵ㡢β�ڵ� 
	ListNode* oddEvenList(ListNode* head) {
		//����Ϊ0��1�ͷ��� 
        if(head==nullptr || head->next==nullptr){
        	return head;
		}
		//������β�ͽڵ� 
		ListNode* o=head;
		//ż����ͷ�ڵ� 
		ListNode* p=head->next;
		//ż����β�ͽڵ� 
		ListNode* e=p;
		//����û���ˣ��ͷ��� 
		while(o->next!=nullptr && e->next!=nullptr){
			//����β�ͽڵ����һ��������Ϊż������һ�� 
			o->next=e->next;
			//����β�ͽڵ���� 
			o=o->next;
			//ż������һ��ָ������β�ͽڵ����һ�� 
			e->next=o->next;
			//����ż��β�ͽڵ� 
			e=e->next;
		}
		//�����ĺ��棬����ŷ���ڵ��ͷ 
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
