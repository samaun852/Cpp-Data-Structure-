#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
/// Sort arr[] of size n using Bubble Sort. 
void BubbleSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
{
		for (j = 0; j < n-i-1; ++j)
{
/// Comparing consecutive data and switching values if value at j > j+1.
	if (arr[j] > arr[j+1])
	{
	arr[j] = arr[j]+arr[j+1];
	arr[j+1] = arr[j]-arr[j + 1];
	arr[j] = arr[j]-arr[j + 1];
			}
		}
	/// Value at n-i-1 will be maximum of all the values below this index.
	}	
}
/// Swapping two values.
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 
/// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	/// Getting index of pivot.
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	/// Swapping value at high and at the index obtained.
	swap(&a[pivot], &a[index]);
 
	return index;
}
 
//// Random selection of pivot.
int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	/// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
/// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
/// Implementing QuickSort algorithm.
int QuickSort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
		/// Partitioning array using randomized pivot.
		pindex = RandomPivotPartition(a, low, high);
		/// Recursively implementing QuickSort.
		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	
}

int search(int a[],int n,int e)
{
    int f,l,m;
    f=0;
    l=n-1;
    
    while(f<=l)
    {
        m=(f+l)/2;
        if(e==a[m])
            return(m);
        else
            if(e>a[m])
                f=m+1;
            else
                l=m-1;
    }
    
    return -1;
}

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
char ex;	
	 do{	  
	   char n;
	    cout<<"==========================="<<endl;
		cout<<"Enter your choice!! From 1-6:"<<endl;
		cout<<"Main Menu"<<endl;
		cout<<"1.Bubble Sort Algorithm"<<endl;
		cout<<"2.Quick Sort Algorithm"<<endl;
		cout<<"3.Linear Search"<<endl;
		cout<<"4.Binary Search"<<endl;
		cout<<"5.Singly Linked List"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"==========================="<<endl;
	    cin>>n;      	 
	   switch(n)
	{
			case '1':
			{
			cout<<"This is Bubble Sort Algorithm"<<endl;
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	BubbleSort(arr, n); 
                             	// Display the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];			
			}
				break;			
	case '2':
			{
			cout<<"This is Quick Sort Algorithm"<<endl;
			int n, i;
	      cout<<"\nEnter the number of data element to be sorted: ";
     	cin>>n;
       	int arr[n];
	for(i = 0; i < n; i++)	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
	QuickSort(arr, 0, n-1);
                                    	// Printing the sorted data.
        	cout<<"\nSorted Data ";
	        for (i = 0; i < n; i++)
        	cout<<"->"<<arr[i];
		}			
		break;			
	case '3':
			{				
	cout<<"This is Linear Search Algorithm"<<endl;
	 int a[20],n,x,i,flag=0;
    cout<<"How many elements?";
    cin>>n;
    cout<<"\nEnter elements of the array\n";   
    for(i=0;i<n;++i)
        cin>>a[i];   
    cout<<"\nEnter element to search:";
    cin>>x;  
    for(i=0;i<n;++i)
    {
        if(a[i]==x)
        {
            flag=1;
            break;
        }
    }
    
        if(flag)
             cout<<"\nElement is found at position "<<i+1;
       else
            cout<<"\nElement not found";
			}			
			break;			
	case '4':
			{
	cout<<"This is Binary Search Algorithm"<<endl;
	int search(int [],int,int);
    int n,i,a[100],e,res;
    cout<<"How Many Elements:";
    cin>>n;
    cout<<"\nEnter Elements of Array in Ascending order\n";
    
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    
    cout<<"\nEnter element to search:";
    cin>>e;
    
    res=search(a,n,e);
    
    if(res!=-1)
        cout<<"\nElement found at position "<<res+1;
    else
        cout<<"\nElement is not found....!!!";
			}
			
			break;
			case '5':
			{
				cout<<"This is Singly Linked List "<<endl;
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
		 }
	 }
			}		
			break;        //case 5 end here
		case '6':
			{
				return 0;
			}		
			default:
				{
			cout<<"This is not right keyword.. Please Select From 1-5:"<<endl;
	         	}
			break;	
	    }
	cout<<"\n\n\nPlease Press any key to go 'Main Menu: '";
    cin>>ex;
  }while(ex>'a' ||ex<'z' && ex>'A' ||ex<'Z' );
	
}
