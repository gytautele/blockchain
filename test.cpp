#include <fstream>
#include <iostream>
#include <map>
int main() {
    std::map<std::string, unsigned int> hasher;
    std::ifstream fd("hash.txt");
    std::string z;

    //į map konteinerį insertina tik tada, jeigu hash'as nesutampa su prieš tai buvusiais
    //jeigu iš viso hash yra 500, o testas atspausdina skaičių 499, vadinasi vienas hash sutapo
    //ir word coallision yra lygus 1

    for (int i = 0; i < 100000; i++) {
        fd >> z;
        hasher.insert(std::pair<std::string, unsigned int>(z, 1));
    }
    std::cout << hasher.size();
    return 0;
}
