#include <iostream>
#include <vector>
using namespace std;

class Sieve {

    public:
    vector<int> spf; //used to store the smallest prime factor (SPF) of every number

    Sieve(int size) {
        spf.resize(size+1);

        //initialy mark spf[i] = i;

        for(int i = 0 ; i <= size ; i++) {
            spf[i] = i;
        }

        fillSPF(size);
    }

    private:
    void fillSPF(int size) {

        for(int i = 2; 1LL * i * i <= size; i++) {

            if(spf[i] == i) {

                // Mark spf for all multiples of i
                for(int j = i*i; j <= size; j+=i) {
                    // Only update if it hasn't been marked by a smaller prime yet
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
};

int main() {

    vector<int> arr;
    int x;
    cout << "Enter numbers (-1 to end): ";

    while (cin >> x && x != -1) {
        arr.push_back(x);
    }

    Sieve s(1e5);

    for(int i = 0 ; i < arr.size() ; i++) {

        cout << "Prime Factors for " << arr[i] << " are : ";
        int x = arr[i];

        //unique
        while(x > 1) {

            int spf = s.spf[x];
            cout << spf << " ";

            while(x > 1 && s.spf[x] == spf) { //skip duplicates
                x = x/s.spf[x];
            }

            
        }
        cout << endl;
    }
    return 0;

}