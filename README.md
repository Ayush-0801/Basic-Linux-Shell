# Basic-Linux-Shell
An implementation of linux shell in C programming language.

<h2>Steps of Implementation:</h2>

1. Take string input for the command.
2. Parse the string into individual words for easier computation . 
3. Check for command and then its option
4. Execute external commands using fork() and execl(). 
5. Printing the necessary output.

<h2>Internal Commands</h2>

<h3>1. cd (options: ‘..’ , ‘~’)</h3>
  
It changes the working directory.

Implementation in C using: **chdir()**<br>
```int chdir(const char *path);```<br>
chdir() changes the current working directory of the calling process
to the directory specified in path.

$ cd ..<br>
Changes the directory to the previous directory.

$ cd ~<br>
Changes the directory to the home directory.

<h3>2. pwd (options: ‘-L’ , ‘-P’)</h3>

It prints the path of the working directory.

Implementation in C using : **getcwd()**<br>
```char *getcwd(char *buf, size_t size);```<br>
The getcwd() function copies an absolute pathname of the current
working directory to the array pointed to by buf, which is of length size.

$ pwd -L<br>
Prints the symbolic path.

$pwd -P<br>
Prints the actual path.

<h3>3. history(options: ‘-c’ , [number])</h3>

Used to view the previously executed command

Implementation in C using: **simple 2d array to store string commands.**<br>

$ history 5<br>
To show the limited number of commands that executed previously

$ history -c<br>
The whole history can be removed using history -c option. (Using memset on the array in C)

<h3>4. echo(options: ‘-n’ , ‘-e’)</h3>

Used to display line of text/string that are passed as an argument

Implementation in C using: **Reading the command string character by character.**<br>

$ echo -n<br>
This option is used to omit echoing trailing newline.

$echo -e<br>
Enables the interpretation of backslash escapes

<h3>5. exit(options: ‘-n’ , ‘-e’)</h3>

Terminates the shell

Implementation in C using: **exit(0)**

<h2>External Commands</h2>

For external commands my shell creates a new process using the fork() system call and executes the external .c file corresponding to that command with the help of execvp() system call to run the command externally.<br>

int execvp (const char *file, char *const argv[]);<br>
*file*: points to the file name associated with the file being executed.<br> 
*argv*:is a null terminated array of character pointers.<br>

<h3>1. ls(option: ‘-a’ , ‘-1’)</h3>

ls with no option list files and directories in bare format

Implementation in C using: **readdir()** 
```struct dirent *readdir(DIR *dirp);```<br>
The readdir() function returns a pointer to a dirent structure representing the next directory entry in the directory stream pointed to by dirp. It returns NULL on reaching the end of the directory stream or if an error occurred.

$ ls -a<br>
Prints all files including the ones starting with dot

$ls -1<br>
Prints all files and directories in a long list format.

<h3>2. mkdir(option: ‘-v’ , ‘-p’)</h3>

Creates directory in the working directory
 
Implementation in C using: **mkdir()**
```int mkdir(const char *path, mode_t mode);```<br>
The mkdir() function shall create a new directory with name path. The file permission bits of the new directory shall be initialized from mode.

$ mkdir -v<br>
It displays a message for every directory created

$mkdir -p<br>
A flag which enables the command to create parent directories as necessary. If the directories exist, no error is specified.

<h3>3. rm(option: ‘-i’ , ‘-d’)</h3>

Removes files/directories from the working directory

Implementation in C using:**remove()**

$ rm -i<br>
Confirms from user for the deletion to begin

$ rm -d<br>
Used for the deletion of empty directories (Implementation in C by rmdir())

<h3>4. cat(option: ‘-n’ , ‘-s’)</h3>

It reads data from the file and gives their content as output.

Implementation in C using: **fopen()**- to open the file <br>**fgets()**-to read the file line by line

$ cat -s<br>
suppress repeated empty lines in output

$ cat -n<br>
To view contents of a file preceding with line numbers.

<h3>5. date(option: ‘-u’ , ‘%+d’)</h3>

Displays the current date and time of the system

Implementation in C using: **C library time.h** 

$ rm -u<br>
Displays GMT time

$ rm +%d<br>
Displays the number of day of the month

<h2>Corner Cases Handled (Error Handling)</h2>

1. Multiple inputs handled for mkdir,cat and rm 
2. Invalid command and option error handled 
3. File/Directory not found error handled
4. Fork failing.
