// create account, deposit, withdraw, balance enquiry, all ac holder list, close acc, exit
    // int acc_no;
    // char name[50];
    // int deposit;
    // char type;
    // bool ans;


#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<iomanip>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Class
class Bank {
    int accNo = (rand()%10)+1;
    float deposit ;
    float totaldeposit;
    int initialDep;     // starting deposit balance
    char accType;
    char name[50];
    int getAccNo;       // for getting account no. info from user
    int withdrawBal;
    int otp;
   int getotp;
   int reciept_no = (rand()%799)+1;
   int tenure;
    int rI = 5 ;
    float fdAmt; 
   
   int get_otp(){
     int otp = (rand()%10000)+1;
      return otp; 
   }
   bool password(){
         termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    
    char s[50];
    cin.getline(s,50 );
     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
     
     char pass[50] = "admin@123";
    int compare = strcmp(pass,s);
    if(compare==0){
        return true;
    }else{
        return false;
    }
    
    }

    
   
    public:
    
    void createAcc();   // Creating account
    void depositAmt(int);  // deposit's
    void withdrawAmt(int); // Withdrawl
    void display_account();  //display account details
   void updateaccount();  //update account
    void report() ;  //report
  friend  void feedback();    // Close accountt
    int returnaccno() const
{
	return accNo;
}
char returntype() const
{
	return accType;
}
float returndeposit() const
{
	return totaldeposit;
}
int returnfd_recieptno() const
{
    return reciept_no;
}
 void createFd(int);
    void checkFd();

   
};

// Creating Bank Account
void Bank::createAcc(){
    

    cout << "Your Account number: " << accNo << "\n" ;
   
    cout << "Enter account holder's name: ";
    cin.ignore();
    cin.getline(name,50);
   
    cout << "Enter type of Account (C/S): ";
   
    cin >> accType;
   
    if(accType == 'C' || accType == 'c'){
        cout << "Deposit a initial balance of 1000rs: ";
        cin.ignore();
        cin >> initialDep;
       
        if(initialDep < 1000){
            cout << "Initial Deposit requirement not satisfied!, try again";
            createAcc();
        }
       
    }
   
    else{
        cout << "Deposit a initial balance of 500: ";
        cin.ignore();
        cin >> initialDep;
        if(initialDep < 500){
            cout << "Initial Deposit requirement not satisfied!, try again";
            createAcc();
        }
    }
   
    cout << "Account was Successfully Created! \n";
    cout << "Initial Account Balance : " << initialDep << "\n \n";
    cout<<"There are no charges on first deposit. ";
   totaldeposit = initialDep;
   
   
}
void Bank::updateaccount(){
    cout<<"\nUpdating Bank Account Name: ";
    int otp1 = get_otp();
    cout<<"Enter the otp displayed here:"<<otp1<<endl;
    cin>>getotp;

    if(getotp == otp1){
    cin.ignore();
    cout<<"Updating name of the account user";
    cin.getline(name,50);
    cout<<"Updating Type of Account: ";
    cin>>accType;
     cout<<"Enter the new amount of balance: ";
      cin>>totaldeposit;
    }
    else{
     cout<<"You entered the wrong otp. please update details again . ";
    updateaccount();
   
    }

}

void Bank::display_account() {
   
   int otp2 = get_otp();

   cout<<"Enter the otp given : "<<otp2<<endl;
   cin>>getotp;
   if(getotp==otp2){

    cout<<"Your bank account no : ";
    cout<<accNo<<endl;
    cout<<"Bank account Name: ";
    cout<<name<<endl;
    cout<<"Type of account no : ";
    cout<<accType<<endl;
    cout<<"Balance : "<<totaldeposit<<endl;
   }
   else{
    cout<<"You entered the wrong otp . ";
    display_account();
   }

}
void Bank::report() 
{
   
   bool res = password();
   if(res==true){
	cout<<accNo<<setw(10)<<" "<<name<<setw(10)<<" "<<accType<<setw(6)<<totaldeposit<<endl;
   }else{
    report();
   }
}


// Depositing Amount
void Bank::depositAmt(int deposit){
   
   int otp3 = get_otp();
   cout<<"Enter the otp given : "<<otp3<<endl;
   cin>>getotp;
   if(getotp==otp3){
       totaldeposit+=deposit;
      totaldeposit -=20;
    cout << "Your Deposit's of Rs. " << deposit << " were successful! \n";
    cout <<" Rs 20  were taken as transaction charge";
    cout << "Total Balance = " << totaldeposit << "\n \n";
    
   }else{
    cout<<"You entered the wrong otp\n ";
    return;
   }

}

// Withdawing Amount
void Bank::withdrawAmt(int withdrawBal){
    int otp4 = get_otp();
    cout<<"Enter the otp given : "<<otp4<<endl;
   cin>>getotp;
   if(getotp==otp4){
   
    totaldeposit-=withdrawBal;
    totaldeposit -=20;
    cout << "Your withdrawl of Rs. " << withdrawBal << " was successful! \n";
    cout <<"Rs 20 were taken as transaction charge";
    cout << "Remaining Balance = " <<totaldeposit << "\n";
    
     cout<<"This account doesn't exist.\n";
   }else{

   }
   
}


// Feedback
void feedback(){
    
    char feedBackChoice;
   
    cout << "Would you like to give any feedback ? (Y/N): ";
    cin.ignore();
    cin >> feedBackChoice;
   
    char fdBack[100];
    if(feedBackChoice == 'Y' || feedBackChoice == 'y'){
        cout << "Enter your feedback: \n";
        cin >> fdBack;
       
        cout << "Thankyou for your feedBack, your account will be closed within 2-5 working days... \n";
    }
    else if(feedBackChoice == 'N' || feedBackChoice == 'n'){
        cout << "Thankyou, Your account will be closed within 2-5 working days... \n";
    return;
    }
   
   
}

void Bank::createFd(int fd_amt){


int otp5 = get_otp();
cout<<"Enter the otp displayed : "<<otp5;
cin>>getotp;
if(getotp == otp5){
    fdAmt = fd_amt;
        cout << "-------------------------------------------\n";
    
    cout << "Enter tenure(*in years) for FD : ";
    cin >> tenure;
    cout << "Your reciept number: " << reciept_no<< endl;
    cout << "-------------------------------------------\n";
    
    cout << "fd amount of " << fdAmt << " will be cut from your account soon...\n";
    // Sleep(2);
    totaldeposit-=fdAmt;
   
    cout << "Amount of " << fdAmt << " was successfully debited! \n";
    cout << "Remaining Balance = " <<totaldeposit << "\n";
    cout << "-------------------------------------------\n\n";
    
}
}
void Bank::checkFd(){
        cout << "-------------------------------------------\n";
        cout << "Welcome " << name << ", your FD status is...\n";
        cout << "Your invested amount : " << fdAmt << endl;
        cout << "Tenure : " << tenure << "years" << endl;
        cout << "Rate of Interest : " << rI << "%\n";
        float M = 0;
         M= fdAmt*( pow((1+rI/100) ,tenure)) - fdAmt;
      
        cout<<"\nAmount You will get at the end of tenure : "<<M;
        cout << "\n-------------------------------------------\n\n\n";
        
        
    
    // else{
    //     cout << "Invalid Reciept number...Try Again \n";
    //     checkFd();
    // }
}
//File Input and Output
void writebankaccount();
void display_sp(int);
void displayall();

void deletebankaccount(int);
void deposit_withdraw_fd(int, int);
void updateaccount(int);

void createFD(int);
void display_fd(int);


using namespace std;
int main(){
    int i;
    char c;
    int num;

    cout << "Welcome to the Bank Management System in C++ \n";
    cout << "- Developed by \n";
    cout << "FCOG21709 & FCOG21718 \n";
    cout << "---------------------------------------------\n";
   
   
   
    int Decision;       // Taking user's choice
   
   do{
        cout << "0-Display all acounts \n 1-Create account\n 2-Update Account \n 3-Display Account \n 4-Deposit Amount \n 5-Withdraw Amount \n ";
        cout<< " 6-Create Fixed Deposit \n 7-Check Fixed-Deposit \n 8-Close Account \n  9- Exit \n";
        cout << "Enter your choice: (0-9) : ";
        cin >> Decision;
       
        switch(Decision){
            case 0:
            cout<<"\nDisplaying all acounts . \n";
            cout<<"\nEnter the password: \n";
            displayall();
          
            break;
        case 1:
        
            cout << "Create Account \n";
            cout << "--------------\n";
           writebankaccount();
            break;
       
       case 2:
       
            cout << "-Update Account \n";
            cout << "--------------\n";
            cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
            updateaccount(num);
            break;
        case 3:
        
            cout << "Display account \n";
            cout << "---------------\n";
            cout<<"Enter the account no:";cin>>num;
            display_sp(num);
            break;
        case 4:
        
            cout << "Deposit Amount \n";
            cout << "---------------\n";
            cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			deposit_withdraw_fd(num, 1);
           break;

       
        case 5:
        
        cout << "Withdraw Amount \n";
            cout << "---------------\n";
            cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			deposit_withdraw_fd(num, 2);
			break;
            
        case 6: 
        cout<<"create FD\n";
        cout<<"-------------\n";
        cout<<"\n\nPlease enter the account no : "; cin>>num;
        deposit_withdraw_fd(num,3);
             break;

        case 7:

         cout<<"display FD\n";
        cout<<"------------\n";
        cout<<"\n\nPlease enter the account no : "; cin>>num;
        display_fd(num);
        break;
        

        case 8:
         cout << "close acc \n";
            cout << "---------------\n";
            feedback();
            cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			deletebankaccount(num);
          
        break;
       
        case 9:
        
            cout<<"Thanks for using bank management system";
            break;
        default:
            cout<<"Choose another option";
            break;
        }
       
     
    }while(Decision !=9);
   
   
   
 
   
    return 0;
}


//Creating Bank Account in File
 void writebankaccount(){
Bank account;

ofstream outFile;
outFile.open("bankdetails.dat",ios::binary|ios::app);
account.createAcc();
outFile.write(reinterpret_cast<char *>(&account),sizeof(Bank));
outFile.close();
 }


//Function to display account details
void display_sp(int n){
    Bank account;
    bool flag = false;
    ifstream inFile;
   
    inFile.open("bankdetails.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be opened. !! Press any key. ";
        return;
    }
    cout<<"\nBalance Details\n";
    while(inFile.read(reinterpret_cast<char *>(&account),sizeof(Bank)))
    {
        if(account.returnaccno()==n){
            account.display_account();
            flag = true;
        }
        
    }
    inFile.close();
    if(flag==false){
        cout<<"\nAccount No does not exist.";
    }

}

//Function to update details in file

void updateaccount(int n){
    bool found = false;
    Bank account;
    fstream File;
    File.open("bankdetails.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not open !! Press any key..";
        return;
    }
    while(!File.eof() && found == false){
        File.read(reinterpret_cast<char *>(&account),sizeof(Bank));
        if(account.returnaccno()==n)
        {
            account.display_account();
            cout<<"\n\nPlease enter the new details \n";
            account.updateaccount();
            int pos=(-1)*static_cast<int>(sizeof(account));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *>(&account),sizeof(Bank));
        cout<<"\n\nRecord Updated. ";
        found = true;
    }
    
    }
File.close();
if(found == false){
    cout<<"\n Record Not Found.";
}
}


//Deleting account by clearing all the data in that file and creating a new file with same name and rest of data
void deletebankaccount(int n){
    Bank account;
    ifstream inFile;
    ofstream outFile;
    inFile.open("bankdetails.dat",ios::binary);
    if(!inFile){
        cout<<"File could not open || \n";
        return;
    }
    outFile.open("Temp.dat",ios::binary);
    inFile.seekg(0,ios::beg);
    while(inFile.read(reinterpret_cast<char *>(&account),sizeof(Bank)))
    {
        if((account.returnaccno()!=n)){
            outFile.write(reinterpret_cast<char *>(&account),sizeof(Bank));
        }
    }

    inFile.close();
    outFile.close();
    remove("bankdetails.dat");
    rename("Temp.dat","bankdetails.dat");
    cout<<"\n\nRecord Deleted";
}

//Display all accounts 

void displayall(){
Bank account;
ifstream inFile;
inFile.open("bankdetails.dat",ios::binary);
if(!inFile){
    cout<<"File could not open ||\n";
    return;
}cout<<"\n\n\t\tBank_Account HOLDER LIST\n\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
while(inFile.read(reinterpret_cast<char *>(&account),sizeof(Bank)))
{
    
account.report();
}
inFile.close();


}

void deposit_withdraw_fd(int n,int option){
    int amount;
    bool found = false;
    Bank account;
    fstream File;
    File.open("bankdetails.dat",ios::binary|ios::in|ios::out);
    if(!File){
        cout<<"File could not be open !!\n";
		return;
    }
    	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&account), sizeof(Bank));
        if(account.returnaccno()==n)
        {
            account.display_account();
            if(option ==1)
            {
               cout<<"\n\t\tTo deposit the amount  \n";
				cout<<"\nPlease enter The amount to be deposited.\n";
                cin>>amount;
                account.depositAmt(amount);
            }
             if(option == 2){
                cout<<"\n\t\tTo withdraw amount ";
				cout<<"\nPlease enter the amount to be withdrawn";
				cin>>amount;
                int bal = account.returndeposit()-amount;
                if(bal<499){
                    cout<<"Insufficient balance;";
                }
                else{
                    account.withdrawAmt(amount);
                }
                }

            if(option==3){
                cout<<"\nEnter the amount for fixed deposit : \n";
                cin>>amount;
                int bal_ = account.returndeposit()-amount;
                if(bal_<1000){
                    cout<<"\nInsufficient balance to create  a FD \n";
                }
                else{
                account.createFd(amount);
                }
            }
                int pos=(-1)*static_cast<int>(sizeof(account));
                    File.seekp(pos,ios::cur);
                    File.write(reinterpret_cast<char *>(&account),sizeof(Bank));
                    cout<<"\nRecord Updated.";
                    found==true;

        }
        }
        File.close();
        if(found==false){
            cout<<"\n Record Not Found";
        }
    }




void display_fd(int n){
    Bank account;
    bool flag = false;
    ifstream inFile;
    inFile.open("bankdetails.dat",ios::binary);
    if(!inFile){
        cout<<"File could not be opened. !! Press any key. ";
        return;
    }
    cout<<"FD Details";
    while(inFile.read(reinterpret_cast<char *>(&account),sizeof(Bank))){
        if(account.returnaccno()==n){
            int reciept_no;
            cout<<"Enter your reciept no";
            cin>>reciept_no;
            if(reciept_no == account.returnfd_recieptno()){
            account.checkFd();
            flag= true;
            }else{
                cout<<"You entered the wrong reciept no . ";
                return;
            }
        }
    }
    inFile.close();
    if(flag == false){
        cout<<"\nFD does not exist. ";
    }
}
