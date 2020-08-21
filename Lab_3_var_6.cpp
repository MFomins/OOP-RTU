#include <iostream>   //#include <iostream.h>
#include <conio>      //#include <conio.h>
#include <string>
using namespace std;

class OverflowException {
   public:
		OverflowException() {
			cout << endl << "Exception created!" << endl;
      }
      OverflowException(OverflowException&) {
         cout << "Exception copied!" << endl;
      }
		~OverflowException() {
         cout << "Exception finished!" << endl;
		}
};

class Animal {
   protected:
      string nosaukums;
      string iesauka;
      short gads;
   public:
      Animal();
      Animal(string, string, short);
      virtual ~Animal() {
         //cout << "Message from the \"Animal\" - destroyed!" <<
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
        // cout << endl << "Message from the \"ZooAnimal\" - destroyed!" << endl;
      }
      unsigned int GetSector() const {
         return sector;
      }
      void SetSector(unsigned int sector) {
         this->sector = sector;
      }
      virtual void Print() const;
};

class Zoo {
   private:
		typedef ZooAnimal* DPPointer;
		DPPointer *Nodes;
      static const unsigned int DEFAULT_MAX_LENGTH;
      unsigned int MaxLength;
		unsigned int Length;
	public:
		Zoo() : MaxLength(DEFAULT_MAX_LENGTH), Length(0){
			Nodes = new DPPointer[MaxLength];
      }
		Zoo(unsigned int MaxLength) : MaxLength(MaxLength), Length(0) {
			Nodes = new DPPointer[MaxLength];
      }
		~Zoo();
      static unsigned int GetDefaultMaxLength() {
			return DEFAULT_MAX_LENGTH;
      }
		int GetMaxLength() const {
         return MaxLength;
      }
      int GetLength() const {
			return Length;
		}
			short GetMinBirth();

		void AddNode(const ZooAnimal&);
		void Print() const;
};
const unsigned int Zoo::DEFAULT_MAX_LENGTH = 5;

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

 Zoo::~Zoo() {
	for(unsigned int i=0; i<Length; i++)
		delete Nodes[i];
	delete [] Nodes;
}

void Zoo::Print() const {
	cout << "\gadu saraksts: " << "." << endl
		<< "gadi:" << endl;
   for (unsigned int i=0; i<Length; i++) {
		cout << (i+1) << ". ";
		Nodes[i]->Print();
		cout << "." << endl;
	}
}

void Zoo::AddNode(const ZooAnimal& Node){
	if(Length == MaxLength)
		throw OverflowException();
	else


		Nodes[Length++] = new ZooAnimal(
			Node.GetNosaukums(), Node.GetIesauka(), Node.GetGads(), Node.GetSector()
		);
}

void main(void) {


       										// PALIEK NO 2. LAB DARBA

	  /*    const int N = 3;
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

           */

   	Zoo *Line = new Zoo(2);
		ZooAnimal *D1 = new ZooAnimal("Suns", "Funs", 2010, 5);
		ZooAnimal  D2("Suns", "Funs2", 2019, 2);


		try {
		Line->AddNode(*D1);
		cout << "\nNew node added successfully!" << endl;
   }
      catch (OverflowException&) {
         cout << "*** Error: maximal length exceeded ! ***" << endl;
      }
      catch (...) {
         cout << "Unknown Error !" << endl;
      }
		delete D1;

   cout << "\n\nDefault maximal length (from CLASS): " << 
		Zoo::GetDefaultMaxLength() << "." << endl;
   cout << "Default maximal length (from OBJECT): " << 
      Line->GetDefaultMaxLength() << "." << endl;
   cout << "Maximal length: " << Line->GetMaxLength() << "." << endl;
	cout << "Current length: " << Line->GetLength() << "." << endl;

    try {
      Line->AddNode(D2);
      cout << "\nNew node has been added successfully!" << endl;
   }
      catch (const OverflowException&) {
         cout << "*** Error: maximal length exceeded ! ***" << endl;
      }
      catch (...) {
         cout << "Unknown Error !" << endl;
      }

   try {
      Line->AddNode(D2);
      cout << "\nNew node has been added successfully!" << endl;
   }
      catch (const OverflowException&) {
         cout << "*** Error: maximal length exceeded! ***" << endl;
      }
      catch (...) {
         cout << "Unknown error !" << endl;
      }

      Line->Print();

      delete Line;



   while (kbhit()) 
      getch();
   getch();        

/*  Pause: C++ style  */
// cin.get();
}




































