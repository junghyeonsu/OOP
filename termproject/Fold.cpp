#include "Fold.h"
#include "map.h"
#include <ctime> //����
int Fold::Fold_block[2][2] =
{
	{0,0},
	{0,0}
};

int Fold::location_one1 = 0;
int Fold::location_one2 = 0;
int Fold::location_two1 = 0;
int Fold::location_two2 = 0;
int Fold::location_thr1 = 0;
int Fold::location_thr2 = 0;
int Fold::location_four1 = 0;
int Fold::location_four2 = 0;

int Fold::rodate_number = 1;


/* �� ������ */
Fold::Fold() {
	
	srand((unsigned int)time(0));

	int random1 = rand() % 4 + 1;  /* 1~4���� ������ */
	int random2 = rand() % 4 + 1;  /* 1~4���� ������ */
	int random3 = rand() % 4 + 1;  /* 1~4���� ������ */
	
	set_block(0, 0, 0);  	
	set_block(0, 1, random1);
	set_block(1, 0, random2);  
	set_block(1, 1, random3);

}

void Fold::randomize() {
	srand((unsigned int)time(0));

	int random1 = rand() % 4 + 1;  /* 1~4���� ������ */
	int random2 = rand() % 4 + 1;  /* 1~4���� ������ */
	int random3 = rand() % 4 + 1;  /* 1~4���� ������ */

	set_block(0, 0, 0);
	set_block(0, 1, random1);
	set_block(1, 0, random2);
	set_block(1, 1, random3);
}

/* �� ���� �ϴ� �Լ� */
void Fold::set_block(int x, int y, int value) {
	Fold_block[x][y] = value;
	init_location();
	/* 1(1,2)  2(1,2)
	   3(1,2)  4(1,2) */
}


/* ����Ʈ�ϱ� */
void Fold::print() {
	if (rodate_number == 1) {
		Map::block_set_toMap(location_one1, location_one2, Fold_block[0][0]); Map::block_set_toMap(location_two1, location_two2, Fold_block[0][1]);
		Map::block_set_toMap(location_thr1, location_thr2, Fold_block[1][0]); Map::block_set_toMap(location_four1, location_four2, Fold_block[1][1]);
	}
	else if (rodate_number == 2) {
		Map::block_set_toMap(location_one1, location_one2, Fold_block[1][0]); Map::block_set_toMap(location_two1, location_two2, Fold_block[0][0]);
		Map::block_set_toMap(location_thr1, location_thr2, Fold_block[1][1]); Map::block_set_toMap(location_four1, location_four2, Fold_block[0][1]);
	}
	else if (rodate_number == 3) {
		Map::block_set_toMap(location_one1, location_one2, Fold_block[1][1]); Map::block_set_toMap(location_two1, location_two2, Fold_block[1][0]);
		Map::block_set_toMap(location_thr1, location_thr2, Fold_block[0][1]); Map::block_set_toMap(location_four1, location_four2, Fold_block[0][0]);
	}
	else {
		Map::block_set_toMap(location_one1, location_one2, Fold_block[0][1]); Map::block_set_toMap(location_two1, location_two2, Fold_block[1][1]);
		Map::block_set_toMap(location_thr1, location_thr2, Fold_block[0][0]); Map::block_set_toMap(location_four1, location_four2, Fold_block[1][0]);
	}
}

/* ���� ��ġ ���� �Լ� */
void  Fold::set_location(int one1, int one2, int two1, int two2, int thr1 , int thr2 , int four1 , int four2) {
	location_one1 = one1;
	location_one2 = one2;
	location_two1 = two1;
	location_two2 = two2;
	location_thr1 = thr1;
	location_thr2 = thr2;
	location_four1 = four1;
	location_four2 = four2;
}

/* ���� �̵� */
void Fold::move_left() {

	if (is_move_left() == true) {

		Map::block_set_toMap(location_two1, location_two2, 0);   /* �������� ��������� */
		Map::block_set_toMap(location_four1, location_four2, 0); /* �������� ��������� */

		set_location
		(
			location_one1, --location_one2, location_two1, --location_two2,
			location_thr1, --location_thr2, location_four1, --location_four2
		);

		print();
	}
}

/* ������ �̵� */
void Fold::move_right() {

	if (is_move_right() == true) {

		Map::block_set_toMap(location_one1, location_one2, 0); /* ������ ��������� */
		Map::block_set_toMap(location_thr1, location_thr2, 0); /* ������ ��������� */

		set_location
		(
			location_one1, ++location_one2, location_two1, ++location_two2,
			location_thr1, ++location_thr2, location_four1, ++location_four2
		);

		print();
	}
}

/* �Ʒ��� �̵� */
void Fold::move_down() {
	
	if (is_move_down() == true) {
		Map::block_set_toMap(location_one1, location_one2, 0); /* ������ ��������� */
		Map::block_set_toMap(location_two1, location_two2, 0); /* ������ ��������� */

		set_location
		(
			++location_one1, location_one2, ++location_two1, location_two2,
			++location_thr1, location_thr2, ++location_four1, location_four2
		);

		print();

	}
}

/* ���� �Ʒ��� ������ �� */
void Fold::move_all_down() {
	if (is_move_down() == true) {
		Map::block_set_toMap(location_one1, location_one2, 0); /* ������ġ�� ��������� */
		Map::block_set_toMap(location_two1, location_two2, 0); /* ������ġ�� ��������� */
		Map::block_set_toMap(location_thr1, location_thr2, 0); /* ������ġ�� ��������� */
		Map::block_set_toMap(location_four1, location_four2, 0); /* ������ġ�� ��������� */

		int left = Map::check_bottom_left(location_thr2);
		int right = Map::check_bottom_right(location_four2);

		set_location
		(
			left-1, location_one2, right-1, location_two2,
			left, location_thr2, right, location_four2
		);
		print();
	}
}


/* ���� ȸ�� */
void Fold::rodate() {

	if (rodate_number == 1) {
		rodate_number++;
	}
	else if (rodate_number == 2) {
		rodate_number++;
	}
	else if (rodate_number == 3) {
		rodate_number++;
	}
	else {
		rodate_number = 1;
	}
	print();
}

/* �̵� �������� Ȯ���ϴ� �Լ��� */
bool Fold::is_move_left() {
	if (location_one2 == 0 || location_thr2 == 0) { return false; }
	else { return true; }
}
bool Fold::is_move_right() {
	if (location_two2 == 4 || location_four2 == 4) { return false; }
	else{ return true; }
}
bool Fold::is_move_down() {
	if (location_thr1 == 11 || location_four1 == 11) { return false; }
	else { return true; }
}

void Fold::init_location() {
	set_location(0, 2, 0, 3, 1, 2, 1, 3);
}

Fold::~Fold(){
	delete this;
}