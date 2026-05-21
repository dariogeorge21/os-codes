#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid<0){
        printf("Fork Failed!\n");
        return 1;
    }
    else if ( pid==0){
        printf("Child process:\n");
        printf("Child PID: %d\n",getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else{
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        sleep(5); // Sleep to ensure child process finishes before parent process exits
    }
    return 0;
}