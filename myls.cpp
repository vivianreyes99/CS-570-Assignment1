#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
// #include <unistd.h>
using namespace std;
using std::cout;
using std::endl;

int main (int argc, char *argv[])
{
    bool show_all = false;

    //the user only entered "myls" 
	if (argc == 1)
    { 
        //pointer to directory stream of type DIR, DIR is a structure that represents a directory stream
        DIR *directory_path = NULL;
        //name of files/what's in directory is stored in d_pathr, 
        struct dirent *d_pathtr = NULL;     

        //creates the directory stream, returns a pointer to it
        //passing in "." into opendir returns the directory stream of the current directory
        if ((directory_path = opendir(".")) == NULL) //check if the directory exists
		{
            //fix to actual current directory
			cout << "Cannot access " << "current directory" << "\n";
		}
		else 
		{
                //if readdir fails, d_pathr will be null and while loop ends, 
                //else, d_pathr will be a dirent struct and readdir returns the next d_pathr 
                // which are files inside the current directory
                while ( (d_pathtr = readdir(directory_path)) != NULL )
			    {
                    //prints out all the files in the directory_path stream using the d_name field
				    cout << d_pathtr->d_name << "\n";	
                }		      
		}
    }
    
    

	for (int i = 1; i < argc; i++) // loop through each command line argument
	{
		if (strcmp(argv[i], "-h") == 0) // user entered "-h"
    	{
        	//set flag
        	show_all = true;
			continue;
    	}
		
		DIR *directory_path = NULL; // has the path of the directory
		struct dirent *d_pathtr = NULL; // struct contains the directory entries
		
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
