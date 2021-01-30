

/*

High-level explanation A1: Writing our own version of the "ls" command, which lists files in directory

Functionality of myls
1. defualt command "myls" should list all files in current directoy with new line after each file, 
does not include files that start with "."
2. flag "-h", command "myls -h" will list all files or directories including those that start with a "."
3. multiple line arguments: ex "myls a02 a03" should list files in directories a02 and a03, if any directory
cannot be accessed, the error "Cannot access a02" should be printed
4. create makefile
5. 

pseudocode
- using system calls opendir, readdir, closedir to access files
- first figure out how to use the calls in our code 
- assuming it will look something like this 

defualt command: 
opendir(current directory)
readdir()

*/
