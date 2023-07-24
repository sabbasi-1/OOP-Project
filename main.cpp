#include "Normal_mode.h"
#include "Random_mode.h"
#include "Funds.h"

using namespace std;

int main()
{
	
	

	Normal_mode_vender *f=new Normal_mode_vender(); //pointer of base class points to object which is allocated memory
	int classification; //distinguish customer and restocker
	int choicer,choicec; //to choose row and column for item to fend or change price and quantity
	string line; //design (line 44 and 46)
	cout<<"\n\nEnter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
	cin>>classification;
	
		while(classification!=1 && classification!=-1 && classification!=0) //exception of invalid entry
	{
		cout<<"invalid entry enter again\n";
		cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
		cin>>classification;
	}
	
	
	while(classification==1 || classification==-1 || classification==0)
	{
	
	
	if(classification==0) //RESTOCKER
	{
	
	int passcodemain;
	cout<<"enter the passcode:\n";
	cin>>passcodemain;
	f->verifypasscode(passcodemain);//to verify passcode of owner (function from line 174 called in Normal_mode.h)
	do
	{
		
		if(f->verifypasscode(passcodemain)==true)
		{
			system("cls");
			cout<<line.assign(65,'-')<<endl;
			cout<<"ENTRY PERMITTED\nDOOR opened\n";
			cout<<line.assign(65,'-')<<endl;
			break;
		}
		
		cout<<"invalid passcode try again\n";
		cin>>passcodemain;
	}
	while(f->verifypasscode(passcodemain)==false); //do while loop to repeat until passcode is entered correctly
	sleep(3);

	int chooserrestock; //to choose option of tending to items or passcode or cashbox for the owner
	f->displaydata();
	cout<<endl<<endl;
	cout<<"Enter 1 to set item price or refill them\n";
	cout<<"Enter 2 to change amount in cash box\n";
	cout<<"Enter 3 to change passcode\n\n";
	cin>>chooserrestock;
	
	while(chooserrestock!=1 && chooserrestock!=2 && chooserrestock!=3)  //exception
	{
		cout<<"invalid entry try again\n";
		cin>>chooserrestock;
	}
	

	while(chooserrestock==1 || chooserrestock==2 || chooserrestock==3)
	{
		if(chooserrestock==1)
		{
		f->setitempriceandqty(choicer,choicec);
		f->displaydata();						//to change item price and quantity line 240
		}
		else if(chooserrestock==2)
		f->cashcollected();						//to modify cash in cashbox	line 293
		else if(chooserrestock==3)
		f->changepasscode();					//to modify passcode	line 164
	
		cout<<"\nEnter 1 to set item price or refill them\n";
		cout<<"Enter 2 to change amount in cash box\n";
		cout<<"Enter 3 to change passcode\npress any other number to exit\n";
		cin>>chooserrestock;	
	}
	
	
	//............................................................
	cout<<"enter the passcode (modified) before leaving to Lock door:\n"; //line 91-105 ensures that owner enter correct passcode before leaving vender to close door.
	cin>>passcodemain;
	f->verifypasscode(passcodemain);
	do
	{
		
		if(f->verifypasscode(passcodemain)==true)
		break;
		cout<<"invalid passcode try again\n";
		cin>>passcodemain;
	}
	while(f->verifypasscode(passcodemain)==false);
	cout<<line.assign(65,'-')<<endl;
	cout<<"ENTRY PERMITTED\nDOOR closed\n";
	cout<<line.assign(65,'-')<<endl;

	
	} //if restocker ends
	
	else if(classification==1)  //line 110-165 tends to customer 
	{
	bool tryagain=true;  //for exception handling 0.50 dollars/50 cents
	int exiter;			//to exit process of buying item and return money back
	
	do
	{
		tryagain=true;
		sleep(2);
		system("cls");
		cout<<endl<<"Select an item or enter -1 to EXIT"<<endl;
		cout << line.assign(70, '-')<<endl;		//just embellishment
		f->displaydata();
		cout<<"\nselect row\n";
		cin>>choicer;				//customer selscts row
		cout<<"select column\n";
		cin>>choicec;				//customer selects column
		
		while(choicer<=0 || choicec<=0 || choicec>numcol || choicer>numrow ) //exception for invalid row or column entry
		{
			cout<<"invalid Entry enter again...\n";
			cout<<"select row\n";
			cin>>choicer;
			cout<<"select column\n";
			cin>>choicec;
			
		}
		
		
		
		for(int i=0;i<1;i++)
		{
			for (int j=0;j<1;j++)
			{
				while(tryagain) //exception handling segment for 50 cents
				{
					try
					{
						f->buyitem(choicer,choicec);
						tryagain=false;
					}
					catch(Normal_mode_vender::invalidamount)
					{
					cout<<"Please enter valid amount of money. 50 cents are NOT accepted\n";
					f->buyitem(choicer,choicec);
					}
				}
			}
		}
		
	cout<<"enter -1 to exit or any other number to continue\n";
	cin>>exiter;							//to exit process and return to main menu (line 16 of main.cpp)
		
	} while (exiter!=-1);
	
	}//if customer
	
	else if(classification==-1)  //to exit from vending machine
	break;
	

	
	cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
	cin>>classification;
	
	while(classification!=1 && classification!=-1 && classification!=0) //for invalid entry
	{
		system("cls");
		cout<<"invalid entry enter again\n";
		cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
		cin>>classification;
	}
	
}//while loop of choice

delete f;   //signal for destructor (line 60 Normal_mode.h) to excecute and erase all data. Here the allocated memory is cleared up

						//NORMAL MODE ENDS		

//------------------------------------------------------------RANDOM MODE----------------------------------------------------------------------------


//Description of random mode:
//In random mode customers and restockers appear randomly to set data or purchase items. The statistics are shown periodically on the terminal screen.



//lines 213-370 are on the same logic as NORMAL MODE OF VENDING MACHINE. ONLY theALPHANUMERIC VALUES ARE RANDOMIZED and occurance of events is random.


char randommode;
cout<<"\n\nFor random mode press R\n";
cin>>randommode;
while(toupper(randommode)!='R') //if user presses r or R vender goes to random mode
{
	cout<"Invalid INPUT enter again\n";
	cin>>randommode;
}
if(toupper(randommode)=='R')
{
	system("cls");
	cout<<"Entering Random Mode...\n";//displays for 3 seconds
	sleep(3);
	system("cls");
	random *r=new random(); //derived class pointer points to allocated memory for derived object 
	r->displaymenu();
	int randomclassification; 		//distinguish customer and restocker
	int choicer,choicec; 			//tochoose row and column for item to fend or change price and quantity
	cout<<"\n\nEnter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
	srand(time(NULL));				//random seed
	randomclassification=(rand()%2);//random choice selection
	cout<<randomclassification<<endl;
	
	
	
		while(randomclassification!=1 && randomclassification!=-1 && randomclassification!=0)
	{
		cout<<"invalid entry enter again\n";
		cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
		randomclassification=(rand()%4)-1;
		cout<<randomclassification<<endl;
	}
		
	
	while(randomclassification==1 || randomclassification==-1 || randomclassification==0)
	{
	
	
	if(randomclassification==0)
	{

	sleep(5);
	system("cls");
	cout<<line.assign(65,'-')<<endl;
	cout<<"ENTRY PERMITTED\nDOOR opened\n";
	cout<<line.assign(65,'-')<<endl;
	int randomchooserrestock;
	r->displaydata();
	cout<<endl<<endl;
	cout<<"Enter 1 to set item price or refill them\n";
	cout<<"Enter 2 to change amount in cash box\n\n";
	randomchooserrestock=(rand()%4)+1;
	cout<<randomchooserrestock<<endl;
	
	while(randomchooserrestock!=1 && randomchooserrestock!=2 )
	{
		cout<<"invalid entry try again\n";
		randomchooserrestock=(rand()%3)+1;
		cout<<randomchooserrestock<<endl;
	}
	

	while(randomchooserrestock==1 || randomchooserrestock==2 )
	{
		if(randomchooserrestock==1)
		{
		r->setitempriceandqty(choicer,choicec);
		r->displaydata();
		}
		else if(randomchooserrestock==2)
		r->cashcollected();

	
		cout<<"\nEnter 1 to set item price or refill them\n";
		cout<<"Enter 2 to change amount in cash box\n";
		cout<<"press any other number to exit\n";
		randomchooserrestock=(rand()%1)+1;
		cout<<randomchooserrestock<<endl;	
	}
	
	
	//............................................................


	
	} //if restocker
	
	else if(randomclassification==1)
	{
	bool tryagain=true;  //for exception handling 0.50 dollars/50 cents
	int exiter;
	
	do
	{
		tryagain=true;
		sleep(5);
		system("cls");
		cout<<endl<<"Select an item or enter -1 to EXIT"<<endl;
		cout << line.assign(70, '-')<<endl;
		r->displaydata();
		cout<<"\nselect row\n";
		choicer=(rand()%numrow)+1;
		cout<<choicer<<endl;
		cout<<"select column\n";
		choicec=(rand()%numcol)+1;
		cout<<choicec<<endl;
		
		while(choicer<=0 || choicec<=0 || choicec>numcol || choicer>numrow )
		{
			cout<<"invalid Entry enter again...\n";
			cout<<"select row\n";
			choicer=(rand()%numrow)+1;
			cout<<choicer<<endl;
			cout<<"select column\n";
			choicec=(rand()%numcol)+1;
			cout<<choicec<<endl;
			
		}
		
		
		
		for(int i=0;i<1;i++)
		{
			for (int j=0;j<1;j++)
			{
				while(tryagain) //exception handling segment
				{
					try
					{
						r->buyitem(choicer,choicec);
						tryagain=false;
					}
					catch(Normal_mode_vender::invalidamount)
					{
					cout<<"Please enter valid amount of money. 50 cents are NOT accepted\n";
					r->buyitem(choicer,choicec);
					}
				}
			}
		}
		
	cout<<"enter -1 to exit or any other number to continue\n";
	exiter=(rand()%2)-1;
	cout<<exiter<<endl;
		
	} while (exiter!=-1);
	
	}//if customer
	
	else if(randomclassification==-1)
	break;
	

	
	cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
	randomclassification=(rand()%4)-1;
	cout<<randomclassification<<endl;
	
	while(randomclassification!=1 && randomclassification!=-1 && randomclassification!=0)
	{
		sleep(4);
		system("cls");
		cout<<"invalid entry enter again\n";
		cout<<"Enter 0 if you are a RESTOCKER\nEnter 1 if you are CUSTOMER\nPress -1 to exit\n";
		randomclassification=(rand()%4)-1;
		cout<<randomclassification<<endl;
	}
	
}

}//if randommode=='r' (if statement of random mode end)

	
	


return 0;
}

//---------------------------------------------------------CODE ENDS--------------------------------------------------------------------------------

//			CREATED AND PRESENTED BY:
								//	Muhammad Faiez (295848) BEE-11D
								//	Sannan Zia Abbasi(293786) BEE-11D 

