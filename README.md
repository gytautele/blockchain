## v0.1

### Hash'avimo funkcijos idėja
* Į hash'avimo funkciją atsisiųsta visų input suma (paversta naudojantis ASCII sistema).
* Naudojamas std::mt19937 generatorius.
* Generatoriui paduodamas fiksuotas skaičius - visų input suma - dėl to, kad nebūtų generuojamos random reikšmės.
* Parenkama generuoti galimos ribos:
  * skaičius (48, 57)
  * raidė (97, 102);
  * didžioji raidė (65, 70);
* Taip pat sugeneruojama 0, 1, 2:
  * 2 - sugeneruojamas skaičius
  * 3 - raidė
  * 4 - didžioji raidė
  
### Eksperimentinio tyrimo-analizės atlikimas
#### 1 dalis

1. Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio.

| Inputas  | Output |
| ------------- | ------------- |
| a.txt  | efebA38FB43dcDd5e88DB937ba3b03D  |
| b.txt  | 77FB866DeD1EaC23a6FEa084FAEfc70  |

2. Bent du failai būtų sudaryti iš daug visiškai skirtingų simbolių (> 10000 simbolių).

| Inputas  | Output |
| ------------- | ------------- |
| konstitucija.txt (~9500 simbolių) | B50ecfF8EB20979c0Ef717EE2540ae6 |
| metai.txt (~20 000 simbolių)  | ADE3aB65A7AdA3ae7f8Cf4bB5DF926F  |

3. Bent du failai būtų sudaryti iš daug simbolių ir skirtųsi vienas nuo kito tik vienu simboliu.

| Inputas  | Output |
| ------------- | ------------- |
| konstitucija1.txt (pakeista pirma raidė) | 424fd5f7B2ae4ceF720a107CfA310Bf |
| metai1.txt (pakeista pirma raidė)  | 49bcb8f9ad382bd7Faa0EBa5CF8d8ED  |

4. Tuščias failas Ir išveskite output'us.

| Inputas  | Output |
| ------------- | ------------- |
| tuscias.txt  | dFffdcbABcEccF363FAFCEdE7d5Eac1  |
| nulis.txt  | AD4a1dCfBaa377EFE8De1EB87FEBeeF  |

#### 2 dalis

Ištirkite Jūsų sukurtos hash funkcijos efektyvumą: tuo tikslu suhash'uokite kiekvieną eilutę iš konstitucija.txt failo.

| Bandymo numeris  | Laikas |
| ------------- | ------------- |
| 1  | 0.635977 s |
| 2  | 0.61038 s  |
| 3  | 0.620487 s |

#### 3 dalis
https://github.com/dqmis/hashrank

**Legend**  
`A` - Average hashing time of "Konstitucija.txt"  
`B` - Letter collision test time  
`C` - Letter collision similarity average  
`D` - Number of collisions found in Letter test  
`E` - Word collision test time  
`F` - Word collision similarity average  
`G` - Number of collisions found in Word test  

| Github nick | Link to the repo            | Course/group | Reference test | A      | B         | C      | D    | E          | F      | G  |
|-------------|-----------------------------|--------------|----------------|--------|-----------|--------|------|------------|--------|----|
| dqmis       | dqmis/vuhash                | 2/1          | 5.7301         | 0.0052 | 1417.6514 | 0.1108 | 9917 | 1497.0956s | 0.0056 | 0  |
| gytautele   | gytautele/blockchain        | 2/2          | 5.7201         | 0.0047 | 1043.5663 | 0.0136 | 0    | 1060.4037  | 0.0141 | 0 |
| emilisb     | emilisb/Hash                | 2/2          | 5.3863         | 0.0035 | 804.7102  | 0.0108 | 0    | 820.5668   | 0.0108 | 0  |
| gitguuddd   | gitguuddd/Hash_generatorius | 2/2          | 7.119          | 0.0285 | 6833.3648 | 0.0308 | 2    | 6840.2643  | 0.005  | 0  |

#### 4 dalis (Word Coallision)

Sukurtas simple testukas patikrinti koalizijų skaičių, kurių praeitoje versijoje buvo 49.

Test'o esmė: į map konteinerį insertina tik tada, jeigu hash'as nesutampa su prieš tai buvusiais.
PVZ.: jeigu iš viso hash yra 500, o testas atspausdina skaičių 499, vadinasi vienas hash sutapo ir word coallision yra lygus 1.

```
#include <fstream>
#include <iostream>
#include <map>
int main() {
    std::map<std::string, unsigned int> hasher;
    std::ifstream fd("hash.txt");
    std::string z;

    for (int i = 0; i < 100000; i++) {
        fd >> z;
        hasher.insert(std::pair<std::string, unsigned int>(z, 1));
    }
    std::cout << hasher.size();
    return 0;
}
```

