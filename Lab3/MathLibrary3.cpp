
#include <iostream>
#include "MathLibrary.3.h"
namespace Prog3 {

	Ternary_Vector::Ternary_Vector() {
		size = SZ;
		for (int i = 0; i < size; i++) {
			V1[i] = '0';

		}
	}
	Ternary_Vector::Ternary_Vector(char tmpvector[SZ]) {
		int a = strlen(tmpvector);
		size = a;
		for (int i = 0; i < a; i++) {
			if ((tmpvector[i] == '0') || (tmpvector[i] == '1') || (tmpvector[i] == 'X')) {
				V1[i] = tmpvector[i];
			}
			else {
				throw std::exception("Bad vector!");
			}
		}
	}

	Ternary_Vector::Ternary_Vector(int tmpsize) {
		size = tmpsize;
		for (int i = 0; i < tmpsize; i++)
			V1[i] = 0;
	}


	void Ternary_Vector::SetSize(int SIZE) {
		if ((SIZE < 1) || (SIZE > SZ)) {
			throw std::exception("Bad Size");
		}
		else {
			size = SIZE;
		}
	}

	void Ternary_Vector::SetV1(char* tmp) {
		for (int j = 0; j < size; j++) {
			if ((tmp[j] != '0') && (tmp[j] != '1') && (tmp[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		for (int i = 0; i < size; i++) {
			V1[i] = tmp[i];
		}
	}

	Ternary_Vector Ternary_Vector::count_IlI(const Ternary_Vector &tmp) const {
	
		for (int j = 0; j < tmp.size; j++) {
			if ((tmp.V1[j] != '0') && (tmp.V1[j] != '1') && (tmp.V1[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		
		if (tmp.size != size) {
			throw std::exception("Size of vector ¹2 =! Size of main vector");
		}
		Ternary_Vector result_vector;
		result_vector.size = size;
		for (int i = 0; i < size; i++) {
			if ((V1[i] == '0') && (tmp.V1[i] == '0'))
				result_vector.V1[i] = '0';
			if (((V1[i] == '0') && (tmp.V1[i] == '1')) || ((V1[i] == '1') && (tmp.V1[i] == '0')) || ((V1[i] == '1') && (tmp.V1[i] == '1')) || ((V1[i] == '1') && (tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (tmp.V1[i] == '1')))
				result_vector.V1[i] = '1';
			if (((V1[i] == '0') && (tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (tmp.V1[i] == '0')) || ((V1[i] == 'X') && (tmp.V1[i] == 'X')))
				result_vector.V1[i] = 'X';

		}

		return result_vector;
	}

	Ternary_Vector Ternary_Vector::count_I(const Ternary_Vector &Tmp) const {
		for (int j = 0; j < Tmp.size; j++) {
			if ((Tmp.V1[j] != '0') && (Tmp.V1[j] != '1') && (Tmp.V1[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		
		if (Tmp.size != size) {
			throw std::exception("Size of vector ¹2 =! Size of main vector");
		}
		Ternary_Vector result_vector;
		result_vector.size = size;
		for (int i = 0; i < size; i++) {
			if (((V1[i] == '0') && (Tmp.V1[i] == '0')) || ((V1[i] == '0') && (Tmp.V1[i] == '1')) || ((V1[i] == '1') && (Tmp.V1[i] == '0')) || ((V1[i] == '0') && (Tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (Tmp.V1[i] =='0')))
				result_vector.V1[i] = '0';
			if ((V1[i] == '1') && (Tmp.V1[i] == '1')) 
				result_vector.V1[i] = '1';
			if (((V1[i] == 'X') && (Tmp.V1[i] == 'X')) || ((V1[i] == '1') && (Tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (Tmp.V1[i] == '1')))
				result_vector.V1[i] = 'X';
		}
		return result_vector;

	}
	int Ternary_Vector::compare(const Ternary_Vector& Tmp) const {
		for (int j = 0; j < Tmp.size; j++) {
			if ((Tmp.V1[j] != '0') && (Tmp.V1[j] != '1') && (Tmp.V1[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		if (Tmp.size != size) {
			std::cout << "The vectors are not equal. The sizes don't match." << std::endl;
			return 1;
		}
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (Tmp.V1[i] != V1[i])
				flag = 1;
		}
		return flag;

	}
	char* Ternary_Vector::invertor() noexcept {
		char* result_V1 = new char[10];
		for (int i = 0; i < size; i++) {
			if (V1[i] == '0')
				result_V1[i] = '1';
			if (V1[i] == '1')
				result_V1[i] = '0';
			if (V1[i] == 'X')
				result_V1[i] = V1[i];
		}
		
		return result_V1;
	}
	int Ternary_Vector::Analisys() noexcept{
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (V1[i] == 'X')
				flag++;
		}
		return flag;
	}
	std::istream& Ternary_Vector::InputV(std::istream& is) {
		char tmp[10];
		is >> tmp;
		int a = strlen(tmp);
		SetSize(a);
	
		SetV1(tmp);
		return is;
	}	
	std::ostream& Ternary_Vector::OutputV(std::ostream& os) const noexcept{
		const char* tmp = GetV1();
		for (int i = 0; i < GetSize(); i++) {
			os << tmp[i] << " ";
		}
		return os;
	}
	std::ostream& operator <<(std::ostream& out, const Ternary_Vector& Tvector)
	{
		Tvector.OutputV(out);
		return out;
	}

	std::istream& operator >>(std::istream& is, Ternary_Vector& Tvector)
	{	
		Tvector.InputV(is);
		return is;
	}
	Ternary_Vector& Ternary_Vector::operator +=(const Ternary_Vector& Vector2)
	{
		Ternary_Vector result_vector = count_IlI(Vector2);
		const char* input_tmp = result_vector.GetV1();
		for (int i = 0; i < GetSize(); i++) {
			V1[i] = input_tmp[i];
		}
		
		return *this;
	}
	Ternary_Vector Ternary_Vector::operator +(const Ternary_Vector& tmp) const {
		Ternary_Vector result_vector = count_IlI(tmp);

		return result_vector;
	}
	Ternary_Vector& Ternary_Vector::operator =(const Ternary_Vector& tmp) {

		const char* input_tmp = tmp.GetV1();

		for (int i = 0; i < GetSize(); i++) {
			V1[i] = input_tmp[i];
		}
		
		return *this;
	}
	Ternary_Vector& Ternary_Vector::operator ++() {
		Ternary_Vector Vector3;
		char result[10];
		int i;
		for (i = 0; i < GetSize(); i++) {

			result[i] = '1';
		}
		result[i] = '\0';
		std::cout << strlen(result);
		Ternary_Vector V2(result);
		*this += V2;
		return *this;
	}
	Ternary_Vector Ternary_Vector::operator ++(int k) {
		Ternary_Vector Vector3;
		Ternary_Vector V2;
		 char tmp[10]; 
		 int i;
		 for (i = 0; i < GetSize(); i++) {
			 tmp[i] = '1'; 
		 }
		 tmp[i] = '\0';
		 int lenght = strlen(tmp);
		V2.SetSize(lenght);
		 V2.SetV1(tmp);
		 Vector3 = *this;
		 *this += V2;

		return Vector3;
	}
	Ternary_Vector Ternary_Vector::operator ~() {
			char* result = invertor();
			for (int i = 0; i < GetSize(); i++) {
				V1[i] = result[i];
			}
		
		return *this;
	}
	bool Ternary_Vector::operator ==(const Ternary_Vector& Tab1) {
		if (this->compare(Tab1) == 1)
			return false;
		return true;
	}	
	char Ternary_Vector::operator[] (int i) const {
		char B = V1[i];
		return B;
	}
	char& Ternary_Vector::operator[] (int i) {
		return V1[i];
	}
}