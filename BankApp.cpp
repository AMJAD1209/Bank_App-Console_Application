#include<iostream>
using namespace std;

int displayMenu();
void displayAccounts();
void searchAccount();
void depositAmount();
void withdrawAmount();
void clacInterest(string accNo);

string customerDetails[4][5]={
    {"4810055992","4962006345","4753008741","3345256348","4954083265"},
    {"Tom Lara","Simon David","Ben Stacy" ,"John Mark","Cooper Jake"},
    {"965622411V", "931122456V" ,"927391333V" ,"961343267V" ,"967591530V"},
    {"Saving" ,"Current" ,"Fixed" ,"Current" ,"Saving"}
};

double balance[]={153000,25000,85000,62000,178000};



int main(){
    char isYes;
    string accNo;    
    do{
        switch(displayMenu()){
            case 1:
                displayAccounts();
                break;
            case 2:
                searchAccount();
                break;
            case 3:
                depositAmount();
                break;
            case 4:
                withdrawAmount();
                break;
            case 5:
                
                cout<<"Account Number: ";
                cin>>accNo;
                clacInterest(accNo);
                break; 
            default:
                cout<<"wrong fuck you!"<<endl;
        }
        cout<<"run again? ";
        cin>>isYes;
    }while(isYes=='y' || isYes=='Y');

    cout<<"hamaniyan"<<endl;

    return 0;

    
}


int displayMenu(){
    cout<<"1 - Customer Details\n2 - Search Account Details\n3 - Deposit\n4 - Withdrawal\n5 - Interest\n";
    int option;
    cout<<"select: ";
    cin>>option;
    return option;
}

void displayAccounts(){
    cout<<"Account Number\tCustomer Name\tNIC-Number\tAccount-Type\tBalance\n";
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cout<<customerDetails[j][i]<<"\t";
        }
        cout<<"\t"<<balance[i]<<endl;
    }
}

void searchAccount(){
    cout<<"NIC: ";
    string nic;
    cin>>nic;

    for(int i=0;i<5;i++){
        if(customerDetails[2][i]==nic){
            cout<<"Account Number\tCustomer Name\tNIC-Number\tAccount-Type\tBalance\n";
            for(int j=0;j<4;j++){
                cout<<customerDetails[j][i]<<"\t";
            }
            cout<<"\t"<<balance[i]<<endl;
            return;
        }
    }
    cout<<"Sorry, we don't have any account for this NIC Number"<<endl;
}

void depositAmount(){
    string accNo;
    double amount;

    cout<<"Account Number: ";
    cin>>accNo;
    cout<<"Amount: ";
    cin>>amount;

     for(int i=0;i<5;i++){
        if(customerDetails[0][i]==accNo){
            balance[i]+=amount;
            return;
        }
     }
}

void withdrawAmount(){
    string accNo;
    double amount;

    cout<<"Account Number: ";
    cin>>accNo;
    cout<<"Amount: ";
    cin>>amount;

     for(int i=0;i<5;i++){
        if(customerDetails[0][i]==accNo){
            if(balance[i]>10000){
                balance[i]-=amount;
            }else{
                cout<<"The balance is not sufficient to withdraw"<<endl;
            }
            return;
        }
    }
}

void clacInterest(string accNo){
    for(int i=0;i<5;i++){
        if(customerDetails[0][i]==accNo){
            if(customerDetails[3][i]=="Saving"){
                cout<<"interrest: "<<(balance[i]*10)/100<<endl;
            }
            else if(customerDetails[3][i]=="Current"){
                cout<<"interrest: "<<(balance[i]*8)/100<<endl;
            }else{
                cout<<"interrest: "<<(balance[i]*13)/100<<endl;
            }
        }
    }
}



