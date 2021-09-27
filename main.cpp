#include <iostream>

int make_some_bash(std::string str)
{
	system("ls");

}



int main(int argc, char const *argv[])
{
	std::cout << "Put string to enter" << std::endl; 
	std::string str;
	std::cin >> str;
	


	
	make_some_bash(str);
	std::cout << "strin : " << str << std::endl;
	return 0;
}