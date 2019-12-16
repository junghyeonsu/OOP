#pragma once
#include <iostream>

class Map {
private:
	static int map[12][5];
	static int is_explosion[12][5];
public:
	Map();
	void static print();

	int static check_bottom_left(int x);/* ���� ���ʺκ��� �� ���������ִ��� Ȯ���ϴ��Լ� */
	int static check_bottom_right(int x);/*���� �����ʺκ��� �� ���������ִ��� Ȯ���ϴ��Լ� */

	void static block_set_toMap(int x,int y,int value); /* ���� �ʿ��� ��� */

	void static explosion(); /* ������ �ϴ� �Լ� */
	int static check_explosion(int x,int y,int count, int value); /* �������ִ��� Ȯ�� */
	void static explosion_map(); /* Ȯ���ϰ� ������ �Ǵ°� ������ �����.*/

	void static reset_is_explosion(); /* is_explosion �Լ��� reset�ϴ� �Լ� */
};