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
//testing githubs
//now viv testing github

using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
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
		
		DIR *directory_path = NULL; // has the path of the directory
		struct dirent *d_pathtr = NULL; // struct contains the directory entries
		// https://www.thegeekstuff.com/2012/06/c-directory/
		
		if ((directory_path = opendir(argv[i])) == NULL) //check if the directory exists
		{
			cout << "Cannot access " << argv[i] << "\n";
		}
		else 
		{
            while ( (d_pathtr = readdir(directory_path)) != NULL ) //adds current directory entry to the struct
			{
				// if no flag and it starts with a dot, continue to next iteration 
				// (if it starts with ., don't print it)
				if (show_all == false && d_pathtr->d_name[0] == '.')
				{
					continue;
				}
				cout << d_pathtr->d_name << "\n"; // puts val of d_name into d_pathtr, prints d_pathtr
			}
		}
	}
}