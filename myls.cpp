/* 
 * CS 570
 * Professor Roch
 * Assignment 1: Myls
 * accepts command line arguments and prints the contents of specified directories
 * after checking that the directory exists 
 * Accepts a "-h" argument that prints the hidden files (files that begin with ".")
 * accomplishes this using system calls opendir,readdir, and closedir
 *
 * We the undersigned promise that we have in good faith attempted to follow the principles of 
 * pair programming. Although we were free to discuss ideas with others, the implementation is 
 * our own. We have shared a common workspace and taken turns at the keyboard for the majority
 * of the work that we are submitting. Furthermore, any non programming portions of the
 * assignment were done independently. We recognize that should this not be the case, we will
 * be subject to penalties as outlined in the course syllabus.
 * Anoodnya Sangam
 * Vivian Reyes
 */

#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
using std::cout;
using std::endl;
 
void printDir (string name, bool print_all);

int main (int argc, char *argv[]) {
   //boolean for the -h flag, if show_all is true
   //then show all files including the hidden files
   bool show_all = false;
 
   //the user only entered "myls" or "myls -h"
   if (argc == 1 || (strcmp(argv[1], "-h") == 0 && argc == 2)) {
       // user entered "myls -h"
       if (argc == 2){
           //set flag to true since user typed in -h and wants to show hidden files
           show_all = true;
       }
	   
	   //passing in "." into opendir returns the directory stream of the current directory
	   printDir("." , show_all);
   }
   
   // loop through each command line argument
   for (int i = 1; i < argc; i++) {
       if (strcmp(argv[i], "-h") == 0) { // user entered "-h
           //set flag
           show_all = true;
           continue;
       }
      
       //DIR *directory_path = opendir(argv[i]); // has the path of the directory
       //struct dirent *d_pathtr = NULL; // struct contains the directory entries

	   printDir(argv[i], show_all); // calls function to print everything in this directory
   }
}

void printDir(string name, bool print_all) {
	DIR *directory_path = NULL;  //pointer to directory stream of type DIR, DIR is a structure that represents a directory stream
    struct dirent *d_pathtr = NULL; // struct contains the directory entries

	// opendir opens a directory stream for the current dir called name, returns pointer to it
	//check if the directory exists, if not print error message
	if ((directory_path = opendir(name.c_str())) == NULL) {
        cout << "Cannot access " << name << "\n";
    }
	else {
		if (!(name == ".")){
			cout << name << "\n";
		}

		//if readdir fails, d_pathr will be null and while loop ends,
        //else, d_pathr will be a dirent struct and readdir returns the next d_pathr
        // which are files inside the current directory
        while ( (d_pathtr = readdir(directory_path)) != NULL ) {
            // if no flag and it starts with a dot, continue to next iteration
            // (if it starts with ., don't print it)
            if (print_all == false && d_pathtr->d_name[0] == '.') {
                continue;
            }
            cout << d_pathtr->d_name << "\n"; // puts val of d_name into d_pathtr, prints d_pathtr
        }
    }
}
