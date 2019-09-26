#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "hash.h"
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::nanoseconds TimeType;

std::string readfrom(std::string name) {
    std::ifstream df(name);
    std::string out="";
    std::string temp;
    while (!df.eof()) {
        getline(df,temp);
        out += temp;
    }
    df.close();
    return out;
}

int main() {
    int boo;
    do {
        printf("vesit savo stringa - 1, skaitymas is failu - 2, tikrinti greiti - 3, uzteks - 0?\n");
        std::cin >> boo;
        if (boo == 1) {
            std::string v;
            std::cin >> v;
            printf("\nkas iejo: %s\nhash: %s\n", v.c_str(), hash(v).c_str());
        } else if (boo == 2) {
            printf("| tuscias failas | %s |\n", hash(readfrom("a.txt")).c_str());
            printf("| failas su vien a raide | %s |\n", hash(readfrom("x.txt")).c_str());
            printf("| failas su vien G raide | %s |\n", hash(readfrom("b.txt")).c_str());
            printf("| failas su vien G raide, bet vienas simbolis pakeistas | %s |\n", hash(readfrom("c.txt")).c_str());
            printf("| failas su atsitiktiniais simboliais | %s |\n", hash(readfrom("d.txt")).c_str());
            printf("| failas su tais pat atsitiktiniais simboliais, tik vienas simbolis pakeistas | %s |\n", hash(readfrom("e.txt")).c_str());
            /*
            printf("tuscias failas:\n");
            printf("hash: %s\n",hash(readfrom("a.txt")).c_str());
            printf("du failai su vien G, bet vienam skiriasi tik vienas simbolis:\n");
            printf("pirmas failas: %s\n",hash(readfrom("b.txt")).c_str());
            printf("antras failas: %s\n",hash(readfrom("c.txt")).c_str());
            printf("\ndar du failai su atsitiktiniais simboliais, skiriasi tik vienas simbolis:\n");
            printf("pirmas failas: %s\n",hash(readfrom("d.txt")).c_str());
            printf("antras failas: %s\n",hash(readfrom("e.txt")).c_str());*/
        }
        else if (boo == 3) {
            std::chrono::high_resolution_clock::time_point t1;
            std::chrono::high_resolution_clock::time_point t2;
            std::ifstream df ("konstitucija.txt");
            std::string v;
            std::string out;
            while(df) {
                getline(df, v);
                t1=Clock::now();
                out = hash(v);
                t2=Clock::now();
                printf("| %s | %I64d |\n",out.c_str(),(std::chrono::duration_cast<TimeType>(t2 - t1)).count());
                //printf("\nhash: %s\nuztruko %I64d nanosekundziu\n",out.c_str(),(std::chrono::duration_cast<TimeType>(t2 - t1)).count());
            }
            df.close();
        }
    } while (boo!=0);

    return 0;
}