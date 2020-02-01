#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 10
typedef int datatype;      /*�������������Ԫ�ص���������*/

typedef struct seqqueue {
	datatype data[MAXSIZE];    //��������Ϊ���еĴ���ռ�
	int front, rear;     /*ָʾ��ͷλ�úͶ�βλ�õ�ָ��*/
}seq_queue, * seq_pqueue;

#include "seqqueue.h"

seq_pqueue init1_seqqueue(void)     //��������
{
	seq_pqueue q;
	q = (seq_pqueue)malloc(sizeof(seq_queue));
	if (q == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	q->front = q->rear = MAXSIZE - 1;

	return q;
}

void init_seqqueue(seq_pqueue* Q)      //�������У�ͬ�ϣ�
{
	*Q = (seq_pqueue)malloc(sizeof(seq_queue));
	if ((*Q) == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	(*Q)->front = (*Q)->rear = MAXSIZE - 1;

	return;
}
//�ж϶����Ƿ���
bool is_full_seqqueue(seq_pqueue q)
{
	if ((q->rear + 1) % MAXSIZE == q->front)
		return true;
	else
		return false;
}
//���
bool in_seqqueue(datatype data, seq_pqueue q)
{
	//�ж϶����Ƿ���
	if (is_full_seqqueue(q)) {
		printf("��������!\n");
		return false;
	}

	//���
	q->rear = (q->rear + 1) % MAXSIZE;
	q->data[q->rear] = data;
	return true;
}
bool is_empty_seqqueue(seq_pqueue q)    //�ж϶����Ƿ�Ϊ�ն���
{
	if (q->rear == q->front)
		return true;
	else
		return false;
}
//����
bool out_seqqueue(seq_pqueue q, datatype* D)
{
	//�ж϶����Ƿ��
	if (is_empty_seqqueue(q)) {
		printf("�����ѿ�!\n");
		return false;
	}

	//����
	q->front = (q->front + 1) % MAXSIZE;
	*D = q->data[q->front];

	return true;
}

void show_seqqueue(seq_pqueue q)      //�Ӷ�ͷ����β������ʾ�����е�����
{
	int i;
	if (is_empty_seqqueue(q))
		return;
	//�ǿ�ʱ���Ӷ�ͷ��ӡ����β
	for (i = (q->front + 1) % MAXSIZE; i != (q->rear + 1) % MAXSIZE; i = (i + 1) % MAXSIZE)
	{
		printf("%d\t", q->data[i]);
	}
	printf("\n");
}


void free_seqqueue(seq_pqueue q)  //�ͷŶ���
{
	free(q);
}

extern seq_pqueue init1_seqqueue(void);    //��������
extern void init_seqqueue(seq_pqueue* Q);    //�������У�ͬ�ϣ�
extern bool is_full_seqqueue(seq_pqueue q);   //�ж϶����Ƿ�Ϊ������
extern bool is_empty_seqqueue(seq_pqueue q);    //�ж϶����Ƿ�Ϊ�ն���
extern bool in_seqqueue(datatype data, seq_pqueue q);    //���
extern bool out_seqqueue(seq_pqueue q, datatype* D);   //����
extern void show_seqqueue(seq_pqueue q);    //�Ӷ�ͷ����β������ʾ�����е�����
extern void free_seqqueue(seq_pqueue q);  //�ͷŶ���

#endif
