//To check Credit card number valid or not.
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

bool isNumberString(const string& s){
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9')
        return false;
    }
    return true;
}

int main(){
    string ccNumber;
    cout<<"this program uses the luhn algorithm to validate a cc number."<<endl;
    while(true){
        cout<<"please enter a cc number to validate: ";
        cin>>ccNumber;
        if(ccNumber=="exit")
        break;
        else if
        (!isNumberString(ccNumber)){
            cout<<"Bad input";
            continue;
        }
        int len=ccNumber.length();
        int doubleEvenSum=0;
        //Step 1 is to double every second digit,starting from the right.if it//results in a two digit number,
        //add both the digits to obtain a single //digit number.
        //finally,sum of all the answers to obtain 'doubleEvensum'.
        for(int i=len-2;i>=0;i=i-2){
            int dbl=((ccNumber[i]-48)*2);
            if(dbl>9){
                dbl=(dbl/10)+(dbl%10);
            }
            doubleEvenSum+=dbl;
        }
        //step 2 is to add every odd place digit from the right to the value//'doubleEvenSum'.
        for(int i=len-1;i>=0;i=i-2){
            doubleEvenSum+=(ccNumber[i]-48);
        }
        //step 3 is to check if the final 'doubleEvenSSum' is a multiple of 10. //if yes,it is a valid cc number.otherwise,not.
        cout<<(doubleEvenSum%10==0?"valid!":"invalid!")<<endl;
        continue;
    }
    return 0;
}
