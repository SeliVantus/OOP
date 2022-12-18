
#include <iostream>
#include "Lab.Header.h"
namespace Prog3 {

	Ternary_Vector::Ternary_Vector() {
		MS = QUOTA;
		size = QUOTA;
		V1 = new char[QUOTA + 1];
		int i;
		for (i = 0; i < size; i++) {
			V1[i] = '0';
		}
		V1[i] = '\0';
	}
	Ternary_Vector::Ternary_Vector(char* tmpvector) {
		int a = strlen(tmpvector);
		if (a <= QUOTA) {
			MS = QUOTA;
			size = a;
			V1 = new char[a + 1];
			int i;
			for (i = 0; i < a; i++) {
				if ((tmpvector[i] == '0') || (tmpvector[i] == '1') || (tmpvector[i] == 'X')) {
					V1[i] = tmpvector[i];
				}
				else {
					throw std::exception("Bad vector!");
				}
			}
			V1[i] = '\0';
		}
		else {
			size = a;
			MS = (a / 10 + 1) * QUOTA;
			V1 = new char[MS + 1];
			int i;
			for (i = 0; i < size; i++) {
				if ((tmpvector[i] == '0') || (tmpvector[i] == '1') || (tmpvector[i] == 'X')) {
					V1[i] = tmpvector[i];
				}
				else {
					throw std::exception("Bad vector!");
				}
			}
			V1[i] = '\0';
		}
	}

	Ternary_Vector::Ternary_Vector(int tmpsize) {

		size = tmpsize;
		if (tmpsize <= QUOTA) {
			MS = QUOTA;
			V1 = new char[tmpsize + 1];
			int i;
				for (i = 0; i < tmpsize; i++)
					V1[i] = '0';
				V1[i] = '\0';
		}
		else {
			MS = (tmpsize / 10 + 1) * QUOTA;
			V1 = new char[MS + 1];
			int i;
			for (i = 0; i < size; i++)
				V1[i] = '0';
			V1[i] = '\0';
		}
	}
	
	Ternary_Vector::Ternary_Vector(const Ternary_Vector& Klass1) {
		size = Klass1.GetSize();
		MS = Klass1.GetMaxsize();
		V1 = new char[Klass1.GetSize() + 1];
		memcpy(V1, Klass1.GetV1(), sizeof(char) * Klass1.GetSize() + 1);
		//std::cout << " ------------------------------" << std::endl;
	}

	Ternary_Vector::Ternary_Vector(Ternary_Vector&& Klass2) {
		size = Klass2.GetSize();
		MS = Klass2.GetMaxsize();
		V1 = Klass2.V1;
		Klass2.V1 = nullptr;
		/*char* ptr = Klass2.GetV1();
		V1 = ptr;*/
		//V1 = Klass2.GetV1();
		//std::cout << " This is MOVE CNST" << std::endl;
	}

	Ternary_Vector& Ternary_Vector::operator =(const Ternary_Vector& Klass) {
		if (this != &Klass) {
			size = Klass.GetSize();
			MS = Klass.GetMaxsize();
			delete[] V1;
			V1 = new char[Klass.GetSize()];
			memcpy(V1, Klass.GetV1(), sizeof(char) * Klass.GetSize());
		}
		return *this;
	}

	Ternary_Vector& Ternary_Vector::operator =(Ternary_Vector&& Klass) {
		int tmpsize = size;
		size = Klass.size;
		Klass.size = tmpsize;
		tmpsize = MS;
		MS = Klass.MS;
		Klass.MS = tmpsize;
		char* tmp = V1;
		V1 = Klass.V1;
		Klass.V1 = tmp;
		return *this;
	}

	void Ternary_Vector::SetSize(int SIZE) {
		if (SIZE < 1) {
			throw std::exception("Bad Size");
		}
		else {
			size = SIZE;
			//MS = (SIZE / 10 + 1) * QUOTA;
		}
	}

	void Ternary_Vector::SetV1(char* tmp) {
		for (int j = 0; j < size; j++) {
			if ((tmp[j] != '0') && (tmp[j] != '1') && (tmp[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		if (size <= QUOTA) {
			MS = QUOTA;
			//V1 = new char(QUOTA);
			for (int i = 0; i < size; i++) {
				V1[i] = tmp[i];
			}
		}
		else {

			MS = (GetSize() / 10 + 1) * QUOTA;
			delete[] V1;
			V1 = new char[MS];
				for (int i = 0; i < size; i++) {
					V1[i] = tmp[i];
				}
		}
	}

	Ternary_Vector Ternary_Vector::count_IlI(const Ternary_Vector& tmp) const {

		for (int j = 0; j < tmp.size; j++) {
			if ((tmp.V1[j] != '0') && (tmp.V1[j] != '1') && (tmp.V1[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}

		if (tmp.size != size) {
			throw std::exception("Size of vector №2 =! Size of main vector");
		}
		Ternary_Vector result_vector;
		result_vector.V1 = new char[MS + 1];
		result_vector.MS = MS;
		result_vector.size = size;
		int i;
		for (i = 0; i < size; i++) {
			if ((V1[i] == '0') && (tmp.V1[i] == '0'))
				result_vector.V1[i] = '0';
			if (((V1[i] == '0') && (tmp.V1[i] == '1')) || ((V1[i] == '1') && (tmp.V1[i] == '0')) || ((V1[i] == '1') && (tmp.V1[i] == '1')) || ((V1[i] == '1') && (tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (tmp.V1[i] == '1')))
				result_vector.V1[i] = '1';
			if (((V1[i] == '0') && (tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (tmp.V1[i] == '0')) || ((V1[i] == 'X') && (tmp.V1[i] == 'X')))
				result_vector.V1[i] = 'X';
		}
		result_vector.V1[i] = '\0';
		
		return result_vector;
		delete[] result_vector.V1;
	}

	Ternary_Vector Ternary_Vector::count_I(const Ternary_Vector& Tmp) const {
		for (int j = 0; j < Tmp.size; j++) {
			if ((Tmp.V1[j] != '0') && (Tmp.V1[j] != '1') && (Tmp.V1[j] != 'X'))
				throw std::exception("Bad Vector. Please repeat");
		}
		if (Tmp.size != size) {
			throw std::exception("Size of vector №2 =! Size of main vector");
		}
		Ternary_Vector result_vector;
		result_vector.V1 = new char[MS + 1];
		result_vector.MS = MS;
		result_vector.size = size;
		int i;
		for (i = 0; i < size; i++) {
			if (((V1[i] == '0') && (Tmp.V1[i] == '0')) || ((V1[i] == '0') && (Tmp.V1[i] == '1')) || ((V1[i] == '1') && (Tmp.V1[i] == '0')) || ((V1[i] == '0') && (Tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (Tmp.V1[i] == '0')))
				result_vector.V1[i] = '0';
			if ((V1[i] == '1') && (Tmp.V1[i] == '1'))
				result_vector.V1[i] = '1';
			if (((V1[i] == 'X') && (Tmp.V1[i] == 'X')) || ((V1[i] == '1') && (Tmp.V1[i] == 'X')) || ((V1[i] == 'X') && (Tmp.V1[i] == '1')))
				result_vector.V1[i] = 'X';
		}
		result_vector.V1[i] = '\0';
		
		return result_vector;
		delete[] result_vector.V1;

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
		char* result_V1 = new char[MS + 1];
		int i;
		for (i = 0; i < size; i++) {
			if (V1[i] == '0')
				result_V1[i] = '1';
			if (V1[i] == '1')
				result_V1[i] = '0';
			if (V1[i] == 'X')
				result_V1[i] = V1[i];
		}
		result_V1[i] = '\0';
		return result_V1;
	}
	int Ternary_Vector::Analisys() noexcept {
		int flag = 0;
		for (int i = 0; i < size; i++) {
			if (V1[i] == 'X')
				flag = 1;
		}
		return flag;
	}
	std::istream& Ternary_Vector::InputV(std::istream& is) {
		char* tmp = new char[MS + 1];
		is >> tmp;
		int a = strlen(tmp);
		SetSize(a);

		SetV1(tmp);
		delete[] tmp;
		return is;
	}
	std::ostream& Ternary_Vector::OutputV(std::ostream& os) const noexcept {
		char* tmp = GetV1();
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
		char* input_tmp = result_vector.GetV1();
		int i = 0;
		for (i = 0; i < GetSize(); i++) {
			V1[i] = input_tmp[i];
		}
		V1[i] = '\0';

		return *this;
	}
	Ternary_Vector Ternary_Vector::operator +(const Ternary_Vector& tmp) const {
		Ternary_Vector result_vector = count_IlI(tmp);
		return result_vector;
	}
	Ternary_Vector& Ternary_Vector::operator ++() {
		Ternary_Vector Vector3;
		char* result = new char[MS + 1];
		int i;
		for (i = 0; i < GetSize(); i++) {

			result[i] = '1';
		}
		result[i] = '\0';
		Ternary_Vector V2(result);
		*this += V2;
		delete[] result;
		return *this;
	}
	Ternary_Vector Ternary_Vector::operator ++(int k) {
		Ternary_Vector Vector3;
		Ternary_Vector V2;
		char* tmp = new char[MS + 1];
		int i;
		for (i = 0; i < this->GetSize(); i++) {
			tmp[i] = '1';
		}
		tmp[i] = '\0';
		int lenght = strlen(tmp);
		V2.SetSize(lenght);
		V2.SetV1(tmp);
		Vector3 = *this;
		*this += V2;
		delete[] tmp;
		return Vector3;
	}
	Ternary_Vector Ternary_Vector::operator ~() {
		char* result = new char[MS];
		result = invertor();
		int i;
		for (i = 0; i < GetSize(); i++) {
			V1[i] = result[i];
		}
		V1[i] = '\0';
		delete[] result;
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