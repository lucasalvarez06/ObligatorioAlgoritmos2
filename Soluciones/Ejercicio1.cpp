
#include "Hashx.cpp"
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

int main(){

    int n;
    cin >> n;

    Hash* h = crearHash(n*2);

    for(int i=0; i<n ; i++){

       string s = "";
       cin >> s;
       insertar(h,s); 

    }

    cout << h->cantElem;

}
