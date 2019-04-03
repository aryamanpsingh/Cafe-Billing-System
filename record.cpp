//Noddy's Cafe Project
//Made by Aryaman Pratap Singh
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
using namespace std;

//Declarations
    int qty[100],buffer,menuCost[100],counterA=1,init,counterB=0,counterC,counterD=0,serialNo;
    int optionNo,quantity;
    string filename,mobile,custFirstName,custLastName,custFile,custMob,folder,finalTime,fileDetails,firstOrder,menuLineinp[1000],menuLine[1000],billFile,orderStatus,engineNo,chasisNo;
    char charTime[80];
    
//Streams
    ofstream storeDetails;
    ofstream custnameOut[1000];
    ofstream bill;
    ofstream dayFinalOut;
    ofstream menuQtyOut;
    ofstream menuOutput;
    
    ifstream menuQtyIn("quantity.txt");
    ifstream custnameIn[1000];
    ifstream menucost;
    ifstream menuInput[1000];
    ifstream dayFinalIn("finalDetails.txt");
    
    class customerDetails{
          string firstName;
          string lastName;
          string mobile;
          
          public:
                 
          void saveNumber()
          {
               cout<<"Enter customer's First name: ";
               cin>>firstName;
               cout<<"Enter customer's last name: ";
               cin>>lastName;
               cout<<"Enter customer mobile number: ";
               cin>>mobile;
               }
          
          string getMobile()
          {
          cout<<"Enter customer mobile number: ";
        cin>>mobile;
               return mobile;
               }
          string giveMobile()
          {
                 cout<<firstName<<endl;
cout<<lastName<<endl;
cout<<mobile<<endl;
                 return mobile;
                 }
               
          /*void detailsExport()
          {
               filename="CustomerNames/"+mobile+".dat";
               custnameOut[counterB].open(filename.c_str());
               custnameOut[counterB].write((char *)&customerDetails,sizeof(customerDetails));
               }
          
          void detailsImport()
          {
               cout<<"Enter customer mobile number: ";
               cin>>mobile;
               filename="CustomerNames/"+mobile+".dat";
               custnameIn[counterB].open(filename.c_str());
               custnameIn[counterB].read((char *)&customerDetails,sizeof(customerDetails));
               }*/
               
          void welcome()
          {
               cout<<"Welcome "<<firstName<<lastName<<endl;
               }
               
          void createBill()
          {
               billFile=finalTime+"/"+mobile+".txt";
               bill.open(billFile.c_str());
               }
          
          void billFirstline()
          {
               bill<<"Bill of "<<firstName<<" "<<lastName<<endl;
               }
          
          }customer;
    
//Functions
void detailsExport()
{

     customer.giveMobile();
    mobile=customer.giveMobile();
    filename="CustomerNames/"+mobile+".dat";
    custnameOut[counterB].open(filename.c_str());
    custnameOut[counterB].write((char *)&customer,sizeof(customer));
    custnameOut[counterB].close();
    }
          
void detailsImport()
{ 
    mobile=customer.getMobile();
    filename="CustomerNames/"+mobile+".dat";
    custnameIn[counterB].open(filename.c_str());
    custnameIn[counterB].read((char *)&customer,sizeof(customer));
    custnameIn[counterB].close();
    }

void quantityUpdate(int a)
{
    qty[a-1]--;
    }

void quantityOut()
{
    for (init=0;init<100;init++)
    {
        menuQtyOut<<qty[init]<<endl;
        }
    }
void quantityIn()
{
    for (init=0;init<100;init++)
    {
        menuQtyIn>>qty[0];
        if (init==0)
           buffer=qty[0];
        qty[init]=qty[0];
        }
        qty[0]=buffer;
    }


    
int checkYN(string a)
{
    if (a=="y"||a=="yes"||a=="Y"||a=="YES")
        return 1;
    else
        return 0;
    }

int checkEnd(int a)
{
    if (a==counterC)
       return 1;
    else
       return 0;
    }
int quantityCheck(int a)
{
     if (qty[a-1]==0)
        return 0;
     else
        return 1;
         
     }
int main()
{


    //Classes
    
    class costDetails{
          int menu[100];
          int real;
          int asked;
          int paid;
          int balance;
          int discount;
          int totalReal;
          int totalAsked;
          int totalPaid;
          int totalBalance;
          int totalDiscount;
          
          public:
                 
          void setMenuCost()
          {
               //assigning values to menu's cost
               for (::init=0;::init<100;::init++)
               {
                   ::menucost>>menu[0];
        
                   if (::init==0)
                   {
                       ::buffer=menu[0];
                       }
                   else
                   {
                       menu[::counterA]=menu[0];
                       ::counterA++;
                       }
                       
                   }
                   
               menu[0]=buffer;
               }
          void reset()
          {
               totalReal=0;
               totalDiscount=0;
               totalAsked=0;
               totalPaid=0;
               totalBalance=0;
               }
          
          void input()
          {
               cout<<"Asked price: ";
               cin>>asked;
               cout<<"Amount paid: ";
               cin>>paid;
               }
               
          void setValue()
          {
               balance=asked-paid;
               real=menu[optionNo-1];
               discount=real-asked;
               //Total values
               totalPaid+=paid;
               totalBalance+=balance;
               totalReal+=real;
               totalAsked+=asked;
               totalDiscount+=discount;
               }
          
          void writeToBill()
          {
               ::bill<<serialNo<<".\t\t"<<menuLine[optionNo]<<"\t\t"<<engineNo<<"\t\t"<<chasisNo<<"\t\t"<<menu[optionNo-1]<<"\t\t"<<asked<<"\t\t\t"<<paid<<"\t\t"<<balance<<endl<<endl;
               }
          void finalDisplay()
          {
               cout<<"Ex-showroom price: "<<totalReal<<endl;
               cout<<"Discount: "<<totalDiscount<<endl;                                                                           
               cout<<"Total amount to be paid: "<<totalAsked<<"\n";
               cout<<"Total amount paid: "<<totalPaid<<endl;
               cout<<"Balance: "<<totalBalance<<endl;
        
               ::bill<<"Ex-showroom price: \t\t\t\t\t\t\t\t\t\t\t"<<totalReal<<endl;
               ::bill<<"Discount: \t\t\t\t\t\t\t\t\t\t\t\t"<<totalDiscount<<endl;      
               ::bill<<"Total amount to be paid: \t\t\t\t\t\t\t\t\t\t"<<totalAsked<<"\n";
               ::bill<<"Total amount paid: \t\t\t\t\t\t\t\t\t\t\t"<<totalPaid<<endl;
               ::bill<<"Balance: \t\t\t\t\t\t\t\t\t\t\t\t"<<totalBalance;     
               }
        
        }cost;
    
    class customerDetails{
          string firstName;
          string lastName;
          string mobile;
          string filename;
          
          public:
                 
          void saveNumber()
          {
               cout<<"Enter customer's First name: ";
               cin>>firstName;
               cout<<"Enter customer's last name: ";
               cin>>lastName;
               cout<<"Enter customer mobile number: ";
               cin>>mobile;
               }
          
          string getMobile()
          {
               return mobile;
               }
               
          /*void detailsExport()
          {
               filename="CustomerNames/"+mobile+".dat";
               custnameOut[counterB].open(filename.c_str());
               custnameOut[counterB].write((char *)&customerDetails,sizeof(customerDetails));
               }
          
          void detailsImport()
          {
               cout<<"Enter customer mobile number: ";
               cin>>mobile;
               filename="CustomerNames/"+mobile+".dat";
               custnameIn[counterB].open(filename.c_str());
               custnameIn[counterB].read((char *)&customerDetails,sizeof(customerDetails));
               }*/
               
          void welcome()
          {
               cout<<"Welcome "<<firstName<<lastName<<endl;
               }
               
          void createBill()
          {
               billFile=finalTime+"/"+mobile+".txt";
               bill.open(billFile.c_str());
               }
          
          void billFirstline()
          {
               bill<<"Bill of "<<firstName<<" "<<lastName<<endl;
               }
          
          }customer;

    //using to take time and store its value in finalTime
    time_t rawtime;
    tm* timeinfo;    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(charTime,80,"%Y-%m-%d-%H-%M-%S",timeinfo);
    finalTime=charTime;
    
    //Creating folder 'Customer Names' to store customer names
    system("md CustomerNames");
    
    //changing colour of background and text
    system("color 0a");
    
    cout<<"\n\nUDAI Autos\n\n";
    
    menucost.open("menucost.txt");
    cost.setMenuCost();
    
    folder="md "+finalTime;
    system(folder.c_str());
    
    //New customer
    serialNo=0;
    //resetting values
    cost.reset();
    
    cout<<"Is this the customer's first transaction? ";
    cin>>firstOrder;
    if (checkYN(firstOrder))
    {
       //Save number by name
       customer.saveNumber();
       
       detailsExport();     
       }
    else
    {
        
       detailsImport();
       }
    customer.welcome();
    
    //Importing menu details from file
    menuInput[counterD].open("menu.txt");
    counterC=0;
    do 
    {
        cout<<counterC+1<<". ";
        menuInput[counterD]>>menuLineinp[counterD];
        menuLine[counterC+1]=menuLineinp[counterD];
        cout<<menuLineinp[counterD]<<endl;
        counterC++;
    }
    while (menuLine[counterC]!="end");
    
    //Creating bill file
    customer.createBill();
    customer.billFirstline();
    bill<<"S.No.\t\t"<<"Model\t\t"<<"Eng.No.\t\t"<<"Ch.No.\t\t"<<"ExSP\t\t"<<"Our-Price\t\t"<<"Paid\t\t"<<"Balance"<<endl;
    
    quantityIn();
    
    //Taking order
    newItem:;
    serialNo++;
    //Bike details
    reEnter:;
    cout<<"Enter option number: ";
    cin>>optionNo;
    
    if (checkEnd(optionNo))
       goto customerEnd;
    if (quantityCheck(optionNo)==0)
    {
       cout<<"Item not available.";
       goto reEnter;
       }
    if (optionNo>5)
    {
       goto skip;
       }
    cout<<"Engine number: ";
    cin>>engineNo;
    cout<<"Chasis number: ";
    cin>>chasisNo;
    
    skip:;
    
    //Price details
    cost.input();
    
    cost.setValue();
    
    //Writing to bill
    cost.writeToBill();
    
    cout<<"Order complete? ";
    cin>>orderStatus;
    if (checkYN(orderStatus))
    {
        cost.finalDisplay();
        
        goto customerEnd;
        }
    else
    {
        goto newItem;
        }
       
    customerEnd:;
    bill.close();
    
    menuQtyOut.open("quantity.txt");
    quantityUpdate(optionNo);
    quantityOut();
    
    system("pause");
}
