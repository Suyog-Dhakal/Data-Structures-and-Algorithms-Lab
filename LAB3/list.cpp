#include<iostream>
using namespace std;
class Node{
public:
    int index,data;
};

class List{
private:
    Node *nodeList;
    int sizeOfList;
    int position;
public:
    List(int size){
        sizeOfList = size;
        nodeList = new Node[sizeOfList];
        position = -1;
    }
    ~List(){
        delete[] nodeList;
    }


		bool isEmpty()
	    {
	        return position == -1;
	    }

	    bool isFull()
	    {
	        return position > sizeOfList - 1;
	    }
    void append(int data){
        if(isEmpty()){position = 0;}
        else if(isFull()){cout<<"Full list"<<endl;}
        else{position++;}
        nodeList[position].data = data;
        nodeList[position].index = position;
    }

    void insertData(int index, int data){
        if(isEmpty()){
            append(data);
        }else if(index < 0 || index > sizeOfList -1){
        cout<<"invalid index on list"<<endl;}
        else{
            nodeList[index].data = data;
        }
    }

    void removeData(int index){
        if(isEmpty()){
            cout<<"empty list"<<endl;
        }
        else if(index <0 || index > sizeOfList -1){
            cout<<"invalid index on list"<<endl;
        }
        else{
            for(int i=index; i<=position; i++){
                nodeList[i].data = nodeList[i+1].data;
                nodeList[i].index = nodeList[i+1].index;
            }
        }

    }

    void printList(){
        if(isEmpty()){
            cout<<"empty list"<<endl;
        }
        else{
            for(int i = 0; i <= position; i++){
                cout<<" "<<nodeList[i].data;
            }
        }
        cout<<endl;
    }

};

int main()
{
    List li(10);

    li.append(1);
    li.append(2);
    li.append(3);
    li.printList();
    li.insertData(1,22);
    li.printList();
    li.removeData(1);
    li.printList();
}
