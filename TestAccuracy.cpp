#include <iostream>
#include <fstream>

using namespace std;

int gender, ix, n = 0;
double height, weight, ans = 0;

int main() {
    freopen("testset.txt", "r", stdin);
    while (cin >> gender) {
        n++; cout << n << endl;
        cin >> height >> weight >> ix;
        ofstream file("a.inp");
        file << height << " " << weight;
        file.close();
        system("male_female_predictor.exe");
        ifstream file2("a.res");
        int res; file2 >> res;
        if (res == gender) ans++;
        file2.close();
    }
    cout << ans /(double)n;
    return 0;
}
