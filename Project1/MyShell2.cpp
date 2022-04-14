#include <iostream>
#include <sys/wait.h>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <vector>
using namespace std;

string get_line();
int parse_line(string input, vector <string> &args);
void execute(int count, vector <string> &args);


int main(){

 string line;
 int count;
 vector <string> args;
 vector <string> history;
 
   while(1){
      args.clear();
      cout << "$$>";
      line = get_line(); //get user input

      history.push_back(line); //Used for History cmd

      count = parse_line(line,args); //tokenize input
      

      if(args[0] == "history"){ //function to handle History
         cout << "history size=" << history.size() <<endl;
         for(int i = 0; i<history.size(); i++){
            cout << i << " " << history[i] << "\n";
         }//for

      }//if

      else if(args[0] == "help"){ //function to handle help
         const char *ex; 
         ex = line.c_str();
         system(ex);
      }//else if

      else{
      execute(count,args); //execute
      }//else
	
      
   }//while

return 0;

}//main

//------------------------------

string get_line(void){
 string tmp;

 getline(cin,tmp);
 
return tmp;
}//get_line


int parse_line(string input, vector <string> &args){
 int i=0;
 stringstream ssin(input);
 
 while (ssin.good()){
    string temp;
    getline(ssin,temp, ' ');
    args.push_back(temp);
    i++;//counter
    
 } //while

return i;
} //parse_line


void execute(int count, vector <string> &args){
 
 //int status;
 int pid=fork();
 //int childPID;
 string command ="/bin/" +  args[0];
 string cmd = args[0];
 string argument_list[args.size()-1];
 

 for(int i=0; i<args.size()-1; i++){
    argument_list[i] = args.at(i+1);
    
 }//for
 
 
 if (pid == 0){
 
  if(args.size() > 1){ 
     execlp(command.c_str(),cmd.c_str(),argument_list[0].c_str(),0);
  }//if
  else{
  execlp(command.c_str(),cmd.c_str(),0);
  }//else
  
 }//if

 else{
   while(pid != wait(0));
 }//else


} //execute
