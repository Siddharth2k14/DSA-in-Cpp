#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{
    public:
    int value;
    int weight;
};

static bool cmp(pair<double, Item> a, pair<double, Item> b){
    return a.first > b.first;
}

double fractionalKnapsack(int W, Item arr[], int n){
    vector<pair<double, Item>> v;
    for(int i = 0; i < n; i++){
        double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    double totalValue = 0;
    for(int i = 0; i < n; i++){
        if(v[i].second.weight > W){
            totalValue = totalValue + W*v[i].first;
            W = 0;
        }
        else{
            totalValue = totalValue + v[i].second.value;
            W = W - v[i].second.weight;
        }
    }

    return totalValue;

}

int main() {
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value and weight of item " << i+1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value that can be put in a knapsack of capacity " << W << " is " << maxValue << endl;

    return 0;
}