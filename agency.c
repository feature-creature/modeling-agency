#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void) {
            
    /* declare child process variables */
    pid_t pid, sid;
                    
    /* initialize child process PID
     * by forking the child process
     * from the parent process */
    pid = fork();

    /* if PID creation fails
     * kill child process */
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
                                    
    /* If PID creation succeeds,
     * exit the parent process. */
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    
    /* Change the file mode mask 
     * for the child process
     * so that that system files
     * and daemon-generated data
     * are accessible to daemon process */
    umask(0);                                                        
    
    /* Optional logging facilities */

    

    /* Create a new SID for the child process */
    sid = setsid();
    
    /* If SID creation fails,
     * kill child process */
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }
    
    /* Change the current working directory 
     * if cd / fails,
     * kill child process */
    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }
    
    /* Close out the standard file descriptors
     * to prevent users from directly interacting
     * with daemon through a terminal.
     * This can be classified in other settings as a security measure.
     * doesn't necessarily protect from causal user interaction.*/
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    
    /* Daemon-specific initialization*/

    /* The 'infinite' Big Loop */
    while (1) {

        /* Code for Daemon task ... */

        sleep(30); 
    }

    /* kill daemon */
    exit(EXIT_SUCCESS);
}
