#ifndef Random_mode_H
#define Random_mode_H
#include "Normal_mode.h"

using namespace std;




class random:public Normal_mode_vender //deroved class for random mode of vending machine.Has all protected members and functions of base class
{

	public:
		//almost all these functions were virtual in base class and are redefined here with random values 
		void setitempriceandqty(int choicerow,int choicecolumn);
		void displaymenu();
		void displaydata();
		void cashcollected();
		void buyitem(int choicer,int choicec);
		void inputmoney(int choicer,int choicec);
		~random();
	
};


//----------------------------------------------------Class 3 ends--------------------------------------------------------------------------------


//--------------------------------------------------Functions of random class---------------------------------------------------------------
	

	
	void random::displaymenu() //same role as in base class
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
	
	
	
	
	
	
	void random::setitempriceandqty(int choicer,int choicec)//redefined
	{
		
			cout<<"Enter row to edit price and quantity\n";choicer=(rand()%numrow)+1;cout<<choicer<<endl;
			cout<<"Enter column to edit price and quantity\n";choicec=(rand()%numcol)+1;cout<<choicec<<endl;
			while(choicer<=0 || choicec<=0 || choicec>numcol || choicer>numrow )
			{
				cout<<"invalid Entry enter again...\n";
				cout<<"select row\n";
				choicer=(rand()%numrow)+1; //random row selected
				cout<<choicer;
				cout<<"select column\n";
				choicec=(rand()%numcol)+1;//random column selected
				cout<<choicec;
			
			}
			int exiteritempriceandqty; //to exit from editing data
			for(int i=0;i<numrow;i++)
			{
				for(int j=0;j<numcol;j++)
				{
				
				//	items[i][j].name=vend[i][j];
				sleep(3);
					cout<<"set the price for item: "<<items[choicer-1][choicec-1].name<<": $";
					items[choicer-1][choicec-1].price=(rand()%3)+0.25;    //to set random prices for items
					cout<<items[choicer-1][choicec-1].price<<endl;
					

					cout<<"set the quantity of this item to be fed in the vending machine: "<<endl;
					items[choicer-1][choicec-1].qty=rand()%10;			// random quantity of items
					cout<<items[choicer-1][choicec-1].qty<<endl;
					sleep(4);
					
					//if(j==numcol)
					//cout<<endl;
					cout<<"Enter -1 to exit or any other number to continue\n";
					exiteritempriceandqty=(rand()%2)-1;				//random option
					cout<<exiteritempriceandqty<<endl;
					if(exiteritempriceandqty==-1)
						break;
					else
					{
						cout<<"Enter row to edit price and quantity\n";choicer=(rand()%numrow)+1;cout<<choicer<<endl;
						cout<<"Enter column to edit price and quantity\n";choicec=(rand()%numcol)+1;cout<<choicec<<endl;
					}
				
				}
				sleep(3);
				if(exiteritempriceandqty==-1)
				break;
			}

	}
	
	
	
	
	void random::displaydata()  //modified data by owner can be used by owner and customer uses protected and public. Same function as base class but now applies randomized values
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
	


	void random::cashcollected()  //derived class using cashbox and total members
	{
		cout<<"total money collected in cashbox are: $"<<(total)<<endl;
		cout<<"press 0 to empty cash box:\nPress 1 to modify amount in cashbox\n";
		int emptier;
		emptier=(rand()%3);
		cout<<emptier<<endl;
		while(emptier!=0 && emptier!=1)
		{
			cout<<"invalid input...try again\n";
			emptier=(rand()%3);
			cout<<emptier;
		}
		if(emptier==0)
		{
		cout<<"cashbox has been emptied\n";
		total=0;
		}
		else if(emptier==1)
		{
			cout<<"enter the amount you would like to refill the cash box with: $";
			cashbox=(rand()%50)+1;
			cout<<cashbox<<endl;
		
			total+=cashbox;
			cout<<"now the total amount in cashbox is: $"<<(total)<<endl;
		}
		sleep(3);
	}
	

	
	void random::inputmoney(int choicer,int choicec)  //redefined in derived class.could be derived class in funds. 
	{
		
			cout<<"The cost for "<<items[choicer - 1][choicec-1].name<< " is $ "<<items[choicer-1][choicec-1].price<<endl;
			cout<<"Insert the amount for desired item: $";
			money=(rand()%3); //random money enterer
			cout<<money<<endl;
			while(money!=0.10 && money!=0.25 && money!=1.00 && money!=2.00)
			{
				cout<<"Invalid amount please enter 10 cents, 25 cents, 1 dollar or 2 dollar coins\n";
				money=0;
				cout<<"Insert the amount for desired item: $";
				money=((rand()%3));
				cout<<money<<endl;
				if(money==0.50)
					{
						while(money==0.50)
						{
							cout<<"invalid amount entered,Cant accept 50 cents "<<endl;  //exception
							throw invalidamount();
							money=0;
							money=((rand()%3));
							cout<<money<<endl;
						}
					}
			}
			
			
			if(cashbox==0)  //incase noone filled cashbox it will have $50 as default for change
				{
					cashbox=50.00;  
				}
		
				
			if(cashbox<2.00)
				{
					while(cashbox<2.00)
					{
						cout<<"Enter exact amount as change box is almost empty\n";
						money=((rand()%3));
						cout<<money<<endl;
					}
				}
			
			
			double insufficientmoney;	
			if (money<items[choicer-1][choicec-1].price)
			{
				while(money<items[choicer-1][choicec-1].price)
				{
					
					insufficientmoney+=money;
					//cout<<insufficientmoney;	
						
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
						money=((rand()%3));
						cout<<money<<endl;
				
				
						while(money!=0.10 && money!=0.25 && money!=1.00 && money!=2.00)
						{
							int invalidmoneyreturn=money;
							cout<<"Invalid amount please enter 10 cents, 25 cents, 1 dollar or 2 dollar coins\n";
							cout<<"Invalid amount dispensed through return slot: $"<<money<<endl;
							money-=invalidmoneyreturn;
							cout<<"Insert the amount for desired item: $";
							money=((rand()%3));
							cout<<money<<endl;
					
						}
					}
				}//while (money<items)
			}//if(money<items)
			
			else
			{
				enoughmoney=true;
			}
				
			
	}	
	
	
	void random::buyitem(int choicer,int choicec) //could be derived class
	{
		char purchasechoice[7]={'y','n','t','f','Y','A','N'}; //array of random options including some others other than y or n
		int index;
		inputmoney(choicer,choicec);
		if (enoughmoney)
		{
			cout<<"Confirm purchase for item?(Y/N)  ";
		
			for(int i=0;i<1;i++)
			{
				index=(rand()%7);
				cout<<purchasechoice[index]<<endl;
			}
		while (toupper(purchasechoice[index])!='Y' && toupper(purchasechoice[index])!='N')
		{
			cout<<"Please enter a valid option, purchase item (Y/N)? ";
			for(int i=0;i<1;i++)
			{
				index=(rand()%7); //radom element out of array
				cout<<purchasechoice[index]<<endl;
			}
			
		}


		if (toupper(purchasechoice[index])=='Y')
		{
			if (items[choicer-1][choicec-1].qty<=0)
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
			
			

			if (money>items[choicer-1][choicec-1].price)
			{
				money-=items[choicer-1][choicec-1].price;
	
				cout<<"Your change is $" <<money<<endl;
			}
		}
		else if(money>total)
		{
			cout << "Here is your money back $" << money << endl;
		}
		else
		cout<<"Here is your money back $" << money << endl;
		}
	}
	
	
	
	random::~random() //to display amount collected in cashbox in random mode
	{
		
		if(cashbox==50)
		{
			cout<<"The total amount of money collected for the day is $"<<(cashbox-total)<<endl;
		}
		else
		cout<<"The total amount of money collected for the day is $"<<(total-cashbox)<<endl;
		//delete data in allocated memory
	
	}
	
	
	
	
	
	//--------------------------------------------------functions end---------------------------------------------------------------------------
	


#endif
