#include <iostream>
#include <cctype>

using namespace std;


    
     
      
class gym {
     char name[50];
    int b_c;
    int muscle;
    int weekday;
    int times;
    public:
     void choosemuscle();
    void week();
    
    void enterdetails();
   
    
    void bulk(){
    cout<<"Select the day of the week where you want to excercise\n Select from 1 - 7\n";
   
     week();

    

}
    void cut(){
    cout<<"Select the day of the week where you want to excercise\n Select from 1 - 7\n";
   
     week();
  
    

}

    void chest();
    void tricep();
    void back();
    void bicep();
    void abbs();
    void core();
    void legs();
    void shoulders();
    void foreams();
    
};

void gym::enterdetails(void){
    cout<<"Enter your name : ";
    cin.get(name,50);
    cout<<"\nChoose whether you wanna bulk or cut: \n Select 1 for bulk and 0 for cut\n";
    cin>>b_c;
    if(b_c==1){
       bulk();
    }else if (b_c == 0){
       cut();
    }else{
        enterdetails();
    }
    
    
}
void gym::choosemuscle(void){
    
    int chose;
        cout<<"Muscles to train: ";
        cout<<"\n\n\t01. CHEST";
		cout<<"\n\n\t02. BACK";
		cout<<"\n\n\t03. LEGS";
		cout<<"\n\n\t04. ABS";
		cout<<"\n\n\t05. BICEPS";
		cout<<"\n\n\t06. TRICEPS";
		cout<<"\n\n\t07. FOREARMS";
		cout<<"\n\n\t08. SHOULDERS";
		cout<<"\n\n\t09. CORE";
		cout<<"\n\n\tSelect Your Option (1-9) \n";
        cin>>chose;
     
   switch(chose) {
       
       case 0:
       
      cout<<"Thank You \n";
      
       break;
       
       case 1:
       
       chest();
       
       break;
       
       case 2:
       
       back();
        break;
        
       case 3:
       
       legs();
        break;
        
       case 4:
       
       abbs();
        break;
        
       case 5:
       
       bicep();
        break;
        
       case 6:
       
       tricep();
        break;
        
        case 7:
        
        foreams();
        break;
        
        case 8:
        
        shoulders();
        break;
        
        case 9:
        
        core();
        break;
        
        default:
        
        cout<<"This muscle is not in the menu";
        break;
   }
   
    
}
void gym::week(){
     int weekday;
    do{
    cout<<"\nEnter the day you want to train\n";
   
     cin>>weekday;
     
         
       switch(weekday)
    {
        case 0:
        cout<<"Thank You ";
        break;
        
        case 1: 
        cout<<" You chose Monday. \n\n  Choose which muscles you want to train:  ";
            choosemuscle();
             cout<<"Select the second muscle for the day. ";
           choosemuscle();
             
            break;
            
        case 2:
        cout<<" You chose Tuesday. \n\n  Choose which muscles you want to train: ";
           choosemuscle();
            cout<<"Select the second muscle for the day. ";
           choosemuscle();
       
            break;
            
        case 3: 
        cout<<" You chose Wednesday. \n\n  Choose which muscles you want to train:  ";
           choosemuscle();
           cout<<"Select the second muscle for the day. ";
           choosemuscle();
         
            break;
        case 4: 
        cout<<" You chose Thurday. \n\n T Choose which muscles you want to train:  ";
           choosemuscle();
           cout<<"Select the second muscle for the day. ";
           choosemuscle();
          
            break;
        case 5: 
        cout<<" You chose Friday. \n\n  Choose which muscles you want to train:  ";
       choosemuscle();
       cout<<"Select the second muscle for the day. ";
           choosemuscle();
         
       break;
       
        case 6:
        cout<<" You chose Saturday. \n\n  Choose which muscles you want to train:  ";
           choosemuscle();
           cout<<"Select the second muscle for the day. ";
           choosemuscle();
         
      break;
      
        case 7: 
        cout<<" You chose Sunday. \n\n Today is a rest day ";
        break;
           
        default: 
        
        cout<<"Invalid input! Please enter week no. between 1-7.";
        break;
    }
    
     }while(weekday!=0);
}


void gym::chest(){
    cout<<" You chose 1. \n CHEST MUSCLE \n";
    return;
    //info cout on chest muscle
}
void gym::back(){
     cout<<" You chose 2. \n BACK MUSCLE \n";
     return;
    //info cout on back muscle
}
void gym::legs(){
     cout<<" You chose 3. \n LEGS MUSCLE \n";
     return;
    //info cout on legs muscle
}
void gym::abbs(){
     cout<<" You chose 4. \n ABS \n";
     return;
    //info cout on abs
}
void gym::bicep(){
     cout<<" You chose 5. \n BICEPS MUSCLE \n";
     return;
    //info cout on bicep
}
void gym::tricep(){
     cout<<" You chose 6. \n TRICEPS MUSCLE \n";
     return;
    //info cout on tricep
}
void gym::foreams(){
     cout<<" You chose 7. \n FOREARMS MUSCLE \n";
     return;
    //info cout on foreams
}
void gym::shoulders(){
     cout<<" You chose 8. \n SHOULDERS MUSCLE \n";
     return;
    //info cout on shoulders
}


void gym::core(){
     cout<<" You chose 9. \n CORE MUSCLE \n";
     return;
    //info cout on core muscle
}




int main()
{
    gym object1;
    object1.enterdetails();

    return 0;
}