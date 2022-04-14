//reads the contents of a given file

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){

   string filename;
   string line;
   
   filename = argv[1];
  
   ifstream myfile (filename.c_str());
   
   if (myfile.is_open()){
      cout << "File is open.\n";

      while (getline (myfile,line)) {

         cout << line << '\n';      
      }

      myfile.close();
      cout << "File closed.\n";
   }

   else cout << "Unable to open file\n";

   return 0;

}

