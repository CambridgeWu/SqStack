#include<stdio.h>
#include "SqStack.h"
#include<stdlib.h>

SqStack s;


int keyDown(int *type){
	printf("               SqStack                \n");
	printf("               1.初始化栈             \n");
	printf("               2.判断栈是否为空       \n");
	printf("               3.得到栈顶元素         \n");
	printf("               4.清空栈               \n");
	printf("               5.销毁栈               \n");
	printf("               6.检测栈长度           \n");
	printf("               7.入栈                 \n");
	printf("               8.出栈                 \n\n\n");
	
	char ch=getch();
	switch(ch){
		case '1':
			{
				float sizes;
				printf("请输入初始化栈的长度(整数):");
				scanf("%f",&sizes);
				if(sizes!=(int)sizes){
					printf("你的输入有误！");
					return;
				}
				if(initStack(&s,sizes)){
					printf("初始化成功！");
				}else{
					printf("初始化失败！");
				}
			}
			break;
		case '2':
			if(isEmptyStack(&s)){
				printf("栈为空"); 
			}else{
				printf("栈不为空！");
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
				printf("清空完成！");
			}else{
				printf("清空失败！");
			}
			break;
		case '5':
			if(destroyStack(&s)){
				printf("销毁成功！");
				*type=0;
			}else{
				printf("销毁失败！");
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
				printf("请输入你要输入的数据(整数):\n");
				scanf("%f",&data);
				if(data!=(int)data){
					printf("你的输入有误！");
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
			printf("你的输入有误！");
			break;
	}
}


int main(){
	int type=1;
	while(type){
		system("cls");
		keyDown(&type);
		printf("\n输入任意键继续...");
		getch();
	}
	return 0;
}
