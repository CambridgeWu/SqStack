#include "SqStack.h"
#include<stdlib.h>
#include<stdio.h>

//基于数组的顺序栈
Status initStack(SqStack *s,int sizes){
	s->size=sizes;
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	s->top=-1;
	return SUCCESS; 
}

Status isEmptyStack(SqStack *s){
	if(s->top==-1){
		return SUCCESS;
	}
	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e){
	if(isEmptyStack(s)){
		printf("栈为空！");
		return ERROR;
	}
	*e=s->elem[s->top];
	printf("栈顶元素值为：%d",*e);
	return SUCCESS;
}

Status clearStack(SqStack *s){
	s->top==-1;
	s->size=s->size+s->top+1;
	return SUCCESS;
}

Status destroyStack(SqStack *s){
	free(s->elem);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length){
	if(s->size==-1){
		printf("栈为空！");
		return ERROR;
	}
	*length=s->size;
	printf("该栈的长度为：%d",*length);
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data){
	if(s->top>=s->size){
		printf("栈已满！");
		return ERROR;
	}
	s->elem[++s->top]=data;
	s->size--;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data){
	if(s->top==-1){
		printf("栈为空！");
		return ERROR;
	}
	*data=s->elem[s->top--];
	printf("该数据为：%d",*data);
	s->size++;
	return SUCCESS;
}






