//Lets user insert numbers into the entered file


#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

   string filename;
   int num;

   filename = argv[1];

   ofstream myfile (filename.c_str(),ios::in | ios::binary | ios::app);

   if (myfile.is_open()){
      cout << "Enter number to add to file or -1 to quit>";
      cin >> num;
      while (num != -1) {
	myfile.write((char*) &num, sizeof(int));
        cout << "Enter number to add to file or -1 to quit>";
	cin >> num;
      }

      myfile.close();
      
   }

   else cout << "Unable to open file\n";



return 0;
}
