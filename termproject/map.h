#pragma once
#include <iostream>

class Map {
private:
	static int map[12][5];
	static int is_explosion[12][5];
public:
	Map();
	void static print();

	int static check_bottom_left(int x);/* 블럭의 왼쪽부분이 더 내려갈수있는지 확인하는함수 */
	int static check_bottom_right(int x);/*블럭의 오른쪽부분이 더 내려갈수있는지 확인하는함수 */

	void static block_set_toMap(int x,int y,int value); /* 블럭을 맵에다 출력 */

	void static explosion(); /* 터지게 하는 함수 */
	int static check_explosion(int x,int y,int count, int value); /* 터질수있는지 확인 */
	void static explosion_map(); /* 확인하고 터져야 되는곳 터지게 만든다.*/

	void static reset_is_explosion(); /* is_explosion 함수를 reset하는 함수 */
};