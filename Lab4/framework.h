#pragma once

#include <string>

namespace Prog4 {

	class Pack {
	private:
		int flag;
		std::string name;
		std::string author_name;
		int inst_version;
	public:
		add_to_rep();
		output_into();
		delete_f_rep();
		void update_pack();
	};

	class Not_empty_pack :Pack {
	private:
		int last_version;
		Empty_pack* empty_pack;
	public:
		unification();
	};

	class Empty_pack :Pack {
	private:

	public:

	};
	
	class Pack_MI :Not_empty_pack {
	private:
		Pack* links;
	public:

	};

	class Pack_soft:Not_empty_pack {
	private:
		Pack_MI* link;
	public:
		separation();
	};
}