#include "Tree.h"
#include "map.h"
#include <ctime> //����
int Tree::Tree_block[3][3] =
{
	{0,0,0},
	{0,0,0},
	{0,0,0}
};

int Tree::location_one1 = 0;
int Tree::location_one2 = 0;
int Tree::location_two1 = 0;
int Tree::location_two2 = 0;
int Tree::location_thr1 = 0;
int Tree::location_thr2 = 0;
int Tree::location_four1 = 0;
int Tree::location_four2 = 0;
int Tree::location_five1 = 0;
int Tree::location_five2 = 0;

int Tree::rodate_number = 1;

/* �� ������ */
Tree::Tree() {
	srand((unsigned int)time(0));

	int random = rand() % 4 + 1;  /* 1~4���� ������ */
	set_block(0, 1, random);
	random = rand() % 4 + 1;
	set_block(1, 1, random);
	random = rand() % 4 + 1;
	set_block(2, 1, random);
	random = rand() % 4 + 1;
	set_block(1, 0, random);
	random = rand() % 4 + 1;
	set_block(1, 2, random);

}

/* �� ���� �ϴ� �Լ� */
void Tree::set_block(int x, int y, int value) {
	Tree_block[x][y] = value;
	init_location();
}


/* ����Ʈ�ϱ� */
void Tree::print() {
	if (rodate_number == 1) {
		Map::block_set_toMap(location_four1, location_four2, 0);
		Map::block_set_toMap(location_five1, location_five2, 0);

		Map::block_set_toMap(location_one1, location_one2, Tree_block[0][1]);
		Map::block_set_toMap(location_two1, location_two2, Tree_block[1][1]);
		Map::block_set_toMap(location_thr1, location_thr2, Tree_block[2][1]);
	}
	else if (rodate_number == 2) {
		Map::block_set_toMap(location_one1, location_one2, 0);
		Map::block_set_toMap(location_thr1, location_thr2, 0);

		Map::block_set_toMap(location_two1, location_two2, Tree_block[1][1]);
		Map::block_set_toMap(location_four1, location_four2, Tree_block[1][0]);
		Map::block_set_toMap(location_five1, location_five2, Tree_block[1][2]);
	}
	else if (rodate_number == 3) {
		Map::block_set_toMap(location_four1, location_four2, 0);
		Map::block_set_toMap(location_five1, location_five2, 0);

		Map::block_set_toMap(location_one1, location_one2, Tree_block[2][1]);
		Map::block_set_toMap(location_two1, location_two2, Tree_block[1][1]);
		Map::block_set_toMap(location_thr1, location_thr2, Tree_block[0][1]);
	}
	else {
		Map::block_set_toMap(location_one1, location_one2, 0);
		Map::block_set_toMap(location_thr1, location_thr2, 0);

		Map::block_set_toMap(location_two1, location_two2, Tree_block[1][1]);
		Map::block_set_toMap(location_four1, location_four2, Tree_block[1][2]);
		Map::block_set_toMap(location_five1, location_five2, Tree_block[1][0]);
	}
}

/* ���� ��ġ ���� �Լ� */
void  Tree::set_location(int one1, int one2, int two1, int two2, int thr1, int thr2,int four1,int four2, int five1, int five2) {
	location_one1 = one1;
	location_one2 = one2;
	location_two1 = two1;
	location_two2 = two2;
	location_thr1 = thr1;
	location_thr2 = thr2;
	location_four1 = four1;
	location_four2 = four2;
	location_five1 = five1;
	location_five2 = five2;
}

void Tree::set_location_col(int one1, int one2, int two1, int two2, int thr1, int thr2) {
	location_one1 = one1;
	location_one2 = one2;
	location_two1 = two1;
	location_two2 = two2;
	location_thr1 = thr1;
	location_thr2 = thr2;
}


/* ���� �̵� */
void Tree::move_left() {

	// ����
	if (rodate_number % 2 == 1) {

		if (is_move_left() == true) {

			Map::block_set_toMap(location_one1, location_one2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_two1, location_two2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_thr1, location_thr2, 0);   /* �������� ��������� */

			set_location
			(
				location_one1, --location_one2,
				location_two1, --location_two2,
				location_thr1, --location_thr2,
				location_four1, --location_four2,
				location_five1, --location_five2
			);

			print();
		}

	}
	// ����
	else {

		if (is_move_left() == true) {

			Map::block_set_toMap(location_five1, location_five2, 0);   /* �������� ��������� */

			set_location
			(
				location_one1, --location_one2,
				location_two1, --location_two2,
				location_thr1, --location_thr2,
				location_four1, --location_four2,
				location_five1, --location_five2
			);

			print();
		}

	}

}

/* ������ �̵� */
void Tree::move_right() {

	if (rodate_number % 2 == 1) {

		if (is_move_right() == true) {

			Map::block_set_toMap(location_one1, location_one2, 0);   /* ������ ��������� */
			Map::block_set_toMap(location_two1, location_two2, 0);   /* ������ ��������� */
			Map::block_set_toMap(location_thr1, location_thr2, 0);   /* ������ ��������� */

			set_location_col
			(
				location_one1, ++location_one2,
				location_two1, ++location_two2,
				location_thr1, ++location_thr2
			);

			print();
		}

	}
	else {

		if (is_move_right() == true) {

			Map::block_set_toMap(location_four1, location_four2, 0);   /* ������ ��������� */
	
			set_location
			(
				location_one1, ++location_one2,
				location_two1, ++location_two2,
				location_thr1, ++location_thr2,
				location_four1, ++location_four2,
				location_five1, ++location_five2
			);

			print();
		}
	}
}

/* �Ʒ��� �̵� */
void Tree::move_down() {

	if (rodate_number % 2 == 1) {

		if (is_move_down() == true) {

			Map::block_set_toMap(location_one1, location_one2, 0);   /* ������ ��������� */
			Map::block_set_toMap(location_two1, location_two2, 0);   
			Map::block_set_toMap(location_thr1, location_thr2, 0);   

			set_location_col
			(
				++location_one1, location_one2,
				++location_two1, location_two2,
				++location_thr1, location_thr2
			);

			print();
		}

	}
	else {

		if (is_move_down() == true) {

			Map::block_set_toMap(location_two1, location_two2, 0);   /* ������ ��������� */
			Map::block_set_toMap(location_four1, location_four2, 0);   
			Map::block_set_toMap(location_five1, location_five2, 0);   

			set_location
			(
				++location_one1, location_one2,
				++location_two1, location_two2,
				++location_thr1, location_thr2,
				++location_four1, location_four2,
				++location_five1, location_five2
			);

			print();
		}
	}
}

/* ���� �Ʒ��� ������ �� */
void Tree::move_all_down() {

	if (rodate_number % 2 == 1) {

		if (is_move_down() == true) {

			Map::block_set_toMap(location_one1, location_one2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_two1, location_two2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_thr1, location_thr2, 0);   /* �������� ��������� */

			set_location
			(
				9, location_one2,
				10, location_two2,
				11, location_thr2,
				10, location_four2,
				10, location_five2
			);

			print();
		}

	}
	else {
		if (is_move_down() == true) {

			Map::block_set_toMap(location_two1, location_two2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_four1, location_four2, 0);   /* �������� ��������� */
			Map::block_set_toMap(location_five1, location_five2, 0);   /* �������� ��������� */

			set_location_col
			(
				9, location_one2,
				10, location_two2,
				11, location_thr2
			);

			print();
		}
	}
}


/* ���� ȸ�� */
void Tree::rodate() {
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

bool Tree::is_move_left() {
	if (rodate_number % 2 == 1) {
		if (location_one2 == 0 || location_two2 == 0 || location_thr2 == 0) { return false; }
		else { return true; }
	}
	else {
		if (location_four2 == 0) { return false; }
		else { return true; }
	}
}
bool Tree::is_move_right() {
	if (rodate_number % 2 == 1) {
		if (location_one2 == 4 || location_two2 == 4 || location_thr2 == 4) { return false; }
		else { return true; }
	}
	else {
		if (location_five2 == 0) { return false; }
		else { return true; }
	}
}
bool Tree::is_move_down() {
	if (rodate_number % 2 == 1) {
		if (location_thr1 == 11) { return false; }
		else { return true; }
	}
	else {
		if (location_four2 == 11 || location_two2 == 11 || location_five2 == 11) { return false; }
		else { return true; }
	}
}


void Tree::init_location() {
	set_location(0, 3, 1, 3, 2, 3, 1, 2, 1, 4);
}


Tree::~Tree() {
	delete this;
}