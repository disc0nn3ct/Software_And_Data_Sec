#include <stdio.h>
#include <sys/msg.h> // для msgget
#include <string.h> // для strlen
#include <stdlib.h>

// #include <sys/ipc.h>

#ifndef MSGMAX
#define MSGMAX 1024
#endif 

struct msgbuf {
long mtype;
char mtext[MSGMAX];
};

int main() 
{
	char cmd[]= "date | cut -d ' ' -f 1-4 | md5sum | cut -d ' ' -f 1 | awk '{print $NF}'";
	// char cmd[]="date";

	FILE *f= popen (cmd, "r");

	struct msgbuf buf;
	buf.mtype = 16;


	fgets (buf.mtext, sizeof(buf.mtext), f);

	printf("%s",buf.mtext);
	pclose (f);

	int fd = msgget(111, IPC_CREAT | 0666 );
	
	if (fd == -1 || msgsnd(fd, &buf, strlen(buf.mtext)+1, IPC_NOWAIT) == -1 )
		perror("Ошибка сообщения"); 
	

	// msgctl(fd, IPC_RMID, 0 );
	// printf("%s",buf.text);

	return 0;
}