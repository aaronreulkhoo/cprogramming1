#include "shell.h"

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args) {

	// printf("shellFind is called!\n");
	// system("pwd");
	// error handling
	if (!args[1]) {
		printf("Usage: find [search-param]\n");
		return 1;
	}
	/** TASK 4 **/
	// 1. Execute the binary program 'find' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/find", args)==-1){
	// 	// 4. Print some kind of error message if it returns -1
		printf("'find' command failed.\n");
	}
	// 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue
	return 1;
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args) {
	// printf("shellDisplayFile is called!\n");
	if (!args[1]) {
		printf("Usage: display [file-name]\n");
		return 1;
	}
	/** TASK 4 **/
	// 1. Execute the binary program 'display' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/display", args)==-1) {
		printf("'display' command failed.\n");
	}
	return 1;
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args) {
	// printf("shellListDirAll is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/listdirall", args)==-1) {
		printf("'listdirall' command failed.\n");
	}
	return 1;
}

/*
	List the items in the directory
*/
int shellListDir(char **args) {
	// printf("shellListDir is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellListDir
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/listdir", args)==-1) {
		printf("'listdir' command failed.\n");
	}
	return 1;
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args) {
	// printf("shellCountLine is called!\n");
	if (!args[1]) {
		printf("Usage: countline [file-name]\n");
		return 1;
	}
	/** TASK 4 **/
	// 1. Execute the binary program 'countline' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/countline", args)==-1) {
		printf("'countline' command failed.\n");
	}
	return 1;
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args) {
	printf("Summoning a daemon...\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'summond' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/summond", args)==-1) {
		printf("'summond' command failed.\n");
	}
	return 1;
}


/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args) {
	// printf("shellCheckDaemon is called!\n");

	/** TASK 4 **/
	// 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
	// 2. Check if execvp is successful by checking its return value
	// 3. A successful execvp never returns, while a failed execvp returns -1
	// 4. Print some kind of error message if it returns -1
	// 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue
	if (execvp("/mnt/c/Users/aaron/All_C/cse_programming/cse_assignment1/PA1/shellPrograms/checkdaemon", args)==-1) {
		printf("'checkdaemon' command failed.\n");
	}
	return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
//   printf("shellCD is called! \n");
  if (args[1] == NULL) {
		chdir("/"); //simulate default behaviour of cd
		// fprintf(stderr, "AaronShell: expected argument to \"cd\"\n");
  }
  else
  {
	// chdir() changes the current working directory of the calling process
	// to the directory specified in path.
	if (chdir(args[1]) != 0)
	{ //use chdir
	  perror("AaronShell");
	}
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
//   printf("shellHelp is called! \n");
  int i;
  printf("For more information on a specific command, type usage [command-name]\n");
//   printf("Usage: command arguments\n");
//   printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++) {
	printf("%s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args) {
	printf("AaronShell exit successful. Exiting now: \n");
	return 0;
}


/*
  Builtin function implementations.
*/
int shellUsage(char **args) {
	int functionIndex = -1;
	
	// error handling
	if (!args[1]) {
		printf("Usage: usage [command-name]\n");
		return 1;
	}

	// Check if the commands exist in the command list
	for (int i = 0; i < numOfBuiltinFunctions(); i++) {
		if (strcmp(args[1], builtin_commands[i]) == 0) {
			//pass it to the functions
			functionIndex = i;
		}
	}

  switch (functionIndex)
  {
  case 0:
	printf("Type: cd directory_name\n");
	break;
  case 1:
	printf("Type: help\n");
	break;
  case 2:
	printf("Type: exit\n");
	break;
  case 3:
	printf("Type: usage command\n");
	break;
  case 4:
	printf("Type: display filename\n");
	break;
  case 5:
	printf("Type: countline filename\n");
	break;
  case 6:
	printf("Type: listdir\n");
	printf("Type: listdir -a to list All_Contents in the current dir and its subdirs\n");
	break;
  case 7:
	printf("Type: listdirall\n");
	break;
  case 8:
	printf("Type: find filename_keyword\n");
	break;
  case 9:
	printf("Type: summond \n");
	break;
  case 10:
	printf("Type: checkdaemon \n");
	break;
  default:
	printf("Command %s not found\n", args[0]);
	break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args) {
	/** TASK 3 **/
	// 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
	if (args[0]==NULL) return 1;
	int command=-1;

	// 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
	/* "cd" //0  "help" //1 "exit" //2 "usage" // 3
	"display" //4 "countline" // 5 "listdir" //6 "listdirall" //7 "find" //8 "summond" //9 "checkdaemon" //10 */
	// printf("string is %s\n",args[0]);
	for (int i=0;i<numOfBuiltinFunctions();i++){
		if (strcmp(args[0],builtin_commands[i])==0) command=i;
	}
	// printf("%d\n",command);
	
	// 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
	if (command >= 4) {
		// printf("//Forking//\n");
		int forkValue=fork();
		if (forkValue < 0) { //if fork fails
			perror("Failed to fork.\n");
			exit(1);
		}

		// 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
		else if (forkValue == 0) { //child
			int value = builtin_commandFunc[command](args);
			exit(value);
		}
		// 5. For the parent process, wait for the child process to complete and fetch the child's return value.
		else { //parent
			int status;
			waitpid(forkValue, &status, WUNTRACED);
			//if child terminates properly, WIFEXITED(status) returns TRUE
			if (WIFEXITED(status)){
				// 6. Return the child's return value to the caller of shellExecuteInput
				if(WEXITSTATUS(status)==1){
					// printf("Fork returned 1 successfully\n");
				}
				// else printf("Fork returned with improper value %d\n",WEXITSTATUS(status));
			} else {
				perror("Fork did not terminate properly\n");
			}
		}
	} else if (command>=0) {
		return builtin_commandFunc[command](args);
	} else {
		// 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
		printf("Invalid command received. Type help to list valid commands.\n");
	}
	return 1;
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
	/** TASK 1 **/
	// read one line from stdin using getline()
	// 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
	static char* shell_buffer;
	shell_buffer = (char *)malloc(sizeof(char*)*SHELL_BUFFERSIZE);
	char cwd[1024];

	// 2. Check that the char* returned by malloc is not NULL
	if( shell_buffer == NULL) {
		perror("buffer is null");
		free(shell_buffer);
		exit(1);
	}

	getcwd(cwd, sizeof(cwd));
	// 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
	printf("AaronShell:%s> ", cwd);
	size_t bufsize=SHELL_BUFFERSIZE;
	getline(&shell_buffer,&bufsize,stdin);
	// printf("The fetched line is : %s \n", shell_buffer);

	// 4. Return the char*
	return shell_buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/
char **shellTokenizeInput(char *line) {
	/** TASK 2 **/
	// 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
	static char **token_positions;
	token_positions = malloc(sizeof(char *) * SHELL_BUFFERSIZE);
	int index = 0;
	char *token = strtok(line, " \n");
	token_positions[index] = token;
	index++;

	// 2. Check that char ** that is returend by malloc is not NULL
	while (token != NULL) {
		// 3. Tokenize the *line using strtok() function
		token = strtok(NULL," \n");      //continue finding the next token
		token_positions[index] = token; //store the position
		index++;
	}

	token_positions[index] = NULL; //dont forget to NULL terminate.
	// 4. Return the char **
	// printf("The first token is '%s' \n", token_positions[0]);
	// printf("The second token is '%s' \n", token_positions[1]);
	return token_positions;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void) {
	//instantiate local variables
	char *line;  // to accept the line of string from user
	char **args; // to tokenize them as arguments separated by spaces
	int status = 1;  // to tell the shell program whether to terminate shell or not
	/** TASK 4 **/
	//write a loop where you do the following:
	while(status) {
		// 1. print the message prompt
		// 2. clear the buffer and move the output to the console using fflush
		fflush(stdin);
		// 3. invoke shellReadLine() and store the output at line
		line = shellReadLine();
		// 4. invoke shellTokenizeInput(line) and store the output at args**
		args = shellTokenizeInput(line);
		// 5. execute the tokens using shellExecuteInput(args)
		status = shellExecuteInput(args);
		// printf("%d\n",status);
		// 6. free memory location containing the strings of characters
		free(line);
		// 7. free memory location containing char* to the first letter of each word in the input string
		free(args);
		// 8. check return value of shellExecuteInput. If 1, continue the loop (point 1) again and prompt for another input. Else, exit shell.
	}
	
	
	
	
	
}

int main(int argc, char **argv)
{
 
 printf("AaronShell run successful. Running now: \n");
 
 // Run command loop
 shellLoop();
 return 0;
}



