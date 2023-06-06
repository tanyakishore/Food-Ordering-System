#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

void login();
void registration();
void forgotPassword();
int Order();

int main()
{
	int ch;
    cout<<"\n                WELCOME TO LOGIN PAGE           \n";
    cout<<"                       MENU                       \n";
    cout<<"|   PRESS 1 TO LOGIN                           |"<<endl; 
    cout<<"|   PRESS 2 TO REGISTER                        |"<<endl; 
    cout<<"|   PRESS 3 TO if you forgot your PASSWORD     |"<<endl; 
    cout<<"|   PRESS 4 TO EXIT                            |"<<endl; 
    cout<<" Please enter your choice: ";
    cin>>ch;
    cout<<endl;

    switch(ch){
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3: 
            forgotPassword();
            break;
        case 4:
            cout<<"Thank you!"<<endl;
            break;
        default:
            cout<<"Please enter a valid choice "<<endl;
        main();
    }
	return 0;
	
}
void login(){
    int count;
    string userId, password,id,pass;
    
    cout<<"Please enter your username and password: "<<endl;
    cout<<"USERNAME : ";
    cin>>userId;
    cout<<"PASSWORD : ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id==userId && pass==password){
            count=1;
            
        }
    }
    input.close();
    if(count==1){
        cout<<userId<<"\nLOGIN SUCCESSFUL \n";
		Order();
    }
    else{
        cout<<"LOGIN ERROR \n Please check your username and password\n";
        main();
    }
}
void registration(){
    string ruserId,rpassword,mobileno,address,rid,rpass,rmob,radd;
    
    cout<<"USERNAME : ";
    cin>>ruserId;
    cout<<"PASSWORD : ";
    cin>>rpassword;
    cout<<"MOBILE NO.: ";
    cin>>mobileno;
	cout<<"ADDRESS : ";
	cin>>address;

    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<rmob<<radd<<endl;
    
    cout<<"Registration is successfull!"<<endl;
    main();
}
void forgotPassword(){
    int option;
    
    cout<<"Forgot password? \n";
    cout<<"Press 1 to search your id by username \n";
    cout<<"Press 2 to go back to the main menu \n";
    cout<<"Enter your choice : ";
    cin>>option;
    switch(option){
        case 1:
        {
            int count = 0;
            string suserId,sId,spass;
            cout<<"Enter the username which you remembered : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass){
                if(sId==suserId){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"Your account is found! \n";
                cout<<"Your password is : "<<spass;
                main();
            }
            else{
                cout<<"Sorry! your account is not found! \n";
                main();
            }
            break;
        }
        case 2: 
        {
            main();
        }
        default:
            cout<<"Wrong choice! Please try again"<<endl;
            forgotPassword();
    }
}
int Order(){
    char name[30], pizza1[]="Chicken Fazita Pizza" ,pizza2[]="Chicken Bar BQ Pizza" ,pizza3[]="Peri Peri Pizza" ,pizza4[]="Creamy Max Pizza", roll1[]="Chicken Chatni Roll", roll2[]="Chicken Mayo Roll", roll3[]="Veg Roll With Fries",bur1[]="Zinger Burger",bur2[]="Chicken Burger",bur3[]="Mutton Burger";
	char sand1[]="Club Sandwich", sand2[]="Chicken Crispy Sandwich", sand3[]="Extream Veg Sandwich";
	char bir1[]="Chicken Biryani", bir2[]="Prawn Biryani", bir3[]="Veg Biryani",gotostart ;
	int choice=0,pchoice,pchoice1, quantity;//time=40;
	beginning:
	
	cout<<"---------Salt and Sizzle -----------\n\n";
	cout<<"Hello! "<<"\nWhat would you like to order?\n\n";

	cout<<"|              MENU                            |\n";
	cout<<"|   PRESS 1. PIZZA                             |"<<endl; 
    cout<<"|   PRESS 2. BURGER                            |"<<endl; 
    cout<<"|   PRESS 3. SANDWICH                          |"<<endl; 
    cout<<"|   PRESS 4. ROLLS                             |"<<endl;
	cout<<"|   PRESS 5. BIRYANI                           |"<<endl; 
	cout<<"\nPlease Enter your Choice: ";
	cin>>choice;
	cout<<endl;

	if(choice==1)
	 {
		cout<<"|   PRESS 1  "<<pizza1<<"              |"<<endl; 
        cout<<"|   PRESS 2  "<<pizza2<<"              |"<<endl; 
        cout<<"|   PRESS 3  "<<pizza3<<"                   |"<<endl; 
        cout<<"|   PRESS 4  "<<pizza4<<"                  |"<<endl; 
		cout<<"\nPlease Enter which Flavour would you like to have?:";
		cin>>pchoice;
		if(pchoice>=1 && pchoice<=5)
		{
			
			cout<<"\n1) Small Rs.250\n"<<"2) Regular Rs.500\n"<<"3) Large Rs.900\n";
			cout<<"\nChoose Size Please:";
			cin>>pchoice1;
			if(pchoice1>=1 && pchoice1<=3)
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 250*quantity;
			break;

			case 2: choice = 500*quantity;
			break;

			case 3: choice = 900*quantity;
			break;


			}
			
			switch (pchoice1)
			{
			 case 1:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<pizza1;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 2:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<"  "<<pizza2;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 3:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<pizza3;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 4:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<pizza4;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;

			}
			cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
            }
            else{
				cout<<"\n\nThank you for ordering from Salt and Sizzle. \n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
		}
    }
    else if(choice==2)
	 {
		cout<<"|   PRESS 1  "<<bur1<<" Rs.180"<<"              |"<<endl; 
        cout<<"|   PRESS 2  "<<bur2<<" Rs.150"<<"             |"<<endl; 
        cout<<"|   PRESS 3  "<<bur3<<" Rs.200"<<"              |"<<endl;  
		cout<<"\nPlease Enter which Burger you would like to have?: ";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 180*quantity;
			break;

			case 2: choice = 150*quantity;
			break;

			case 3: choice = 160*quantity;
			break;

			}
			
			switch (pchoice1)
			{
			 case 1:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<bur1;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 2:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<"  "<<bur2;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 3:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<bur3;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;


			}
			cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
            }
            else{
				cout<<"\n\nThank you for ordering from Salt and Sizzle. \n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
       }
    }
	else if(choice==3)
	 {
		cout<<"|   PRESS 1  "<<sand1<<" Rs.240"<<"              |"<<endl; 
        cout<<"|   PRESS 2  "<<sand2<<" Rs.160"<<"    |"<<endl; 
        cout<<"|   PRESS 3  "<<sand3<<" Rs.100"<<"       |"<<endl;  
		cout<<"\nPlease Enter which Sandwich you would like to have?:";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 240*quantity;
			break;

			case 2: choice = 160*quantity;
			break;

			case 3: choice = 100*quantity;
			break;

			}
			
			switch (pchoice1)
			{
			 case 1:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<sand1;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 2:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<"  "<<sand2;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 3:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<sand2;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;


			}
			cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
            }
            else{
				cout<<"\n\nThank you for ordering from Salt and Sizzle.\n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
		}
	}


	 else if(choice==4)
	 {
		cout<<"|   PRESS 1  "<<roll1<<" Rs.150"<<"        |"<<endl; 
        cout<<"|   PRESS 2  "<<roll2<<" Rs.100"<<"          |"<<endl; 
        cout<<"|   PRESS 3  "<<roll3<<" Rs.120"<<"        |"<<endl;  
		cout<<"\nPlease Enter which you would like to have?: ";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nHow Much Rolls Do you want: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 150*quantity;
			break;

			case 2: choice = 100*quantity;
			break;

			case 3: choice = 120*quantity;
			break;

			}
			
			switch (pchoice1)
			{
			 case 1:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<roll1;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 2:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<"  "<<roll2;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			 case 3:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<roll3;
			 cout<<"\nYour Total Bill is "<<choice;
			 break;
			}
            cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
            }
            else{
				cout<<"\n\nThank you for ordering from Salt and Sizzle.\n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
        }
    }
	else if(choice==5)
	 {
		cout<<"|   PRESS 1  "<<bir1<<" Rs.160"<<"            |"<<endl; 
        cout<<"|   PRESS 2  "<<bir2<<" Rs.220"<<"              |"<<endl; 
        cout<<"|   PRESS 3  "<<bir3<<" Rs.140"<<"                |"<<endl;  
		cout<<"\nPlease Enter which Biryani you would like to have?:";
		cin>>pchoice1;
		if(pchoice1>=1 && pchoice1<=3)
		{
			cout<<"\nPlease Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1: choice = 160*quantity;
			break;

			case 2: choice = 220*quantity;
			break;

			case 3: choice = 140*quantity;
			break;

			}
			
			switch (pchoice1)
			{
			 case 1:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<bir1;
			 cout<<"\nYour Total Bill is"<<choice;
			 break;
			 case 2:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<"  "<<bir2;
			 cout<<"\nYour Total Bill is"<<choice;
			 break;
			 case 3:
			 cout<<"--------YOUR ORDER---------\n";
			 cout<<""<<quantity<<" "<<bir3;
			 cout<<"\nYour Total Bill is"<<choice;
			 break;


			}
			cout<<"\nWould you like to order anything else? Y / N:";
			cin>>gotostart;
			if(gotostart=='Y' || gotostart=='y')
			{
			  goto beginning;
            }
            else{
				cout<<"\n\nThank you for ordering from Salt and Sizzle.\n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
		}
	}

	else{
			
			cout<<"Please Select Right Option: \n";
			cout<<"\nWould You like to Start the program again? Y / N: " ;
			cin>>gotostart;

			if(gotostart=='Y' || gotostart=='y')
			{
			    goto beginning;
            }
            else{
				cout<<"\n\nThank you for visiting Salt and Sizzle.\n";
                cout<<"Visit again <3\n";
                cout<<"Have a good day!";
				return 0;
			}
	    }
}