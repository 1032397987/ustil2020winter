#include<stdio.h>
#include<stdlib.h>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * LinkQueue;

LinkQueue rear, head;

int EnQueue(int e)//����� 
{
	LinkQueue p;
	p = (LinkQueue)malloc(sizeof(QNode));
	p->data = e;
	rear->next = p;
	rear = p;
	rear->next = head;
}

int Create(int n)//����
{
	LinkQueue p;
	int e;
	head = (LinkQueue)malloc(sizeof(QNode));
	rear = head;
	head->next = rear;
	rear->next = head;
	rear->data = head->data = NULL;
	printf("�������Ԫ�أ� ");
	while (n--)
	{
		scanf("%d", &e);
		EnQueue(e);
	}

}

int Show()//��ʾ 
{
	LinkQueue p;
	printf("��ǰ����Ԫ��Ϊ�� ");
	p = head->next;
	if (head == rear)//����Ϊ��ʱ
	{
		printf("����Ϊ��\n");
		return 0;
	}
	for (; p != rear; p = p->next)
	{
		printf("%d ", p->data);
	}
	printf("%d\n", p->data);
}

int DeQueue()//������  
{
	int e;
	LinkQueue p;
	p = head->next;
	e = p->data;
	if (head == rear)//����Ϊ��ʱ
	{
		printf("����Ϊ��\n");
		return 0;
	}
	head->next = head->next->next;
	if (head->next == head)
	{
		rear = head;
	}
	free(p);
	printf("������Ԫ��Ϊ�� %d\n", e);
}

int main()
{
	int select, e, n;
	printf("1.��������\t2.�����\t3.������\t4.�˳�\n");
	while (1)
	{
		printf("ѡ������� ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("������еĳ��ȣ� ");
			scanf("%d", &n);
			Create(n);
			Show();
			break;
		case 2:
			printf("���������Ԫ�أ� ");
			scanf("%d", &e);
			EnQueue(e);
			Show();
			break;
		case 3:
			DeQueue();
			Show();
			break;
		case 4:
			return 0;
		default:
			printf("�������\n");
			break;
		}
	}
	return 0;
}