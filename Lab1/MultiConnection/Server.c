/* Multi-connection server in the Internet domain using TCP
   The port number is passed as an argument */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <sys/wait.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

/* Function to handle each client */
void dostuff(int sockfd)
{
    char buffer[256];
    int n;

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
        error("ERROR reading from socket");

    printf("Here is the message: %s\n", buffer);

    n = write(sockfd, "I got your message", 18);
    if (n < 0)
        error("ERROR writing to socket");
}

/* Prevent zombie processes */
void sigchld_handler(int signo)
{
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    pid_t pid;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    /* Handle terminated child processes */
    signal(SIGCHLD, sigchld_handler);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Server listening on port %d\n", portno);

    /* Accept clients forever */
    while (1)
    {
        newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        pid = fork();
        if (pid < 0)
            error("ERROR on fork");

        if (pid == 0)
        {
            /* Child process */
            close(sockfd);
            dostuff(newsockfd);
            close(newsockfd);
            exit(0);
        }
        else
        {
            /* Parent process */
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}
