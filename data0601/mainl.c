#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);

}

ListNode* insert_first(ListNode* head, element data)
{	
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* delete_first(ListNode* head)
{
	if (head == NULL)
	{
		printf("cant remove!!!\n");
		return NULL;
	}

	ListNode* removed = head->link;
	head->link = removed->link;

	if (removed == head) {
		free(removed);
		return NULL;
	}

	free(removed);
	return head;
}
ListNode* delete_last(ListNode* head)
{
	if (head == NULL)
	{
		printf("Can't remove!!!\n");
		return NULL;
	}

	ListNode* cur = head;

	// ��尡 �� ���� ���
	if (cur->link == head)
	{
		free(cur);
		return NULL;
	}

	// ������ ��� Ž��
	while (cur->link != head)
	{
		cur = cur->link;
	}

	// cur �� ������ ���� ���
  // ������ ���(head) ����
	cur->link = head->link;  // ������ ���� -> ó�� ��� ����
	free(head);
	head = cur; // ��� ����

	return head;
}




// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	while (1)
	{
		int menu;
		printf("***********Menu***************\n");
		printf("(1)Insert First\n");
		printf("(2)Insert last\n");
		printf("(3)Delete First\n");
		printf("(4)Delete last\n");
		printf("(5)Print List\n");
		printf("(0)Exit\n");

		printf("Enter the Menu : ");
		scanf_s("%d", &menu);

		if (menu == 1)
		{
			int num;
			printf("Input a number : ");
			scanf_s("%d", &num);

			head = insert_first(head, num);
		}
		else if (menu == 2)
		{
			int num;
			printf("Input a number : ");
			scanf_s("%d", &num);

			head = insert_last(head, num);
		}
		else if (menu == 3)
		{
			head = delete_first(head);
			printf("First node has been delete\n");
		}
		else if (menu == 4)
		{
			head = delete_last(head);
			printf("Last Node has been deleted!!\n");
		}
		else if (menu == 5)
		{
			print_list(head);
			printf("\n");
		}
		else if(menu == 0)
		{
			return 0;
		}




	}
	


	return 0;
}