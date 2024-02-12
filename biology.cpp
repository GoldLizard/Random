#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int bb = 0;
    int Bb = 0;
    int BB = 0;
    int initialB;
    int initialb;
    int sampleSize;
    int generation;
    char bbDead;

    int randomInt1;
    int randomInt2;
    int gene1; //0 is b, 1 is B
    int gene2;
    int finalb;
    int finalB;
    
    cout << "number of dominant genes in pool = ";
    cin >> initialB;

    cout << "number of recessive genes in pool = ";
    cin >> initialb;

    cout << "number of generations = ";
    cin >> generation;
    
    cout << "sample size in each generation = ";
    cin >> sampleSize;

    cout << "are all bb killed off? y/n" << endl;
    cin >> bbDead;
    cout << endl << endl;
    cout << "\t" << "\t" << "BB" << "\t" << "Bb" << "\t" << "bb" << "\t" << "total B" << "\t" << "total b" << endl;

    for(int i = 1; i <= generation; i++){
        for(int i = 0; i < sampleSize; i++){
            //randomizes gene1
            randomInt1 = rand()%(initialb + initialB) +1;
            if(randomInt1 <= initialB){gene1 = 1;}
            else{gene1 = 0;}
            
            //randomizes gene2
            randomInt2 = rand()%(initialb + initialB) +1;
            if(randomInt2 <= initialB){gene2 = 1;}
            else{gene2 = 0;}

            //tallies bb, Bb, or BB depending on gene1 and gene2 combination
            if(gene1 + gene2 == 0){bb++;}
            else if(gene1 + gene2 == 1){Bb++;}
            else if(gene1 + gene2 == 2){BB++;}
        }

        //calculates final number and % of each gene in gene pool
        if(bbDead == 'y'){
            finalb = Bb;
            finalB = 2*BB + Bb;
        }
        if(bbDead == 'n'){
            finalb = 2*bb + Bb;
            finalB = 2*BB + Bb;
        }
        
        //outputs chart
        cout << "Generation " << i << ":  " ;
        cout << BB << "\t" << Bb << "\t" << bb << "\t" << finalB << "\t" << finalb << endl;

        //prepares next generation
        initialB = finalB;
        initialb = finalb;
        BB = 0;
        Bb = 0;
        bb = 0;
    }

    system("Pause");
    return 0;
}