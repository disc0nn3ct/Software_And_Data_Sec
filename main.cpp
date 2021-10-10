#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/msg.h>
#include <sys/wait.h> // для wait
#include <unistd.h> // для read и pipe 
#include <random>
#include <sys/ptrace.h>




int random(int min, int max) { static std::mt19937 prng(std::random_device{}()); return std::uniform_int_distribution<>(min, max)(prng); } /*Дополняет рандомными символами строку Если переменная k = 0 Дополняет нулями строку, иначе дополняет случайными символами*/ void complete_line(char* str, int S_size, bool k) { if(k==0){ for(int i=strlen(str); i<S_size; i++ ) { str[i]='0'; } } else { for(int i=strlen(str); i<S_size; i++ ) { str[i]=(char)(random(33,126)); } } }

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
	// метод Control flow flattening
	int h=1;
	int S_size=32;
	char str1[32];
	while(h!=15)
	{
		switch(h)
		{
			case 12:{
				for(int i=0; i<32; i++)
				{
					str[i]|=str2[i];
					str[i]=(char)(34+((uint)(str[i])%89));
				}
				h=15;
				break;}			
			case 10:{
				for(int i=0; i<32; i++)
				{
					str[i]=rev(str[i]);
					str2[i]=rev(str2[i]);
				}			
				h=12;
				break;}
			case 9:
				{for(int i=0; i < 16; i++)
				{
					str2[i]^=str1[16+i];
					str2[16+i]^=str1[i];
				}
				h=10;
				break;}				
			case 1:
				{strncpy(str1, str, 32);
				for(int i=0; i < 32; i++)
				{
					str[i]^=str2[i];
				}
				h=9;
				break;}				
		}
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









// Достаточно Стандартное средство
void check_proc_status() {
    FILE* proc_status = fopen("/proc/self/status", "r");
    if (proc_status == NULL){
        return;
    }
    char line[1024] = { };
    char *fgets(char *s, int size, FILE *stream);
    while (fgets(line, sizeof(line), proc_status) != NULL) {
        const char traceString[] = "TracerPid:";
        char* tracer = strstr(line, traceString);
        if (tracer != NULL)
        {
            int pid = atoi(tracer + sizeof(traceString) - 1);
            if (pid != 0){
                fclose(proc_status);
                kill(getppid(), SIGKILL);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(proc_status);
}







int main()
{

	char login[32];
	char pasww[32];
	char key[32] = "";
	char cmd[1024];
	char key_in[32];

	int g=10;
	while(g!=99)
	{
		switch(g)
		{
			case 10:
			{
				{
					unsigned char s[] = 
					{
					    0xba, 0x5b, 0x5c, 0xa9, 0x93, 0x63, 0x48, 0x59, 
					    0x3a, 0xaa, 0xa1, 0xbd, 0x42, 0x6b, 0x40, 0x55, 
					    0xa7, 0x10, 0x6c, 0xde, 0x6a, 0xa2, 0xa0, 0x6d, 
					    0x4a, 0x9f, 0x4c, 0x39, 0x5a, 0x3f, 0xa0, 0x3d, 
					    0x83, 0xde, 0xd4, 0x71, 0x42, 0x57, 0x3c, 0x74, 
					    0x19, 0x33, 0xc7, 0x39, 0x7b, 0x6b, 0x38, 0x59, 
					    0x52, 0x5f, 0x30, 0x8
					};

					for (unsigned int m = 0; m < sizeof(s); ++m)
					{
					    unsigned char c = s[m];
					    c += 0xce;
					    c ^= m;
					    c = -c;
					    c -= m;
					    c = ~c;
					    c += 0xfe;
					    c = ~c;
					    c = -c;
					    c -= m;
					    c = ~c;
					    c -= 0x88;
					    c ^= 0x47;
					    c = (c >> 0x2) | (c << 0x6);
					    c += 0xb;
					    c = ~c;
					    s[m] = c;
					}

					printf("%s\n", s);	
				}
				g=4;
				break;
			}
			case 12:
			{

				complete_line(login, 32, 1);
				{
					unsigned char s[] = 
					{

					    0x49, 0x8b, 0xb8, 0x12, 0xbe, 0xca, 0xe7, 0xe, 
					    0xe0, 0xb1, 0x2c, 0xc8, 0xa5, 0xc7, 0xf0, 0x88, 
					    0x7f, 0x6, 0x26, 0xcb, 0xbf, 0xc5, 0xfc, 0xe9, 
					    0xa6
					};

					for (unsigned int m = 0; m < sizeof(s); ++m)
					{
					    unsigned char c = s[m];
					    c = (c >> 0x7) | (c << 0x1);
					    c = -c;
					    c ^= 0x58;
					    c = (c >> 0x6) | (c << 0x2);
					    c -= m;
					    c = (c >> 0x6) | (c << 0x2);
					    c -= m;
					    c = ~c;
					    c -= 0xb5;
					    c ^= m;
					    c = ~c;
					    c = (c >> 0x2) | (c << 0x6);
					    c ^= 0xf8;
					    c = (c >> 0x2) | (c << 0x6);
					    c = -c;
					    s[m] = c;
					}

					printf("%s\n", s);
				}				
				g=3;
				// g=99;
				break;					
			}

			case 54:
			{
			    int f_pid = fork();
			    if (f_pid == 0){
			        if (ptrace(PTRACE_ATTACH, getppid(), NULL, NULL) != 0){
			            exit(EXIT_FAILURE);
			        }
			        ptrace(PTRACE_SETOPTIONS, getppid(), NULL, PTRACE_O_TRACEFORK);
			        int status = 0;
			        wait(&status);
			        ptrace(PTRACE_CONT, getppid(), NULL, NULL);
			        while (true)
			        {
			            check_proc_status();
			            int pid = waitpid(-1, &status, WNOHANG);
			            if (pid == 0)
			            {
			                sleep(1);
			                continue;
			            }
			            if (status >> 16 == PTRACE_EVENT_FORK)
			            {
			                long newpid = 0;
			                ptrace(PTRACE_GETEVENTMSG, pid, NULL, &newpid);
			                ptrace(PTRACE_ATTACH, newpid, NULL, NULL);
			                ptrace(PTRACE_CONT, newpid, NULL, NULL);
			            }
			            ptrace(PTRACE_CONT, pid, NULL, NULL);
			        }
			    }

				g=2;
				break;
				}
			case 3:
			{
				std::cin >> pasww;
				complete_line(pasww, 32, 1);
				xor_on_str_part_to_part(login, pasww); // do some black magic
				g=54;
				break;
			}				
			case 2:
			{
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
					make_some_bash("WpbV93");
					wait(NULL);
					close(p[1]);
					read(p[0], cmd, sizeof(cmd));
				}
				g=44;
				break;
			}
			case 44:
			{
				{
					unsigned char s[] = 
					{
					    0xa2, 0x36, 0x17, 0x36, 0x84, 0xb6, 0xc4, 0x38, 
					    0x5a, 0xe0, 0x36, 0x3a, 0x64, 0x8b, 0x4b
					};

					for (unsigned int m = 0; m < sizeof(s); ++m)
					{
					    unsigned char c = s[m];
					    c = -c;
					    c = (c >> 0x5) | (c << 0x3);
					    c ^= m;
					    c += 0x9e;
					    c = -c;
					    c += 0x3a;
					    c ^= 0x32;
					    c += 0xd0;
					    c ^= m;
					    c += 0x77;
					    c = -c;
					    c -= m;
					    c ^= m;
					    c -= 0x49;
					    c ^= 0x9f;
					    s[m] = c;
					}

					printf("%s\n", s);		
				}
				day_mask(login, cmd, key);
				vivod_mas_char(key,32);
				g=7;
				break;
			}
			case 7:
			{
				{
					unsigned char s[] = 
					{

					    0xf, 0x30, 0x2c, 0x4e, 0xec, 0xc, 0xd0, 0xed, 
					    0x83, 0x50, 0xc4, 0x4f, 0xe4, 0x4c, 0xa5, 0xe5, 
					    0x7a, 0x37
					};

					for (unsigned int m = 0; m < sizeof(s); ++m)
					{
					    unsigned char c = s[m];
					    c += 0xe6;
					    c = ~c;
					    c ^= 0x7a;
					    c = -c;
					    c = ~c;
					    c = -c;
					    c = (c >> 0x3) | (c << 0x5);
					    c = -c;
					    c -= 0xd6;
					    c = ~c;
					    c = (c >> 0x5) | (c << 0x3);
					    c = ~c;
					    c ^= m;
					    c -= 0xfe;
					    c = (c >> 0x5) | (c << 0x3);
					    s[m] = c;
					}

					printf("\n%s\n", s);		


				}
				std::cin >> key_in;


				if(cmp_str_str(key,key_in)){
			        {
						unsigned char s[] = 
						{

						    0xfe, 0xca, 0xfe, 0x8b, 0xb7, 0xc0, 0xfb, 0x5f, 
						    0xcc, 0xe6, 0x57, 0xe3, 0xe5, 0xe4, 0x90, 0x5f, 
						    0x8a, 0x8c, 0xfc, 0xb4, 0xb4, 0x48, 0x7f, 0x1f
						};

						for (unsigned int m = 0; m < sizeof(s); ++m)
						{
						    unsigned char c = s[m];
						    c = -c;
						    c -= m;
						    c = -c;
						    c -= m;
						    c ^= 0xa2;
						    c = ~c;
						    c ^= m;
						    c -= m;
						    c ^= 0x73;
						    c += 0xdc;
						    c ^= m;
						    c += m;
						    c = -c;
						    c = ~c;
						    c += 0xac;
						    s[m] = c;
						}

						printf("%s\n", s);        	
			        }
			    }
			    else
			    {
			    	{
						unsigned char s[] = 
						{
						    0x30, 0xea, 0x5a, 0xc8, 0xd0, 0xa5, 0xab, 0xd4, 
						    0xe, 0x2e, 0x8b, 0x66, 0x5c, 0xf6, 0x8b, 0x6a, 
						    0x48, 0xd5, 0x91, 0x40, 0x50, 0x58, 0x38, 0x1b, 
						    0x1f, 0x1, 0xa9, 0xbd, 0xff
						};

						for (unsigned int m = 0; m < sizeof(s); ++m)
						{
						    unsigned char c = s[m];
						    c += m;
						    c ^= 0xa0;
						    c = -c;
						    c = (c >> 0x3) | (c << 0x5);
						    c = ~c;
						    c -= m;
						    c = ~c;
						    c = (c >> 0x5) | (c << 0x3);
						    c = -c;
						    c += 0xa6;
						    c ^= m;
						    c += 0x2c;
						    c = -c;
						    c = (c >> 0x1) | (c << 0x7);
						    c ^= m;
						    s[m] = c;
						}

						printf("%s\n", s);    		
			    	}
			    }
				g=99;
				break;
			}
			case 4:
			{
 				std::cin >>login;
				g=12;
				break;				
			}		
		}
	}
	return 0;
}