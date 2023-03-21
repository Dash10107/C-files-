#include <iostream>
#include <unordered_map>
using namespace std;
int AGE = 0;

class CovidTest{
  
    
    public:
    string city;
    string name;
    long int aadhar;
    int age;
    bool covid;
    void addCitizen(){
        cout << "Enter Your Name :";
        cin >> name;
        cout << "Enter your Aadhar Number :";
        cin >> aadhar;
        cout << "Enter your Age :";
        cin >> age;
        cout << "Enter your Covid Results : (0/1)";
        cin >> covid;
        cout << "Enter your City :";
        cin >> city;
        cout << endl << endl;
    }
    void displayCitizen(){
        cout << "Name :" << name << endl;
        cout << "Aadhar Number :" << aadhar << endl;
        cout << "Age :" << age << endl;
        cout << "Covid Result :" << covid << endl;
        cout << "City  :" << city << endl;
    }
    
    
    
    
};

void positiveAgeCount(CovidTest obj[3]);
void cityProportion(CovidTest obj[3]);

int main()
{
    int n;
    int x;
    CovidTest obj[3];
    for(int i=0;i<3;i++){
        obj[i].addCitizen();
    }
     int k = 0;
    do{
    cout<<"Enter 1 for age count and 2 for city Proportion ";
   
    cin>>k;
    switch(k){
        case 1:
          positiveAgeCount(obj);
    break;
    case 2:
         cityProportion(obj);
    break;
    
    default:
        break;
    }
    }while(k!=0);
    return 0;
}

void positiveAgeCount(CovidTest obj[3]){
   int cnt1=0,cnt2=0,cnt3=0;
   for(int i =0;i<3;i++){
    if(obj[i].covid ==1){
            if(obj[i].age>=20 && obj[i].age<39 ){
                cnt1++;
            }else if(obj[i].age>=40 && obj[i].age<69){
                cnt2++;
            }else if(obj[i].age>69){
                cnt3++;
            }else{
                continue;
            }


    }else{
        continue;
    }
   }

    cout<<"Age Group 1 : "<<cnt1<<endl;
    cout<<"Age Group 2 : "<<cnt2<<endl;
    cout<<"Age Group 3 : "<<cnt3<<endl;
   
}

void cityProportion(CovidTest obj[3]){
    unordered_map<string,int> umap;
    for(int i =0;i<3;i++){
        if(obj[i].covid ==1){
        umap[obj[i].city]++;
        }else{
            continue;
    }
    }

         for(const auto& key_value: umap) {
    string key = key_value.first;
    int val = key_value.second;
    float value = (key_value.second*100)/3;
    
    cout << key << " - " <<val<<"-"<< value <<"%"<< endl;
                                    }

}