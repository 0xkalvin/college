#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int shmid;
    int *shmptr;
    pid_t pid;

    if(argc != 2){
        printf(" Required integer argument should be passed \n");
        exit(-1);
    }

    shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);

    if (shmid < 0)
    {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }

    printf("Program has received a shared memory of one integer...\n");

    shmptr = (int *)shmat(shmid, NULL, 0);
    if ((int)shmptr == -1)
    {
        printf("*** shmat error (server) ***\n");
        exit(1);
    }

    printf("Program has attached the shared memory...\n");
   
    shmptr[0] = atoi(argv[1]);
    printf("Program has initialized a value for the shared variable: %d \n", shmptr[0]);

    pid = fork();

    if (pid < 0)
    {
        printf("Fork has failed");
        return -1;
    }

    if (pid > 0)
    {
        printf("Parent process \n");
        printf("Waiting for child process... \n");
        wait(NULL);
        printf("Back to parent process... \n");
        shmptr[0] = shmptr[0] - 1;
        printf("Subtracting shared variable by 1: %d \n", shmptr[0]);
        shmdt((void *) shmptr);
        printf("Program has detached its shared memory...\n");
        shmctl(shmid, IPC_RMID, NULL);
        printf("Program has removed its shared memory...\n");
        printf("Program exiting...\n");
    }

    if (pid == 0)
    {
        printf("Child process \n");
        shmptr[0] = shmptr[0] * 2;
        printf("Multiplying shared variable by 2: %d \n", shmptr[0]);
        exit(0);
    }

    return 0;
}
