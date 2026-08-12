#include <bits/stdc++.h>
using namespace std;

bool canDistribute(vector<int>& population, int k, double maxLoad) {
    long long clinics = 0;

    for (int p : population) {
        clinics += (long long)ceil(p / maxLoad);

        if (clinics > k)
            return false;
    }

    return true;
}

double minimumMaxLoad(vector<int>& population, int k) {
    double low = 0.0;
    double high = *max_element(population.begin(), population.end());

    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;

        if (canDistribute(population, k, mid))
            high = mid;
        else
            low = mid;
    }

    return high;
}

int main() {
    int n = 3;
    vector<int> population = {200, 20, 50};
    int k = 5;

    double ans = minimumMaxLoad(population, k);

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
