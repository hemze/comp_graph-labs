
// TODO: ���������� ��� �������.
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

// ����������� �������
void vect_size(){
	printf("Vector size will soon be found!\n");
}
void line_by2p(){
	printf("A line will soon be found!\n");
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
// �����-�������� ��� ���� �������� ������� ������
class data_parser{
protected:
	std::ifstream ifs;
public:
	int counter;
	data_parser(std::ifstream str);
	~data_parser();
	int* parse(int data[]);
};
class data_parser_2lines : public data_parser{};
class data_parser_3lines : public data_parser{};
class data_parser_N_sim_lines : public data_parser{};
class data_parser_2N_lines : public data_parser{};
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

}

//////////////////////////////////////
// DATA_PARSER class IMPLEMENTATION //
//////////////////////////////////////

data_parser::data_parser(std::ifstream str): ifs(str){}

data_parser::parse(int data[]){
	if (ifs && !ifs.eof()){
		//std::string counter;
		ifs >> counter;
		int i = 0;
		while (!ifs.eof()){
			ifs >> data[i];
			i++;
		}
	} else {
		notice_error(BAD_IFSTREAM,1);
	}
}
