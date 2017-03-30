#ifndef STACK_H
#define STACK_H


#define MAXSIZE 100

typedef int datatype;

struct _seqstack{
    datatype stack[MAXSIZE];
    int top;
};

typedef struct _seqstack seqstack;


void INITSTACK(seqstack *S);

int EMPTY(seqstack *S);

seqstack *PUSH(seqstack *S, int x);

int POP(seqstack *S);

int gettop_seqstack(seqstack *S);

#endif
