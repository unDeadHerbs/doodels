#include <iostream>
#include <signal.h>

static bool running=true;
static void die(int x){
	std::cout<<"recived kill signal"<<std::endl;
	running=false;
}

static void setup_quit_handlers(){
	signal(SIGHUP,  die);
	signal(SIGINT,  die);
	signal(SIGQUIT, die);
	signal(SIGILL,  die);
	signal(SIGTRAP, die);
	signal(SIGABRT, die);
	signal(SIGIOT,  die);
	signal(SIGFPE,  die);
	signal(SIGKILL, die);
	signal(SIGUSR1, die);
	signal(SIGSEGV, die);
	signal(SIGUSR2, die);
	signal(SIGPIPE, die);
	signal(SIGTERM, die);
	#ifdef SIGSTKFLT
		signal(SIGSTKFLT, die);
	#endif
	signal(SIGCHLD, die);
	signal(SIGCONT, die);
	signal(SIGSTOP, die);
	signal(SIGTSTP, die);
	signal(SIGTTIN, die);
	signal(SIGTTOU, die);
}

#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
char*socket_path="./socket";

int main(int argc, char *argv[]){
	setup_quit_handlers();
	int opt=0;
	while(opt!=1&&opt!=2){
		std::cout<<"is this a client(1) or a server(2) :";
		std::cin>>opt;
	}
	if(opt==1){
		std::cout<<"this is a client"<<std::endl;
		std::cout<<"connecting to server"<<std::endl;
		//check for server
		//connect to server
		//display client number
		//list other connected clients
		while(running){
			//wait for command
			//if other connect anounce
		}
		//tell server that leaving
	}else{
		std::cout<<"server"<<std::endl;
		struct sockaddr_un addr;
		char buf[100];
		int fd,cl,rc;
		//if(argc>1)socket_path=argv[1];
		if((fd=socket(AF_UNIX,SOCK_STREAM,0))==-1){
			perror("socket error");
			exit(-1);
		}
		memset(&addr,0,sizeof(addr));
		addr.sun_family=AF_UNIX;
		if(*socket_path=='\0'){
			*addr.sun_path='\0';
			strncpy(addr.sun_path+1,socket_path+1,sizeof(addr.sun_path)-2);
		}else{
			strncpy(addr.sun_path,socket_path,sizeof(addr.sun_path)-1);
		}
		unlink(socket_path);
		if(bind(fd,(struct socketaddr*)&addr,sizeof(addr))==-1){
			perror("bind error");
			exit(-1);
		}
		if(listen(fd,5)==-1){
			perror("listen error");
			exit(-1);
		}
		while(running){
			if((cl=accept(fd,NULL,NULL))==-1){
				perror("accept error");
				continue;
			}
			while((rc=read(cl,buf,sizeof(buf)))>0){
				printf("read %u pytes: %.*s\n",rc,rc,buf);
			}
			
		//check for other servers
		//open port
		while(running){
		}
	}
	return 0;
}
