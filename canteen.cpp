#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;
float bill=0;
float timetaken=0;
int quantity=0;
void user();//CLASS FOR MANAGER
class list
{
	public:
	int size;
	char item[50];
	float price;
	char name[30];
	int room, acc;
	long int mobile;
	float time;
    void acceptitem()
	{
		
		
cout<<endl<<"************************************";
	 	cout<<endl<<"ENTER ITEM TO BE ADDED TO MENU:";
	 	cin>>item;
	 	fflush(stdin);
	 	cout<<endl<<"PRICE:";
	 	cin>>price;
	 	fflush(stdin);
	 	cout<<endl<<"ENTER TIME TO PREPARE:";
	 	cin>>time;
	 	fflush(stdin);
	 	
	}
	void display()
	{
	    cout<<strupr(item)<<"\t   Rs."<<price<<endl;	
    }	
};
list obj;
//FXN TO ADD ITEM TO MENU
void additem()
{
	fstream wr;
	wr.open("G:\\items.txt",ios::app);
    obj.acceptitem();
    wr.write((char*)&obj,sizeof(obj));
    wr.close();
}
//FXN TO SEE MENU
void seeitem()
{
	fstream rd;
	rd.open("G:\\items.txt",ios::in);
	rd.seekg(0,ios::end);
	int size=rd.tellg();
	int n=size/sizeof(obj);
	rd.seekg(0,ios::beg);
	cout<<endl<<"Sno.\t  ITEM \t  PRICE";
	
	
	cout<<endl<<"************************************";
	for(int i=1;i<=n;i++)
	{
		rd.read((char*)&obj,sizeof(obj));
		cout<<endl<<i<<"\t";
		obj.display();
	}
	
}
//FXN TO UPDATE MENU
void updatemenu()
{
	fstream rd,wr;
	rd.open("G:\\items.txt",ios::in);
	wr.open("G:\\temp.txt",ios::app);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
	char citem[50];
	cout<<endl<<"******************************************";
	
	
	cout<<endl<<"ENTER ITEM TO BE UPDATED:";
	cin>>citem;
	for(int i=1;i<=size;i++)
	{
	rd.read((char*)&obj,sizeof(obj));
		if(stricmp(obj.item,citem)==0)
		{
		obj.acceptitem();
		cout<<endl<<"UPDATION COMPLETE...........";
		wr.write((char*)&obj,sizeof(obj));
		}
		else
		{
		wr.write((char*)&obj,sizeof(obj));
		}
    }
    
	rd.close();
	wr.close();
	remove("G:\\items.txt");
	rename("G:\\temp.txt","G:\\items.txt");
}
//FXN TO REMOVE ITEMS FROM MENU
void removeitem()
{
	fstream rd,wr;
	rd.open("G:\\items.txt",ios::in);
	wr.open("G:\\temp.txt",ios::out);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
	char citem[50];
	
	
	cout<<endl<<"************************************";
	cout<<endl<<"CREATE YOUR ACCOUNT HERE";
	cout<<endl<<"ENTER ITEM TO BE DELETED:";
	cin>>citem;
    for(int i=1;i<=size;i++)
	{
    	rd.read((char*)&obj,sizeof(obj));
	 	if(strcmpi(obj.item,citem)==0)
	 	{
	 		cout<<endl<<"ITEM DELETED.....";
	 	}
		 else
	 	{  
		wr.write((char*)&obj,sizeof(obj));
     	}
	}
	
	rd.close();
	wr.close();
	remove("G:\\items.txt");
	rename("G:\\temp.txt","G:\\items.txt");
}

//CLASS FOR USER 
class order
{   
public:
	 int ans;
	 char name[50],password[50];
	 int roll,room,acc;
	 long long int ph;
	 void createaccount()
	 {
	 	int p=0;
	 	srand(time(NULL));
		acc=rand()%1000+1000;
		
		
		
		cout<<endl<<"************************************";
	
	 	cout<<endl<<"ENTER YOUR NAME:";
	 	cin>>name;
	 	fflush(stdin);
		for(int b=0;b<strlen(name);b++)
		{
			if(isdigit(name[b])==true)
			{
			 p=1;
			}
		}
		if(p==1)
		{
			cout<<endl<<"INVALID NAME";
			system("pause>nul");
			system("cls");
			user();
		}
		else
		{
		cout<<endl<<"ENTER YOUR ROLL NO.:";
	 	cin>>roll;
	 	fflush(stdin);
	   	cout<<endl<<"ENTER YOUR ROOM NO.:";
	 	cin>>room;
	 	fflush(stdin);
		cout<<endl<<"ENTER YOUR  PHONE NO.:";
	 	cin>>ph;
	 	fflush(stdin);
	 	cout<<endl<<"ENTER YOUR PASSWORD:";
	 	cin>>password;
	 	fflush(stdin);
	      }

    }
        
}; 
order obj2;

class book
{
	public:
		   char i[50];
		   float p;
		   int q;
};
book obj3;
//FXN TO DISPLAY MENU TO USER
void displayitems()
{
	fstream rd;
	rd.open("G:\\items.txt",ios::in);
	rd.seekg(0,ios::end);
	int size=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	cout<<endl<<"Sr."<<"\t"<<setw(10)<<"ITEM"<<setw(10)<<"PRICE";
	
	cout<<endl<<"************************************";
	for(int i=1;i<=size;i++)
	{
	rd.read((char*)&obj,sizeof(obj));
	cout<<endl<<i<<"\t"<<setw(10)<<strupr(obj.item)<<setw(10)<<obj.price;	
	}

	
	rd.close();
}
//FXN TO SELECT ITEMS
void select()
{   
    
    int num;
	fstream rd,wr;
	rd.open("G:\\items.txt",ios::in);
	wr.open("G:\\list.txt",ios::app);
	rd.seekg(0,ios::end);
	int size2=rd.tellg()/sizeof(obj);
	rd.seekg(0,ios::beg);
	cout<<endl<<"****************************************";
	
	cout<<endl<<"ENTER ITEM NO.:";
	cin>>num;
	fflush(stdin);
	for(int a=1;a<=size2;a++)
	{
	rd.read((char*)&obj,sizeof(obj));
	if(a==num)
	{
	strcpy(obj3.i,obj.item);
	cout<<endl<<"ENTER QUANTITY:";
	cin>>quantity;
	fflush(stdin);
	obj3.q=quantity;
    bill= bill+obj.price*quantity;
    obj3.p=obj.price;
    wr.write((char*)&obj3,sizeof(obj3));
	timetaken=timetaken+obj.time;
    cout<<"YOU HAVE TO PAY Rs."<<bill;
    
  }
	rd.close();
	wr.close();
}
}
//FXN FOR USER TO SIGNUP
void signup()
{   //system("pause>nul");
	system("cls");
    char password2[50];
    cout<<endl<<"*****************************************";
	cout<<endl<<"CREATE YOUR ACCOUNT HERE";
	fstream wr;
	wr.open("G:\\accountdetail.txt",ios::app);
	obj2.createaccount();
	cout<<endl<<"RE-ENTER PASSWORD:";
	cin>>password2;
	fflush(stdin);
	if(strcmpi(password2,obj2.password)==0)
	{
	
	wr.write((char*)&obj2,sizeof (obj2));
	cout<<endl<<"YOUR ACCOUNT NUMBER :"<<obj2.acc;
	cout<<endl<<"YOUR ACCOUNT IS CREATED......";
    }
    else
    {
    	cout<<endl<<"PASSWORD DIDN'T MATCH......";
    }
	wr.close();
}
//FXN TO SIGN IN
void signin()
{				int y=1;
				
				fstream rd2,wr;
				wr.open("G:\\orders.txt",ios::app);
				rd2.open("G:\\accountdetail.txt",ios::in);
			    
			
				rd2.seekg(0,ios::end);
				int size2=rd2.tellg()/sizeof(obj2);
				rd2.seekg(0,ios::beg);
				char password[50];
				int acc;
				int sel=0;
				cout<<endl<<"***************************************";
				cout<<endl<<"ENTER YOUR ACCOUNT NO.:";
				cin>>acc;
				fflush(stdin);
				cout<<"ENTER YOUR PASSWORD:";
				cin>>password;
				fflush(stdin);
				for(int i=1;i<=size2;i++)
				{
				 
				 rd2.read((char*)&obj2,sizeof(obj2));
				 
				 if(strcmpi(password,obj2.password)==0 && acc==obj2.acc)
				 {
				 	    y=2;
				 	    cout<<endl<<"YOU ARE LOGGED IN.............";
				 		system("pause>nul");
				 		system("cls");
				 		int e =0;
 				    	while(e==0)
 						{	
 					displayitems();
					char ch;
					    
					    cout<<endl<<"*************************************";
					cout<<endl<<"ENTER 1 TO SELECT ITEMS";
					cout<<endl<<"ENTER 2 TO SEE YOUR BILL";
					cout<<endl<<"ENTER 3 TO SEE YOUR ACCOUNT DETAILS";
 					cout<<endl<<"ENTER 4 TO EXIT";
 					cout<<endl<<"ENTER YOUR CHOICE:";
 					cin>>ch;
 				
 					fflush(stdin);
 					
 					switch(ch)
 					{
 					
 					case '1':
					        
					        sel++;
					 		select(); 
					 		
 							break;
 					case '2':  
					        char yn;  
					        
					        cout<<endl<<"**********************************";
	
 	            		    cout<<endl<<"NAME:"<<strupr(obj2.name);
 	            		    cout<<endl<<"ROOM NO.:"<<obj2.room;
 	            		    cout<<endl<<"BILL: Rs."<<bill;
 	            		    if (bill>0)
 	            		    {
							 
 	            		    cout<<endl<<"ENTER Y TO BOOK ORDER";
 	            		    cout<<endl<<"ENTER N TO DISCARD ORDER";
 	            		    cout<<endl<<"ENTER YOUR CHOICE:";
 	            		    cin>>yn;
 	            		    fflush(stdin);
 	            		    if(yn=='Y'||yn=='y')
 	            		    {
 	            		    	cout<<endl<<"ORDER BOOKED......";
 	            		    	cout<<endl<<"YOUR ORDER WILL BE READY IN "<<(int)timetaken/sel<<"mins";
 	            		    	wr.write((char*)&obj2,sizeof(obj2));
 	            		        bill=0;
 	            		        timetaken=0;
 	            		        sel=0;
 	            		        
 	            		        
							}
							else if(yn=='N'||yn=='n')
							{
								cout<<endl<<"ORDER NOT BOOKED.......";
								bill=0;
								timetaken=0;
								sel=0;
								
								
								
							}
							
							else
							{
								cout<<endl<<"WRONG CHOICE";
							}
						
						}
 	            		    break;
 	            	case '3':
					        
							cout<<endl<<"*************************************";
	   
 	            		    cout<<endl<<"NAME:"<<strupr(obj2.name);
 	            		    cout<<endl<<"ROOM NO.:"<<obj2.room;
 	            		    cout<<endl<<"ROLL NO.:"<<obj2.roll;
 	            		    cout<<endl<<"PHONE NO.:"<<obj2.ph;
 	            		    	    
 	            		    
 	            		    break;
 		            case '4':    
					    	e=1;
 		       			    break;
 			     	default:
 		        		    cout<<endl<<"WRONG INPUT";
 		        	    	break;
 				    }
 				    system("pause>nul");
 				    system("cls");
 				    }	
 				    
		          }
		           
		}
		if(y==1)
		{
			cout<<endl<<"WRONG ACCOUNT NO. OR PASSWORD";
		}
 rd2.close();
 wr.close();
}
void booked()
{
	fstream rd1,rd2;
	float pay=0;
	rd1.open("G:\\orders.txt",ios::in);
	rd2.open("G:\\list.txt",ios::in);
	rd1.seekg(0,ios::end);
	int size1=rd1.tellg()/sizeof(obj2);
	rd1.seekg(0,ios::beg);
	rd2.seekg(0,ios::end);
	int size2=rd2.tellg()/sizeof(obj3);
	rd2.seekg(0,ios::beg);
	
	
	for(int i=1;i<=size1;i++)
	{    
	    pay=0;
	    
	    cout<<endl<<"************************************";
		cout<<endl<<i<<". NAME:"<<obj2.name;
		cout<<endl<<"ROOM NO.:"<<obj2.room;
		cout<<endl<<"---------------------------------------";
		cout<<endl<<"Sno.\t ITEM \t PRICE OF EACH \t QUANTITY";
		cout<<endl<<"---------------------------------------";
		for(int i=1;i<=size2;i++)
		{
			cout<<endl<<i<<" \t "<<obj3.i<<" \t "<<obj3.p<<"\t\t"<<obj3.q;
			pay=pay+(obj3.p*obj3.q);
		}
		cout<<endl<<"---------------------------------------";
	    cout<<endl<<"BILL: Rs."<<pay;
	
	}
}

void user()
{
 int p=0;
 char choice;
 while(p==0)
 {
 	cout<<endl<<"************************************";
 	cout<<endl<<"*ENTER 1 TO SIGN UP";
 	cout<<endl<<"*ENTER 2 TO SIGN IN";
 	cout<<endl<<"*ENTER 3 TO EXIT";
 	cout<<endl<<"*ENTER YOUR CHOICE:";
 	cin>>choice;
 	fflush(stdin);
 	switch(choice)
 	{
	 case '1':
	 			signup();
	 			break;
	 case '2':
	 	
	 			signin();
	 			break;
	 case '3':
	 			p=1;
	 			break;
	 default:
	 			cout<<endl<<"WRONG CHOICE";
	 			break;			
	}
	system("pause>cls");
	system("cls");
 }
 
}
void manager()
{
 int e =0;
 while(e==0)
{
 	char ch;
 	
 	cout<<endl<<"************************************";
	cout<<endl<<"* ENTER 1 TO SEE MENU";
 	cout<<endl<<"* ENTER 2 TO ADD ITEM";
    cout<<endl<<"* ENTER 3 TO UPDATE TO MENU";
    cout<<endl<<"* ENTER 4 TO REMOVE ITEM";
	cout<<endl<<"* ENTER 5 TO SEE ORDERS";
    cout<<endl<<"* ENTER 6 TO EXIT";
 	cout<<endl<<"ENTER YOUR CHOICE:";
	cin>>ch;
 	fflush(stdin);
	switch(ch)
	{
 		case '1':
 		    		seeitem();
 		     		break;
 		case '2':
 		    		additem();
 		    	    break;
 		case '3':
	        		updatemenu();
 					break;
 		case '4':
 		            removeitem();
 		            break;
 		case '5':
 		            
					 booked();
 		            break;
 	    case '6':     
		 			e=1;
 		            break;
 	    default:
 		            cout<<endl<<"WRONG INPUT";
 		            break;
        }
        system("pause>nul");
        system("cls");
    }	
}
main()
{ 
int a=1;
 char id[50];
 while(a==1)
 {
 	char choice;
 	cout<<endl<<"============================";
 	cout<<endl<<"* ENTER A FOR USER";
    cout<<endl<<"* ENTER B FOR MANAGER";
 	cout<<endl<<"* ENTER C TO EXIT";
 	cout<<endl<<"============================";
 	cout<<endl<<"ENTER YOUR CHOICE:";
    cin>>choice;
    fflush(stdin);
    switch(choice)
    {
    	case 'A':
    	case 'a':
    		     user();
    		     break;
    	case 'B':
    	case 'b':
    			cout<<endl<<"ENTER YOUR ID :";
    			cin>>id;
    			if(strcmpi(id,"xx30xx30")==0)
    			{
				manager();
			    }
			    else
			    {
			    	cout<<endl<<"WRONG INPUT";
				}
                break;
    	case'C':
		case'c': 
			    a=2;
			    break;
		default:
 		        cout<<endl<<"WRONG INPUT";
 		        break;      
    		
	}
   system("pause>nul");
   system("cls");
 }
}
