//1 parent 
//4 child
//2 grandchild
//UID      //PID      //PPID
//501      //50138    //50129
//501      //50139    //50138
//501      //50140    //50138
//501      //50141    //50138
//501      //50142    //50138
//501      //50143    //50140
//501      //50144    //50141

//I am the parent process 
//I am the child process 0
//I am the child process 1
//I am a grandchild process from child process 1
//I am the child process 2
//I am a grandchild process from child process 2
//I am the child process 3


#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    std::cout << "I am the parent process" << std::endl;
    int pid;
    for (int i = 0; i < 4; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            std::cout << "I am the child process " << i << std::endl;
            if (i == 1)
            {
                pid = fork();
                if (pid == 0)
                {
                    std::cout << "I am a grandchild process from child process " << i << std::endl;
                    _exit(0);
                }
                
                wait(nullptr);
            }
            else if (i == 2)
            {
                pid = fork();
                if (pid == 0)
                {
                    std::cout << "I am a grandchild process from child process " << i << std::endl;
                    _exit(0);
                }
                wait(nullptr);
            }
            _exit(0);
        }
        wait(nullptr);
    }
    return 0;
}