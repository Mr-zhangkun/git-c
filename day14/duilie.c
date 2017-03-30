#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define OK 1
#define ERROR 0


//单链队列，队列的链式存储结构
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;            //队头指针
    QueuePtr rear;            //队尾指针
}LinkQueue;

//构造一个空队列
int InitQueue(LinkQueue *q)
{
    //
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(q->front == NULL)
    {
        fprintf(stderr, "malloc() error.\n");
        return ERROR;
    }

    q->front->next = NULL;
    q->rear->next = NULL;

    return OK;
}

//销毁队列，Q不在存在
int DestroyQueue(LinkQueue *q)
{
    //
    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
    return OK;
}

//判断队列是否为空
int IsEmptyQueue(LinkQueue *q)
{
    return (q->front->next == NULL && q->rear->next == NULL);
}

//插入元素e为新的队尾元素
int InsertQueue(LinkQueue *q, ElemType e)
{
    //
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(p == NULL)
    {
        fprintf(stderr, "malloc() error.\n");
        return ERROR;
    }

    p->data = e;
    p->next = NULL;

    //如果队列为空
    if(IsEmptyQueue(q))
    {
        q->front->next = p;
        q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;            //不要忘记这句啊
    }
    return OK;
}

//若队列不空，则删除队头元素，用e返回其值，并返回OK
int DeQueue(LinkQueue *q, ElemType *e)
{
    //
    if(IsEmptyQueue(q))
    {
        fprintf(stdout, "the queue is null.\n");
        return ERROR;
    }

    //注意有队头结点
    QueuePtr temp;
    temp = q->front->next;
    *e = temp->data;

    q->front->next = temp->next;

    //一个元素
    if(q->rear == temp)
    {
        q->rear = q->front;
    }

    free(temp);

    return OK;
}

//打印队列
void printQueue(LinkQueue *q)
{
    QueuePtr temp;
    temp = q->front->next;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

int main(int argc, char **argv)
{
    LinkQueue *q;
    InitQueue(q);

  //  srand(time(NULL));

    int i = 0;
    for(i = 0; i < 10; i++)
    {
        InsertQueue(q, i);
    }

    printf("插入队列的元素为:\n");
    printQueue(q);

    int e;
    DeQueue(q, &e);
    printf("队头元素为: %d\n", e);

    return 0;
}
