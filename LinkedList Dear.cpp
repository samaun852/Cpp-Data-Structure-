#include<iostream>
#include<string.h>
using namespace std;
class Node
{
	public:
		int rollNumber;
		char name[20];
		Node *next;
};
class List
{
	Node *START;
	public:
		List();
		void addNode();
		bool Search(int rollNo, Node **current, Node **previous);
		bool listEmpty();
		bool delNode(int element);
		void traverse();
};
 List::List()
{
	START = NULL;
}


void List::addNode()
{
	int rollNo;
	char na[20];
	cout<<"\nEnter the roll number of student: ";
	cin>>rollNo;
	cout<<"\nEnter the name of the stuednt: ";
	cin>>na;
	Node *newnode=new Node;
	newnode->rollNumber=rollNo;
	strcpy(newnode->name,na);
	
	if(START == NULL || rollNo <= START -> rollNumber)
	{
		if((START !=NULL) && (rollNo == START ->rollNumber))
		{
			cout<<"\nDuplicate roll numbers not allowed\n";
			return ;
		}
	newnode->next=START;
	START=newnode;
	return ;	
	}
	 Node *previous, *current;
	 previous = START;
	 current = START;
	 while((current!=NULL) && (rollNo>=current->rollNumber))
	 {
	 	if(rollNo == current ->rollNumber)
	 	{
	 		cout<<"\nDuplicate number not allowed\n";
	 		return;
		 }
		 previous=current;
		 current=current->next;
	 }
	    newnode->next=current;
	    previous->next=newnode;
}
bool List :: listEmpty()
{
	if(START == NULL)
	   return true;
	else
	   return false;   
   }   
 bool List :: delNode(int rollNo)
 {
 	Node *current, *previous;
 	if(Search(rollNo,&previous,&current)==false)
 	    return false;
 	previous->next=current->next;
	 if(current==START)
	    START-START->next;
		delete current;
		return true;    
   }  
bool List :: Search(int rollNo, Node **previous, Node **current)
{
	*previous=START;
	*current=START;
	while((*current!=NULL)&&(rollNo!=(*current)->rollNumber))
	{
		*previous=*current;
		*current=(*current)->next;
	}
	return(*current !=NULL);
}  
void List::traverse()
{
	if(listEmpty())
	    cout<<"\nList in empty\n";
	else
	{
		cout<<endl<<"The record in the List are:"<<endl;
		Node *currentNode;
		for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)(
			cout<<currentNode->rollNumber<<" "<<currentNode->name<<"\n");
		   
		} 
		cout<<endl;   
 } 
 int main()
 {
 	List obj;
 	int rollNo;
 	char ch;
 	while(1)
 	{
 		cout<<"Main Menu";
 		cout<<endl<<"1. Add a record to the list"<<endl;
 		cout<<"2. Delete a record from the list"<<endl;
 		cout<<"3. view all the record in the list"<<endl;
 		cout<<"4. Search for a record in the list"<<endl;
 		cout<<"5. Exit"<<endl;
 		cout<<endl<<"Enter your choice (1-5): ";
 		cin>>ch;
 		switch(ch)
 		{
 			case '1':
 				    {
 				    	obj.addNode();
					 }
			   break;
			case '2':
			       {
			       	if(obj.listEmpty())
			       	{
			       		cout<<endl<<"List is Empty"<<endl;
			       		break;
					   }
			cout<<endl<<"\nEnter the roll number of the student whose record is to be deleted: ";
			cin>>rollNo;
			    if(obj.delNode(rollNo)==false)
				    cout<<endl<<"record not found"<<endl;
				else
				   cout<<endl<<"Record with roll number "<<rollNo<<"deleted "<<endl;			   
				   }  
				break;
			case '3':
			{
				obj.traverse();
			 }	
			 break;
			 case '4':
			   {
			   	if(obj.listEmpty()==true)
			   	{
			   		cout<<"\nList is empty\n";
			   		break;
				   }
				   Node *previous, *current;
				   cout<<endl<<"Enter the roll number of the student whose record is to be searcher:";
				   cin>>rollNo;
				   if(obj.Search(rollNo, &previous, &current)==false)
				   cout<<endl<<"Record not found"<<endl;
				   else
				   {
				   	cout<<endl<<"Record found"<<endl;
				   	cout<<"\nRoll number: "<<current->rollNumber;
				   	cout<<"\n\nName: "<<current->name;
				   	cout<<"\n";
				   }
				} 
				break;
				case '5':
				{
					return 0;
				} 
				break;
				defult:
				{
					cout<<"BU hao keyword."<<endl;
				}
				break;  		 
		 }
	 }
 } 