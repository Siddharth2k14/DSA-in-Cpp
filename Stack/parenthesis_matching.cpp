/*#include<bits/stdc++.h>
using namespace std;

bool balancing_of_parenthesis(string exp){
    stack<char> temp;
    for(int i = 0; i < exp.length(); i++){
        if(temp.empty()){
            temp.push(exp[i]);
        }
        else if((temp.top() == '(' && exp[i] == ')') || (temp.top() == '[' && exp[i] == ']') || (temp.top() == '{' && exp[i] == '}')){
            temp.pop();
        }
        else{
            temp.push(exp[i]);
        }
    }
    if(temp.empty()){
        return true;
    }
    return false;
}

int main(){
    string exp = "{()}[]}}";
    if(balancing_of_parenthesis(exp)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}*/

// C++ code to reverse a
// stack using recursion
#include <bits/stdc++.h>
using namespace std;

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(stack<char>& st, char x)
{

	if (st.size() == 0) {
		st.push(x);
	}
	else {

		// All items are held in Function Call
		// Stack until we reach end of the stack
		// When the stack becomes empty, the
		// st.size() becomes 0, the above if
		// part is executed and the item is
		// inserted at the bottom

		int a = st.top();
		st.pop();
		insert_at_bottom(st, x);

		// push allthe items held in
		// Function Call Stack
		// once the item is inserted
		// at the bottom
		st.push(a);
	}
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse(stack<char>& st)
{
	if (st.size() > 0) {

		// Hold all items in Function
		// Call Stack until we
		// reach end of the stack
		char x = st.top();
		st.pop();
		reverse(st);

		// Insert all the items held
		// in Function Call Stack
		// one by one from the bottom
		// to top. Every item is
		// inserted at the bottom
		insert_at_bottom(st, x);
	}
	return;
}

// Driver Code
int main()
{
	stack<char> st, st2;
	// push elements into
	// the stack
	for (int i = 97; i <= 100; i++) {
		st.push(i);
	}

	st2 = st;

	cout << "Original Stack" << endl;
	// printing the stack after reversal
	while (!st2.empty()) {
		cout << st2.top();
		st2.pop();
	}
	cout<<endl;

	// function to reverse
	// the stack
	reverse(st);
	cout << "Reversed Stack" << endl;
	// printing the stack after reversal
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
