/* 
Dev: Nathan Emigh
Email: 47Pandas@gmail.com
Professor: Tonning
Discription: A Bank statement that produces balance and interest rate

Not ready -- fix Interest rate, daily min for month, fix daily average, 

*/
#include <iostream>
#include <string>
#include <vector>

class Bank
{
   public:
      Bank();
      void print();
      void get_interest(int day);
      double add_balance(double a); // pulls transactions amounts in to total balance
      double average_daily(double average, int day); // takes the total amount for one month and divides it by 30
      double min_daily(double a); // ensures the daily minimum is met.
      double get_average();      
      void set_previous_day(int a); // ensures the interest is added every 30 days
   private:
      double total_balance;
      double interest_rate;
      double total_interest;
      int previous_day;
      double the_average;
};

Bank::Bank()
{
   total_balance = 0.0;
   interest_rate= 1.005; // sets the interest rate at .5%
}

void Bank::print() 
{
   std::cout << "Total Interest is: " << total_interest << std::endl;
   std::cout << "Current balance is: " << total_balance << std::endl;
   std::cout << "Average daily Balance is: " << the_average << std::endl;
}

void Bank::set_previous_day(int a) // used in get interest to set a 30 day cycle
{
   previous_day = a;
}

void Bank::get_interest(int day) // calulates the daily interest then after 30 days it adds it to your account.
{
     
   // std::cout << day << " " <<  previous_day << std::endl;  
    
    int i = (day / 30) * 30;

    if( i > previous_day && i < day) // this is what I used to ensure its within the 30 day month.
    total_balance *= interest_rate;
    
    total_interest = total_balance * (interest_rate - 1); // shows only the interest rate
}

double Bank::add_balance(double a) // take the transactions and adds it to a total balance.
{
   total_balance = total_balance + a; 
}

double Bank::average_daily(double average, int day) // similar to the get interest, but calculates the average daily.
{
   double total_average = 0.0;  
   
   int i = (day / 30) * 30;
  
   if( i > previous_day && i < day)
     total_average += average;
  
   the_average = total_average / 30.0;
  
}

double Bank::get_average()
{
   return the_average; 
}

double Bank::min_daily(double a = 35) // deducts 35 dollars when your account get below 500.
{
   if(total_balance < 500)
   {
      total_balance - a;
      std::cout << "Your account has been charged 35 dollars due to having less than 500 dollars in your account." << std::endl;
   }
}

class Transaction
{
   public:
      Transaction();
      void read();
      void print() const; 
      int get_day();
      double get_amount();
                
   private:
      int day;
      double amount;
      std::string description;
};

Transaction::Transaction()
{
   day = 0;
   amount = 0.0;
}

void Transaction::read()
{
   std::cout << " Enter DATA as follows: [Day 1-365] [Amount] [Description] then press enter. You will be prompted if you want to enter more DATA" << std::endl;
   std::cin >> day;
   std::cin >> amount;
   std::cin.ignore();
   std::getline(std::cin, description);
}

void Transaction::print() const
{
   std::cout << "Day: " << day << std::endl;
   std::cout << "Amount: " << amount << std::endl;
   std::cout << "Description: " << description << std::endl;
}

int Transaction::get_day()
{
   return day;
}

double Transaction::get_amount()
{
   return amount;
}

void print_transactions(const std::vector<Transaction> t)
{
   for(int i = 0; i < t.size();i++)
      t[i].print();
}

int main()
{
   Bank b;
   
   std::vector<Transaction> transaction;
   bool more = true;
   while(more)
   {
      Transaction t;
      
      double temp_addtobal = 0.0;
      int day;
      
      t.read();
      
      temp_addtobal = t.get_amount();
      b.add_balance(temp_addtobal);
      
      day = t.get_day();
      b.get_interest(day); 
      b.min_daily();
      b.average_daily(temp_addtobal, day);
      b.set_previous_day(t.get_day());
      transaction.push_back(t);
      b.print();
      std::cout << "Enter another Transaction? y or n" << std::endl;
      char response;
      std::cin >> response;      
      if(response != 'y' && response != 'Y')
         more = false;
      
    }

    print_transactions(transaction);
    b.print();

return 0;
}


