//Write a menu driven program in C++ to implement a circular Queue.
#include<iostream.h>
#include<conio.h>
#include<process.h>

//PROTOTYPES
int Insert_in_CQ(int CQ[], int ele);
void Display(int CQ[], int front, int rear);
int Delete_in_CQ(int CQ[]);

//GLOBAL VARIABLES
const int size = 10;
int CQ[size], front =-1, rear=-1;

int main()
{
	int ITEM, result, ch;
	do
	{
		cout<<"\n\t\tCircular Queue : \n[1]Insert Element\n[2]Display Queue\n[3]Delete Elementn\n[4]Exit\n\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Item to be inserted into Queue : ";
				cin>>ITEM;
				result=Insert_in_CQ(CQ,ITEM);
				if(result==-1)
					cout<<"\nOVERFLOW";
				else
					Display(CQ,front,rear);
				break;
			case 2:
				Display(CQ,front,rear);
				break;
			case 3:
				result=Delete_in_CQ(CQ);
				if(result==-1)
					cout<<"\nUNDERFLOW";
				else
					Display(CQ,front,rear);
				break;
			case 4:
				exit(0);
			default:
				cout<<"\nEnter a Valid choice";
		}
	}while(ch!=4);
	return 0;
}

int Insert_in_CQ(int CQ[], int element)
{
	if((front==0&&rear==size-1)||(front==rear+1))
		return -1;
	else if(rear==-1)
		front=rear=0;
	else if(rear==size-1)
		rear=0;
	else
		rear++;
	CQ[rear]=element;
	return 0;
}
void Display(int CQ[], int front, int rear)
{
	int i=0;
	cout<<"\n Circular Queue is : \n(Front shown as '>>>' and Rear is shown as '<<<' and free space as '_')\n";
	if(front==-1)
		return;
	if(rear>=front)
	{
		for(i=0;i<front;i++)
			cout<<" _ ";

		cout<<">>>";

		for(i=front;i<rear;i++)
			cout<<CQ[i]<<" <- ";
		cout<<CQ[rear]<<"<<<"<<endl;
	}
	else
	{
		for(i=0;i<rear;i++)
			cout<<CQ[i]<<" <- ";
		for(i++;i<front;i++)
			cout<<" _ ";
		cout<<">>>";
		for(i=front;i<size;i++)
			cout<<CQ[i]<<" <- ";
		cout<<"\t...wrap around...";
	}
}
int Delete_in_CQ(int CQ[])
{
	int ret;
	if(front==1)
		return -1;
	else
	{
		ret=CQ[front];
		if(front==rear)
			front=rear=-1;
		else if(front==size-1)
			front=0;
		else
			front++;
	}
	return ret;
}
