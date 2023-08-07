# Piped-Messaging-Application-with-Multithreading
This C project involves creating a program that acts as a simple messaging system using threads and pipes. The main purpose of the project is to read data from one pipe, display it to the console, and simultaneously write data from the standard input to another pipe.

The program takes two command-line arguments: the first argument specifies the name of the read-pipe, and the second argument specifies the name of the write-pipe. The project's main components are as follows:

pipe_read_thread Function: This function is executed in a separate thread. It reads data from the specified read-pipe (argv1) and prints it to the console using the puts function.

Main Function: The main function starts by validating the correct number of command-line arguments. It then creates a thread (thread1) to execute the pipe_read_thread function. If the thread creation fails, an error message is printed, and the program exits.

The main function also opens the write-pipe (specified by argv[2]) for writing. It then enters a loop where it reads input from the standard input using fgets and writes that input to the write-pipe using fputs. The fflush function is used to ensure that data is immediately written to the pipe.

In summary, this project demonstrates the use of threads and pipes to create a basic messaging system where one thread reads data from a pipe and displays it, while the main thread reads input from the user and sends it to another pipe. It provides a simple example of interprocess communication using pipes and showcases the concurrent execution of threads.
