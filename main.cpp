#include <iostream>
// #include <string>
#include <cstring>

#include <sys/msg.h>
void make_some_bash(std::string str)
{
	system("ls");
}



std::string make_license_key(const std::string &logon, const std::string &password, std::string &license_key)
{





	return 0;
} 





int main(int argc, char const *argv[])
{

	// ////////////////////////////////////////
	// std::cout << "Good time! Enter your credential!" << std::endl; 
	// std::cout << "Enter your logig" << std::endl; 
	// std::string login;
	// std::cin >> login;
	// std::string password;
	// std::cout << "Enter your password" << std::endl; 
	// std::cin >> password;




	////////////////////////////////////////

char one[1024];
	struct msgbuf buf;

	char cmd[1024] ;
	memset(cmd,0,1024);

	int fd = msgget(111, 0)
;
	if(fd == -1)
		perror("Ошибка сообщения"); 

	tryAgain:
	if(msgrcv(fd, &buf, 1024, 16, IPC_NOWAIT) != -1){
		strcpy(cmd, buf.mtext); 
		printf("%s\n",cmd);
		// printf("%s\n ", buf.mtext);
	}
	else {perror("Ошибка в msgrcv()\n"); goto tryAgain;} 
	msgctl(fd, IPC_RMID, NULL);







	std::cout << "=========================================" << std::endl;

	////////////////////////////////////////

	// std::string license_key;
	// std::cout << "License key:" << license_key << std::endl;  




	// if( )	




	// make_some_bash(login);
	// std::cout << "strin : " << login << std::endl;
	return 0;
}