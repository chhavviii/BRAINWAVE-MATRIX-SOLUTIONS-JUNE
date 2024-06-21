#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

//IN THIS CODE OF ATM WE WILL USE BASIC CONCEPTS OF CLASS,ACCESS,MODIFIERS IN C++, DATA TYPES, VARIABLES, SWITCH CASE
class Solution{
    private:
    string name;
    long long Accnumber;
    char type[10];
    long long amount=0;
    long long total=0;
    int userPIN;
    vector<string> transactionHistory;

    public:
        void logTransaction(const string& type, long long amount, long long balance) {
            string record = "Type: "+ type +", Amount:" + to_string(amount) + ", Balance: " + to_string(balance);
            transactionHistory.push_back(record);
        }

       void setValue(){
          cout<<"Enter name:"<<endl;
          cin.ignore();

          getline(cin,name);

          cout<<"Enter Account Number:"<<endl;
          cin>>Accnumber;
          cout<<"Enter Account type:"<<endl;
          cin>>type;
          cout<<"Enter Balance:"<<endl;
          cin>>total;
       }

       void showdata(){
        cout<<"Name:"<<name<<endl;
        cout<<"Account no.:<<"<<Accnumber<<endl;
        cout<<"Account type:"<<type<<endl;
        cout<<"Balance:"<<total<<endl;
       }

       void deposit(){
        cout<<"Enter amount to be Deposited"<<endl;
        cin>>amount;
        total += amount;
        logTransaction("Deposit", amount, total);
        cout<<"Total balance is:"<< total<<endl;
       }

       void showbal(){
        cout<<"Total balance is:"<<total;
       }
       string generateLoanApplicationID(){
         string id = "";
         const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
         for(int i=0; i<8 ;++i){
            id += alphanum[rand() % (sizeof(alphanum)-1)];
         }
         return id;
       }
       void withdrawal(){
        int a,Available_Balance;
        cout<<"Enter amount to withdraw:"<<endl;
        cin>>a;
        if(a <= total){
            total -= a;
            logTransaction("Withdrawal", a, total);
            cout<<"Available Balance is:"<< total <<endl;
        }
        else{
            cout<<"Insufficient balance!"<<endl;
        }
        }
        void setPIN(int pin){
            userPIN = pin;
        }
        
         bool isHardPIN(int pin) const {
          string pinstr=to_string(pin);

          for(size_t i=0;i<pinstr.length()-1;++i){
            if(pinstr[i+1] == pinstr[i]+1){
                return false;
            }
            if(pinstr[i+1] == pinstr[i]-1){
                return false;
            }
          }
          return true;
        }
        
        bool validatePIN(int inputPIN){
            return inputPIN == userPIN;
        }

        void changePIN(int oldPIN){
            if(validatePIN(oldPIN)){
            int  newPIN;
            cout<<"ENTER NEW PIN:"<<endl;
            cin>>newPIN;

           while(!isHardPIN(newPIN)){
            cout<<"New PIN is too easy. Please enter HARDER PIN"<<endl;
            cin>>newPIN;
           }

           userPIN=newPIN;
           cout<<"PIN has changed successfully!"<<endl;
            }
            else{
                cout<<"Incoorect old PIN"<<endl;
            }
        }

        void fetchTransactionHistory(const string& bankName, const string& accountNumber) {
    // Simulated function to fetch transaction history
        cout << "Fetching transaction history from Bank: " << bankName << ", Account Number: " << accountNumber << endl;
    // Simulated transaction history
        cout << "Transaction History:" << endl;
        cout << "- Transaction 1: ..." << endl;
        cout << "- Transaction 2: ..." << endl;
        cout << "- Transaction 3: ..." << endl;
        for(const string &record: transactionHistory){
            cout<<record<<endl;
        }
    // Actual implementation would fetch data from bank or database
}

        void loanInquiry(){
            string identityProof;
            string bankName;
            string accountNumber;
            double desiredLoanAmount;
             int loanType;

    // Step 1: Choose Identity Proof
             cout << "Choose your identity proof:" << endl;
             cout << "1. Aadhar Card" << endl;
             cout << "2. Passport" << endl;
             cout << "3. Voter ID" << endl;
             cout << "4. Driver License" << endl;
             cout << "Enter option: ";
             int identityOption;
             cin >> identityOption;

             switch (identityOption) {
               case 1:
                  identityProof = "Aadhar Card";
                  break;
               case 2:
                  identityProof = "Passport";
                  break;
               case 3:
                  identityProof = "Voter ID";
                   break;
               case 4:
                  identityProof = "Driver License";
                  break;
               default:
                   cout << "Invalid identity proof option!" << endl;
                   return;
    }

    // Step 2: Fetch Account Transaction History
    cout << "Enter Bank Name: ";
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, bankName);

    cout << "Enter Account Number: ";
    getline(cin, accountNumber);

    fetchTransactionHistory(bankName, accountNumber);

    // Step 3: Desired Loan Amount
    cout << "Enter desired loan amount: ";
    cin >> desiredLoanAmount;

    // Step 4: Choose Loan Type
    cout << "Available Loans:" << endl;
    cout << "1. Education Loan" << endl;
    cout << "2. Personal Loan" << endl;
    cout << "3. Home Loan" << endl;
    cout << "4. Vehicle Loan" << endl;
    cout << "Enter loan type to inquire: ";
    cin >> loanType;

    switch (loanType) {
        case 1:
            cout << "Education Loan Details: ..." << endl;
            break;
        case 2:
            cout << "Personal Loan Details: ..." << endl;
            break;
        case 3:
            cout << "Home Loan Details: ..." << endl;
            break;
        case 4:
            cout << "Vehicle Loan Details: ..." << endl;
            break;
        default:
            cout << "Invalid loan type option!" << endl;
            break;
    }
        }
       
};
int main(){

    Solution b;
    
    int initialPIN;
    cout<<"Set your initial PIN: ";
    cin>>initialPIN;

    while(!b.isHardPIN(initialPIN)){
        cout<<"PIN is too easy. Please enter a harder PIN"<<endl;
        cin>>initialPIN;
    }

    b.setPIN(initialPIN);

    int enteredPIN;
    cout<<"Enter current PIN to proceed:"<<endl;
    cin>>enteredPIN;
    
    string Bankname;
    cout<<"Bank name:"<<endl;
    cin.ignore();
    getline(cin,Bankname);

    string AccNo;
    cout<<"Enter your account number"<<endl;
    getline(cin,AccNo);
    int choice;

    if(b.validatePIN(enteredPIN)){
        
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            <<"~~~WELCOME~~~~~~~~~~~~~~~~~~~~~~~"
            <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            <<"~~~~~~~~~~~~\n\n";
        
        cout<<"Enter Your Choice"<<endl;
        cout<<"\t1. Enter name, Account"
            <<"number, Account type"<<endl;
        cout<<"\t2. Balance Enquiry"<<endl;
        cout<<"\t3. Deposit Money"<<endl;
        cout<<"\t4. Your Total Balance is"<<endl;
        cout<<"\t5. Withdrawal Money"<<endl;
        cout<<"\t6. Change PIN"<<endl;
        cout<<"\t7. Loan Inquiry"<<endl;
        cout<<"\t8. Transaction History"<<endl;
        cout<<"\t9. Cancel"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
            b.setValue();
            break;
            case 2:
            b.showdata();
            break;
            case 3:
            b.deposit();
            break;
            case 4:
            b.showbal();
            break;
            case 5:
            b.withdrawal();
            break;
            case 6:
            b.changePIN(enteredPIN);
            break;
            case 7:
            b.loanInquiry();
            break;
            case 8:
            b.fetchTransactionHistory(Bankname,AccNo);
            break;
            case 9:
            exit(0);
            break;
            default:
            cout<<"INVALID CHOI9605CE"<<endl;
        }
    
    }
    else{
        cout<<"INVALID PIN!"<<endl;
        cout<<"ACCESS DENIED.";
    }
    return 0;
}