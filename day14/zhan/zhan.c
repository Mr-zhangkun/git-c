#include "zhan.h"
#include <stdio.h>

#define TRUE 1
#define NULL 0

void INITSTACK(seqstack *S)
{
    S->top =-1;
}                     //初始化

int EMPTY(seqstack *S)
{
    if(S->top< 0)
        return TRUE;
    else
        return NULL;
}　　　　　　　　　　　　　

seqstack *PUSH(seqstack *S, datatype x)
{
    if(S->top >= MAXSIZE-1)
    {
        printf("栈满溢出错误!\n");
        return NULL;
    }
    else
    {
        S->top++;
        S->stack[S->top]=x;
    }
    return S;
}

datatype POP(seqstack *S)
{
    datatype x;
    if(EMPTY(S))
    {
        printf("下溢错误!\n");
        return NULL;
    }
    else
    {
        x=S->stack[S->top];
        S->top--;
        return x;
    }
}

int gettop_seqstack(seqstack *S)
{
    if(EMPTY(S))
    {
        printf("栈是空栈!\n");
        return NULL;
    }
    else
    {
        return (S->stack[S->top]);
    }
}
