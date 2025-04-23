#include<bits/stdc++.h>
using namespace std;

signed main(){
    while (true) {
        system("./gen.out > ./tmp.in");
        system("./h.out < ./tmp.in > ./tmp.out");
        system("./h_ac.out < ./tmp.in > ./tmp_AC.out");
        if (system("diff ./tmp.out ./tmp_AC.out")) {
            cout << "WA" << endl;
            return 0;
        } else cout << "AC" << endl;
    }
    return 0;
}