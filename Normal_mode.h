#ifndef NORMAL_MODE_H
#define NORMAL_MODE_H
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>//sleep
#include<iomanip>
#include<cctype>


using namespace std;
	const int namesize=15;  //field width for strings
	const int numrow=10;	//number of rows for vending machine items
	const int numcol=5;		//number of columns for vending machine items
	
	
struct venditem				//structure having item name,price and quantity
{
		string name;
		double price;
		int qty;
};




class Normal_mode_vender	//base class for normal mode of vending machine
{
	private:
		int passcode=3456;  //passcode for owner to open and close door of vending machine to set prices and quantity of items
	
	
	protected:
		
		venditem items[numrow][numcol];
		double cashbox;			//cashbox that collects money.can be reset by the owner and/or modified
		double money;			//to input money by customer
		double total;			//displays amount saved in the vending machine for the day
		bool enoughmoney;		//checker to see if enough money have been entered
		int amount;				//same as quantity of item
	
	
	public:
		Normal_mode_vender();	//constructor that displays the menu (items with price)
		virtual void setitempriceandqty(int choicerow,int choicecolumn);	//for owner to set price and quantity of items in vender
		virtual void displaymenu();	//to display menu of items to customer
		virtual void displaydata();	//to display menu to customer after owner has made changes in price/quantity/item.
		void changepasscode();		//for the owner to change passcode 
		bool verifypasscode(int);	//checker to verify whether passcode entered is correct or not
		

		virtual void inputmoney(int choicer,int choicec);//to input money by customer. setter function that takes row and column as argument
		virtual void cashcollected();// to display amount of cash collected for the day
		virtual void buyitem(int choicer,int choicec);//to buy item.This functions directs user to input money function(line53)
		
		//53-55 are virtual as they are redifned in derived class random for random mode.

		class invalidamount{};     //class to handle exception of 0.50 cents
		~Normal_mode_vender();		//destructor to signal end of progrm and display the amount of cash collected for the day
		

};


//----------------------------------------------------------Class 1 ends-----------------------------------------------------------------


Normal_mode_vender::Normal_mode_vender()
	{
			string vend[numrow][numcol]={{{"wavy"},{"malt"},{"mars"},{"Bar6"},{"pringles"}},
			{{"snickers"},{"soda"},{"twix"},{"glee"},{"lemonade"}},
			{{"lays"},{"cola"},{"prince"},{"nuts"},{"foxs"}},
			{{"tops"},{"vita"},{"KIT-KAT"},{"oreo"},{"FIZZ"}},
			{{"moro"},{"red-bull"},{"milo"},{"Snackers"},{"fudge"}},
			{{"bamm"},{"chocochip"},{"lime"},{"rolo"},{"polo"}},
			{{"brandy"},{"snackers"},{"fanta"},{"bounty"},{"bunties"}},
			{{"crackers"},{"pepsi"},{"sprite"},{"Nesfruta"},{"GALAXY"}},
			{{"bourbon"},{"bounty"},{"coyota"},{"MONSTER"},{"Bang"}},
			{{"xyience"},{"V8 Energy"},{"Sting"},{"BOUNTY"},{"Chiz"}}};
			//cout<<fixed<<showpoint<<setprecision(2);	

			int i,j;
			for(i=0;i<numrow;i++)
			{
	
				for(j=0;j<numcol;j++)//price set as default in case owner does not change it
				{
					items[i][j].name=vend[i][j];//structure assigned with string of 2D array. without it no item name is displayed
					if(j==0 || j==6)
					items[i][j].price=1.00;
					else if(j==1)
					items[i][j].price=1.50;
					else if(j==2)
					items[i][j].price=0.50;
					else if(j==4)
					items[i][j].price=2.00;
					else if(j==3 || j==5)
					items[i][j].price=0.25;
					
					items[i][j].qty=5;//initial quantity of all items=5
			
						cout.width(15);//right justified field width of 15
						cout<<right<<items[i][j].name<<":  $"<<fixed<<showpoint<<setprecision(2)<<items[i][j].price;
				}
				if(j==numcol)
				cout<<endl;
			}
			total=0.0;
			money=0.0;
			
	}
	
	void Normal_mode_vender::displaymenu()
	{
			system("cls");
			sleep(2);
			
			string vend[numrow][numcol]={{{"wavy"},{"malt"},{"mars"},{"Bar6"},{"pringles"}},
			{{"snickers"},{"soda"},{"twix"},{"glee"},{"lemonade"}},
			{{"lays"},{"cola"},{"prince"},{"nuts"},{"foxs"}},
			{{"tops"},{"vita"},{"KIT-KAT"},{"oreo"},{"FIZZ"}},
			{{"moro"},{"red-bull"},{"milo"},{"Snackers"},{"fudge"}},
			{{"bamm"},{"chocochip"},{"lime"},{"rolo"},{"polo"}},
			{{"brandy"},{"snackers"},{"fanta"},{"bounty"},{"bunties"}},
			{{"crackers"},{"pepsi"},{"sprite"},{"Nesfruta"},{"GALAXY"}},
			{{"bourbon"},{"bounty"},{"coyota"},{"MONSTER"},{"Bang"}},
			{{"xyience"},{"V8 Energy"},{"Sting"},{"BOUNTY"},{"Chiz"}}};
			cout<<fixed<<showpoint<<setprecision(2);	

			int i,j;
			for(i=0;i<numrow;i++)
			{
	
				for(j=0;j<numcol;j++)
				{
					items[i][j].name=vend[i][j];
					if(j==0)
					items[i][j].price=1.00;
					else if(j==1)
					items[i][j].price=1.50;
					else if(j==2 || j==4)
					items[i][j].price=0.50;
					else if(j==3 || j==5)
					items[i][j].price=2.00;
					
					items[i][j].qty=5;
					
					if(j==numcol)
					cout<<endl;
					
					
					
						cout.width(15);
						cout<<right<<items[i][j].name<<":  $"<<items[i][j].price;
				}
				if(j==numcol)
				cout<<endl;
			}
	}
	
	
	
	void Normal_mode_vender::changepasscode() //belongs to bas class Normal_mode_vender
	{
		int passcodenew;
		cout<<"if you wish to change pass code change here:\n"; //to change passcode
		cout<<"enter new passcode: ";
		cin>>passcodenew;
		passcode=passcodenew;
	}
			

	bool Normal_mode_vender::verifypasscode(int passcodemain)  //belongs to base class Normal_mode_vender
	{

		if (passcode==passcodemain) //checks if passcode entered is same as the one of owner
		return true;
		else
		return false;	
	}	
	
	
	
	
	
	
	
	
	void Normal_mode_vender::setitempriceandqty(int choicer,int choicec)
	{
		
 		//	string vend[numrow][numcol]={{{"wavy"},{"malt"},{"mars"},{"Bar6"},{"pringles"}},{{"snickers"},{"soda"},{"twix"},{"glee"},{"lemonade"}},{{"lays"},{"cola"},{"prince"},{"nuts"},{"foxs"}},
		//	{{"tops"},{"vita"},{"KIT-KAT"},{"oreo"},{"FIZZ"}},{{"moro"},{"red-bull"},{"milo"},{"Snackers"},{"fudge"}},{{"bamm"},{"chocochip"},{"lime"},{"rolo"},{"polo"}},{{"brandy"},{"snackers"},{"fanta"},{"bounty"},{"bunties"}},
		//	{{"crackers"},{"pepsi"},{"sprite"},{"Nesfruta"},{"GALAXY"}},{{"bourbon"},{"bounty"},{"coyota"},{"MONSTER"},{"Bang"}},{{"xyience"},{"V8 Energy"},{"Sting"},{"BOUNTY"},{"Chiz"}}};
			//int rsip,csip;//row set item price and column set item price
			cout<<"Enter row to edit price and quantity\n";cin>>choicer;
			cout<<"Enter column to edit price and quantity\n";cin>>choicec;
			while(choicer<=0 || choicec<=0 || choicec>numcol || choicer>numrow )
			{
				cout<<"invalid Entry enter again...\n"; //to handle exception of invalid row/column entry
				cout<<"select row\n";
				cin>>choicer;
				cout<<"select column\n";
				cin>>choicec;
			
			}
			int exiteritempriceandqty; //to exit from editing data
			for(int i=0;i<numrow;i++)
			{
				for(int j=0;j<numcol;j++)
				{
					cout<<"set the price for item: "<<items[choicer-1][choicec-1].name<<": $";
					cin>>items[choicer-1][choicec-1].price;
					

					cout<<"set the quantity of this item to be fed in the vending machine: "<<endl;
					cin>>items[choicer-1][choicec-1].qty;
					
					cout<<"Enter -1 to exit or any other number to continue\n";
					cin>>exiteritempriceandqty;
					if(exiteritempriceandqty==-1)
						break;
					else
					{
						cout<<"Enter row to edit price and quantity\n";cin>>choicer;
						cout<<"Enter column to edit price and quantity\n";cin>>choicec;
					}
				
				}
				if(exiteritempriceandqty==-1)
				break;
			}

	}
	
	
	
	
	void Normal_mode_vender::displaydata()  //modified data by owner can be used by owner and customer uses protected and public
	{
		system("cls");
		cout<<"now displaying...\n\n";
		
		string vend[numrow][numcol]={{{"wavy"},{"malt"},{"mars"},{"Bar6"},{"pringles"}},
		{{"snickers"},{"soda"},{"twix"},{"glee"},{"lemonade"}},
		{{"lays"},{"cola"},{"prince"},{"nuts"},{"foxs"}},
		{{"tops"},{"vita"},{"KIT-KAT"},{"oreo"},{"FIZZ"}},
		{{"moro"},{"red-bull"},{"milo"},{"Snackers"},{"fudge"}},
		{{"bamm"},{"chocochip"},{"lime"},{"rolo"},{"polo"}},
		{{"brandy"},{"snackers"},{"fanta"},{"bounty"},{"bunties"}},
		{{"crackers"},{"pepsi"},{"sprite"},{"Nesfruta"},{"GALAXY"}},
		{{"bourbon"},{"bounty"},{"coyota"},{"MONSTER"},{"Bang"}},
		{{"xyience"},{"V8 Energy"},{"Sting"},{"BOUNTY"},{"Chiz"}}};
		
		cout<<fixed<<showpoint<<setprecision(2);	

		int i,j;
		for(i=0;i<numrow;i++)
			{
	
				for(j=0;j<numcol;j++)
				{
						cout.width(15);
					
						cout<<right<<items[i][j].name<<":  $"<<items[i][j].price;
				}
				if(j==numcol)
				cout<<endl;
			}
	
	
	}
	
	
	
	Normal_mode_vender::~Normal_mode_vender() //destructor to show amount of cash collected for the day
	{
		
		if(cashbox==50) //in-case owner does not fill cashbox, default amount is 50
		{
			cout<<"The total amount of money collected for the day is $"<<(cashbox-total)<<endl;
		}
		else
		cout<<"The total amount of money collected for the day is $"<<(total-cashbox)<<endl;
		//delete data in allocated memory
	
	}
	
	


	void Normal_mode_vender::cashcollected()  //derived class using cashbox and total members
	{
		cout<<"total money collected in cashbox are: $"<<(total)<<endl;
		cout<<"press 0 to empty cash box:\nPress 1 to modify amount in cashbox\n";
		int emptier;		//to choose option of either emptying cashbox or modifying the amount in it
		cin>>emptier;
		while(emptier!=0 && emptier!=1) //exception handler
		{
			cout<<"invalid input...try again\n";
			cin>>emptier;
		}
		if(emptier==0)
		{
			cout<<"cashbox has been emptied\n";
			total=0;
		}
		else if(emptier==1)
		{
			cout<<"enter the amount you would like to refill the cash box with: $";
			cin>>cashbox;
			while(cashbox<0)
			{
				cout<<"Enter valid amount of money please\n";
				cin>>cashbox;
			}
			total+=cashbox;
			cout<<"now the total amount in cashbox is: $"<<(total)<<endl;
		}
	}
	

	
			


//------------------------------------------------------Functions of derived class---------------------------------------------------------------------------------------------
				
	
	void Normal_mode_vender::inputmoney(int choicer,int choicec)  //to input money from customer (main.cpp 124 and 126 line)
	{
		
			cout<<"The cost for "<<items[choicer - 1][choicec-1].name<< " is $ "<<items[choicer-1][choicec-1].price<<endl;
			cout<<"Insert the amount for desired item: $";
			cin>>money;
			while(money!=0.10 && money!=0.25 && money!=1.00 && money!=2.00) //exception handling loop to ensure that invalid amount of money is not entered
			{
				cout<<"Invalid amount please enter 10 cents, 25 cents, 1 dollar or 2 dollar coins\n";
				money=0;
				cout<<"Insert the amount for desired item: $";
				cin>>money;
				if(money==0.50)
					{
						while(money==0.50)
						{
							cout<<"invalid amount entered,Cant accept 50 cents "<<endl;  //exception
							throw invalidamount();  //exception handler for 50 cents
							money=0;
							cin>>money;
						}
					}
			}
			
			
			if(cashbox==0)  //incase noone filled cashbox it will have $50 as default for change
				{
					cashbox=50.00;  
				}
		
				
			if(cashbox<2.00) //when cashbox is less than 2.00 message displays. Very Rare event to occur
				{
					while(cashbox<2.00)
					{
						cout<<"Enter exact amount as change box is almost empty\n";
						cin>>money;
					}
				}
			
			
			double insufficientmoney;	//in case insufficient amount is entered  
			if (money<items[choicer-1][choicec-1].price)
			{
				while(money<items[choicer-1][choicec-1].price)
				{
					
					insufficientmoney+=money;	
						
					if(insufficientmoney>=items[choicer-1][choicec-1].price || money>=items[choicer-1][choicec-1].price) //when input money(coins) is greater than or equal to amount of item the item will be dispensed to user
					{
						money=insufficientmoney;
						enoughmoney=true;
					}	
					else
					{
						cout << "Can not deliver desired item, not enough money entered"<<endl;
						enoughmoney=false;	
						cout<<"Insert the amount for desired item: $";
						cin>>money;
				
				
						while(money!=0.10 && money!=0.25 && money!=1.00 && money!=2.00)
						{
							int invalidmoneyreturn=money;
							cout<<"Invalid amount please enter 10 cents, 25 cents, 1 dollar or 2 dollar coins\n";
							cout<<"Invalid amount dispensed through return slot: $"<<money<<endl;
							money-=invalidmoneyreturn;
							cout<<"Insert the amount for desired item: $";
							cin>>money;
					
						}
					}
				}//while (money<items)
			}//if(money<items)
			
			else
			{
				enoughmoney=true;
			}
				
			
	}
	
	
	void Normal_mode_vender::buyitem(int choicer,int choicec) //could be derived class from funds. to buy item from vender.ponter of class points to this function which inturn calls to input money function
	{
		char purchasechoice;
		inputmoney(choicer,choicec);
		if (enoughmoney)
		{
			cout<<"Confirm purchase for item?(Y/N)  ";
			cin>>purchasechoice;
		while (toupper(purchasechoice)!='Y' && toupper(purchasechoice)!='N') //in case invalid choice is entered
		{
			cout<<"Please enter a valid option, purchase item (Y/N)? ";
			cin>>purchasechoice;
		}


		if (toupper(purchasechoice)=='Y')
		{
			if (items[choicer-1][choicec-1].qty<=0) //if item is sold out the money will be returned to customer
			{
				cout<<"This item is SOLD OUT!" << endl;
				cout<<"Here is your deposited amount back $"<<money<<endl;
			}
			else
			{
				cout<<"Here is your purchased item enjoy..."<<endl;
				cout<<items[choicer-1][choicec-1].name<<endl;
				total+=items[choicer-1][choicec-1].price;
				items[choicer-1][choicec-1].qty-=1;
			}
			
			

			if (money>items[choicer-1][choicec-1].price) //to return change from cashbox
			{
				money-=items[choicer-1][choicec-1].price;
	
				cout<<"Your change is $" <<money<<endl;
			}
		}
		
		else
		cout<<"Here is your money back $" << money << endl;
		}
		
	}



#endif
