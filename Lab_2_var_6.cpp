#include <iostream>   //#include <iostream.h>
#include <conio>      //#include <conio.h>
#include <string>
using namespace std;

class Animal {
   protected:
      string nosaukums;
      string iesauka;
      short gads;
   public:
      Animal();
      Animal(string, string, short);
      virtual ~Animal() {
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
      virtual void Print() const;
};

class ZooAnimal :public Animal{
     private:
     unsigned int sector;
     public:
     ZooAnimal():Animal(), sector(0){
     }
     ZooAnimal(string, string, short, unsigned int);
      virtual ~ZooAnimal() {
         cout << endl << "Message from the \"ZooAnimal\" - destroyed!" << endl;
      }
      unsigned int GetSector() const {
         return sector;
      }
      void SetSector(unsigned int sector) {
         this->sector = sector;
      }
      virtual void Print() const;
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

ZooAnimal::ZooAnimal(string Nosaukums, string Iesauka, short Gads, unsigned int Psector): Animal(Nosaukums, Iesauka, Gads) {
	 sector = Psector;
}

inline void ZooAnimal::Print() const{
 	Animal::Print();
   cout << ", Sector = " << sector;
}






void main(void) {



	      const int N = 3;
   ZooAnimal *DP1 = new ZooAnimal("test-nosaukums", "test-iesauka", 2010, 5);
   Animal   *DP2 = new ZooAnimal();

   Animal *Animals[N] = {
      new Animal("test-nosaukums-2", "test-iesauka-2", 2012),
      new ZooAnimal(),
      new ZooAnimal("test-nosaukums-4", "test-iesauka-4", 2014,6)
   };
   clrscr();

   cout << "Array: " << endl;
   for(int i=0; i<N; i++) {
      cout << (i+1) << ". ";
      Animals[i]->Print();
      cout << endl;
   }

   cout << endl << "ZooAnimal:" << endl;

   DP1->Print();
   cout << endl << "Nosaukums " << DP1->GetNosaukums() << ".";
   cout << endl << "Sector = " << DP1->GetSector() << "." << endl << endl;

   for(int k=0; k<N; k++) {
      delete Animals[k];
   }
   delete DP1;
   delete DP2;







   while (kbhit()) 
      getch();
   getch();        

/*  Pause: C++ style  */
// cin.get();
}




































