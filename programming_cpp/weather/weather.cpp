#include <iostream>

using namespace std;

int main()
{
    // Informacios szovegeket a cerr << -rel lehet kiirni
    cerr << "Idojaras" << endl;
    // Statikus felveves
     //const int maxmeret = 1000;
     //int n;
     //int napimin[maxmeret], napimax[maxmeret];
    //
    int n;
    cerr << "Hany adat lesz: "; cin >> n;
    int napimin[n], napimax[n];
    for (int i= 0; i < n; i++){

        cerr << i + 1 << ".adat: ";
        cin >> napimin[i] >> napimax[i] ;
    }

    // 1. feladat
    cout << "#\n";
    int db = 0;

    for (int i = 0; i < n ; ++i){
        if(napimin[i] <= 0){
            ++db;
        }
    }

    cout << db <<"\n";
    // 2. feladat
    cout << "#\n";

    int max_value = 0;
    int maxertek  = napimax[0] - napimin[0];

    int sorszam;
    for(int i = 1; i<n; ++i){
        int d = napimax[i] - napimin[i];

        if(d > max_value){
            max_value = d;
            sorszam = i;
        }
    }

    cout << sorszam+1 << endl;


    // 3. feladat
    cout << "#\n";

    int ind; bool van;
    int i = 1;
    while ( i<n && napimax[i] >= napimin[i-1]){
        ++i;
    }

    van = i<n;
    if(van){
        ind = i+1;
    }
    else{
        ind = -1;
    }

    cout << ind << endl;
    // 4. feladat
    cout << "#\n";

    db=0;
    for(int i=0;i <n; ++i){
        if(napimin[i]<=0 && napimax[i]>0) ++db;
    }

    cout << db;

    for(int i=0;i <n; ++i){
        if( napimin[i]<=0 && napimax[i]>0) cout << " " << i+1;
    }

    cout << endl;

    return 0;
}
