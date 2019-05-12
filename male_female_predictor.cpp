#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAX_N = 100009;
const double PI = 3.14159265358979323846;

struct data_person {
    int id, gender;
    double weight, height, repwt, repht;
};

int n = 0, males = 0, females = 0;
double target_height, target_weight,  males_weight_mean = 0, males_height_mean = 0, females_weight_mean = 0, females_height_mean = 0, males_weight_variance = 0, males_height_variance = 0, females_weight_variance = 0, females_height_variance = 0,
males_posible, females_posible;
data_person data[MAX_N];
string info;

bool cmp(data_person a, data_person b) {
    return a.gender < b.gender;
}

void set_mean_and_variance() {
    // Males
    for (int i = females + 1; i <= n; i++) {
        males_weight_mean += data[i].weight;
        males_height_mean += data[i].height;
    }
    males_weight_mean /= (double) males;
    males_height_mean /= (double) males;
    for (int i = females + 1; i <= n; i++) {
        males_weight_variance += (data[i].weight - males_weight_mean) * (data[i].weight - males_weight_mean);
        males_height_variance += (data[i].height - males_height_mean) * (data[i].height - males_height_mean);
    }
    males_weight_variance /= (double) (males - 1);
    males_height_variance /= (double) (males - 1);

    // Females
    for (int i = 1; i <= females; i++) {
        females_weight_mean += data[i].weight;
        females_height_mean += data[i].height;
    }
    females_weight_mean /= (double) females;
    females_height_mean /= (double) females;
    for (int i = 1; i <= females; i++) {
        females_weight_variance += (data[i].weight - females_weight_mean) * (data[i].weight - females_weight_mean);
        females_height_variance += (data[i].height - females_height_mean) * (data[i].height - females_height_mean);
    }
    females_weight_variance /= (double) (females - 1);
    females_height_variance /= (double) (females - 1);
}

double getProb(double x, double mean, double variance) {
    double p = 1 / sqrt(2.0 * PI * variance) * exp(-((x - mean) * (x - mean)) / (2.0 * variance));
    return p;
}

int main() {
    // Calculate prior
    ifstream file("data.txt");
    getline(file, info);
    while (file >> data[++n].id) {
            file >> data[n].gender >> data[n].weight >> data[n].height >> data[n].repwt >> data[n].repht;
            (data[n].gender == 0) ? (females++) : (males++);
    }

    n--;
    sort(data + 1, data + n + 1, cmp);
    set_mean_and_variance();
    file.close();

    // Input
    freopen("a.inp", "r", stdin);
    freopen("a.res", "w", stdout);
    //cout << "Enter your height: ";
    cin >> target_height;
    //cout << "Enter your weight: ";
    cin >> target_weight;

    // Calculate prob and Print answer
    males_posible = ((double) males / (double) n) * getProb(target_height, males_height_mean, males_height_variance) * getProb(target_weight, males_weight_mean, males_weight_variance);
    females_posible = ((double) females / (double) n) * getProb(target_height, females_height_mean, females_height_variance) * getProb(target_weight, females_weight_mean, females_weight_variance);
    if (males_posible > females_posible) {
        cout << 1 << endl;//cout << "You are male.";
    }
    else if (females_posible > males_posible) {
        cout << 0 << endl;//cout << "You are female.";
    }
    else cout << -1 << endl;//cout << "Can not predict.";
    //cout << males_posible << " " << females_posible;
    return 0;
}
