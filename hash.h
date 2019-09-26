#include <string>
#include <bitset>
#include <vector>

std::string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string hash(std::string a) {
    std::vector < bool > bin;
    int nn = 0;
    for (char x: a) {
        for (int i = 0; i < 8; i++) {
            bin.push_back(std::bitset < 8 > ((int) x)[i]);
        }
        nn += (int) x;
    }
    while (bin.size() / 6 < 40) {
        bin.push_back(0);
        bin.push_back(1);
    }
    srand(nn);
    for (int i = 0; i < bin.size()+nn; i++) {
        int j = rand() % bin.size();
        bin[j] = !bin[j];
    }
    int ll = (bin.size() - 40 * 6) / 40;
    std::string out = "";
    std::bitset < 6 > letter;
    int stup=0;
    if(ll!=0) { stup = rand() % ll; }
    for (int i = 0; i < bin.size(); i += 6 + stup) {
        for (int o = 0; o < 6; o++) {
            letter[o] = bin[i + o];
        }
        if(ll!=0) { stup = rand() % ll; }
        out += base[letter.to_ulong()];
    }
    return out;
}
