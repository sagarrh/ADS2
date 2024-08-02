#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> a;
    int input;
    while(true){
        cout<<"Enter your choice 1.push 2.pop 3.multipop 4.display";
        cin>>input;
        switch(input){
            case 1:
            int val;
            cout<<"Enter val";
            cin>>val;
            a.push(val);
            break;
            case 2:
            if(a.empty()){
                cout<<"empty";
            }else
            a.pop();
            break;
            case 3:
            int val2;
            cout<<"how many?";
            cin>>val2;
            while(val2){
                if(a.empty()){
                    cout<<"Empty";
                }
                else{
                    a.pop();
                }
                val2--;
            }
            break;
            case 4:
            while(!a.empty()){
                int th=a.top();
                cout<<th<<' ';
                a.pop();
            }

        }

    }
    return 0;
}