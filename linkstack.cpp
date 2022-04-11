#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;
struct node* temp;

void Insert()
{
    int val;
    cout<<"INSER THE ELEMENT IN QUEUE : "<<endl;
    cin>>val;
    if(rear=NULL)
    {
        rear=(struct node*)malloc(sizeof(struct node));
        rear->next=NULL;
        rear->data=val;
        front=rear;
    }
    else
    {
    	temp=(struct node*)malloc(sizeof(struct node));
    	rear->next=temp;
    	temp->data=val;
    	temp->next=NULL;
    	rear=temp;
    }
}

void Delete()
{
	temp=front;
	if(front==NULL)
	{
		cout<<"UNDERFLOW"<<endl;
		return;
	}
	else
	{
		if(temp->next!=NULL)
		{
			temp=temp->next;
			cout<<"ELEMENT DELETE FROM QUEUE IS : "<<front->data<<endl;
			free(front);
			front=temp;
		}
		else
		{
			cout<<"ELEMENT DELETE FROM QUEUE IS : "<<front->data<<endl;
			free(front);
			front=NULL;
			rear=NULL;
		}
	}
}

void Display()
{
	temp=front;
	if ((front==NULL)&&(rear==NULL))
	{
		cout<<"QUEUE IS EMPTY"<<endl;
		return;
	}
	cout<<"QUEUE ELEMENTS ARE : ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	int choice;
	cout<<"1) INSERT ELEMENT TO QUEUE "<<endl;
	cout<<"2) DELETE ELEMENTS FROM QUEUE "<<endl;
	cout<<"3) DISPLAY ALL THE ELEMENT OF QUEUE "<<endl;
	cout<<"4) EXIT"<<endl;
	do
	{
		cout<<"ENTER YOUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
			case 1: Insert();
			break;
			case 2: Delete();
			break;
			case 3: Display();
			break;
			case 4: cout<<"EXIT"<<endl;
			break;
			default:cout<<"INVALID CHOICE !"<<endl;
		}
	}
	while(choice!=4);
	return 0;
}
