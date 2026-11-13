
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;
int main()
{
    int serverSocket, clientSocket;
    char message[1024] = {0};
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        cout << "Socket creation failed";
        return 1;
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);
    bind(serverSocket, (struct sockaddr*)&serverAddress,
         sizeof(serverAddress));
    listen(serverSocket, 5);
    cout << "Server is waiting for client..." << endl;
    clientSocket = accept(serverSocket, NULL, NULL);
    cout << "Client connected!" << endl;
    recv(clientSocket, message, sizeof(message) - 1, 0);
    cout << "Message from client: " << message << endl;
    string reply = "Hello Client! Message received.";
    send(clientSocket, reply.c_str(), reply.length(), 0);
    cout << "Reply sent to client." << endl;
    close(clientSocket);
    close(serverSocket);
    return 0;
}
