#define _OPEN_SYS_ITOA_EXT
#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>  
#include<sys/shm.h>  
#include<string.h>  
int main()  
{  

    int maxIdx = 0;


    int i;  
    void *shared_memory;  
    char buff[100];  
    int shmid;  
    //shmid=shmget((key_t)2345, 1024, 0666);  


	int curIdx =maxIdx;
    int offset=5;
    int var=-1;
	while(1) {
        sleep(1);
        var++;
        //printf("ok\n");
		//while(curIdx < maxIdx + 5) {
			//sleep(2);
			//fd1 = open(myfifo1, O_RDONLY);
            //printf("ok1");
            shmid=shmget((key_t)2345, 1024, 0666);  
            //printf("ok2");
			//ret = read(fd1, buff, sizeof(buff));
            shared_memory=shmat(shmid,NULL,0);
            //printf("ok3");
			//close(fd1);
			/*if(ret == -1) {	
				perror("couldn't read");
				exit(EXIT_FAILURE);
			}*/
			//curIdx = buff[0];
            //if(maxIdx%2==0)
            if(var%2==0)
            {
                //printf("var is %d\n",var);
                printf("STRING SENT BY CLIENT: ");	
                //maxIdx++;

            }
				
			printf("%s\n",(char *)shared_memory); 
			/*for(int i = 1; i < 12; i++) {
				printf("%c", buffer[i]);
			}
			printf("\n");*/
			
			//sprintf(buff, "%d", curIdx);
            strncpy(buff,(char *)shared_memory,sizeof(buff));
            /*if(maxIdx%2==0)
            {
                offset=5;
                printf("ID SENT BY CLIENT = %d\n", buff[0]);	
                maxIdx++;
            }
            else
            {
                offset=0;
            }*/
			
		//}
		//buffer contains the string with the 0th idx as the index of the string
		
		//maxIdx = curIdx;
		//fd2 = open(myfifo2, O_WRONLY);
		//ret = write(fd2, buffer, sizeof(buffer));
        shmid=shmget((key_t)2345, 1024, 0666);   
		shared_memory=shmat(shmid,NULL,0); 

        //strcpy(shared_memory,strlen(buff));
        int a=strlen(buff)+offset;
        //while((a)!=(maxIdx+1)*5);
        char str[100];
        //itoa(a, str, 10);
        sprintf(str,"%d",a);
        strcpy(shared_memory,str);
        
        /*if(maxIdx%2==0)
        {
            offset+=5;
            printf("ID SENT BY CLIENT = %d\n", buff[0]);	
            maxIdx++;
        }*/
        if(var%2!=0)
        {
            
            
            maxIdx++;
        }
        printf("ID SENT BY CLIENT = %d\n", buff[0]);	
        offset+=5;
        /*else
        {
            offset=0;
        }*/
         
        
         
		//close(fd2);
		// break;
        //offset=0;
		if(maxIdx >= 50) exit(EXIT_SUCCESS);
	}


    // int i;  
    // void *shared_memory;  
    // char buff[100];  
    // int shmid;  
    // shmid=shmget((key_t)2345, 1024, 0666);  
    // printf("Key of shared memory is %d\n",shmid);  
    // shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment  
    // printf("Process attached at %p\n",shared_memory);  
    // printf("Data read from shared memory is : %s\n",(char *)shared_memory);  
}  


// #include<stdio.h>
// #include<string.h>
// #include<fcntl.h>
// #include<sys/stat.h>
// #include<sys/types.h>
// #include<unistd.h>
// #include<time.h>
// #include<stdlib.h>
// #include<sys/un.h>
// #define BUFFER_SIZE 100


// int main() {
//     int fd1, fd2;

//     int ret;
//     char buffer[BUFFER_SIZE];
// 	int maxIdx = 0;
//     // FIFO file path
//     char * myfifo1 = "FIFO1";
//     char * myfifo2 = "FIFO2";

    
//     // Creating the named file(FIFO)
//     // mkfifo(<pathname>, <permission>)
    
//     mkfifo(myfifo1, 0666);
//     mkfifo(myfifo2, 0666);


// 	maxIdx = 0;
// 	int curIdx = maxIdx;
// 	while(1) {
// 		while(curIdx < maxIdx + 5) {
// 			sleep(2);
// 			fd1 = open(myfifo1, O_RDONLY);
// 			ret = read(fd1, buffer, sizeof(buffer));
// 			close(fd1);
// 			if(ret == -1) {	
// 				perror("couldn't read");
// 				exit(EXIT_FAILURE);
// 			}
// 			curIdx = buffer[0];
// 			printf("STRING SENT BY CLIENT: ");		
			
// 			for(int i = 1; i < 12; i++) {
// 				printf("%c", buffer[i]);
// 			}
// 			printf("\n");
			
// 			sprintf(buffer, "%d", curIdx);
// 			printf("ID SENT BY CLIENT = %s\n", buffer);	
// 		}
// 		//buffer contains the string with the 0th idx as the index of the string
		
// 		maxIdx = curIdx;
// 		fd2 = open(myfifo2, O_WRONLY);
// 		ret = write(fd2, buffer, sizeof(buffer));
// 		close(fd2);
// 		// break;
// 		if(maxIdx >= 50) exit(EXIT_SUCCESS);
// 	}
//     return 0;
// }