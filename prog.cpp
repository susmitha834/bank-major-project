#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<fstream>
using namespace std;
class bank_account
{
	public:
	char name[30];
	int acc_num;
	string acc_type;
	char address[40];
	int balance;
    //displaying the details of the user (acc_number,name,balance amount)
	public:
		bank_account()
        {
			strcpy(name," ");
            acc_num=0;
            acc_type=" ";
            balance=0;
            strcpy(address," ");

		}
      //explicit declaration
		void acc_create(char s[],int n,string t,int b, char ads[])
        {
			strcpy(name,s);
			acc_num=n;
			acc_type=t;
			balance=b;
			strcpy(address,ads);
			store_in_file();
			
		}
		void store_in_file(){
        	ofstream outFile;
        	outFile.open("input.txt",ios::in|ios::app);
        	outFile.write(reinterpret_cast<char *> (this), sizeof(bank_account));
        	outFile.close();
		}
      //function calling for deposit,withdraw,disp_details
		void deposit(int n)
        {
			balance+=n;
		}
		void withdraw(int n)
        {
			if(balance<n)
         {
			cout<<"low balance   your account balance is: "<<balance<<endl;
		 }
            else
         {
			balance-=n;
		 }
		}
		void disp_details()
       {
			cout<<"Name: "<<name<<endl;
			cout<<"Account type: "<<acc_type<<endl;
			cout<<"Account number: "<<acc_num<<endl;
			cout<<"Account Balance: "<<balance<<endl;
			cout<<"Address: "<<address<<endl;
	    }
	};

int main()
{
  int m=10,flag=0;
  bank_account acc[m];
  char name[30],ads[40];
  string type;
  int balance,num,ac_no;
  int n=1,a,amt=0,i=-1,j,k,month,l,si;
  while(n!=0)
  {
	cout<<"\n................................"<<endl;
    //input from user of his choice
	cout<<"\nEnter 1 to new create account "<<"\n"<<"Enter 2 to deposit amount in this account\nEnter 3 to withdraw amount in this account\nEnter 4 to display details of this account \nEnter 5 to select the bank account with account no.\nEnter 6 to display the account number of the last entry\nenter 7 "<<endl;
	cout<<"enter 7 to check acc exits or not \n enter 8 retrieve name enter 9 retrieve  account numberretrieve address";
	cin>>a;
	cout<<"................................"<<endl;
	switch(a)
	{
			//taking details from user 
    case 1:
      	 i++;
         cout<<"Enter following details to create account"<<endl;
         cout<<"enter your name: "<<endl;
         cin.ignore();
         cin.getline(name,30);
         cout<<"enter account number: "<<endl;
         cin>>num;
         cout<<"enter account type(current/savings): "<<endl;
         cin>>type;
         cout<<"enter balance amount: "<<endl;
         cin>>balance;
         if(balance<0)
		   {
              cout<<"your balance cannot be negative.Please check\nenter again:"<<endl;
              cin>>balance;
           }
         cout<<"enter address of the account holder: "<<endl;
         cin.ignore();
         cin.getline(ads,40);
         //for bank_account class object is created and aruguements are passed into the class
         acc[i].acc_create(name,num,type,balance,ads);
         break;
         //money is deposited for the acc_num given by user
	case 2:
		flag=0;
		cout<<"Enter the account number:  "<<endl;
		cin>>ac_no;
		for( j=0;j<=i;j++)
		{
			if(acc[j].acc_num==ac_no)
			{
			cout<<"Enter amount to be Deposited : "<<endl;
			cin>>amt;
			flag=1;
			acc[j].deposit(amt);
			break;
			}
		}
			if(flag==1)
			{
			  	cout<<"money deposited succesfully...."<<endl;
			}
			else
			{
			  	cout<<"Account with this account no. does not exist"<<endl;
			}
			break;
				//money is withdrawn from the account
	case 3:
		flag=0;
		cout<<"Enter the account number:  "<<endl;
		cin>>ac_no;
		cout<<"did you withdraw your amount 2 month back?enter 1 for yes/0 for no"<<endl;
          cin>>k;
          if(k==0){
         cout<<"for how many months you didnt withdraw amount"<<endl;
        cin>>month;
        if(month>=2)
		{
        cout<<"**interest**";
        cout<<"please enter your rate of interest";
        cin>>l;
        si=(balance*l/100*month)/100*12;
        }
          else
		  {
            cout<<"pls check your month";
          }
          }
          
         else
          {
            //exit(0);
            return 0;
          }
         
         for(j=0;j<=i;j++)
		{
			if(acc[j].acc_num==ac_no)
			{
				cout<<"Enter amount to be Withdrawn: "<<endl;
				cin>>amt;
				flag=1;
				acc[j].withdraw(amt);
				break;
			}
		}
			if(flag==1)
			{
			  	cout<<"money withdrawn succesfully...."<<endl;
			}
			else
			{
			  	cout<<"Account with this account no. does not exist"<<endl;
			}
			break;
			
			
			
			
			
		case 4:		//details are displayed for all the account_holder
			if(i==-1)
			{
			   	cout<<"No accounts are created till date: "<<endl;
			}
			else
			{
			   	cout<<"\n................................"<<endl;
				cout<<"Displaying the details of all accounts......"<<endl;
			   	for(int j=0;j<=i;j++)
				   {
			   		acc[j].disp_details();
			   		cout<<".................."<<endl;
				   }	
			}
			break;
				//
	case 5:
		flag=0;
			if(i==-1)
			{
			   	cout<<"No accounts are created till date: "<<endl;
			}
			else
			{
			    cout<<"Enter the account number:  "<<endl;
			    cin>>ac_no;
			for(j=0;j<=i;j++)
			{
				if(acc[j].acc_num==ac_no)
				{
					i=j;
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"user interface has changed ton this account: "<<endl;
			}
			else
			{
				cout<<"please enter valid account number "<<endl;
			}
		    }
			break;
			//account num of last entry
    case 6:
            cout<<"account no. of last entry is "<<acc[i].acc_num<<endl;
            break;
            //checks whether acc exists or not
    case 7:
        	cout<<"Enter the account number:  "<<endl;
			cin>>ac_no;
			flag=0;
			for(j=0;j<=i;j++)
			{
				if(acc[j].acc_num==ac_no)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout<<"This account exist "<<endl;
			}
			else
			{
				cout<<"This account does not exist "<<endl;
			}
			break;
	
			//retrieve the name of the account holder
	case 8:
			cout<<"Enter the account number:  "<<endl;
			cin>>ac_no;
			flag=0;
			for(j=0;j<=i;j++)
			{
				if(acc[j].acc_num==ac_no)
				{
					flag=1;
					cout<<"The name of the account holder is "<<acc[j].name<<endl;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"The account with this account no. does not exist"<<endl;
			}
			break;
			//retrieve the address of the account holder
	case 9:
			cout<<"Enter the account number:  "<<endl;
			cin>>ac_no;
			flag=0;
			for(j=0;j<=i;j++)
			{
				if(acc[j].acc_num==ac_no)
				{
					flag=1;
					cout<<"The address of the account holder is "<<acc[j].address<<endl;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"The account with this account no. does not exist"<<endl;
			}
			break;
			//retrieve the acc balance of the account holder
	case 10:
			cout<<"Enter the account number:  "<<endl;
			cin>>ac_no;
			flag=0;
			for(j=0;j<=i;j++)
			{
				if(acc[j].acc_num==ac_no)
				{
					flag=1;
					cout<<"The account balance of the account holder is "<<acc[j].balance<<endl;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"The account with this account no. does not exist"<<endl;
			}
			break;
		}
	}
}




