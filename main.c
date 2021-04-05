#include<stdio.h>
#include "SqStack.h"
#include<stdlib.h>

SqStack s;


int keyDown(int *type){
	printf("               SqStack                \n");
	printf("               1.��ʼ��ջ             \n");
	printf("               2.�ж�ջ�Ƿ�Ϊ��       \n");
	printf("               3.�õ�ջ��Ԫ��         \n");
	printf("               4.���ջ               \n");
	printf("               5.����ջ               \n");
	printf("               6.���ջ����           \n");
	printf("               7.��ջ                 \n");
	printf("               8.��ջ                 \n\n\n");
	
	char ch=getch();
	switch(ch){
		case '1':
			{
				float sizes;
				printf("�������ʼ��ջ�ĳ���(����):");
				scanf("%f",&sizes);
				if(sizes!=(int)sizes){
					printf("�����������");
					return;
				}
				if(initStack(&s,sizes)){
					printf("��ʼ���ɹ���");
				}else{
					printf("��ʼ��ʧ�ܣ�");
				}
			}
			break;
		case '2':
			if(isEmptyStack(&s)){
				printf("ջΪ��"); 
			}else{
				printf("ջ��Ϊ�գ�");
			}
			break;
		case '3':
			{
				int e;
				getTopStack(&s,&e);
			}
			break;
		case '4':
			if(clearStack(&s)){
				printf("�����ɣ�");
			}else{
				printf("���ʧ�ܣ�");
			}
			break;
		case '5':
			if(destroyStack(&s)){
				printf("���ٳɹ���");
				*type=0;
			}else{
				printf("����ʧ�ܣ�");
			}
			break;
		case '6':
			{
				int length;
				stackLength(&s,&length);
			}
			break;
		case '7':
			{
				float data;
				printf("��������Ҫ���������(����):\n");
				scanf("%f",&data);
				if(data!=(int)data){
					printf("�����������");
					return;
				}
				data=(int)data;
				pushStack(&s,data);
			}
			break;
		case '8':
			{
				int data;
				popStack(&s,&data);
			}
			break;
		default:
			printf("�����������");
			break;
	}
}


int main(){
	int type=1;
	while(type){
		system("cls");
		keyDown(&type);
		printf("\n�������������...");
		getch();
	}
	return 0;
}
