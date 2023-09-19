#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	float data;
	struct TreeNode* left, * right;
} TreeNode;

// 원형 큐 사용
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;

typedef struct { 		// 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {			// 오류 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}
void init_queue(QueueType* q) {		// 큐 초기화 함수
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) {			// 공백 상태 검출 함수
	return (q->front == q->rear);
}
int is_full(QueueType* q) {			// 포화 상태 검출 함수
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {	// 삽입 함수
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear =(q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[(q->rear)] = item;
}
element dequeue(QueueType* q) {		// 삭제 함수

	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front)];
}

float evaluate(TreeNode* root){
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return (root->data);
	else {
		float op1 = (float)evaluate(root->left);
		float op2 = (float)evaluate(root->right);
		//printf("op2:%f\n", root->right);
		printf("%f %c %f을 계산합니다. ",op1, (char)root->data,op2);
		switch ((char)root->data) {
		case '+':printf("=%f \n", op1 + op2); return (float)(op1 + op2);
		case '-':printf("=%f \n", op1 - op2); return (float)(op1 - op2);
		case '*': printf("=%f \n", op1 * op2); return (float)(op1 * op2);
		case '/': printf("=%f \n", op1 / op2);  return (float)(op1 / op2);
		}

	}
	//return 0;
}

TreeNode a1 = { 1,  NULL, NULL };
TreeNode a2 = { 4,  NULL,  NULL };
TreeNode a3 = { '*', &a1,&a2 };
TreeNode a4 = { 16, NULL, NULL };
TreeNode a5 = { 25 , NULL,  NULL };
TreeNode a6 = { '+', &a4,  &a5 };
TreeNode a7 = { '+', &a3,  &a6 };
TreeNode* exp = &a7;

TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;



TreeNode e1 = { 2,  NULL, NULL };
TreeNode e2 = { 3,  NULL,  NULL };
TreeNode e3 = { '+', &e1,&e2 };
TreeNode e4 = { 4, NULL, NULL };
TreeNode e5 = { 5 , NULL,  NULL };
TreeNode e6 = { '*', &e4,  &e5 };
TreeNode e7 = { '+', &e3,  &e6 };

TreeNode e8 = { 6, NULL, NULL };
TreeNode e9 = { 7 , NULL,  NULL };
TreeNode e10 = { '/', &e8,  &e9 };
TreeNode e11 = { '-', &e7,  &e10 };

TreeNode e12 = { 9 , NULL,  NULL };
TreeNode e13= { '+', &e11,  &e12 };

TreeNode* exp1 = &e13;




int main(void) {
	//printf("레벨 순회=");
	//level_order(root);
	//printf("\n"); 
	printf("수식의 값은 %f.\n",(float)evaluate(exp1));
	printf("총노드의 갯수는 %d개 입니다. \n",13);
	//printf("\n"); 
	//printf("수식의 값은 %d.\n", evaluate(exp));

	return 0;
}
