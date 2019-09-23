#include<stdio.h>
#include<cmath>
#include<iostream>

string readfrom(string name)
{
    std::ifstream df (name);
    string out;
    while(df){df.get(out);}
    df.close();
    return out;
}

int main () {
    bool boo;
    fprint("kas isejo: %s",readfrom("a.txt"));






    return 0;
}