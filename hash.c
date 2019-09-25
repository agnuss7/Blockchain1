#include<fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<iostream>

std::string readfrom(std::string name)
{
    std::ifstream df(name);
    std::string out;
    getline(df,out);
    df.close();
    return out;
}

std::string hash(std::string a) {

}

int main () {
bool boo;
printf("ivesit string - 0, is failo - 1?\n");
std::cin>>boo;
if(boo==0) {
std::string v;
std::cin>>v;
printf("kas isejo: %s\n",v.c_str());

}
else {
printf("kas isejo: %s\n",hash(readfrom("a.txt")).c_str());

}




return 0;
}
