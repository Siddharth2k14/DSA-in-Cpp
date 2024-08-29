#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int size){
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for(int i = size-1; i >= 0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int size){
    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for(int i = 0; i < size; i++){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()] >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heigths){
    int n = heigths.size();

    vector<int> next(n);
    next = nextSmallerElement(heigths, n);
    
    vector<int> prev(n);
    prev = prevSmallerElement(heigths, n);

    int area = INT_MIN;

    for(int i = 0; i < n; i++){
        int length = heigths[i];
        if(next[i] == -1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;

        area = max(area, newArea);
    }

    return area;
}

int main(){

    int n;
    cout << "Enter the number of elements in the histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the histogram: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);
    cout << "The largest rectangle area in the histogram is: " << maxArea << endl;

    return 0;
}