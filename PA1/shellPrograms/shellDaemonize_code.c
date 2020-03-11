/*
 * daemonize.c
 * This example daemonizes a process, writes a few log messages,
 * sleeps 60 seconds and terminates afterwards.
 */

// To test compile: gcc Daemonize.c -o summond
// ./summond
// see output at Console : search the log message or process name i.e: summond
// can check using ps aux | grep summond
// for better formatted:  ps -ejf | egrep 'STIME|summond'

#include "shellPrograms.h"

//TODO: change to appropriate path
char *path = "/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/logfiles.txt";

/*This function summons a daemon process out of the current process*/
static int create_daemon() {
    /* TASK 7 */
    // Incantation on creating a daemon with fork() twice
    // 1. Fork() from the parent process
    // printf("//FORKING//\n");
    int forkValue=fork();
    if (forkValue < 0) { //if fork fails
        perror("Failed to fork.\n");
        return 0;
    }

    // 2. Close parent with exit(1)
    else if (forkValue > 0) { // parent (original fork)
        // printf("//PARENT EXITING//\n");
        exit(1);
    }
    
    else { //child (intermediate)
        // 3. On child process (this is intermediate process), call setsid() so that the child becomes session leader to lose the controlling TTY
        setsid();
        
        // 4. Ignore SIGCHLD, SIGHUP
        signal(SIGCHLD, SIG_IGN);
        signal(SIGHUP, SIG_IGN);

        // 5. Fork() again, parent (the intermediate) process terminates
        // printf("//FORKING AGAIN//\n");
        int forkValue2=fork();
        if (forkValue2 < 0) { //if fork fails
            perror("Failed to fork.\n");
            return 0;
        } else if (forkValue2>0){ //parent (intermediate)
            // printf("//INTERMEDIATE EXITING//\n");
            exit(1);
        }
        else { //child (daemon)
        // 6. Child process (the daemon) set new file permissions using umask(0). Daemon's PPID at this point is 1 (the init)
        // printf("//UMASK//\n");
        umask(0);
        
        // 7. Change working directory to root
        // printf("//CHDIR//\n");
        chdir("/");

        // 8. Close all open file descriptors using sysconf(_SC_OPEN_MAX) and redirect fd 0,1,2 to /dev/null
        // printf("THIS SHOULD PRINT\n");
        for (int x = sysconf(_SC_OPEN_MAX); x>=0; x--) close (x);
        
        /* Attach file descriptors 0, 1, and 2 to /dev/null. */
        // printf("THIS SHOULDN'T PRINT\n");
        FILE *fd0=open("/dev/null", O_RDWR);
        FILE *fd1=dup(0);
        FILE *fd2=dup(0);
        // printf("THIS ALSO SHOULDN'T PRINT\n");
        // 9. Return to main
        return 1;
        }
    }
}

static int daemon_work() {
    int num = 0;
    FILE *fptr;

    //write PID of daemon in the beginning
    fptr = fopen(path, "a");
    if (fptr == NULL)
    {
        return EXIT_FAILURE;
    }

    fprintf(fptr, "%d with FD %d\n", getpid(), fileno(fptr));
    fclose(fptr);

    while (1)
    {
        //use appropriate location if you are using MacOS or Linux
        //TODO: Change to appropriate path
        fptr = fopen(path, "a");

        if (fptr == NULL)
        {
            return EXIT_FAILURE;
        }

        fprintf(fptr, "PID %d Daemon writing line %d to the file.  \n", getpid(), num);
        num++;

        fclose(fptr);

        sleep(10);

        if (num == 10)
            break;
    }

    return EXIT_SUCCESS;
}
int main(int argc, char **args)
{
    create_daemon();

    /* Open the log file */
    openlog("customdaemon", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "Daemon started.");
    closelog();

    return daemon_work();
}