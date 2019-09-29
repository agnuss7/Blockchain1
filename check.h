#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bitset>

std::string base1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int check () {
    std::ifstream df("output.txt");
    std::string f;
    std::vector<std::string> sh;
    while(df){
        getline(df,f);
        sh.push_back(f);
    }
    df.close();
    int damn=0;
    for(int i=0;i<sh.size();i++)
    {
        for(int j=0;j<sh.size();j++)
        {
            if(j!=i && sh[j]==sh[i])
            {
                damn++;
            }
        }
    }
    return damn;
}

int diff (std::string a, std::string b) {
    std::vector < bool > bin1;
    std::vector < bool > bin2;
    for (char x : a) {
        int xx;
        for (int i=0;i<64;i++) {
            if(base1[i]==x) {
                xx=i;
                break;
            }
        }
        for (int i = 0; i < 6; i++) {
            bin1.push_back(std::bitset < 6 > (xx)[i]);
        }
    }
    for (char x : b) {
        int xx;
        for (int i=0;i<64;i++) {
            if(base1[i]==x) {
                xx=i;
                break;
            }
        }
        for (int i = 0; i < 6; i++) {
            bin2.push_back(std::bitset < 6 > (xx)[i]);
        }
    }
    int proc=0;
    for(int i=0;i<(30*6);i++) {
        if(bin1[i]==bin2[i]) { proc++; }
    }
    return proc;
}

std::string status (int d) {
    if(d<60){return "nepanasu, iki 33 proc panasumo";}
    else if(d<120){return "siek tiek panasu, iki 66 proc panasumo";}
    else if(d<160){return "panasu, iki 90 proc panasumo";}
    else if(d>=170){return "labai panasu, iki 100 proc panasumo";}

}