#include<iostream>
using namespace std;
class queue
{
    int front,rear;
    int *queue1;
    int qsize;
public:
    queue(int size);
    void isfull();
    void isempty();
    void enqueue(int a);
    int dequeue();
    int peak();
    void display();
};
queue :: queue(int size)
{
    qsize=size;
    queue1=new int[qsize];
    front=rear=-1;
}
void queue :: isempty()
{
    if(front == -1 && rear==-1)
        cout<<"Queue is empty\n";
    else
        cout<<"Queue is not empty\n";
}
void queue :: isfull()
{
    if (rear == qsize-1)
        cout<<"Queue is full\n";
    else
        cout<<"Queue is not full\n";
}
void queue :: enqueue(int a)
{
    if(rear == qsize-1)
        cout<<"Queue is full"<<endl;
    else if(front == -1)
        front=0;
    rear=(rear+1);
    queue1[rear]=a;
}
int queue :: dequeue()
{
    if(front==-1 || front>rear)
        cout<<"Queue is empty\n";
    else
    {
        cout<<"Deleted element "<<queue1[front]<<endl;
        front++;
    }
}
void queue :: display()
{
    if(front==-1)
        cout<<"Queue is empty"<<endl;
    else
    {
        for(int i=front;i<=rear;i++)
            cout<<queue1[i]<<"\n";
    }
}
int main()
{
    queue q(6);
    int ch,n;
    cout<<"1) isfull\n";
    cout<<"2) isempty\n";
    cout<<"3) insertion\n";
    cout<<"4) deletion\n";
    cout<<"5) display\n";
    cout<<"6) Exit\n";
    do
    {
        cout<<"Enter your choice : ";/* code */
        cin>>ch;
        switch(ch)
        {
            case 1:q.isfull();
                break;
            case 2:q.isempty();
                break;
            case 3:cout<<"Enter a number : ";
                cin>>n;
                q.enqueue(n);
                break;
            case 4:q.dequeue();
                break;
            case 5:q.display();
                break;
            case 6:cout<<"Exit\n";
                break;
            default:cout<<"Invalid";
                break;
        }
    }
     while (ch<7);
     return 0;
}