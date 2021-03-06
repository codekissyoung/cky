#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char* argv[] )
{
    int sem_id;
    int nsems = 1;
    int flags = 0666;
    struct sembuf buf;

    sem_id = semget( IPC_PRIVATE, nsems, flags );

    if( sem_id < 0 )
    {
        perror( "semget error" );
        exit( 1 );
    }

    printf( "successfully created a semaphore : %d\n", sem_id );

    buf.sem_num = 0;
    buf.sem_op  = 1;
    buf.sem_flg = IPC_NOWAIT;

    if( semop( sem_id, &buf, nsems ) < 0 )
    {
        perror("semop");
        exit(1);
    }
    system("ipcs -s ");
    exit(0);
}
