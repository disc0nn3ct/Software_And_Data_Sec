#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/msg.h>
#include <sys/wait.h> // для wait
#include <unistd.h> // для read и pipe 
#include <random>

int random(int min, int max) {
    static std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution<>(min, max)(prng);
}


// Дополняет рандомными символами строку
// Если переменная k = 0 Дополняет нулями строку, иначе дополняет случайными символами 

void complete_line(char* str, int S_size, bool k)
{
	if(k==0){
		for(int i=strlen(str); i<S_size; i++ )
		{
			str[i]='0';
		}
	}
	else {
		for(int i=strlen(str); i<S_size; i++ )
		{
			str[i]=(char)(random(33,126));
		}
	}
	// str[S_size]='\0';
}

// Просто вывод, так как тут С 
void vivod_mas_char(char* str, int S_size)
{
	for(int i=0; i < S_size; i++)
	{
		std::cout<<str[i];
	}
}

// Возвращает 1 если одинаковые, иначе 0
bool cmp_str_str(char* str1, char* str2)
{
	bool k=1; 
	for(int i=0; i<32; i++)
	{
		if(str1[i]!=str2[i])
		{
			k=0;
			break;
		}
	}
	return k;
}

// Разворачивает битовую последовательность 
unsigned char rev(const char a)
{
	// std::cout << (uint)(a) << std::endl;
	// for (int i=sizeof(a)*8-1; i>=0; --i)
	// {
	// 	std::cout<<(int)((a>>i)&1);
	// }

	// std::cout << std::endl; 

	unsigned char k=0;
	for(int i=7; i >=0; i--) 
	{ 
		k |= ((a >> (7-i))&1) << i;
	}
	return k;

}

void xor_on_str_part_to_part(char* str, char* str2)
{
	int S_size=32;
	char str1[32];
	strncpy(str1, str, 32);
	for(int i=0; i < 32; i++)
	{
		str[i]^=str2[i];
	}
	for(int i=0; i < 16; i++)
	{
		str2[i]^=str1[16+i];
		str2[16+i]^=str1[i];
	}
	for(int i=0; i<32; i++)
	{
		str[i]=rev(str[i]);
		str2[i]=rev(str2[i]);
	}
	for(int i=0; i<32; i++)
	{
		str[i]|=str2[i];
		str[i]=(char)(34+((uint)(str[i])%89));
	}
}

// Применить маску дневную 
void day_mask(char *str, char *d_mask, char* key)
{
	for (int i=0; i<32; i++)
	{
		key[i] = (48+(uint)(str[i] ^ d_mask[i])%74);
	}
}




// Получить md5hash дня. Которая потом будет использована как маска 
void make_some_bash(const char* a)
{
	std::string str1 = "U2FsdGVkX19pZp6nDOlsWY8mu6nULH48Qs20Mo6HT77HsdAMXBsRS4+WSh9RFzjy\nmxip1KECiDIlRVWADRm45PTAWfnFQRgoxpzq8Nk+Ykjg9DGSJTl0nhoAgPhXIqhP\nH5EL9Q0kEUsiaMkek7C0JoFsx717fY1RTI2YpAWHr9s1/yAm3BxCOA9Rd9EGiH8o\n0FpjyDT64bZn60lzClOKhgSI+0KlJJSbStOGz+RS3BMUXiP2FKSuA8VKyb4T5Jd0\ncbN3KLbunCU+iuyhqRXMdvZ1j+Xil8TujoVVTF3D2FJYllQVYr1Lq7tKycAZkgkQ\n30/SWGkittfxtVxnv+2UGfx7TGwxJ46Aww4+CWyoMI2Napnns3Z8/3xH6f36GNRS\ntjqZjmLNt1jf0OczCkKMXkpvt5xrkz74t4W2Jnt6HKtUyBENYfsnssbaLU+c3D+E\n6l6aCYIuNVyuStdooScWgw47Aw88z9nc9aGqpUSyJSDJoGj4nRYicmNJI3e07gu8\nGSPMBORgIEuZk2tgfM7Ebly+mtYj+xx40Q4hbZhnL/JHU8TNGrnIa0HKOdzivU5Y\n6RKAwP0X687WCmT1e2yiq18xwzsrl2On4wtkUAHFgZY8G6rxcFTQHIK1B0R6mxyw\nQppLX9Nn6Fy+64GRG/fLH2xZu51kVXl/K07pikHUAarHVe1AVx55AuD8pedTbE+6\nCJAAE4yRmtrNDpQX7hOFq4OrVpHrDvdwC1NGc6xWAv+qyQYMGgh2uD5/nraVDIxW\nDxNC+IYpB3g1FJjVaSCYBWql4EWlkzzLEdU17uuhrxQPoMqKUVbQPGkJ6v4NhAST\nzY6RhHHjdUbpY5jcYRBW3IevA1FB+jxDpX+dTYDuyMrjL6OustATJFJrybV4LqBg\nzXFUm+nAS5IDSvBPn17jE+IPdW+lLD0EBDhljuPBro5U5Gcvo5mxCwO0fLBuEfmF\nj9kk7wB6J50=";

    std::ofstream out;  
    out.open("one1.c"); 
    if (out.is_open())
    {
        out << str1;
    }
    out.close();

    str1.clear();
    str1="openssl enc -d -in one1.c -out one2.c -des3 -base64 -pass pass:" + std::string(a) +  " -pbkdf2 ; gcc one2.c -o client.o ; ./client.o ; rm one1.c one2.c client.o";

    char buf[255];
	strcpy(buf,str1.c_str());
    system(buf);

}

int main()
{
	std::cout << "Good time! Enter your credential!" << std::endl;
	std::cout << "Enter your login:" << std::endl;  

	char login[32];
 	std::cin >>login;

	complete_line(login, 32, 1);

	std::cout << "And enter your password:" << std::endl;  
	char pasww[32];
	std::cin >> pasww;
	complete_line(pasww, 32, 1);
	xor_on_str_part_to_part(login, pasww); // do some black magic

	char key[32] = "";

	char cmd[1024];
	memset(cmd, 0, 1024);

	int p[2];
    if (pipe(p) < 0)
		{perror("Error pipe");} 


	if(fork() == 0)
	{
		// child
	struct msgbuf buf;
	
	tryAgain:
	int fd = msgget(111, 0);
	if(msgrcv(fd, &buf, 1024, 16, IPC_NOWAIT) != -1)
	{
		// memcpy(cmd, buf.mtext, sizeof(buf.mtext));
		strcat(cmd, buf.mtext); 
		close(p[0]); 
		write(p[1], cmd, strlen(cmd));
	}
	else goto tryAgain; 
	msgctl(fd, IPC_RMID, NULL);
    exit(0);
	}
	else
	{
		// papa
		make_some_bash("WpbV93");
		wait(NULL);
		close(p[1]);
		read(p[0], cmd, sizeof(cmd));
	}


	std::cout<< "Generated key:" << std::endl;
	day_mask(login, cmd, key);
	vivod_mas_char(key,32);
	char key_in[32];
	std::cout << "\nNow enter the key" << std::endl;
	std::cin >> key_in;


	if(cmp_str_str(key,key_in)){
        std::cout<<"Congratulation, it is true key!!! \n";
    }
    else
    {
    	std::cout<< "Ow no, the key is wrong! :C " << std::endl;
    }
	return 0;
}