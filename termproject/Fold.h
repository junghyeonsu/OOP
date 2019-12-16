#pragma once
#pragma once
#include <iostream>


class Fold {
private:
	static int Fold_block[2][2]; // fold�� �迭
	static int rodate_number; // ȸ���Ҷ����� ���ϴ� ����
	/*               x                y               */
	static int location_one1, location_one2; //������
	static int location_two1, location_two2; //��������
	static int location_thr1, location_thr2; // ���ʾƷ�
	static int location_four1, location_four2; // �����ʾƷ��� �ִ� ������ ��ġ
public:
	Fold();
	void static set_block(int x, int y, int value); /* x,y = value �� set���ִ� �Լ� */

	void static print(); /* ó�� ���� ����Ʈ = map�� ����  */ 

	void static init_location(); /* fold�� ����ȭ�鿡�� �ʱ���ġ �����ִ� �Լ� */
	/* ���� �� �κ��� location�� �������ִ� �Լ� */
	void static set_location(int x1, int x2, int y1, int y2 , int z1, int z2, int k1, int k2);

	/* �̵� �Լ��� */
	void static move_left();  //����
	void static move_right(); // ������
	void static move_down(); // �Ʒ�
	void static move_all_down(); // ���ξƷ��� �̵�
	void static rodate(); // ȸ��


	/* �̵� ���� Ȯ�� �Լ��� */
	bool static is_move_left(); //�������� �̵� �Ҽ��ֳ� Ȯ���ϴ��Լ�?
	bool static is_move_right();//���������� �̵� �Ҽ��ֳ� Ȯ���ϴ��Լ�?
	bool static is_move_down();// �Ʒ��� �̵� �Ҽ��ֳ� Ȯ���ϴ��Լ�?

	/* �������� ��������ֱ� */
	void static randomize();

	~Fold();
};