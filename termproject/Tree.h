#pragma once
#pragma once
#pragma once
#include <iostream>


class Tree {

private:
	static int Tree_block[3][3];
	static int rodate_number;
	static int location_one1, location_one2;
	static int location_two1, location_two2;
	static int location_thr1, location_thr2;
	static int location_four1, location_four2;
	static int location_five1, location_five2;

public:
	Tree();
	void static set_block(int x, int y, int value); /* x,y = value �� set���ִ� �Լ� */

	void static print(); /* ó�� ���� ����Ʈ = map�� ����  */

	void static init_location();
	void static set_location(int one1, int one2, int two1, int two2, int thr1, int thr2, int four1, int four2, int five1, int five2);
	void static set_location_col(int one1, int one2, int two1, int two2, int thr1, int thr2);

	/* �̵� �Լ��� */
	void static move_left();
	void static move_right();
	void static move_down();
	void static move_all_down();
	void static rodate();

	/* �̵� ���� Ȯ�� �Լ��� */
	bool static is_move_left();
	bool static is_move_right();
	bool static is_move_down();



	~Tree();
};

