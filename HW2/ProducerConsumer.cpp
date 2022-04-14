/*
 * Purpose: Solve the Producer Consumer Problem
 * Programmer: Keith Burgess
 *
 */
#include <stdlib.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;


//forward declarations
void* Producer1(void* arg);
void* Producer2(void*arg);
void* Consumer1(void*arg);

void enqueue(int pid,int num);
void dequeue();

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;


int maxBuffer = 10;
int buffer[10];
int head=0;
int tail=0;

int main(){
 
 int create_rc1,create_rc2,create_rc3;  // pthread_create return code
 int join_rc1,join_rc2,join_rc3;        // pthread_join return code
 pthread_t thread1,thread2,thread3;     // thread ID

 
 if(create_rc1 = pthread_create(&thread1,NULL,Producer1,NULL)){
  cout << "pthread_create (thread1) return code: " << create_rc1 << endl;
 }
 
// if(join_rc1 = pthread_join(thread1,NULL)){
//  cout << "pthread_join (thread1) return code: " << join_rc1 << endl;
// }

 
 if(create_rc2 = pthread_create(&thread2,NULL,Producer2,NULL)){
  cout << "pthread_create (thread2) return code: " << create_rc2 << endl;
 }

// if(join_rc2 = pthread_join(thread2,NULL)){
//  cout << "pthread_join (thread2) return code: " << join_rc2 << endl;
// }


 if(create_rc3 = pthread_create(&thread3,NULL,Consumer1,NULL)){
  cout << "pthread_create (thread3) return code: " << create_rc3 << endl;
 }

// if(join_rc3 = pthread_join(thread3,NULL)){
//  cout << "pthread_join (thread3) return code: " << join_rc3 << endl;
// }

if(join_rc1 = pthread_join(thread1,NULL)){
  cout << "pthread_join (thread1) return code: " << join_rc1 << endl;
}

if(join_rc2 = pthread_join(thread2,NULL)){
  cout << "pthread_join (thread2) return code: " << join_rc2 << endl;
}

if(join_rc3 = pthread_join(thread3,NULL)){
  cout << "pthread_join (thread3) return code: " << join_rc3 << endl;
}

return 0;

}// main



void* Producer1(void* arg){

 int num = 1;
 int pid=1;

 while(1){
  
  enqueue(pid,num);
  num++;
  sleep(2); // decrease to produce more (BUFFER WILL FILL UP)
            // increase to consume more (BUFFER WILL BE EMPTY)
  }

} // Producer1


void* Producer2(void* arg){
 
 int num = 101;
 int pid=2;

 while(1){

  enqueue(pid,num);
  num++;
  sleep(2); // decrease to produce more (BUFFER WILL FILL UP)
            // increase to consume more (BUFFER WILL BE EMPTY)
 }

} // Producer2


void* Consumer1(void* arg){
 
 while(1){

  dequeue();
  sleep(1); // 1: Buffer never full or empty
 
 }

} // Consumer1



void enqueue(int pid,int i){
 
 pthread_mutex_lock(&mutex);
 
 while((head==maxBuffer && tail==0)||(tail+1==head)){ // guard while(buffer is full)
  cout << "Buffer Full" << endl;
  pthread_cond_wait(&cond1,&mutex); // wait - BUFFER FULL
 } // while
 
 
 buffer[tail]=i;
 cout << "Producer" << pid << " wrote: " << i << endl;
 
 tail++;
 
 if(tail == maxBuffer){ // resets tail to beginning of array
  tail = 0;
 }
 
 pthread_cond_signal(&cond2);// signal - BUFFER NOT EMPTY
 
 pthread_mutex_unlock(&mutex);

} // enqueue



void dequeue(){
 
 pthread_mutex_lock(&mutex);
  
 while(head==tail){ // guard while(buffer is empty)
  cout << "Buffer Empty" << endl;
  pthread_cond_wait(&cond2,&mutex); // wait - BUFFER EMPTY  pthread_cond_wait(c1,m)
 } // while

  cout << "Consumer read: " << buffer[head] << endl;  
  
  head++;
  
  if(head == maxBuffer){ // resets head to beginning of array
   head = 0;
  }

  pthread_cond_signal(&cond1);// signal - BUFFER NOT FULL 
  
  pthread_mutex_unlock(&mutex);
 
} // dequeue
