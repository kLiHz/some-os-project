// #include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

int main() {
    int pipe_fd[2];  // 0: read; 1: write
    
    char read_buf[11] = "0";
    char write_buf[11] = "1234567";
    
    // memset(read_buf, 0, sizeof(read_buf));
    // memset(write_buf, 0, sizeof(write_buf));

    if (pipe(pipe_fd) < 0) {
        std::cerr << "pipe create error\n";
        return -1;
    }
    
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        // child process
        close(pipe_fd[1]);  // close 'write'
        read(pipe_fd[0], read_buf, 10);
        std::cout << "Received: " << read_buf << "\n";
        close(pipe_fd[0]);
        
    } else if (pid > 0) {
        // parent process
        close(pipe_fd[0]);  // close 'read'
        std::cout << "Send: " << write_buf << "\n";
        write(pipe_fd[1], write_buf, 10);
        close(pipe_fd[1]);
    }
}

