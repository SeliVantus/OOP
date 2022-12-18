#pragma once
#include "..\..\Library4\Library4\framework.h"
#include <map>
#include <string>
#include <iostream>
#include <memory>
using namespace std;
namespace Prog4 {

	class Manager {
	private:
		map <std::string, shared_ptr<Pack>> Mypack;

	public:
		bool init();
		bool auto_inst();
		bool inst();
		bool delete_pack();
		void cleaning();
		void glob_update();

	};





}
