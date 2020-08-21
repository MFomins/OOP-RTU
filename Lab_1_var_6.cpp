#include <iostream>   //#include <iostream.h>
#include <conio>      //#include <conio.h>

/*    Strings: C++ style    */
#include <string>
using namespace std;

class Animal {
   private:
      string nosaukums;
      string iesauka;
      short gads;
   public:
      Animal();
      Animal(string, string, short);
      ~Animal() {
         cout << "Message from the \"Animal\" - destroyed!" <<
           endl;
      }
      string GetNosaukums() const {
         return nosaukums;
      }
      void SetNosaukums(string nosaukums) {
         this->nosaukums = nosaukums;
      }
      string GetIesauka() const{
      	return iesauka;
      }
      void SetIesauka(string iesauka){
          this->iesauka = iesauka;
      }
      short GetGads() const {
      	return gads;
      }
      void SetGads(char gads){
      	this->gads = gads;
      }
      void Print() const;
};

Animal::Animal() : nosaukums("default"), iesauka("default"), gads(2010){
}

Animal::Animal(string Nosaukums, string Iesauka, short Gads){
   nosaukums = Nosaukums;
   iesauka = Iesauka;
   gads = Gads;
}

inline void Animal::Print() const {
   cout << "nosaukums= " << nosaukums << ", iesauka = " << iesauka << ", gads = " << gads;
}

void main(void) {

	     Animal anm1("kakis","runcis",2010), *anm2;
        anm2 = new Animal();

        clrscr();

         anm1.Print();cout<<endl;
         anm1.SetIesauka("jauna iesauka");
         anm1.Print();cout<<endl;

         anm2->Animal::Print();cout<<endl;



         delete anm2;



   while (kbhit()) 
      getch();
   getch();        

/*  Pause: C++ style  */
// cin.get();
}
