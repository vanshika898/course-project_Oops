#include <iostream>
using namespace std;

class Account_creation {
    private:
    long account_number;
    long password_num=1234;
	int current_amount=2000;
	
	
public:
    string gmail, name, dob, address, citizenship,Account_type;
    long mobile_number;
    
        void account() {
        cout << "----------------------------------------------------------------------------------------------------" << endl;
        cout << "                     WELCOME TO BANK INVENTORY SYSTEM                                       " << endl;
        cout << "----------------------------------------------------------------------------------------------------" << endl;
        cout << "Accounts" << endl;
        cout << "1. Login\n2. Create new account" << endl;
    }
    
         void set_Account_number(long a){
          account_number=a;
        }
        long getAccountNumber() {
            return account_number;
            }
        bool find_is_custumer(){
           bool iscustomer;
           int a;
            cout<<"Enter your above set account number :";
            cin>>a;
           if (a!=getAccountNumber()){
               iscustomer=false;
           }
           else{
               iscustomer=true;
           }
           return iscustomer;
        }
             
        void update_information (){
            string new_address;
            long new_mobile;
            cout<<"--------------------------------------------------------------------------------------"<<endl;
            cout<<"Upadate account"<<endl;
            cout<<"----------------------------------------------------------------------------------------"<<endl;
            if(find_is_custumer()){
                cout<<"enter your new address:";
                cin>>new_address;
                cout<<"enter your mobile number:";
                cin>>new_mobile;
                cout<<"Your  information is successfully updated!"<<endl;
            
        } else{
            cout<<"invalid user";
        }
        }
        void displayinfo(){
            cout<<"Name :"<<name<<endl;
            cout<<"address :"<<address<<endl;
            cout<<"Account_type :"<<Account_type<<endl;
            cout<<"mobile_number :"<<mobile_number<<endl;
            cout<<"date of birth :"<<dob<<endl;
            cout<<"citizenship_number:"<<citizenship<<endl;
            cout<<"gmail :"<<gmail<<endl;
            
        }
        void see_details(){
             cout<<"----------------------------------------------------------------------------------------"<<endl;
            cout<<"Your details"<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            if(find_is_custumer()){
                displayinfo();
            }else{
                cout<<"invalid customer";
            }
             cout<<"------------------------------------------------------------------------------------------"<<endl;
            
        }
        void delete_account() {
        cout<<"Are you sure you want to delete your account? (yes/no): ";
        string confirmation;
        cin>>confirmation;

        if (confirmation=="yes") {
            cout<<"Account deleted successfully!" << endl;
            name="";
            dob="";
            address="";
            mobile_number=0;
            citizenship="";
            gmail="";
            Account_type="";
             
        } else {
            cout<<"Account not deleted."<< endl;
        }
    }
    void deletation(){
        cout<<"------------------------------------------------------------------------" << endl;
              cout<<"Options:" << endl;
              cout<<"1. Delete Account" << endl;
              cout<<"2. Exit" << endl;
              cout<<"Choose an option: ";
              int option;
              cin>>option;

              if (option == 1) {
              delete_account(); 
        
              } else if (option == 2) {
             cout<<"Exiting the program."<<endl;
              } else {
        cout<<"Invalid option."<<endl;
    }
    }
       friend class transaction_Managment; 
       
        void set_password_num(long z){
          password_num = z;
        }
        long getpassword_num() {
            return password_num;}
            
		bool find_is_password(){
        bool ispassword;
        int z;
            cout<<"Enter password number :";
            cin>>z;
           if (z!=getpassword_num()){
              ispassword=false;
           }
           else{
               ispassword=true;
           }
           return ispassword;
        }
            
        void security_acc() {
    

    try{

        if (find_is_password()) {
            cout << "Your account is secure!" << endl;
        } else {
            throw runtime_error("Invalid password");
        }
    } catch (const runtime_error &e) {
        cout << e.what() << endl;
    }
}

        
};

class transaction_Managment:virtual public Account_creation{
	public:
		int tbalance=0;
		
//deposits , withdrawl , fund transfer , history , view account_details (current balance) , interest calculate.
	
	void account_details(Account_creation o){
		int  i;
		cout<<"--------------------------------------------------------------------- "<<endl;
		cout<<"                   Looking for transcation                            "<<endl;
		cout<<"Enter above given account number to know about transcation details : ";
	    cin>>o.account_number;
		cout<<" Are you interested in new deposit or withdrawl ?"<<endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		cout<<"Press "<<endl<<"1.deposit"<<endl<<"2.withdrawl"<<endl;
		cout<<"Your choice is:";
		cin>>i;
		cout<<"----------------"<<endl;
		cout<<"Your current amount in your account is :"<<o.current_amount<<endl;
		if(i==1){
			int deposit_amount=0;
			cout<<"Enter the amount you want to deposit in your current account:";
			cin>>deposit_amount;
			tbalance=deposit_amount+o.current_amount;
			cout<<"With this your total amount become : "<<tbalance<<endl;
		}
		else if (i==2){
			int withdrawl_amount=0;
			cout<<"Enter the amount you want to withdrawl from your current account:";
			cin>>withdrawl_amount;
			tbalance= o.current_amount-withdrawl_amount;
			cout<<"With this your total amount become : "<<tbalance<<endl;
		}

	}
    void transfer_fund() {
    	
    	int fund,a_n,t,pass,PIN;
    	string b;
    	cout<<"--------------------------------------------------------------------- "<<endl;
		cout<<"                   Looking for fund transfer to other account-         "<<endl;
        cout<<"Enter the amount you want to transfer:";
        cin>>fund;
        if (fund<=tbalance){
        	cout<<"Enter account number you want to transfer money:";
        	cin>>a_n;
        	cout<<"PIN number is:"<<PIN<<endl;
        	t=tbalance-fund;
        	cout<<"Your fund is successfully tranferred in "<< a_n <<"account number!"<<endl;
        	cout<<"After transcation your current balance become:"<<t<<endl;
        	cout<<"------------------------------------------------------------------------------------------"<<endl;
		}
	else{
	    cout<<"You don't have enough money to transfer, do you have other account to link with press yes :";
	    cin>>b;
	    if(b=="yes"){
	       account_linking(200);
	    }else{
	        cout<<"Invalid";
	    }
	    }
			
		}
		
    	
    void calintereset(Account_creation p){
    	 int total_amount=0;
    	 string type;
         cout<<"--------------------------------------------------------------------- "<<endl;
		 cout<<"                   Interest calculation of current balance-          "<<endl;
    	cout<<"Enter Account type (current / saving): ";
        cin >> p.Account_type;

        if (p.Account_type=="saving"){
        	total_amount=tbalance+(int)(0.05*tbalance);
        	cout<<"Your current_amount with 5% interest is: "<<total_amount<<endl; 	}
        else{ 
            total_amount=tbalance;
        	cout<<"Your current_amount with 0% interest is: "<<total_amount<<endl; 	}
		}
		void account_linking(int a_mount){
		    int t;
		    cout<<"Enter the account number of account for linking the account :";
		    cin>>t;
		    cout<<"In this account your balance is :"<<a_mount<<endl;
		    int to_tal=a_mount+tbalance;
		    cout<<"By linking this account your total balance is:"<<to_tal<<endl;
		}

};
class login:virtual public Account_creation,virtual public transaction_Managment{
    Account_creation w;
    public:
    string gmail;
    int password;
    login(){
        cout<<"Enter your gmail Id:";
        cin>>gmail;
        cout<<"password:";
        cin>>password;
        cout<<"You are now log in :"<<endl;
    }
    
   void welcome(){
       
    cout<<"You currently visited this system for- "<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    cout<<"1.Edit details\n2.See details\n3.Transcations\n4.Delete account"<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
    }
    void displayinfo(string name ,string date_of_birth,string address,long mobile_number,string gmail,int citizenship_number){
       cout<<"Your details!"<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"date of birth:"<<date_of_birth<<endl;
        cout<<"address:"<<address<<endl;
        cout<<"mobile_number:"<<mobile_number<<endl;
        cout<<"gmail:"<<gmail<<endl;
        cout<<"Citizenship number:"<<citizenship_number<<endl;
        set_Account_number(124);
        cout<<"Account number is:"<<getAccountNumber()<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    ~login(){
        cout<<"Programm ends!"<<endl;
        
    }
        
        
        
    
};
class createAccount:virtual public Account_creation,virtual public transaction_Managment{
    public:
    void create_account() {
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout<<"Account Creation"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter your date of birth: ";
        cin >> dob;
        cout << "Enter your address: ";
        cin >> address;
        cout << "Enter your mobile number: ";
        cin >> mobile_number;
        cout << "Enter your gmail id: ";
        cin >> gmail;
        cout << "Enter your citizenship number: ";
        cin >> citizenship;
        
        
    }
     
    
    
    
};
 
int main() {
    int choice;
    Account_creation a1;
    a1.account();
    cout << "Enter your choice: ";
    cin >> choice;
    
    if (choice==1) {
            login l;
            cout<<"---------------------------------------------------------------------------"<<endl;
            l.welcome();
            
            int Choice;
            cout<<"Enter choice:";
            cin>>Choice;
            if(Choice==1){
           l.update_information();
           }
           else if (Choice==2){    
           l.displayinfo("vanshika","31_july_2005","ujjain",8989537765,"vansik",123456);
           }
           else if(Choice==3){
           l.account_details(a1);
           }
           else if(choice==4){
               l.security_acc();
               l.delete_account();
               
           }
           

        }
    else if (choice==2) {
            createAccount c; 
            c.create_account();
            c.set_Account_number(124);
            cout<<"Account number is:"<<c.getAccountNumber()<<endl;
            c.update_information();
            c.see_details();
            
            c.account_details(a1);
            c.transfer_fund();
            c.calintereset(a1);
            cout<<"-----------------------------------------------------------------------------------------"<<endl;
            c.security_acc();
            cout<<"-----------------------------------------------------------------------------------------"<<endl;
            c.deletation();
             
            
            
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;
        }
        else{
            cout << "Invalid choice.";
    }

    
    return 0;
}