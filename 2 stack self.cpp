#include<iostream>
#define MAX 20
using namespace std;
class TwoStack{
	private:
		int array[MAX];
		int top1 = -1,top2 = MAX;
	public :
		void push(int stack,int value){
		
		if(top1<top2-1){
			if(stack==1){
				array[++top1]=value;
				cout<<array[top1]<<" pushed to stack 1"<<endl;
			}else if(stack == 2){
				array[--top2]=value;
				cout<<array[top2]<<" pushed to stack 2"<<endl;
			}else {
                cout << "Invalid stack number. Choose 1 or 2." << endl;
            }
		}else {
            cout << "Stack Overflow. No space left to push." << endl;
        }
	}
	void pop(int stack){
		if(stack == 1){
			if(top1>=0){
				cout<<array[top1--]<<" is popped from stack 1"<<endl;
			}else{
				cout<<"Stack 1 is under flow"<<endl;
			}
		}else if(stack ==2){
			if(top2<MAX){
				cout<<array[top2++]<<" is poped from stack 2"<<endl;
			}else{
				cout<<"Stack 2 is underflow"<<endl;
			}
		}
	}
	void display() {
        cout << "Stack 1: ";
        for (int i = 0; i <= top1; ++i)
            cout << array[i] << " ";
        cout << "\nStack 2: ";
        for (int i = MAX - 1; i >= top2; --i)
            cout << array[i] << " ";
        cout << "\n";
    }
};
int main(){
	TwoStack ts;
    int choice, stack, value;

    do {
        cout << "\n1. Push to Stack\n2. Pop from Stack\n3. Display Stacks\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Select the stack (1 or 2): ";
                cin >> stack;
                cout << "Enter value to push: ";
                cin >> value;
                ts.push(stack, value);
                break;
            case 2:
                cout << "Select the stack (1 or 2): ";
                cin >> stack;
                ts.pop(stack);
                break;
            case 3:
                ts.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
