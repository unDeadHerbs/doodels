#include <iostream>
#include <iomanip>
int main(int argc, char const *argv[]){
std::cout<<"#include <iostream>\nint main(int argc, char const *argv[]){"<<std::endl;
for (int i = 0; i < 0xD800; ++i)
	std::cout<<"\tstd::cout<<\"Char \\\\u"<<std::setw(4)
	<<std::setfill('0')<<std::hex<<i<<" is \\u"
	<<std::setw(4)<<std::setfill('0')<<std::hex<<i
	<<"\"<<std::endl;"<<std::endl;
std::cout<<"return 0;\n}"<<std::endl;
return 0;
}
