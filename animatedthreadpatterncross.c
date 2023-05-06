
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *runner();
void main()
{
    pthread_t tid;//thread id
    int ret;//to store a return value
    ret=pthread_create(&tid,NULL,runner,0);//creating a thread
    
    if(ret==-1)
    {
        printf("\n Thread has not been created");
        exit(1);
    }
    pthread_join(tid,0);
 
}

void *runner()
{
    int i,j,m,n;// i and j are loop counters 
    // m and n are used as counters for spacing
    m=0;
    n=7;
    for(i=1;i<=5;i++)
    {//to generate upper half of the pattern
       for(j=1;j<=m;j++)
       {
           printf("   ");
       }
       printf("* ");
    
       if(i==5)
        continue;
       for(j=1;j<=n;j++)
       printf("   ");
       m+=1;
       n-=2;
       printf("* ");
       sleep(2);
       printf("\n");
       
    }
    n=1;
    m=3;
    printf("\n");
    for(i=1;i<=4;i++)
    { //to generate lower half of the pattern
        for(j=1;j<=m;j++)
        printf("   ");
        printf("* ");
        for(j=1;j<=n;j++)
        printf("   ");
        printf("* ");
        sleep(2);
        m-=1;
        n+=2;
        printf("\n");
        
    }
    pthread_exit(0);
}
