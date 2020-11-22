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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// �������⡭�� 
//����������������յ�Ӧ�þ��Ǹ��ֶ�������Ȼ���ٹҽӰ��������������Ҫ�õ��������������������
//
//merge(l1, l2)��˫·�鲢�������������������Ѿ��ǳ������ģ��Ͳ��������ˡ�
//cut(l, n)��������Щͬѧû����˵��������ʵ����һ�� split �����������������������Ҹо�ʹ�� cut ��׼ȷһЩ������ʾ�������� l �е�ǰ n ���ڵ㣬�����غ�벿�ֵ�����ͷ��
//�����ٲ���һ�� dummyHead �󷨣��Ѿ������������ˣ���ϸ���ɡ�
//---
//
//ϣ��ͬѧ���ܰ�˫·�鲢�� cut �����Ĵ����ü����ģ��Ժ󿴵����Ƶ���Ŀ�ܹ�ˢ������
//
//���������������������ǵ� bottom-to-up �㷨α�����ʮ�������ˣ�
//
//current = dummy.next;
//tail = dummy;
//for (step = 1; step < length; step *= 2) {
//	while (current) {
//		// left->@->@->@->@->@->@->null
//		left = current;
//
//		// left->@->@->null   right->@->@->@->@->null
//		right = cut(current, step); // �� current �е�ǰ step ��ͷ��������
//
//		// left->@->@->null   right->@->@->null   current->@->@->null
//		current = cut(right, step); // �� right �е�ǰ step ��ͷ��������
//		
//		// dummy.next -> @->@->@->@->null�����һ���ڵ��� tail��ʼ�ռ�¼
//		//                        ^
//		//                        tail
//		tail.next = merge(left, right);
//		while (tail->next) tail = tail->next; // ���� tail Ϊβ��
//	}
//}

class Solution {
public:
	// ���� ��˼·�ǳ���������Ҫ������Ķ��� ���ӵĲ������Ƚ��Ѵ��� 
	ListNode* sortList(ListNode* head) {
		ListNode dummyHead(0);
		dummyHead.next=head;
		auto p = head;
		int length=0;
		// ��ͳ�Ƴ��ȣ��Թ��������¶��ϵĹ鲢���� 
		while(p){
			++length;
			p=p->next;
		} 
		// ��1-2-4-8----����ָ���������鲢���� 
		for(int size=1;size<length;size<<=1){
			//��ǰ�����Ŀ�ͷ 
			auto cur=dummyHead.next;
			//�������ӵ�ǰÿһ��С�ַ��صĹ鲢�õ��Ӽ� 
			auto tail=&dummyHead;
			//���û�е���β���ͼ��� 
			while(cur){
				//��߿�ͷ���Ӽ� 
				auto left=cur;
				//����size����left��ʼ����ָ��size���ȣ������أ��γ��ұ��Ӽ� 
				auto right=cut(left,size);
				// �ұ��Ӽ����к���ĺܶ�Ԫ�أ�����������ָ��size���ȣ����жϣ�Ȼ�󷵻أ���Ϊ��һ�ֿ�ʼ�ĵ��� 
				cur=cut(right,size);
				//��β���赱ǰ�鲢�Ľ�� �������µ���β 
				tail->next=merge(left,right);
				while(tail->next){
					tail=tail->next;
				}
			}
		}
		//���� ��� 
		return dummyHead.next;
    }
    // ���ܾ��ǣ�����ָ��n���ȵ�Ԫ�أ����ж����Ԫ�غ���һ��Ԫ�ص����ӣ�ͬʱ������һ��Ԫ�ص�ַ 
    ListNode* cut(ListNode* head,int n){
    	auto p=head;
    	while(--n&&p){
    		p=p->next;
		}
		if(!p) return nullptr;
		
		auto next=p->next;
		p->next=nullptr;
		return next;
	}
    // ���ܾ��Ƕ�l1��l2���й鲢 
    ListNode* merge(ListNode* l1,ListNode* l2){
    	ListNode dummyHead(0);
    	auto p=&dummyHead;
    	//ֻҪl1����l2��Ϊ�գ���ѭ���ȴ�С�����赽�ڱ��ڵ���� 
    	while(l1 && l2){
    		if(l1->val < l2->val){
    			p->next=l1;
    			p=l1;
    			l1=l1->next;
			}else{
				p->next=l2;
				p=l2;
				l2=l2->next;
			}
		}
		//��Ϊ�յ�ȫ�����赽�ڱ��ڵ������� 
		p->next=l1?l1:l2;
		return dummyHead.next;
	}
};


int main(){
	ListNode *head = new ListNode(4);
	ListNode *tail=head;
	tail->next=new ListNode(2);
	tail=tail->next;
	tail->next=new ListNode(1);
	tail=tail->next;
	tail->next=new ListNode(3);
	tail=tail->next;
	
	Solution s = Solution();
	ListNode* res = s.sortList(head);
	while(res){
		cout<<res->val<<" ";
		res=res->next;
	}
	
	return 0;
} 
