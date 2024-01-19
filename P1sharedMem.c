#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h> 
#include<time.h> 

#define BUFFER_SIZE 100

/*void getRandStr(char randstrs[][10]) {        
    srand (time(NULL));                            
    /*for (int j = 0; j < 50; j++) {
        randstrs[j][0] = j;
    }
    
    for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 10; j++) {
			randstrs[i][j] = rand() % 26 + 65;
		}
	}
}*/

void getRandStr(char randstrs[][12]) {        
    srand (time(NULL));                            
    for (int j = 0; j <= 50; j++) {
        randstrs[j][0] = j;
    }
    
    for(int i = 0; i <= 50; i++) {
		for(int j = 1; j <= 10; j++) {
			randstrs[i][j] = rand() % 26 + 65;
		}
	}
}

int main()  
{  
    int ret;
    char buffer[BUFFER_SIZE];
    
    char randStr[51][12] = {{0}};

    /*getRandStr(randStr);

    for(int i = 0; i < 50; i++) {
		for(int j = 0; j < 10; j++) {
			/*if(j == 0) {
				printf("%d ", randStr[i][j]);
			}
			//else printf("%c", randStr[i][j]);
			printf("%c", randStr[i][j]);
		}
		printf("\n");
	}*/

	getRandStr(randStr);
    
	for(int i = 1; i <= 50; i++) {
		for(int j = 0; j < 12; j++) {
			if(j == 0) {
				printf("%d ", randStr[i][j]);
			}
			else printf("%c", randStr[i][j]);
		}
		printf("\n");
	}

	printf("\n%s\n", "The above strings are random strings created");

    void *shared_memory;    
    int shmid;  
    

    int maxIdx = 1; //curIdx = 0;
	int offset=0;
	int var=-1;
    while(1) {
        /*while(curIdx < maxIdx + 5) {
            
			
			

        }*/

		shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
		shared_memory=shmat(shmid,NULL,0); 
		
		for(int i=1+offset;i<6+offset;i++)
		{
			buffer[i]=randStr[maxIdx][i];
			//printf("%c",randStr[maxIdx][i]);
			
		}
		var++;
		//printf("\n");

		/*for(int i=offset;i<5+offset;i++)
		{
			printf("%c",buffer[i]);
			
		}
		printf("\n");*/

        strcpy(shared_memory,buffer);
		//printf("%s\n",buffer);
		sleep(1);

		//wait & receive

		shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);   
		shared_memory=shmat(shmid,NULL,0); 

		strcpy(buffer,(char *)shared_memory);
		printf("rceived back %s\n",buffer);

		//int a;
		//while((a=atoi(buffer))!=maxIdx*5);
		/*if((a=atoi(buffer))==maxIdx*5)
		{


		}*/
		
		if(maxIdx >= 50) 
		{
			break;
		}

		if(offset==5)
		{
			offset=0;
		}
		else
		{
			offset=5;
		}

		if(var%2!=0)
		{
			
			/*if(offset==5)
			{
				maxIdx++;
				offset=0;
			}
			else
			{
				offset=5;

			}
			printf("now maxids 1 %d\n",maxIdx);*/
			maxIdx++;
			
			
		}
		else
		{
			
			//maxIdx++;
			/*if(offset==0)
			{
				maxIdx++;
				offset=5;
			}
			else
			{
				offset=0;

			}*/
			//offset=0;
			//printf("now maxids 2 %d\n",maxIdx);
		}

		
    }


    return 0;
}  