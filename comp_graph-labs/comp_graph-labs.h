#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct conf{
	int id;
	std::string ifile;
	std::string ofile;
};

void notice_error(std::string msg, bool do_exit){
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

//typedef void(solution::* task_handler_t)();
typedef void(*task_handler_t)();
// ����� ������ ������� � �����������
task_handler_t id_funx_map[13] = {
	&(vect_size),
	&(vect_size),
	&(line_by2p)
};

//task_handler_t* task_handler = id_funx_map;
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
	//TODO: ������� ������ ������� � ���� ��� ����������� �������� ������, ��������������� �������� ����.
	/*
	1)	����� ����� ����� ������
	2)	1-� ������: N
		2-� ������: N ����� ����� ������
		3-� ������: N ����� ����� ������
	3)	1-� ������: N
		2-� ������: N ��� ����� ����� ������
	4)	1-� ������: N
		2-� ������: 2 ����� ����� ������
		...
		N-� ������: 2 ����� ����� ������
	5)	1-� ������: N
		2-� ������: 6 ����� ����� ������
		3-� ������: 2 ����� ����� ������
		...
		(2N-1)-� ������: 6 ����� ����� ������
		(2N)-�   ������: 2 ����� ����� ������
	6)	

	*/
};

///////////////////////////////
// TASK class IMPLEMENTATION //
///////////////////////////////

task::task(const conf& cfg){
	id = cfg.id;
	//TODO: ��������� ������� � �������� ������
	task_handler = id_funx_map;
	(*task_handler[id])();
}

task::~task(){

}