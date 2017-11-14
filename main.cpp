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
      double add_balance(double a);
      double average_daily(double a);
      double min_daily(double a);
      double get_average();
      void set_previous_day(int a);
   private:
      double total_balance;
      double interest_rate;
      double total_interest;
      int previous_day;
};

Bank::Bank()
{
   total_balance = 0.0;
   interest_rate= 1.005;
}

void Bank::print()
{
   std::cout << "Total Interest is: " << total_interest << std::endl;
   std::cout << "Current balance is: " << total_balance << std::endl;
}

void Bank::set_previous_day(int a)
{
   previous_day = a;
}

void Bank::get_interest(int day)
{
  /* if(day >=30)
   {
      for(int i = 30; i <= day; i++)
      {
         if(!(i % 30))
         {
            total_balance *=  interest_rate;
            std::cout << "Current Balance with interest is: " << total_balance << std::endl;
         }
      }
   }*/
     
    std::cout << day << " " <<  previous_day << std::endl;  
    
    int i = (day / 30) * 30;

    if( i > previous_day && i < day)
      std::cout << "Lloyd is a bundle of sticks" << std::endl;
         
}

double Bank::add_balance(double a)
{
   total_balance = total_balance + a; 
}

double Bank::average_daily(double a)
{
/*
   double average;  
   double average_outcome;    

   std::vector<double> maths;
   
   maths.push_back(a);

   std::cout << "things" << std::endl;

   for(int i = 0; i < maths; i++)
   {
     average = average + a;
   }
 
   average_outcome = average / i;
*/
}



double Bank::get_average()
{
   return 0; 
}

double Bank::min_daily(double a = 35)
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
      
     // b.min_daily();
     // b.average_daily(temp_addtobal);
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


