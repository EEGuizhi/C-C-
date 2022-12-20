#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct data{
	int num;
	struct data *nextPtr;
} ;
typedef struct data data;
typedef data *dataPtr;

void insert(dataPtr *sPtr,int value){
	dataPtr previousPtr;
	dataPtr currentPtr;
	dataPtr newPtr;
	newPtr = malloc(sizeof(data));
	if(newPtr != NULL){
		newPtr -> num = value;
		newPtr -> nextPtr = NULL;
		
		previousPtr = NULL;
		currentPtr = *sPtr;
		
		while(currentPtr != NULL && value > currentPtr -> num ){
			previousPtr = currentPtr;
			currentPtr = currentPtr -> nextPtr;
		}
		
		if(previousPtr == NULL){
			newPtr -> nextPtr = *sPtr;
			*sPtr = newPtr;
		}else{
			previousPtr -> nextPtr = newPtr;
			newPtr->nextPtr =currentPtr;
		}
	}
	else{
		printf("�L�k���J %d �A�S���B�~�Ŷ��C \n",value);
	}
}

void DeleteValue(dataPtr *sPtr,int value){
	dataPtr previousPtr = NULL;
	dataPtr currentPtr = *sPtr;
	
	while(currentPtr != NULL && currentPtr -> num != value ){
		previousPtr = currentPtr;
		currentPtr = currentPtr -> nextPtr;
	}
	if(currentPtr != NULL){
		if(previousPtr != NULL){
			previousPtr -> nextPtr = currentPtr -> nextPtr;	
		}else{
			*sPtr = currentPtr ->nextPtr;
		}
		free(currentPtr);
	}else{
		printf("Link List �S�� %d �A�����R���C \n",value);
	}
}

void edit(dataPtr *sPtr, int value, int value2){  //value�Q�諸  value2��Ӫ� 
	dataPtr currentPtr = *sPtr;
	while(currentPtr != NULL && currentPtr -> num != value){
		currentPtr = currentPtr->nextPtr;
	}
	if(currentPtr != NULL){
		DeleteValue(sPtr , value);
		insert(sPtr , value2);
	}else{
		printf("Link List �S�� %d �A���ݭn�ק�C\n",value);
	}
}

void printList(dataPtr currentPtr){
	printf("Link List���e�p�U : \n");
	if(currentPtr == NULL){
		printf("�S����ơC");
	}
	
	while(currentPtr != NULL){
		printf("%d ",currentPtr -> num);
		currentPtr = currentPtr ->nextPtr;
	}
	printf("\n\n");
}

int main(void){
	dataPtr startPtr = NULL;
	int select,num,num2;
	while(1){
		printf("��J�Ҧ� : (1)�s�W (2)�R�� (3)�ק� (4)��� (5)���} \n");
		scanf("%d",&select);
		switch(select){
			case 1 :	//�s�W 
				while(1){
					printf("��J���s�W�Ʀr(�h�X��J$) : ");
					
					if(scanf("%d",&num) == 0){
					fflush(stdin);
					printf("�����s�W\n");
					break;
					}
					insert(&startPtr, num);					
					printList(startPtr);
				}
				break;
				
			case 2 :	//�R��
				printList(startPtr);
				while(startPtr != NULL){
					printf("��J���R���Ʀr(�h�X��J$) : ");
					
					if(scanf("%d",&num) == 0){
					fflush(stdin);
					printf("�����R��\n");
					break;
					}
					DeleteValue(&startPtr ,num);
					printList(startPtr);
				}
				break;
				
			case 3 :	//�ק� 
				printList(startPtr);
				while(startPtr != NULL){
					printf("��J���諸�Ʀr(�h�X��J$) : ");
					if(scanf("%d",&num) == 0){
						fflush(stdin);
						printf("�����R��\n");
						break;
					}
					printf("��J�ק�᪺�Ʀr : ");
					if(scanf("%d",&num2) == 0){
						fflush(stdin);
						printf("�����R��\n");
						break;
					} 
					edit(&startPtr,num,num2);
					printList(startPtr);
				}
				break;
				
			case 4 :	//��� 
				printList(startPtr);
				break;
			
			case 5 :	//���} 
				return 0;
				break;
		}
	}
}
