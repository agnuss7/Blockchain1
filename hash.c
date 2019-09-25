#include<fstream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<iostream>
#include<bitset>
#include<vector>


std::string readfrom(std::string name)
{
    std::ifstream df(name);
    std::string out;
    getline(df,out);
    df.close();
    return out;
}

std::string base="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string hash(std::string a) {
std::vector<bool> bin;
int nn=0;
for (char x : a)
{
for(int i=0;i<8;i++)
{
bin.push_back(std::bitset<8>((int)x)[i]);
}
nn+=(int)x;
}
while(bin.size()/6<20)
{
bin.push_back(0);
bin.push_back(1);
}
srand(nn);
for(int i=0;i<bin.size();i++)
{
bin[i]=!bin[i];
int j=rand()%bin.size();
bin[j]=!bin[j];
}
int ll=(bin.size()-20*6)/20;
std::string out="";
std::bitset<6> letter;
for(int i=0;i<bin.size();i+=6+ll)
{
for(int o=0;o<6;o++)
{
letter[o]=bin[i+o];
}
out+=base[letter.to_ulong()];
}
return out;
//
}

int main () {
do{
    bool boo;
    printf("ivesit string - 0, is failo - 1?\n");
    std::cin>>boo;
    if(boo==0) {
    std::string v;
    std::cin>>v;
    printf("kas isejo: %s\nbinary: %s\n",v.c_str(),hash(v).c_str());
    }
    else {
	std::string v=readfrom("a.txt");
        printf("kas iejo: %s\nbinary:%s\n",v.c_str(),hash(v).c_str());
	
    }
} while(1);



    return 0;
}
