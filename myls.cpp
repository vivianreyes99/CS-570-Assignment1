#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
//#include <unistd.h>
using namespace std;

//Vivians local machine version
//tester
//testing github
//now viv testing github

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{

    // 1/29 10:52pm this compiles with no errors, prints the files in the directories
    // still need to add the output for just "myls", -h check
    // testing prints dots before the filename ?? idk why we have to figure that out

    bool show_all = false;	

	if (argc == 1) //the user only entered "myls" 
    {
        //print all the directories in the current path
    }
    
    

	for (int i = 1; i < argc; i++) // loop through each command line argument
	{
		if (strcmp(argv[i], "-h") == 0) // user entered "-h"
    	{
        	//set flag
        	show_all = true;
    	}
		
		DIR *directory_path = NULL;
		struct dirent *d_pathtr = NULL;
		
		if ((directory_path = opendir(argv[i])) == NULL) //check if the directory exists
		{
			cout << "Cannot access " << argv[i] << "\n";
		}
		else 
		{
            //if (hidden == true) //&&  // if it starts with ., don't print it
            {
                while ( (d_pathtr = readdir(directory_path)) != NULL )
			    {
				    cout << d_pathtr->d_name << "\n";
			    }
            }
		}
	}
}