/*                           CSCI 1300 PROJECT
                      Coffee Shop Menu Management System
             -> The system allows customers to view menu make an order, add, delete, update, search 
			    and displays details of the order to the customer. 
*/
//All libraries included for program 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

//use of structure for tax and special reservation fee
struct Fee
{
	int cust_price;
	int tax;
};
//All function prototypes 
void mainMenu();
void allData();
void customerData(string& name,int& contactNum,int& seat, int& specialOffer, char& special);
void putOrders(int& espresso,int& Iceblend,int& tea);
void DisplayArray();
void orderValues();
void displayValues(int& espresso,int& Iceblend,int& tea, int& specialOffer);
void deleteItem(int& espresso,int& Iceblend,int& tea, int& specialOffer);
void updateOrder(int& espresso,int& Iceblend,int& tea, int& specialOffer); 
void getallCalc();
void orderPrice(int& espresso);
void paymentSlip();
//All global variables
string name;
int array[4];
int contactNum[10], seat, espresso, Iceblend, tea, specialOffer; //for customer details and menu order
char choice, special;
double e, i, t, s; // variables for espresso, iceblend, tea and specials order prices
//The main method
int main()
{
	do {
	cout << "\n\n\n\n\n\n";
	cout << "\t***********************************************************************" << endl;
	cout << "\t*     ooooooo    ooooooo    ooooooo    ooooooo    ooooooo    ooooooo  *" << endl;
	cout << "\t*     o          o     o    o          o          o          o        *" << endl;
	cout << "\t*     o          o     o    oooo       oooo       oooo       oooo     *" << endl;
	cout << "\t*     o          o     o    o          o          o          o        *" << endl;
	cout << "\t*     ooooooo    ooooooo    o          o          ooooooo    ooooooo  *" << endl;
	cout << "\t*                                                                     *" << endl;
	cout << "\t*                ooooooo    o     o    ooooooo    oooooo              *" << endl;
	cout << "\t*                o          o     o    o     o    o     o             *" << endl;
	cout << "\t*                ooooooo    ooooooo    o     o    oooooo              *" << endl;
	cout << "\t*                      o    o     o    o     o    o                   *" << endl;
	cout << "\t*                ooooooo    o     o    ooooooo    o                   *" << endl;
	cout << "\t***********************************************************************" << endl;
	cout << endl << endl;
	
	system("PAUSE"); //to pause parent program
	system("CLS");   // to clear screen
	
	//Function calls
	mainMenu();
	allData();
	//options for customer to display, add, delete, update orders
	char option;
    orderValues();
    //do-while loop for customer to choose options    
    do
    {
        cout<<"\t\t\tEnter 1 to Display order\n\t\t\tEnter 2 to Update order\n\t\t\tEnter 3 to Delete item\n\n\t\t\t or Enter E to end order\n\n\t\t\t Enter Option: ->  ";
        cin >> option;
        if(option == '1')
          {
            cout<<"Display order."<< endl;
            displayValues(espresso, Iceblend, tea, specialOffer);
            cout<<"Order displayed sucessfully!"<< endl << endl;
            DisplayArray();
            paymentSlip();
          }
        else if(option == '2')
          {
           updateOrder(espresso,Iceblend,tea,specialOffer);
           cout<<"Updated order :"<< endl << endl;
           DisplayArray();
           paymentSlip();
          }
        else if(option == '3')
          {
           deleteItem(espresso, Iceblend,tea, specialOffer);
           cout<<"Order after deleting items :"<< endl <<endl;
           DisplayArray();
           paymentSlip();
          }
        else if(option != 'E' && option != 'e')
		{
		    cout<<"\n\n\t\t\tSelect A Valid Option From Below\n\n";	
		} 
		 
    }while(option != 'E' && option != 'e');
	
	//order slip function call
	getallCalc();
	//Receipt for the customer
	cout << "________________________" << endl; 
	cout << "PAYMENT CHECK-IN RECEIPT" << endl;
	cout << "________________________________________________" << endl;
	cout << "________________________________________________" << endl;
	//payment function call
	paymentSlip();
	//prompt user whether they want to return to menu screen
	char choice;
	cout << "Exit to main menu(Y/N)?: " << endl;
	cin >> choice;
	
	//if statement to determine the choice of the customer
	if(choice == 'N' || choice == 'n')
	{
		exit(80); // exit function from stdlib library used here
	}

   }while(choice == 'Y' || choice == 'y');
   return main();
   
   system("PAUSE");
   
   return 0;
   		
}
/*Function definitions with respective functions for the management system
  Main Menu function */
void mainMenu()
{   //displays to customer the applications list of the program
    cout << endl;
	cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "\t\t++        WELCOME TO COFFEE SHOP MENU MANAGEMENT SYSTEM        ++" << endl;
	cout << "\t\t++        ---------------------------------------------        ++" << "\n\n";
	cout << "\t\t++        *********************************************        ++" << "\n\n";
	cout << "\t\t++        **        1. CUSTOMER DATA DETAILS         **        ++" << "\n\n";
	cout << "\t\t++        **        2. CUSTOMER ORDERS               **        ++" << "\n\n";
	cout << "\t\t++        **        3. ORDERED LIST                  **        ++" << "\n\n";
	cout << "\t\t++        **        4. CALCULATE ORDER PAYMENT       **        ++" << "\n\n";
	cout << "\t\t++        **        5. PRINT ORDERED PAYMENT SLIP    **        ++" << "\n\n";
	cout << "\t\t++        *********************************************        ++" << "\n\n";
	cout << "\t\t++        ---------------------------------------------        ++" << "\n\n";
	cout << "\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << "\n\n";
	
	system("PAUSE");
	system("CLS");
	
	return ;
			
} 
//All data from other functions called here for display of ordered list
void allData()
{
	customerData(name, contactNum[10], seat, specialOffer, special);
	cout << endl;
	putOrders(espresso, Iceblend, tea);
	cout << endl;
}
//customer data details reservation for booking of special offers 
void customerData(string& name,int& contactNum, int& seat, int& specialOffer, char& special) 
{
	cout << "----------------------------------"<< endl;
	cout << ">         CUSTOMER DATA          <"<< endl;
	cout << "----------------------------------"<< endl;
	
	//design for customer entry data
	cout << "1. Customer's Full Name: ";
	getline(cin, name); //getline() function to get the full name of customer 
	
	cout << "2. Contact Number: ";
	cin >> contactNum;
	
	cout << "3. Number of seats: ";
	cin >> seat;
	cout << endl << endl;
	do {
		cout << "4. Do you want to reserve afternoon specials?(Y/N): " << endl;
		cin >> special;
		
		cout << endl;
		//if statement to validate user input
		if(special == 'Y' || special == 'y')
	    {
		    cout << "Kindly choose from the following menu: " << endl << endl;
		    break;
	    }
		//if statement when user input no
	    else if(special == 'N' || special == 'n')
	    {
	        
			cout << "Kindly choose option 5 to skip" << endl;
	    }
		else
		{
			cout << "Invalid input! Please try again." << endl << endl;
		}
	}while(special != 'Y'|| special != 'y'|| special != 'N' || special != 'n');
	
    //if user input Y or N they still recieve the menu	
	do {
	//design for special offers in the afternoon
	cout << "\t\t()()()()()()()()()()()()()()()()()()()" << endl;
	cout << "\t\t()     AFTERNOON SPECIAL OFFERS     ()" << endl;
	cout << "\t\t() 1. COFFEE JELLY        RM 4.00   ()" << endl;
	cout << "\t\t() 2. LATTE CUPCAKE       RM 5.00   ()" << endl;
	cout << "\t\t() 3. MUFFIN LONG BLACK   RM 6.50   ()" << endl;
	cout << "\t\t() 4. CAPPUCCINO BISCOTTI RM 7.50   ()" << endl;
	cout << "\t\t() 5. SKIP SPECIALS                 ()" << endl;
	cout << "\t\t()()()()()()()()()()()()()()()()()()()" << endl << endl;
	
	//prompt user to reserve special offers 
	cout << "Reservation no. : ";
	cin >> specialOffer;
	
	//if statement to ensure validity of reservation no input by user 
	if(specialOffer < 1 || specialOffer > 5)
	{
		cout << "Invalid input detected! Please try again." << endl;
	}
	
  }while(specialOffer < 1 || specialOffer > 5);
  
  /*switch statements to confirm their order with respective 
   	specials number chosen by the customer */
   	switch(specialOffer)
   	{
   	    case 1: {
   	    	        cout << "You have chosen COFFEE JELLY             RM 4.00" << endl;
   	    	        s = 4.00;
		          } break;
		case 2: {
			        cout << "You have chosen LATTE CUPCAKE            RM 5.00" << endl;
			        s = 5.00;
		          } break;
		case 3: {
			        cout << "You have chosen MUFFIN LONG BLACK        RM 6.50" << endl;
			        s = 6.50;
		        } break;
		case 4:{
			        cout << "You have chosen CAPPUCCINO BISCOTTI      RM 7.50" << endl;
			        s = 7.50;
		       } break;
		case 5:{
			        cout << "No afternoon special reserved!                  " << endl;
	           } break;	   	
		default: {}	   			   	
	}
	cout << endl;
	
	system ("PAUSE");
 
    return;
	  
}
//Menu List display for customers to order
void putOrders(int& espresso,int& Iceblend,int& tea)
{
	do {
	
	cout << "\t\t#########################" << setw(3) << endl;
	cout << "\t\t##       ORDERS        ##" << setw(3) << endl;
	cout << "\t\t## ------------------- ##" << setw(3) << endl;
	cout << "\t\t##   1. Espresso       ##" << setw(3) << endl;
	cout << "\t\t#########################" << setw(3) << endl << endl;
	
	cout << "\t\t[][][][][][][][][][][][][][][][][][]" << endl;
	cout << "\t\t[]   1. AMERICANO       RM 6.00   []" << endl;
	cout << "\t\t[]   2. CAPPUCCINO      RM 5.00   []" << endl;
	cout << "\t\t[]   3. DOUBLE ESPRESSO RM 8.00   []" << endl;
	cout << "\t\t[]   4. LATTE           RM 9.00   []" << endl;
	cout << "\t\t[]   5. MACCHIATO       RM 10.00  []" << endl;
	cout << "\t\t[]   6. MOCHA           RM 15.00  []" << endl;
	cout << "\t\t[]   7. WHITE MOCHA     RM 17.00  []" << endl;
	cout << "\t\t[]   8. HOT CHOCOLATE   RM 18.00  []" << endl;
	cout << "\t\t[]   9. SKIP ORDER                []" << endl;
	cout << "\t\t[][][][][][][][][][][][][][][][][][]" << endl << endl;
	
	//prompt user to reserve espresso number
	cout << "Espresso no. : ";
	cin >> espresso;
	
	//if statement to ensure validity of espresso no
	if(espresso < 1 || espresso > 9)
	{
		cout << "Invalid input detected! Please try again." << endl << endl;
	}
	
   }while(espresso < 1 || espresso > 9);
   
   /*switch statements to confirm their order with respective 
   	espresso number chosen by the customer */ 
   	
   	switch(espresso)
   	{
   		case 1: {
			        cout << "You have chosen AMERICANO       RM 6.00" << endl;
			        e = 6.00;
		        } break;
		case 2: {
			        cout << "You have chosen CAPPUCCINO      RM 5.00" << endl;
			        e = 5.00;
		        } break; 
	    case 3: {
			        cout << "You have chosen DOUBLE ESPRESSO RM 8.00" << endl;
					e = 8.00; 
		        } break;
		case 4: {
			        cout << "You have chosen LATTE           RM 9.00" << endl;
			        e = 9.00;
		        } break;
		case 5: {
			        cout << "You have chosen MACCHIATO       RM 10.00" << endl;
			        e = 10.00;
		        } break;
		case 6: {
			        cout << "You have chosen MOCHA           RM 15.00" << endl;
			        e = 15.00;
		        } break;
		case 7: {
			        cout << "You have chosen WHITE MOCHA     RM 17.00" << endl;
			        e = 17.00;
		        } break;
		case 8: {
			        cout << "You have chosen HOT CHOCOLATE   RM 18.00" << endl;
			        e = 18.00;
		        } break;
		case 9: {
			        cout << "No espresso ordered!                    " << endl;
		        } break;
		default:{} 
    } 
    
    cout << endl;
    
    do {
    	cout << "\t\t## ------------------- ##" << endl;
	    cout << "\t\t##     2. FRAPPE       ##" << endl;
	    cout << "\t\t#########################" << endl << endl;
	    
	    cout << "\t\t[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	    cout << "\t\t[]   1. BUTTERSCOTCH CARAMEL    RM 7.00   []" << endl;
	    cout << "\t\t[]   2. COOKIES AND CREAM       RM 5.60   []" << endl;
	    cout << "\t\t[]   3. HAZELNUT MOCHA          RM 10.00  []" << endl;
	    cout << "\t\t[]   4. MINT CHOCOLATE CHIP     RM 9.50   []" << endl;
	    cout << "\t\t[]   5. COFFEE AND DONUTS       RM 8.40   []" << endl;
	    cout << "\t\t[]   6. VANILLA BEAN            RM 6.20   []" << endl;
	    cout << "\t\t[]   7. MATCHA CREAM            RM 10.40  []" << endl;
	    cout << "\t\t[]   8. SKIP ORDER                        []" << endl;
	    cout << "\t\t[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	    
	    //prompt user for frappe number to order
	    cout << "Frappe no. : ";
	    cin >> Iceblend;
	    
	    //if statement to ensure validity of frappe number input by user
	    if(Iceblend < 1 || Iceblend > 8)
	    {
	    	cout << "Invalid input detected! Please try again." << endl << endl;
		}
	}while(Iceblend < 1 || Iceblend > 8);
	
	/* switch statements to confirm their order with respective 
   	frappe number chosen by the customer */ 
   	switch(Iceblend)
   	{
   		case 1: {
                    cout << "You have chosen BUTTERSCOTCH CARAMEL    RM 7.00" << endl;
                    i = 7.00;
		        } break;
		case 2: {
			        cout << "You have chosen COOKIES AND CREAM       RM 5.60" << endl;
			        i = 5.60;
		        } break;
	    case 3: {
	    	        cout << "You have chosen HAZELNUT MOCHA          RM 10.00" << endl;
	    	        i = 10.00;
		        } break;
		case 4: {
			        cout << "You have chosen MINT CHOCOLATE CHIP     RM 9.50" << endl;
			        i = 9.50;
		        } break;
		case 5: {
			        cout << "You have chosen COFFEE AND DONUTS       RM 8.40" << endl;
			        i = 8.40;
		        } break;
		case 6: {
                    cout << "You have chosen VANILLA BEAN            RM 6.20" << endl;
                    i = 6.20;
		        } break;
		case 7: {
			        cout << "You have chosen MATCHA CREAM            RM 10.40" << endl;
			        i = 10.40;
		        } break;
		case 8: {
			        cout << "No frappe ordered!                              " << endl;
		        } break;        
		default: {}						 							        
	} 
	
	cout << endl;
	
	do {
	
	    cout << "\t\t## ------------------- ##" << endl;
	    cout << "\t\t##       3. TEA        ##" << endl;
	    cout << "\t\t#########################" << endl << endl;
	    
	    cout << "\t\t[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	    cout << "\t\t[]   1. EARL GREY                RM 4.50  []" << endl;
	    cout << "\t\t[]   2. PEACH GREEN              RM 5.50  []" << endl;
	    cout << "\t\t[]   3. STRAWBERRY HIBISCUS      RM 6.40  []" << endl;
	    cout << "\t\t[]   4. MINT ROSEMARY LEMONGRASS RM 9.00  []" << endl;
	    cout << "\t\t[]   5. GINGER CARDAMOM          RM 8.50  []" << endl;
	    cout << "\t\t[]   6. SKIP ORDER                        []" << endl;
	    cout << "\t\t[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	    
	    //prompt user for tea order number
	    cout << "Tea no. : ";
	    cin >> tea;
	    
	    //if statement to ensure validity of tea number input by customer
	    if(tea < 1 || tea > 6)
	    {
	    	cout << "Invalid input detected! Please try again." << endl << endl;
		}
    }while(tea < 1 || tea > 6);
    
    /*switch statements to confirm their order with respective 
   	tea number chosen by the customer */
   	switch(tea)
   	{
   		case 1: {
			        cout << "You have chosen EARL GREY                RM 4.50" << endl;
			        t = 4.50;
		        } break;
		case 2: {
			        cout << "You have chosen PEACH GREEN              RM 5.50" << endl;
			        t = 5.50;
		        } break;
		case 3: {
			        cout << "You have chosen STRAWBERRY HIBISCUS      RM 6.40" << endl;
			        t = 6.40;
		        } break;
		case 4: {
		            cout << "You have chosen MINT ROSEMARY LEMONGRASS RM 9.00" << endl;
		            t = 9.00;
		        } break;
		case 5: {
			        cout << "You have chosen GINGER CARDAMOM          RM 8.50" << endl;
			        t = 8.50;
		        } break;
		case 6: {
			       cout << "No tea ordered!                                  " << endl;
		        } break;        
		default: {}								        
	}
	
	cout << endl;
	system("PAUSE");
	
	return ;	    
} 
void DisplayArray()
{
	for (int i=0;i<4;i++)
         cout<< "Item ["<< i <<"] = "<< array[i]<< endl;
}    
void orderValues()
{   
    for(int i=0;i<4;i++)
    {
        array[i] = 1;
        cout<<"Item ["<< i <<"]" << "= "<< array[i] <<endl;
    }
}
//to display and arrange order to customer 
void displayValues(int& espresso,int& Iceblend,int& tea, int& specialOffer)
{
	//if statements for espresso orders
   if(e == 6.00)
   cout << "Espresso ordered      : " << "AMERICANO       "<< "                RM " << setw(8) << e << endl;
   if(e == 5.00)
   cout << "Espresso ordered      : " << "CAPPUCCINO     " << "                RM " << setw(8) << e << endl;
   if(e == 8.00)
   cout << "Espresso ordered      : " << "DOUBLE ESPRESSO "<< "                RM " << setw(8) << e << endl;
   if(e == 9.00)
   cout << "Espresso ordered      : " << "LATTE "          << "                RM " << setw(8) << e << endl;
   if(e == 10.00)
   cout << "Espresso ordered      : " << "MACCHIATO"       << "                RM " << setw(8) << e << endl;
   if(e == 15.00)
   cout << "Espresso ordered      : " << "MOCHA"           << "                RM " << setw(8) << e << endl;
   if(e == 17.00)	 
   cout << "Espresso ordered      : " << "WHITE MOCHA"     << "                RM " << setw(8) << e << endl;
   if(e == 18.00)
   cout << "Espresso ordered      : " << "HOT CHOCOLATE"   << "                RM " << setw(8) << e << endl;

   //if statements for frappe orders
   if(i == 7.00)
   cout << "Frappe ordered        : " << "BUTTERSCOTCH CARAMEL"<< "            RM " << setw(8) << i << endl;
   if(i == 5.60)
   cout << "Frappe ordered        : " << "COOKIES AND CREAM"   << "            RM " << setw(8) << i << endl;
   if(i == 10.00)
   cout << "Frappe ordered        : " << "HAZELNUT MOCHA"      << "            RM " << setw(8) << i << endl;
   if(i == 9.50)
   cout << "Frappe ordered        : " << "MINT CHOCOLATE CHIP" << "            RM " << setw(8) << i << endl;
   if(i == 8.40)
   cout << "Frappe ordered        : " << "COFFEE AND DONUTS"   << "            RM " << setw(8) << i << endl;
   if(i == 6.20)
   cout << "Frappe ordered        : " << "VANILLA BEAN"        << "            RM " << setw(8) << i << endl;
   if(i == 10.40)
   cout << "Frappe ordered        : " << "MATCHA CREAM"        << "            RM " << setw(8) << i << endl;

   
   //if statements for tea orders
   if(t == 4.50)
   cout << "Tea ordered           : " << "EARL GREY" << "                      RM " << setw(8) << t << endl;
   if(t == 5.50)
   cout << "Tea ordered           : " << "PEACH GREEN" << "                    RM " << setw(8) << t << endl;
   if(t == 6.40)
   cout << "Tea ordered           : " << "STRAWBERRY HIBISCUS" << "            RM " << setw(8) << t << endl;
   if(t == 9.00)
   cout << "Tea ordered           : " << "MINT ROSEMARY LEMONGRASS" << "       RM " << setw(8) << t << endl;
   if(t == 8.50)
   cout << "Tea ordered           : " << "GINGER CARDAMOM" << "                RM " << setw(8) << t << endl;

   //if statements for special orders
   if(s == 4.00)
   cout << "Afternoon special item: " << "COFFEE JELLY" << "                RM " << setw(6) << s << endl;
   if(s == 5.00)
   cout << "Afternoon special item: " << "LATTE CUPCAKE" << "               RM " << setw(6) << s << endl;
   if(s == 6.50)
   cout << "Afternoon special item: " << "MUFFIN LONG BLACK" << "           RM " << setw(6) << s << endl;
   if(s == 7.50)
   cout << "Afternoon special item: " << "CAPPUCCINO BISCOTTI" << "         RM " << setw(6) << s << endl;

}
//To delete order if customer decided to make changes to order
void deleteItem(int& espresso,int& Iceblend,int& tea, int& specialOffer)
{
	//if statements for espresso orders
   if(e == 6.00)
   cout << "Espresso ordered      : " << "AMERICANO       "<< "                RM " << setw(8) << e << endl;
   if(e == 5.00)
   cout << "Espresso ordered      : " << "CAPPUCCINO     " << "                RM " << setw(8) << e << endl;
   if(e == 8.00)
   cout << "Espresso ordered      : " << "DOUBLE ESPRESSO "<< "                RM " << setw(8) << e << endl;
   if(e == 9.00)
   cout << "Espresso ordered      : " << "LATTE "          << "                RM " << setw(8) << e << endl;
   if(e == 10.00)
   cout << "Espresso ordered      : " << "MACCHIATO"       << "                RM " << setw(8) << e << endl;
   if(e == 15.00)
   cout << "Espresso ordered      : " << "MOCHA"           << "                RM " << setw(8) << e << endl;
   if(e == 17.00)	 
   cout << "Espresso ordered      : " << "WHITE MOCHA"     << "                RM " << setw(8) << e << endl;
   if(e == 18.00)
   cout << "Espresso ordered      : " << "HOT CHOCOLATE"   << "                RM " << setw(8) << e << endl;
   
   //if statements for frappe orders
   if(i == 7.00)
   cout << "Frappe ordered        : " << "BUTTERSCOTCH CARAMEL"<< "            RM " << setw(8) << i << endl;
   if(i == 5.60)
   cout << "Frappe ordered        : " << "COOKIES AND CREAM"   << "            RM " << setw(8) << i << endl;
   if(i == 10.00)
   cout << "Frappe ordered        : " << "HAZELNUT MOCHA"      << "            RM " << setw(8) << i << endl;
   if(i == 9.50)
   cout << "Frappe ordered        : " << "MINT CHOCOLATE CHIP" << "            RM " << setw(8) << i << endl;
   if(i == 8.40)
   cout << "Frappe ordered        : " << "COFFEE AND DONUTS"   << "            RM " << setw(8) << i << endl;
   if(i == 6.20)
   cout << "Frappe ordered        : " << "VANILLA BEAN"        << "            RM " << setw(8) << i << endl;
   if(i == 10.40)
   cout << "Frappe ordered        : " << "MATCHA CREAM"        << "            RM " << setw(8) << i << endl;
   
   
   //if statements for tea orders
   if(t == 4.50)
   cout << "Tea ordered           : " << "EARL GREY" << "                      RM " << setw(8) << t << endl;
   if(t == 5.50)
   cout << "Tea ordered           : " << "PEACH GREEN" << "                    RM " << setw(8) << t << endl;
   if(t == 6.40)
   cout << "Tea ordered           : " << "STRAWBERRY HIBISCUS" << "            RM " << setw(8) << t << endl;
   if(t == 9.00)
   cout << "Tea ordered           : " << "MINT ROSEMARY LEMONGRASS" << "       RM " << setw(8) << t << endl;
   if(t == 8.50)
   cout << "Tea ordered           : " << "GINGER CARDAMOM" << "                RM " << setw(8) << t << endl;
   
   //if statements for special orders
   if(s == 4.00)
   cout << "Afternoon special item: " << "COFFEE JELLY" << "                RM " << setw(6) << s << endl;
   if(s == 5.00)
   cout << "Afternoon special item: " << "LATTE CUPCAKE" << "               RM " << setw(6) << s << endl;
   if(s == 6.50)
   cout << "Afternoon special item: " << "MUFFIN LONG BLACK" << "           RM " << setw(6) << s << endl;
   if(s == 7.50)
   cout << "Afternoon special item: " << "CAPPUCCINO BISCOTTI" << "         RM " << setw(6) << s << endl;
   //array list for deletion of item from display of ordered items 
   int delNum;
   
    cout << "Item[0] is special offer, Item[1] is espresso, Item[2] is frappe, Item[3] is tea." <<endl;
   //prompt user to ask which item to delete
   cout<<"Enter the Item Number To Delete Order :";
   cin >> delNum;
    
    if(delNum > 4 || delNum < 0)
    {
        cout<<"Invalid Item Entered-> Valid Range(0-4)"<<endl;
        deleteItem(espresso,Iceblend,tea, specialOffer);// Recall the function
    }
    else
    {
        array[delNum] = 0;
    }
    cout<<"\n\t\t\tItem Deleted...  Successfully "<<endl;
	
}
//To update order after add/remove of items 
void updateOrder(int& espresso,int& Iceblend,int& tea, int& specialOffer)
{
	//if statements for espresso orders
   if(e == 6.00)
   cout << "Espresso ordered      : " << "AMERICANO       "<< "                RM " << setw(8) << e << endl;
   if(e == 5.00)
   cout << "Espresso ordered      : " << "CAPPUCCINO     " << "                RM " << setw(8) << e << endl;
   if(e == 8.00)
   cout << "Espresso ordered      : " << "DOUBLE ESPRESSO "<< "                RM " << setw(8) << e << endl;
   if(e == 9.00)
   cout << "Espresso ordered      : " << "LATTE "          << "                RM " << setw(8) << e << endl;
   if(e == 10.00)
   cout << "Espresso ordered      : " << "MACCHIATO"       << "                RM " << setw(8) << e << endl;
   if(e == 15.00)
   cout << "Espresso ordered      : " << "MOCHA"           << "                RM " << setw(8) << e << endl;
   if(e == 17.00)	 
   cout << "Espresso ordered      : " << "WHITE MOCHA"     << "                RM " << setw(8) << e << endl;
   if(e == 18.00)
   cout << "Espresso ordered      : " << "HOT CHOCOLATE"   << "                RM " << setw(8) << e << endl;
   
   //if statements for frappe orders
   if(i == 7.00)
   cout << "Frappe ordered        : " << "BUTTERSCOTCH CARAMEL"<< "            RM " << setw(8) << i << endl;
   if(i == 5.60)
   cout << "Frappe ordered        : " << "COOKIES AND CREAM"   << "            RM " << setw(8) << i << endl;
   if(i == 10.00)
   cout << "Frappe ordered        : " << "HAZELNUT MOCHA"      << "            RM " << setw(8) << i << endl;
   if(i == 9.50)
   cout << "Frappe ordered        : " << "MINT CHOCOLATE CHIP" << "            RM " << setw(8) << i << endl;
   if(i == 8.40)
   cout << "Frappe ordered        : " << "COFFEE AND DONUTS"   << "            RM " << setw(8) << i << endl;
   if(i == 6.20)
   cout << "Frappe ordered        : " << "VANILLA BEAN"        << "            RM " << setw(8) << i << endl;
   if(i == 10.40)
   cout << "Frappe ordered        : " << "MATCHA CREAM"        << "            RM " << setw(8) << i << endl;
   
   
   //if statements for tea orders
   if(t == 4.50)
   cout << "Tea ordered           : " << "EARL GREY" << "                      RM " << setw(8) << t << endl;
   if(t == 5.50)
   cout << "Tea ordered           : " << "PEACH GREEN" << "                    RM " << setw(8) << t << endl;
   if(t == 6.40)
   cout << "Tea ordered           : " << "STRAWBERRY HIBISCUS" << "            RM " << setw(8) << t << endl;
   if(t == 9.00)
   cout << "Tea ordered           : " << "MINT ROSEMARY LEMONGRASS" << "       RM " << setw(8) << t << endl;
   if(t == 8.50)
   cout << "Tea ordered           : " << "GINGER CARDAMOM" << "                RM " << setw(8) << t << endl;
   
   //if statements for special orders
   if(s == 4.00)
   cout << "Afternoon special item: " << "COFFEE JELLY" << "                RM " << setw(6) << s << endl;
   if(s == 5.00)
   cout << "Afternoon special item: " << "LATTE CUPCAKE" << "               RM " << setw(6) << s << endl;
   if(s == 6.50)
   cout << "Afternoon special item: " << "MUFFIN LONG BLACK" << "           RM " << setw(6) << s << endl;
   if(s == 7.50)
   cout << "Afternoon special item: " << "CAPPUCCINO BISCOTTI" << "         RM " << setw(6) << s << endl;
   
   cout << "Item[0] is special offer, Item[1] is espresso, Item[2] is frappe, Item[3] is tea." <<endl;
   //prompt user to enter order items to update
   cout<<"Enter Item Number to Update :";
        int update;
        cin >> update;
        if(update > 4 || update < 0)
        {
            cout<<"Invalid Item Entered-> Valid Range(0-4)"<<endl;
            updateOrder(espresso,Iceblend,tea,specialOffer);// Recall The Function
        }
        else
        {
            cout<<"Enter the New Value To Update Item [ "<< update <<" ] = ";
            cin >> array[update];
            cout<<"\n\t\t\tOrder Updated...  Successfully "<<endl;
        }    

}
//To get all calculations for the order prices
void getallCalc()
{
	orderPrice(espresso);
}
// the calculation for the order prices
void orderPrice(int& espresso)
{
   //structure and pointer defined here for reservation and tax fee 
   Fee money;
   Fee* ptr = &money;
   ptr->cust_price = 10;
   ptr->tax = 20;
   
   //variable for total calculation
   int total;
   //total calculation using addition operator
   total = e + i + t + s + ptr->cust_price + ptr->tax;
   
   //design for payment
   cout << " -------------------------- " << endl;
   cout << "|         PAYMENT          |" << endl;
   cout << " -------------------------- " << endl << endl;
   cout << "Orders" << "                                                 " << "Price" << endl;
   cout << "------------------------------------------------------------------------------" << endl<<endl;
   
   //print customer name, reservation no, no of seats etc
   	cout << "\t\tCustomer Receipt" << endl;
	cout << "\t\t----------------" << endl;
	cout << "\nCustomer Name: " << name << endl;
    cout << "Specials reservation no: " << specialOffer << endl; 
	cout << "Number of seats: " << seat << endl;
   
   //if statements for espresso orders
   if(e == 6.00)
   cout << "Espresso ordered      : " << "AMERICANO       "<< "                RM " << setw(8) << e << endl;
   if(e == 5.00)
   cout << "Espresso ordered      : " << "CAPPUCCINO     " << "                RM " << setw(8) << e << endl;
   if(e == 8.00)
   cout << "Espresso ordered      : " << "DOUBLE ESPRESSO "<< "                RM " << setw(8) << e << endl;
   if(e == 9.00)
   cout << "Espresso ordered      : " << "LATTE "          << "                RM " << setw(8) << e << endl;
   if(e == 10.00)
   cout << "Espresso ordered      : " << "MACCHIATO"       << "                RM " << setw(8) << e << endl;
   if(e == 15.00)
   cout << "Espresso ordered      : " << "MOCHA"           << "                RM " << setw(8) << e << endl;
   if(e == 17.00)	 
   cout << "Espresso ordered      : " << "WHITE MOCHA"     << "                RM " << setw(8) << e << endl;
   if(e == 18.00)
   cout << "Espresso ordered      : " << "HOT CHOCOLATE"   << "                RM " << setw(8) << e << endl;
   
   //if statements for frappe orders
   if(i == 7.00)
   cout << "Frappe ordered        : " << "BUTTERSCOTCH CARAMEL"<< "            RM " << setw(8) << i << endl;
   if(i == 5.60)
   cout << "Frappe ordered        : " << "COOKIES AND CREAM"   << "            RM " << setw(8) << i << endl;
   if(i == 10.00)
   cout << "Frappe ordered        : " << "HAZELNUT MOCHA"      << "            RM " << setw(8) << i << endl;
   if(i == 9.50)
   cout << "Frappe ordered        : " << "MINT CHOCOLATE CHIP" << "            RM " << setw(8) << i << endl;
   if(i == 8.40)
   cout << "Frappe ordered        : " << "COFFEE AND DONUTS"   << "            RM " << setw(8) << i << endl;
   if(i == 6.20)
   cout << "Frappe ordered        : " << "VANILLA BEAN"        << "            RM " << setw(8) << i << endl;
   if(i == 10.40)
   cout << "Frappe ordered        : " << "MATCHA CREAM"        << "            RM " << setw(8) << i << endl;
   
   
   //if statements for tea orders
   if(t == 4.50)
   cout << "Tea ordered           : " << "EARL GREY" << "                      RM " << setw(8) << t << endl;
   if(t == 5.50)
   cout << "Tea ordered           : " << "PEACH GREEN" << "                    RM " << setw(8) << t << endl;
   if(t == 6.40)
   cout << "Tea ordered           : " << "STRAWBERRY HIBISCUS" << "            RM " << setw(8) << t << endl;
   if(t == 9.00)
   cout << "Tea ordered           : " << "MINT ROSEMARY LEMONGRASS" << "       RM " << setw(8) << t << endl;
   if(t == 8.50)
   cout << "Tea ordered           : " << "GINGER CARDAMOM" << "                RM " << setw(8) << t << endl;
   
   //if statements for special orders
   if(s == 4.00)
   cout << "Afternoon special item: " << "COFFEE JELLY" << "                RM " << setw(6) << s << endl;
   if(s == 5.00)
   cout << "Afternoon special item: " << "LATTE CUPCAKE" << "               RM " << setw(6) << s << endl;
   if(s == 6.50)
   cout << "Afternoon special item: " << "MUFFIN LONG BLACK" << "           RM " << setw(6) << s << endl;
   if(s == 7.50)
   cout << "Afternoon special item: " << "CAPPUCCINO BISCOTTI" << "         RM " << setw(6) << s << endl;
   
   //if statement for other fees
   if(special == 'Y' || special == 'y')
   cout << "Afternoon special reservation fee                           RM " << setw(5) << money.cust_price << endl;
   cout << "Government tax                                              RM " << setw(4) << money.tax << endl;
   cout << "_________________________________________________________________________" << setw(4) << endl << endl;
   cout << "Total Amount                                                RM " << setw(4) << total << endl << endl;
   
   return;
   
}
//To display all orders in form of customer's payment slip 
void paymentSlip()
{
	//structure and pointer defined here for reservation and tax fee
	Fee money;
	Fee* ptr = &money;
    ptr->cust_price = 10;
    ptr->tax = 20; 
    
    //total variable for sum of the orders
	int total;
	//using addition operator to calculate order 
	total = total = e + i + t + s + ptr->cust_price + ptr->tax; 
	
	//use of ofstream function
	ofstream myFile;
	myFile.open("Payment slip.txt"); 
	
	myFile << "\t\tCustomer Receipt" << endl;
	myFile << "\t\t----------------" << endl;
	myFile << "\nCustomer Name: " << name << endl;
    myFile << "Specials reservation no: " << specialOffer << endl; 
	myFile << "Number of seats: " << seat << endl;
    myFile << "Orders" << "                                                  " << "Price" << setw(4) << endl;
    myFile << "------------------------------------------------------------------------------" << setw(4) << endl<<endl;
    
    //if statements for espresso orders
   if(e == 6.00)
   myFile << "Espresso ordered      : " << "AMERICANO"       << "                RM " << setw(8) << e << endl;
   if(e == 5.00)
   myFile << "Espresso ordered      : " << "CAPPUCCINO"      << "                RM " << setw(8) << e << endl;
   if(e == 8.00)
   myFile << "Espresso ordered      : " << "DOUBLE ESPRESSO" << "                RM " << setw(8) << e << endl;
   if(e == 9.00)
   myFile << "Espresso ordered      : " << "LATTE "          << "                RM " << setw(8) << e << endl;
   if(e == 10.00)
   myFile << "Espresso ordered      : " << "MACCHIATO"       << "                RM " << setw(8) << e << endl;
   if(e == 15.00)
   myFile << "Espresso ordered      : " << "MOCHA"           << "                RM " << setw(8) << e << endl;
   if(e == 17.00)	 
   myFile << "Espresso ordered      : " << "WHITE MOCHA"     << "                RM " << setw(8) << e << endl;
   if(e == 18.00)
   myFile << "Espresso ordered      : " << "HOT CHOCOLATE"   << "                RM " << setw(8) << e << endl;
   
   
   //if statements for frappe orders
   if(i == 7.00)
   myFile << "Frappe ordered        : " << "BUTTERSCOTCH CARAMEL" << "           RM " << setw(8) << i << endl;
   if(i == 5.60)
   myFile << "Frappe ordered        : " << "COOKIES AND CREAM"    << "           RM " << setw(8) << i << endl;
   if(i == 10.00)
   myFile << "Frappe ordered        : " << "HAZELNUT MOCHA"       << "           RM " << setw(8) << i << endl;
   if(i == 9.50)
   myFile << "Frappe ordered        : " << "MINT CHOCOLATE CHIP"  << "           RM " << setw(8) << i << endl;
   if(i == 8.40)
   myFile << "Frappe ordered        : " << "COFFEE AND DONUTS"    << "           RM " << setw(8) << i << endl;
   if(i == 6.20)
   myFile << "Frappe ordered        : " << "VANILLA BEAN "        << "           RM " << setw(8) << i << endl;
   if(i == 10.40)
   myFile << "Frappe ordered        : " << "MATCHA CREAM"         << "           RM " << setw(8) << i << endl;
   
   
   //if statements for tea orders
   if(t == 4.50)
   myFile << "Tea ordered           : " << "EARL GREY"            << "           RM " << setw(8) << t << endl;
   if(t == 5.50)
   myFile << "Tea ordered           : " << "PEACH GREEN"          << "           RM " << setw(8) << t << endl;
   if(t == 6.40)
   myFile << "Tea ordered           : " << "STRAWBERRY HIBISCUS"  << "           RM " << setw(8) << t << endl;
   if(t == 9.00)
   myFile << "Tea ordered           : " << "MINT ROSEMARY LEMONGRASS" << "       RM " << setw(8) << t << endl;
   if(t == 8.50)
   myFile << "Tea ordered           : " << "GINGER CARDAMOM "         << "       RM " << setw(8) << t << endl;
   
   //if statements for special orders
   if(s == 4.00)
   myFile << "Afternoon special item: " << "COFFEE JELLY" << "                RM " << setw(6) << s << endl;
   if(s == 5.00)
   myFile << "Afternoon special item: " << "LATTE CUPCAKE" << "               RM " << setw(6) << s << endl;
   if(s == 6.50)
   myFile << "Afternoon special item: " << "MUFFIN LONG BLACK" << "           RM " << setw(6) << s << endl;
   if(s == 7.50)
   myFile << "Afternoon special item: " << "CAPPUCCINO BISCOTTI" << "         RM " << setw(6) << s << endl;
   
   //if statement for other fees
   if(special == 'Y' || special == 'y')
   myFile << "Afternoon special reservation fee                           RM " << setw(5) << money.cust_price << endl;
   myFile << "Government tax                                              RM " << setw(4) << money.tax << endl;
   myFile << "_________________________________________________________________________" << setw(4) << endl << endl;
   myFile << "Total Amount                                                RM " << setw(4) << total << endl << endl;
   
   myFile << "Thank you and have a nice day, May Allah bless you!" << endl;


   //End Of The Program  
}               
