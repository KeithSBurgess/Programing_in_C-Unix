//Lets user insert numbers into the entered file


#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

   string filename;
   int num;

   filename = argv[1];

   ofstream myfile (filename.c_str(),ios::app);

   if (myfile.is_open()){
      cout << "File is open.\n";
      cin >> num;
      while (num != -1) {
         myfile << num << '\n';
         cin >> num;
      }

      myfile.close();
      cout << "File closed.\n";
   }

   else cout << "Unable to open file\n";



return 0;
}
