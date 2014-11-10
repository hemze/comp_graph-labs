
// TODO: ���������� ��� �������.
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

const std::string DATA_STRUCT_ERR_TMPL = "Data structure error: %s\n";
const std::string BAD_IFSTREAM = "Bad input stream provided\n";
const std::string BAD_OFSTREAM = "Bad output stream provided\n";

struct conf{
	int id;
	std::string ifile;
	std::string ofile;
};

void notice_error(std::string msg, bool do_exit = 0){
	std::cout << msg << std::endl;
	if (do_exit){
		exit(1);
	}
}

std::string input_file = "";
std::string output_file = "";

/////////////////////////////////////
// �����-�������� ��� ���� �������� ������� ������
class data_parser{
protected:
	std::ifstream ifs;
	std::ofstream ofs;
public:
	int counter;
	data_parser(std::string ipath,std::string opath);
	~data_parser();
	void put_data(){
		//TODO ���������, ��� ������ ����
	};
	std::vector<int>& parse(std::vector<int>&);
	std::vector<int>& parse_2lines(std::vector<int>&);
	std::vector<int>& parse_3lines(std::vector<int>&);
	std::vector<int>& parse_N_sim_lines(std::vector<int>&);
	std::vector<int>& parse_2N_lines(std::vector<int>&);
};
//class data_parser_2lines : public data_parser{
//public:
//	data_parser_2lines(){};
//	~data_parser_2lines(){};
//	std::vector<int>& parse(std::vector<int>&){};
//};
//class data_parser_3lines : public data_parser{
//	
//};
//class data_parser_N_sim_lines : public data_parser{
//	
//};
//class data_parser_2N_lines : public data_parser{
//	
//};

/////////////////////////////////////
// ����������� �������
void vect_size(){
	double size = 0;
	double curr = 0;
	data_parser parser(input_file,output_file);
	std::vector<int> data;
	parser.parse(data);
	for(std::vector<int>::iterator it = data.begin(); it != data.end(); ++it){
		curr = *it;
		size += pow(curr,2);
	}
	parser.put_data(size);
}
void line_by2p(){
	printf("A line will soon be found!\n");
	data_parser parser(input_file);
	std::vector<int> data;
	parser.parse(data);
	std::cout << "--" << data.size() << std::endl;
}

/////////////////////////////////////
// ����� ������ ������� � �����������
// 1. ���������� ��� ��������� �� ����������
typedef void(*task_handler_t)();
// 2. ���������� ������ ���������� �� ����������� ��������������� ����
task_handler_t id_funx_map[13] = {
	&(vect_size),
	&(vect_size),
	&(line_by2p)
};
/////////////////////////////////////

/////////////////////////////////////
// ����� �������
class task{
private:
	int id;
	task_handler_t* task_handler;
	std::ifstream ifs;
	std::ofstream ofs;
public:
	task(const conf& cfg);
	~task();
	void show_help();
	/*
	1)	����� ����� ����� ������
	2)	1-� ������: N (���������� ���-�� ����� � ��������� �������)
		2-� ������: N ����� ����� ������
		3-� ������: N ����� ����� ������
	3)	1-� ������: N (���������� ���-�� ����� � ��������� �������)
		2-� ������: 2N ����� ����� ������
	4)	1-� ������: N (���������� ���������� ����������� �����)
		2-� ������: 2 ����� ����� ������
		...
		N-� ������: 2 ����� ����� ������
	5)	1-� ������: N (���������� ���������� ����������� ����� x2)
		2-� ������: 6 ����� ����� ������
		3-� ������: 2 ����� ����� ������
		...
		(2N-1)-� ������: 6 ����� ����� ������
		(2N)-�   ������: 2 ����� ����� ������
	*/
};
/////////////////////////////////////

///////////////////////////////
// TASK class IMPLEMENTATION //
///////////////////////////////

task::task(const conf& cfg):ifs(cfg.ifile.c_str()), ofs(cfg.ofile.c_str()){
	id = cfg.id;
	task_handler = id_funx_map;
	(*task_handler[id])();
}

task::~task(){
	ifs.close();
	ofs.close();
}

//////////////////////////////////////
// DATA_PARSER class IMPLEMENTATION //
//////////////////////////////////////

data_parser::data_parser(std::string ipath,std::string opath): ifs(ipath.c_str()), ofs(opath.c_str()){
	if (!ifs){
		notice_error(BAD_IFSTREAM,1);
	}
	if (!ofs){
		notice_error(BAD_OFSTREAM,1);
	}
}

data_parser::~data_parser(){
	ifs.close();
	ofs.close();
};

std::vector<int>& data_parser::parse(std::vector<int>& data){

	if (ifs && !ifs.eof()){
		int i = 0;
		int val = 0;
		while (!ifs.eof()){
			ifs >> val;
			//std::cout << "Value : \"" << val << "\"" << std::endl;
			data.push_back(val);
		}
	} else {
		notice_error(BAD_IFSTREAM,1);
	}
	return data;
}

std::vector<int>& data_parser::parse_2lines(std::vector<int>& data){
	return data;
};
std::vector<int>& data_parser::parse_3lines(std::vector<int>& data){
	return data;
};
std::vector<int>& data_parser::parse_N_sim_lines(std::vector<int>& data){
	return data;
};
std::vector<int>& data_parser::parse_2N_lines(std::vector<int>& data){
	return data;
};