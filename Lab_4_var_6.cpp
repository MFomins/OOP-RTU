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

template <class T>
class Animal {
   protected:
      string nosaukums;
      string iesauka;
      T gads;
   public:
      Animal();
      Animal(string, string, T);
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
      T GetGads() const {
      	return gads;
      }
      void SetGads(T gads){
      	this->gads = gads;
      }
      virtual void Print() const;
};

template <class T>
class ZooAnimal :public Animal<T>{
     private:
     unsigned int sector;
     public:
     ZooAnimal():Animal<T>(), sector(0){
     }
     ZooAnimal(string, string, T, unsigned int);
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

template <class T>
class Zoo {
   private:
		typedef ZooAnimal<T>* DPPointer;
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

		void AddNode(const ZooAnimal<T>&);
		void Print() const;
};

template <class T>
const unsigned int Zoo<T>::DEFAULT_MAX_LENGTH = 5;

template <class T>
Animal<T>::Animal() : nosaukums("default"), iesauka("default"), gads(2010){
}

template <class T>
Animal<T>::Animal(string Nosaukums, string Iesauka, T Gads){
   nosaukums = Nosaukums;
   iesauka = Iesauka;
   gads = Gads;
}

template <class T>
inline void Animal<T>::Print() const {
   cout << "nosaukums= " << nosaukums << ", iesauka = " << iesauka << ", gads = " << gads;
}


template <class T>
ZooAnimal<T>::ZooAnimal(string Nosaukums, string Iesauka, T Gads, unsigned int Psector): Animal<T>(Nosaukums, Iesauka, Gads) {
	 sector = Psector;
}

template <class T>
inline void ZooAnimal<T>::Print() const{
 	Animal<T>::Print();
   cout << ", Sector = " << sector;
}

template <class T>
 Zoo<T>::~Zoo() {
	for(unsigned int i=0; i<Length; i++)
		delete Nodes[i];
	delete [] Nodes;
}

template <class T>
void Zoo<T>::Print() const {
	cout << "\gadu saraksts: " << "." << endl
		<< endl;
   for (unsigned int i=0; i<Length; i++) {
		cout << (i+1) << ". ";
		Nodes[i]->Print();
		cout << "." << endl;
	}
}

template <class T>
void Zoo<T>::AddNode(const ZooAnimal<T>& Node){
	if(Length == MaxLength)
		throw OverflowException();
	else


		Nodes[Length++] = new ZooAnimal<T>(
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

                                        //PALIEK NO 3.LAB DARBA

  /*

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

         */

      Zoo<unsigned int> *UintLine = new Zoo<unsigned int>(2);
		Zoo<unsigned short> *UshortLine = new Zoo<unsigned short>(2);

		ZooAnimal<unsigned int> *UintDzimgads = new ZooAnimal<unsigned int>("Suns","Funs",2000,5);
		ZooAnimal<unsigned short> *UshortDzimgads = new ZooAnimal<unsigned short>("Kakis","Runcis",20015,6);

		ZooAnimal<unsigned int> UintDzimgads2("Kamis","kamis",1990,5);
		ZooAnimal<unsigned short> UshortDzimgads2("Papagailis","papagailis",2010,6);

	 /*	UintDzimgads -> Print();
			cout << endl << endl;
		UshortDzimgads -> Print();
     */

		try {
		UintLine->AddNode(*UintDzimgads);
		cout << "\nNew node added successfully!" << endl;
	}
		catch (OverflowException&) {
			cout << "*** Error: maximal length exceeded ! ***" << endl;
		}
		catch (...) {
			cout << "Unknown Error !" << endl;
		}
	try {
		UshortLine->AddNode(*UshortDzimgads);
		cout << "\nNew node added successfully!" << endl;
	}
		catch (OverflowException&) {
			cout << "*** Error: maximal length exceeded ! ***" << endl;
      }
		catch (...) {
         cout << "Unknown Error !" << endl;
		}

	try {
		UshortLine->AddNode(UshortDzimgads2);
		cout << "\nNew node added successfully!" << endl;
	}
		catch (OverflowException&) {
			cout << "*** Error: maximal length exceeded ! ***" << endl;
		}
		catch (...) {
			cout << "Unknown Error !" << endl;
		}
	 try {
		UintLine->AddNode(UintDzimgads2);
		cout << "\nNew node added successfully!" << endl;
	}
		catch (OverflowException&) {
			cout << "*** Error: maximal length exceeded ! ***" << endl;
		}
		catch (...) {
			cout << "Unknown Error !" << endl;
		}

    delete UintDzimgads;
	 delete UshortDzimgads;

    	cout << endl << "UNSIGNED integer line:";
		UintLine -> Print();
		//cout << endl << endl;
		cout << endl << "UNSIGNED short line:";
		UshortLine -> Print();

	delete UintLine;
	delete UshortLine;

   


   while (kbhit())
      getch();
   getch();        

/*  Pause: C++ style  */
// cin.get();
}




































