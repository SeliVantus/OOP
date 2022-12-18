#include <iostream>
#include "Header.h"
#include "..\..\Library3b\Library3b\Lab.Header.h"

namespace Prog3 {
	void Settings::dialog() {
		os << "Size of vector-->" << Tvector.GetSize(); os << "\n";
		os << "Vector ¹ 1--> "; Getter(); os << "\n";
		os << "0: Exit" << std::endl <</* "1: Size change" << std::endl << */ "1: Vector 1 change" << std::endl << "2: ILI" << std::endl << "3: I" << std::endl << "4: Compare" << std::endl << "5: NE( Invertor )" << std::endl << "6: Analiz" << std::endl << "7: Input" << std::endl << "8:Output" << std::endl;
		os << "9: +=" << std::endl << "10: +" << std::endl << "11: =" << std::endl << "12: ++ inf" << std::endl << "13: post ++" << std::endl << "14: ~" << std::endl << "15: ==" << std::endl << "16: a = b[i]" << std::endl << "17:b[i] = a" << std::endl;
	}

	int Settings::analysis() {
		int flag = -1;

		do {
			std::cout << "Select function" << std::endl;
			if (getNum(flag) < 0) {
				os << "Input incorrect!" << std::endl;
				flag = -1;
				continue;
			}
			if (flag > 17) {
				os << "No such feature!" << std::endl;
				flag = -1;
			}

		} while (flag < 0);

		if (flag == 0) {
			return 0;
		}
		//if (flag == 1) {
		//	return size_change();
		//}
		if (flag == 1) {
			return V1_change();
		}
		if (flag == 2) {
			return Logical_ILI();
		}
		if (flag == 3) {
			return Logical_I();
		}
		if (flag == 4) {
			return Logical_campare();
		}
		if (flag == 5) {
			return invertor();
		}
		if (flag == 6) {
			return Analisys();
		}
		if (flag == 7) {
			return Input();
		}
		if (flag == 8) {
			return Output();
		}
		if (flag == 9) {
			return Plus_Equal();
		}
		if (flag == 10) {
			return Plus();
		}
		if (flag == 11) {
			return Equal();
		}
		if (flag == 12) {
			return plus_pref();
		}
		if (flag == 13) {
			return post_plus();
		}
		if (flag == 14) {
			return Tilda();
		}
		if (flag == 15) {
			return Equal_Equal();
		}
		if (flag == 16) {
			return A_Bi();
		}
		if (flag == 17) {
			return Bi_A();
		}
		return flag;

	}
	//bool Settings::size_change() {
	//	os << "New size --> " << std::endl;
	//	int s;
	//	if (getNum(s) > 0) {
	//		try {
	//			Tvector.SetSize(s);
	//		}
	//		catch(const std::exception& msg){
	//			os << msg.what() << std::endl;
	//		}
	//	}
	//	return 1;
	//}
	void Settings::Getter() {
		const char* tmp = Tvector.GetV1();
		for (int i = 0; i < Tvector.GetSize(); i++) {
			os << tmp[i] << " ";
		}
		os << "\n";

	}
	bool Settings::V1_change() {
		os << "Input new vector -->" << std::endl;
		char* tmpV = new char[80];
		is >> tmpV;
		int lenght = strlen(tmpV);
		try {
			Tvector.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		try {
			Tvector.SetV1(tmpV);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		//delete[] tmpV;
		return 1;
	}

	bool Settings::Logical_ILI() {
		Ternary_Vector Tmp;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize() + 1];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			Tmp.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		Tmp.SetV1(tmpV2);

		std::cout << "Logical ILI result --> ";
		try {
			Ternary_Vector Result_vector = Tvector.count_IlI(Tmp);
			char* input_tmp = Result_vector.GetV1();
			for (int i = 0; i < Tvector.GetSize(); i++) {
				os << input_tmp[i] << " ";
			}
			os << "\n";

		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		os << std::endl;
		return 1;
	}
	  
	bool Settings::Logical_I() {
		Ternary_Vector Tmp;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize() + 1];
		is >> tmpV2;
		int len = strlen(tmpV2);
		try {
			Tmp.SetSize(len);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		std::cout << "Logical I result --> ";
	 
			try {
				Ternary_Vector result_vector = Tvector.count_I(Tmp);
				char* input_tmp = result_vector.GetV1();
				for (int i = 0; i < Tvector.GetSize(); i++) {
					os << input_tmp[i] << " ";
				}

				os << "\n";
			}
			catch (const std::exception& msg) {
				os << msg.what() << std::endl;
			}
		
		return 1;
	}

	bool Settings::Logical_campare() {
		Ternary_Vector Tmp;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize() + 1];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			Tmp.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		Tmp.SetV1(tmpV2);
		std::cout << "Compare result --> ";
		if (tmpV2 > 0) {
			try {
				int flag = Tvector.compare(Tmp);
				if (flag == 1)
					std::cout << "Vectors are not equal" << std::endl;
				if (flag == 0)
					std::cout << "Vectors are equal!!! )))" << std::endl;
				os << "\n";
			}
			catch (const std::exception& msg) {
				os << msg.what() << std::endl;
			}
		}
		return 1;
	}

	bool Settings::invertor() {
		char* result_vector = Tvector.invertor();
		for (int i = 0; i < Tvector.GetSize(); i++) {
			os << result_vector[i] << " ";
		}
		os << "\n";
		delete[] result_vector;
		return 1;
	}

	bool Settings::Analisys() {
		int flag = Tvector.Analisys();
		if (flag == 0)
			os << "True" << std::endl;
		if (flag > 0)
			os << "False" << std::endl;
		return 1;
	}
	bool Settings::Input() {
		os << "Input --> " << std::endl;
		Tvector.InputV(is);
		return 1;
	}
	bool Settings::Output() {
		Tvector.OutputV(os);
		os << "\n";
		return 1;
	}
	bool Settings::Plus_Equal() {
		Ternary_Vector Vector2;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize()];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			Vector2.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		Vector2.SetV1(tmpV2);
		Tvector += Vector2;
		std::cout << "Plus-equal result --> ";
		Output();
		return 1;
	}
	bool Settings::Plus() {
		Ternary_Vector Vector2;
		//Ternary_Vector Vector3;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize() + 1];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			Vector2.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		Vector2.SetV1(tmpV2);
		Vector2 = Tvector + Vector2;

		const char* input_tmp = Vector2.GetV1();
		for (int i = 0; i < Vector2.GetSize(); i++) {
			os << input_tmp[i] << " ";
		}

		os << "\n";
		return 1;
	}
	bool Settings::Equal() {
		Ternary_Vector Vector2;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize()];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			Vector2.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		Vector2.SetV1(tmpV2);

		Tvector = Vector2;
		Output();

		return 1;
	}
	bool Settings::plus_pref() {
		Ternary_Vector Vector2(Tvector.GetSize());
		Vector2.SetSize(Tvector.GetSize());
		char* input_tmp = Vector2.GetV1();
		for (int i = 0; i < Vector2.GetSize(); i++) {
			os << input_tmp[i] << " ";
		}

		os << "\n";
		Output();
		Vector2 = ++Tvector;
		char* input_tmp2 = Vector2.GetV1();
		for (int i = 0; i < Vector2.GetSize(); i++) {
			os << input_tmp2[i] << " ";
		}

		os << "\n";
		Output();
		return 1;
	}
	bool Settings::post_plus() {
		Ternary_Vector Vector2(Tvector.GetSize());
		Vector2.SetSize(Tvector.GetSize());
		char* input_tmp = Vector2.GetV1();
		for (int i = 0; i < Vector2.GetSize(); i++) {
			os << input_tmp[i] << " ";
		}

		os << "\n";
		Output();
		Vector2 = Tvector++;
		char* input_tmp2 = Vector2.GetV1();
		for (int i = 0; i < Vector2.GetSize(); i++) {
			os << input_tmp2[i] << " ";
		}

		os << "\n";
		Output();
		return 1;
	}
	bool Settings::Tilda() {

		~Tvector;
		return 1;
	}
	bool Settings::Equal_Equal() {
		Ternary_Vector V2;
		os << "Input V2 -->" << std::endl;
		char* tmpV2 = new char[Tvector.GetMaxsize()];
		is >> tmpV2;
		int lenght = strlen(tmpV2);
		try {
			V2.SetSize(lenght);
		}
		catch (const std::exception& msg) {
			os << msg.what() << std::endl;
		}
		V2.SetV1(tmpV2);
		if (Tvector == V2) { os << "True" << std::endl; }
		else
			os << " bad" << std::endl;
		return 1;
	}
	bool Settings::A_Bi() {
		char A;
		int i;
		if (getNum(i) > 0) {
			if ((i < 0) || (i > Tvector.GetSize())) {
				os << "BAD SIZE !!" << std::endl;
				return 1;
			}
		}
		A = Tvector[i];
		os << "A --> " << A << std::endl;
		return 1;
	}
	bool Settings::Bi_A() {
		char A = '1';
		int i;
		if (getNum(i) > 0) {
			if ((i < 0) || (i > Tvector.GetSize())) {
				os << "BAD SIZE !!" << std::endl;
				return 1;
			}
		}
		Tvector[i] = A;
		Output();
		return 1;
	}
}