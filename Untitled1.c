#include<stdio.h>
#include<string.h>
#include<bool.h>
static int counter;

typedef struct passenger {
	int id;
	char name[30];
	struct passenger* next;
int confirmation_id=0;
}passenger;

typedef struct Alloc_Queue
{
	passenger *front, *rear;
}AQ;

typedef struct Wait_Queue
{
	passenger *front, *rear;
}WQ;

passenger* new_passenger(int k,char Name[30], int cid)
{
	passenger* newnode = (passenger*)malloc(sizeof(passenger));
	newnode->id = k;
	strcpy(newnode->name,Name);
	newnode->confirmation_id=cid;
	newnode->next = NULL;
	return newnode;
}

/*AQ* createQueue()
{
    AQ* q = (AQ*)malloc(sizeof(AQ));
	q->front = q->rear = NULL;
	return q;
}


WQ* createQueue()
{
	WQ* q = (WQ*)malloc(sizeof(WQ));
	q->front = q->rear = NULL;
	return q;
}*/


void enQueue(passenger* p, int k, char name[30])
{
	passenger* temp = new_passenger(k,name);
 //yahan ye choose karna hai ki queue konsi hogi filhaal node me aise krna galat hai
	if (p->rear == NULL) {
		p->front = p->rear = temp;
		return;
	}

	p->rear->next = temp;
	p->rear = temp;
}

void deQueue(struct Alloc_Queue* q)
{ //ye function wq pr hi use hoga
    //aq pr ticket csncel k case me
	if (q->front == NULL)
		return;

	struct Node* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

int main()
{
	struct Alloc_Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	deQueue(q);
	deQueue(q);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	deQueue(q);
	printf("Queue Front : %d \n", q->front->id);
	printf("Queue Rear : %d", q->rear->id);
	return 0;
}
