//To compile code: gcc -o server -pthread server.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#define PORT "8080" //"19688" //if config for IP address
#define BACKLOG 10

void sigchld_handler (int s){
  
  int saved_errno = errno;
  while(waitpid(-1,NULL,WNOHANG) > 0);

  errno = saved_errno;
} // sigchld_handler


//get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa){
  if (sa->sa_family == AF_INET){
    return &(((struct sockaddr_in*)sa)->sin_addr);
  }

  return &(((struct sockaddr_in6*)sa)->sin6_addr);

} // get_in_addr


void* sending(void* arg); //For send thread
void* receiving(void* arg); //For receive thread

int create_rc1,create_rc2;
int join_rc1,join_rc2;
pthread_t thread1,thread2;

int main (void){

  int sockfd, new_fd; // listen on sock_fd, new connection on new_fd
  struct addrinfo hints, *servinfo, *p;
  struct sockaddr_storage their_addr; // connector's address information
  socklen_t sin_size;
  struct sigaction sa;
  int yes=1;
  char s[INET6_ADDRSTRLEN];
  int rv;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE; // use my IP

  if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
    return 1;
  }

  // loop through all the results and bind to the first we can
  
  for(p = servinfo; p != NULL; p = p->ai_next) {
     if ((sockfd = socket(p->ai_family, p->ai_socktype,p->ai_protocol)) == -1) {
       perror("server: socket");
       continue;
     }

     if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,sizeof(int)) == -1) {
       perror("setsockopt");
       exit(1);
     }

     if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
       close(sockfd);
       perror("server: bind");
       continue;
     }

     break;

   } // for

 freeaddrinfo(servinfo); // all done with this structure

 if (p == NULL) {
   fprintf(stderr, "server: failed to bind\n");
   exit(1);
 }

 if (listen(sockfd, BACKLOG) == -1) {
   perror("listen");
   exit(1);
 }

 sa.sa_handler = sigchld_handler; // reap all dead processes
 sigemptyset(&sa.sa_mask);
 sa.sa_flags = SA_RESTART;
 if (sigaction(SIGCHLD, &sa, NULL) == -1) {
   perror("sigaction");
   exit(1);
 }

 printf("server: waiting for connections...\n");

 while(1) { // main accept() loop
   sin_size = sizeof their_addr;
   new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
   if (new_fd == -1) {
     perror("accept");
     continue;
   }

 inet_ntop(their_addr.ss_family,
 get_in_addr((struct sockaddr *)&their_addr),s, sizeof s);
 
 printf("server: got connection from %s\n", s);

 
 if(create_rc1 = pthread_create(&thread1,NULL,sending,(void *) &new_fd)){ //Create send thread
  printf("pthread_create (send) return code: %i",create_rc1);
 }
 
 if(create_rc2 = pthread_create(&thread2,NULL,receiving,(void *) &new_fd)){ //Create join thread
  printf("pthread_create (receive) return code: %i",create_rc2);
 }


 if(join_rc1 = pthread_join(thread1,NULL)){ //Join send thread
  printf("pthread_join (send) return code: %i",join_rc1);
 }

 if(join_rc2 = pthread_join(thread2,NULL)){ //Join receive thread
  printf("pthread_join (receive) return code: %i",join_rc2);
 }
 
 } // while

 return 0;

} // main



void* sending(void* arg){
 printf("Sending Thread Created\n"); 
 
 int* new_fd = (int*) arg;
 char msg[100];
 
 while(1){
  
  scanf("%s",msg);
  
  if (send(*new_fd, msg, sizeof(msg), 0) == -1)
     perror("send");
  }
  
} // sending



void* receiving(void* arg){
 printf("Receiving Thread Created\n");
 
 int* new_fd = (int*) arg;
 int numbytes;
 char buf[100];
 
 while(1){
  if(numbytes = read(*new_fd,buf,100) != -1){
  printf("Client: %s\n",buf);
  }
  
 } // while

} // receiving
