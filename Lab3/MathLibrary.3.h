#pragma once
//#include <string>;

namespace Prog3 {


	class Ternary_Vector {
	private:
		static const int SZ = 10;
		int size;
		char V1[SZ];
	public:
		Ternary_Vector();
		Ternary_Vector(char tmpvector[SZ]);
		Ternary_Vector(int tmpsize);


		int GetMaxsize() const noexcept { return SZ; };
		const char* GetV1() const noexcept { return V1; };
		int GetSize() const noexcept { return size; };
		void SetSize(int );
		void SetV1(char*);
		Ternary_Vector count_IlI(const Ternary_Vector&) const;
		Ternary_Vector count_I(const Ternary_Vector&) const;
		int compare(const Ternary_Vector&) const;
		char*  invertor() noexcept;
		int Analisys() noexcept;
		std::istream& InputV(std::istream& );
		std::ostream& OutputV(std::ostream&) const noexcept; 

	
		friend std::ostream& operator <<(std::ostream&, const Ternary_Vector&);
		friend std::istream& operator >>(std::istream&, Ternary_Vector&);
		Ternary_Vector& operator +=(const Ternary_Vector&);
		Ternary_Vector operator +(const Ternary_Vector&) const;
		Ternary_Vector& operator =(const Ternary_Vector&);
		Ternary_Vector& operator ++();
		Ternary_Vector operator ++(int );
		bool operator ==(const Ternary_Vector&);
		Ternary_Vector operator ~();
		char operator[] (int)const;
		char& operator[] (int);
	};

}


