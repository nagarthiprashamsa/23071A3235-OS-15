#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "chat_socket"

int main() {
    int client_fd;
    struct sockaddr_un server_addr;
    char buffer[1024];

    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH);
    connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(client_fd, buffer, strlen(buffer));

        if (strcmp(buffer, "exit\n") == 0)
            break;

        memset(buffer, 0, sizeof(buffer));
        read(client_fd, buffer, sizeof(buffer));
        printf("Server: %s\n", buffer);
    }
    close(client_fd);
    return 0;
}
