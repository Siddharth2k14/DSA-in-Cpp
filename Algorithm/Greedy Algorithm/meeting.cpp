#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int Meeting(vector<int> &start, vector<int> &end){
    int size = start.size();
    vector<pair<int, int>> v;

    for(int i = 0; i < size; i++){
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int ans = v[0].second;

    for(int i = 1;i < size; i++){
        if(v[i].first >= ans){
            count = count + 1;
            ans = v[i].second;
        }
    }

    return count;
}

int main(){
    vector<int> start = {1,2,3,4,5,6};
    vector<int> end = {2,4,6,8,10,12};

    cout << "The number of meetings to be held in the room is " << Meeting(start, end) << endl;

    return 0;
}