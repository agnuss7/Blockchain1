#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "hash.h"
#include "check.h"
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::microseconds TimeType;

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
        printf("vesit savo stringa - 0\n1 testas, skaitymas is failu - 1\ntikrinti greiti (2 testas) - 2\ntikrinti unikaluma (3 testas) - 3\ntikrinti skirtinguma (4 testas) - 4\nuzteks - 5\n");
        std::cin >> boo;
        if (boo == 0) {
            std::string v;
            std::cin >> v;
            printf("\nkas iejo: %s\nhash: %s\n", v.c_str(), hash(v).c_str());
        } else if (boo == 1) {
            printf("\ntuscias failas \nhash: %s\n", hash(readfrom("a.txt")).c_str());
            printf("\nfailas su vien a raide \nhash: %s\n", hash(readfrom("x.txt")).c_str());
            printf("\nfailas su vien G raide \nhash: %s\n", hash(readfrom("b.txt")).c_str());
            printf("\nfailas su vien G raide, bet vienas simbolis pakeistas \nhash: %s\n", hash(readfrom("c.txt")).c_str());
            printf("\nfailas 1 su atsitiktiniais simboliais \nhash: %s\n", hash(readfrom("f.txt")).c_str());
            printf("\nfailas 2 su atsitiktiniais simboliais \nhash: %s\n", hash(readfrom("g.txt")).c_str());
            printf("\nfailas 3 su atsitiktiniais simboliais \nhash: %s\n", hash(readfrom("d.txt")).c_str());
            printf("\nfailas su tais pat atsitiktiniais simboliais kaip 3, tik vienas simbolis pakeistas\nhash: %s\n", hash(readfrom("e.txt")).c_str());
/*
            printf("| tuscias failas | %s |\n", hash(readfrom("a.txt")).c_str());
            printf("| failas su vien a raide | %s |\n", hash(readfrom("x.txt")).c_str());
            printf("| failas su vien G raide | %s |\n", hash(readfrom("b.txt")).c_str());
            printf("| failas su vien G raide, bet vienas simbolis pakeistas | %s |\n", hash(readfrom("c.txt")).c_str());
            printf("| failas 1 su atsitiktiniais simboliais | %s |\n", hash(readfrom("f.txt")).c_str());
            printf("| failas 2 su atsitiktiniais simboliais | %s |\n", hash(readfrom("g.txt")).c_str());
            printf("| failas 3 su atsitiktiniais simboliais | %s |\n", hash(readfrom("d.txt")).c_str());
            printf("| failas su tais pat atsitiktiniais simboliais kaip 3, tik vienas simbolis pakeistas | %s |\n", hash(readfrom("e.txt")).c_str());
  */      }
        else if (boo == 2) {
            std::chrono::high_resolution_clock::time_point t1;
            std::chrono::high_resolution_clock::time_point t2;
            std::ifstream df ("konstitucija.txt");
            std::string v;
            std::string out;
            int time=0;
            while(df) {
                getline(df, v);
                t1=Clock::now();
                out = hash(v);
                t2=Clock::now();
                time+=std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
                printf("\nhash: %s\nuztruko %I64d mikrosekundziu\n",out.c_str(),(std::chrono::duration_cast<TimeType>(t2 - t1)).count());
                //printf("\n | %s | %I64d | \n",out.c_str(),(std::chrono::duration_cast<TimeType>(t2 - t1)).count());
            }
            df.close();
            printf("\nis viso: %d milisekundziu\n", time);
        }
        else if (boo == 3) {
            printf("10 000 skirtingu string'u hash'u, tikrinama, ar sutampa kurie du\n");
            std::ifstream df ("random.txt");
            std::string v;
            std::ofstream rf ("output.txt");
            while (df) {
                getline(df,v);
                rf<< hash(v) << "\n";
            }
            df.close();
            rf.close();
            printf("kiek vienodu hash'u: %d\n", check());
        }
        else if (boo == 4) {
            std::ifstream df ("pairs.txt");
            std::string v;
            std::string out1;
            std::string out2;
            while(df) {
                getline(df, v);
                out1 = hash(v);
                getline(df, v);
                out2 = hash(v);
                printf("\nhash1: %s\thash2: %s\tdiff: %d\tstatusas: %s\n",out1.c_str(),out2.c_str(),diff(out1,out2), (status(diff(out1,out2))).c_str());
                //printf("| %s | %s | %d/180 | %s |\n",out1.c_str(),out2.c_str(),diff(out1,out2), (status(diff(out1,out2))).c_str());

        }
        df.close();
    }} while (boo!=5);

    return 0;
}
