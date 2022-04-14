//To compile gcc -o client client.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT "8080" //"3490" // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once

 // get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa){
 if (sa->sa_family == AF_INET) {
   return &(((struct sockaddr_in*)sa)->sin_addr);
 }
 return &(((struct sockaddr_in6*)sa)->sin6_addr);
} // get_in_addr


int main(void) {
 
 int sockfd, numbytes;
 char buf[MAXDATASIZE];
 struct addrinfo hints, *servinfo, *p;
 int rv;
 char s[INET6_ADDRSTRLEN];


 memset(&hints, 0, sizeof hints);
 hints.ai_family = AF_UNSPEC;
 hints.ai_socktype = SOCK_STREAM;

char* IP = "137.45.192.100"; // IP of LOCAL_HOST

 if ((getaddrinfo(IP, PORT, &hints, &servinfo)) != 0) {
 fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
 return 1;
 }

 // loop through all the results and connect to the first we can
 for(p = servinfo; p != NULL; p = p->ai_next) {
 if ((sockfd = socket(p->ai_family, p->ai_socktype,
 p->ai_protocol)) == -1) {
 perror("client: socket");
 continue;
 }

 if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
 close(sockfd);
 perror("client: connect");
 continue;
 }

 break;
 }

 if (p == NULL) {
 fprintf(stderr, "client: failed to connect\n");
 return 2;
 }

 inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
 printf("client: connecting to %s\n", s);

 freeaddrinfo(servinfo); // all done with this structure

 
char msg [100]; //String to send

 while(1){
  
  printf("Enter message\n");
  scanf("%s",msg);
  
  send(sockfd, msg, sizeof(msg),0);
  
  printf("Waiting for response...\n");
  numbytes = read(sockfd, buf, 100); 
  
  printf("Server: %s\n",buf);
   
} // while

 return 0;
 } // main



