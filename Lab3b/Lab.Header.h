#pragma once
#pragma once
//#include <string>;

namespace Prog3 {


	class Ternary_Vector {
	private:
		static const int QUOTA = 10;
		int MS;
		int size;
		char* V1;
	public:
		Ternary_Vector();
		Ternary_Vector(char*);
		Ternary_Vector(int);
		Ternary_Vector(const Ternary_Vector&);
		Ternary_Vector(Ternary_Vector&&);
		~Ternary_Vector() {
			delete[] V1; 
		};

		Ternary_Vector& operator =(const Ternary_Vector&);
		Ternary_Vector& operator =(Ternary_Vector&&);
		int GetMaxsize() const noexcept { return MS; };
		char* GetV1() const noexcept { return V1; };
		int GetSize() const noexcept { return size; };
		void SetSize(int);
		void SetV1(char*);
		Ternary_Vector count_IlI(const Ternary_Vector&) const;
		Ternary_Vector count_I(const Ternary_Vector&) const;
		int compare(const Ternary_Vector&) const;
		char* invertor() noexcept;
		int Analisys() noexcept;
		std::istream& InputV(std::istream&);
		std::ostream& OutputV(std::ostream&) const noexcept;


		friend std::ostream& operator <<(std::ostream&, const Ternary_Vector&);
		friend std::istream& operator >>(std::istream&, Ternary_Vector&);
		Ternary_Vector& operator +=(const Ternary_Vector&);
		Ternary_Vector operator +(const Ternary_Vector&) const;
		Ternary_Vector& operator ++();
		Ternary_Vector operator ++(int);
		bool operator ==(const Ternary_Vector&);
		Ternary_Vector operator ~();
		char operator[] (int)const;
		char& operator[] (int);
	};

}