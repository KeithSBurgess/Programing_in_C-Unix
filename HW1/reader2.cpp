//reads the contents of a given binary file

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

   string filename;
   
   filename = argv[1];
  
   ifstream file (filename.c_str(),ios::out|ios::binary);
   
   if (file.is_open()){
     
      int num;      
      file.read((char*)&num, sizeof(int));
      
      while(!file.eof()){
	cout << num << endl;
	file.read((char*)&num, sizeof(int));
      }
  }

   else cout << "Unable to open file\n";


   return 0;

}

