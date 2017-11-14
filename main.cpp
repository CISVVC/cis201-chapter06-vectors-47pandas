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
      
   private:
      double total_balance;
      double interest_rate;
};

Bank::Bank()
{
   total_balance = 0.0;
   interest_rate= 1.5;
}

void Bank::print()
{
   std::cout << "Current balance is: " << total_balance << std::endl;
}

void Bank::get_interest(int day)
{
   if(day >=30)
   {
      for(int i = 30; i <= day; i++)
      {
         if(!(i % 30))
         {
            total_balance = total_balance * interest_rate;
            std::cout << "Current Balance with interest is: " << total_balance << std::endl;
         }
      }
   }
}

double Bank::add_balance(double a)
{
   total_balance = total_balance + a;
}

double Bank::average_daily(double a)
{
   int day;
   if(day > 30)
   {
      for(int i = 30; i > day; i+30)
      {
      
      }
   }
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
      b.print();
      b.get_interest(day);
      b.min_daily();
      
      transaction.push_back(t);
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


