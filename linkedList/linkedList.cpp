#include <iostream>
using namespace std;

typedef struct ListNode{
	int data;
	ListNode *link;
}ListNode;

class List{
private:
	ListNode *head;
	int cnt;
public:
	List()
	{
		head = nullptr;
		cnt = 0;
	}
	~List()
	{
		head = nullptr;
		cnt = 0;
	}

	void insert_front(ListNode *new_node) // list 맨 앞에 삽입
	{
		if(head == nullptr)
			head = new_node;
		else
		{
			new_node->link=head;
			head = new_node;
		}
		cnt++;
	}

	void insert_back(ListNode *new_node) // list 맨 뒤에 삽입
	{
		if(head == nullptr)
			head = new_node;
		else
		{
			ListNode *tmp = head;
			while (tmp->link != nullptr)
			{
				tmp = tmp->link;
			}
			tmp->link = new_node;
			new_node->link=nullptr;
		}
		cnt++;
	}

	int insert_index(ListNode *new_node, int idx) // 특정 위치에 삽입, 해당 위치에 삽입할 수 없으면 -1 반환, 성공하면 해당 위치 index 반환
	{
		int n=0;
		if(idx > cnt) // 범위를 벗어난 경우
			return -1;

		if(head == nullptr){ // null list에 삽입하는 경우
			head = new_node;
			new_node->link = nullptr;
		}
		else if(idx == 0) // 맨 앞에 삽입하는 경우
		{
			new_node->link = head;
			head = new_node;	
		}
		else
		{
			int n=0;
			ListNode *tmp = head;

			while(n<idx-1){
				tmp = tmp->link;
				n++;
			}

			if(tmp->link==nullptr){ // 맨 뒤에 삽입하는 경우
				tmp->link = new_node;
			}
			else{
				new_node->link = tmp->link;
				tmp->link = new_node;
			}
			
		}
		cnt++;
		return idx;
		
	}

	void remove(int idx)
	{
		if(idx > cnt) // 제거할 원소의 인덱스가 범위를 벗어난 경우 함수 종료
			return; 

		if(idx == 0) // 맨 앞의 원소를 제거하는 경우
		{
			head = head->link;
		}
		else
		{
			int n=0;
			ListNode *tmp = head;

			while(n<idx-1){
				tmp = tmp->link;
				n++;
			}

			ListNode *removed = tmp->link;
			tmp->link = removed->link;
		}
		cnt--;

	}

	int getSize()
	{
		return cnt;
	}
};

int main()
{
	ListNode node1={1,nullptr};
	ListNode node2={2,nullptr};
	ListNode node3={3,nullptr};
	ListNode node4={4,nullptr};
	ListNode node5={5,nullptr};
	
	List list;

	list.insert_front(&node1);
	list.insert_front(&node2);
	list.insert_front(&node3);
	list.insert_index(&node4, 2);
	list.insert_back(&node5);
	printf("list size: %d\n",list.getSize());

	list.remove(0);
	list.remove(2);
	printf("list size: %d\n",list.getSize());

}
