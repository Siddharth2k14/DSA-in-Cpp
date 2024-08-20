#include<bits/stdc++.h>
using namespace std;

int tansfer_of_disks(stack<int>& a, stack<int>& b){
    if(b.empty() == true){
        b.push(a.top());
        a.pop();
        return 1;
    }
    else if(a.empty() == true){
        a.push(b.top());
        b.pop();
        return 2;
    }
    else{
        if(b.top()>a.top()){
            b.push(a.top());
            a.pop();
            return 1;
        }
        else{
            a.push(b.top());
            b.pop();
            return 2;
        }
    }
}

int main(){
    stack<int> s,a,d;
    int n = 0;
    cin>>n;
    for(int i = n; i >= 1; i--){
        s.push(i);
    }
    int x = pow(2,n)-1;
    int i = 1;

    if(n%2 == 0){
        while(i <= x){
            if(i%3 == 1){
                int y = tansfer_of_disks(s, a);
                if(y == 1){
                    cout<<a.top()<<endl;
                }
                else{
                    cout<<s.top()<<endl;
                }
            }
            else if(i%3 == 2){
                int y = tansfer_of_disks(s,d);
                if(y == 1){
                    cout<<d.top()<<endl;
                }
                else{
                    cout<<s.top()<<endl;
                }
            }
            else{
                int y = tansfer_of_disks(a,d);
                if(y == 1){
                    cout<<d.top()<<endl;
                }
                else{
                    cout<<a.top()<<endl;
                }
            }
            i++;
        }
    }
    else{
        while(i <= x){
            if(i%3 == 1){
                int y = tansfer_of_disks(s,d);
                if(y == 1){
                    cout<<d.top()<<endl;
                }
                else{
                    cout<<s.top()<<endl;
                }
            }
            else if(i%3 == 2){
                int y = tansfer_of_disks(s, a);
                if(y == 1){
                    cout<<a.top()<<endl;
                }
                else{
                    cout<<s.top()<<endl;
                }
            }
            else{
                int y = tansfer_of_disks(a,d);
                if(y == 1){
                    cout<<d.top()<<endl;
                }
                else{
                    cout<<a.top()<<endl;
                }
            }
            i++;
        }
    }

    while(d.empty()!=true){
        cout<<d.top()<<endl;
        d.pop();
    }

    return 0;
}