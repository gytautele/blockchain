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
| a.txt  | EEa4B1DA0e15cD6005b17BabEAc141a  |
| b.txt  | Ba1Ec0ceb8fdD4CEeFEaF6BD948BEbD  |

2. Bent du failai būtų sudaryti iš daug visiškai skirtingų simbolių (> 10000 simbolių).

| Inputas  | Output |
| ------------- | ------------- |
| konstitucija.txt (~9500 simbolių) | d86CA42B59bFBEd3FEFA6aB551Bcbe0  |
| metai.txt (~20 000 simbolių)  | cbc6aacebCBBDFFbfE9E5CDABf9efDa  |

3. Bent du failai būtų sudaryti iš daug simbolių ir skirtųsi vienas nuo kito tik vienu simboliu.

| Inputas  | Output |
| ------------- | ------------- |
| konstitucija1.txt (pakeista pirma raidė) | 6fEBcAEa7eEB3288dcbEccd9bB6c61A |
| metai1.txt (pakeista pirma raidė)  | fBBdc3Ae4EdAB03dbD9EBe9E6D8cF0E  |

4. Tuščias failas Ir išveskite output'us.

| Inputas  | Output |
| ------------- | ------------- |
| tuscias.txt  | EEa4B1DA0e15cD6005b17BabEAc141a  |
| nulis.txt  | dFffdcbABcEccF363FAFCEdE7d5Eac1  |

#### 2 dalis

Ištirkite Jūsų sukurtos hash funkcijos efektyvumą: tuo tikslu suhash'uokite kiekvieną eilutę iš konstitucija.txt failo.

| Bandymo numeris  | Laikas |
| ------------- | ------------- |
| 1  | 0.635977 s |
| 2  | 0.61038 s  |
| 3  | 0.620487 s |

#### 3/4 dalys
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
| gytautele   | gytautele/blockchain        | 2/2          | 5.7201         | 0.0047 | 1043.5663 | 0.0136 | 0    | 1060.4037  | 0.0141 | 49 |
| emilisb     | emilisb/Hash                | 2/2          | 5.3863         | 0.0035 | 804.7102  | 0.0108 | 0    | 820.5668   | 0.0108 | 0  |
| gitguuddd   | gitguuddd/Hash_generatorius | 2/2          | 7.119          | 0.0285 | 6833.3648 | 0.0308 | 2    | 6840.2643  | 0.005  | 0  |

