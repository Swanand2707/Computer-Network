
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;
int main()
{
    int clientSocket;
    char message[1024] = {0};
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        cout << "Socket creation failed";
        return 1;
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1",
              &serverAddress.sin_addr);
    connect(clientSocket, (struct sockaddr*)&serverAddress,
            sizeof(serverAddress));
    cout << "Connected to server!" << endl;
    string msg = "Hello Server!";
    send(clientSocket, msg.c_str(), msg.length(), 0);
    cout << "Message sent to server." << endl;
    recv(clientSocket, message, sizeof(message) - 1, 0);
    cout << "Reply from server: " << message << endl;
    close(clientSocket);
    return 0;
}
