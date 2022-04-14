#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


int main(){//int argc, char** argv){

 const char *command;
 string line;
 vector <string> commands;
 
   while(1){
      cout << "$$>";
      getline(cin,line);
      commands.push_back(line);
      
      if (line == "history"){
         for(int i = 0; i<commands.size(); i++){
            cout << i << " " << commands[i] << "\n";
         }//for
      }//if
      
      command = line.c_str();
      system(command);
      
   }//while

return 0;

}//main

