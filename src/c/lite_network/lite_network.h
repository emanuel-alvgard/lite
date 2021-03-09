//#include "lite_thread.h"

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

// TODO
// make this into lite_server.h API
// create idling funciton in main
// make it possible to change thread number during execution from cmd





int client_start() {

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    return client_socket;

}

int client_connect(int client, int port, char *ip_address) {

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    int connection_status = connect(
        client, 
        (const struct sockaddr *) &server_address, 
        sizeof(server_address));
    
    return connection_status;

}

int client_send() {}

char client_recieve(int client, int size) {
    // malloc server response?
    char server_response[size];
    recv(client, &server_response, sizeof(server_response), 0);

    return server_response;
}

void client_stop(int client) {
    close(client);
    return;
}




void server_start() {}

int server_listen() {}

int server_send() {}

int server_recieve() {}

void server_stop() {}


#pragma clang optimization off



/*
int main() {

    // SEVER SOCKET
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    char server_message[256] = "Welcome to my multi-threaded server! :)\n";

    bind(
        server_socket, 
        (const struct sockaddr *) &server_address, 
        sizeof(server_address));    

    //thread_pool_start(128);
    //struct timespec start = thread_clock_start();

    while (1) {
        // if server has been listening to long the server goes idle
        listen(server_socket, 1);
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);
        //thread(fp_thread_benchmark);
        //thread_benchmark();
        send(client_socket, server_message, sizeof(server_message), 0);
    }

    //thread_clock_stop(start);
    //thread_pool_stop(); // lower sleep_thread to 0?
    close(server_socket);
    
    return 0;
}
*/
#pragma clang optimization on