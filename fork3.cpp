//I am the parent process 
//I am the child process 0
//I am the child process 1
//I am a grandchild process from child process 1
//I am the child process 2

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "I am the parent process" << endl;
    int pid;

    for (int i=0; i<3; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            cout << "I am the child process " << i << endl;
            if (i == 1)
            {
                pid = fork();
                if (pid == 0)
                {
                    cout << "I am the grandchild process from child process " << i << endl;
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