#pragma once
#pragma once
#include <iostream>


class Fold {
private:
	static int Fold_block[2][2]; // fold블럭 배열
	static int rodate_number; // 회전할때마다 변하는 변수
	/*               x                y               */
	static int location_one1, location_one2; //왼쪽위
	static int location_two1, location_two2; //오른쪽위
	static int location_thr1, location_thr2; // 왼쪽아래
	static int location_four1, location_four2; // 오른쪽아래에 있는 블럭들의 위치
public:
	Fold();
	void static set_block(int x, int y, int value); /* x,y = value 로 set해주는 함수 */

	void static print(); /* 처음 시작 프린트 = map에 쓰임  */ 

	void static init_location(); /* fold블럭 게임화면에서 초기위치 정해주는 함수 */
	/* 블럭의 각 부분의 location을 설정해주는 함수 */
	void static set_location(int x1, int x2, int y1, int y2 , int z1, int z2, int k1, int k2);

	/* 이동 함수들 */
	void static move_left();  //왼쪽
	void static move_right(); // 오른쪽
	void static move_down(); // 아래
	void static move_all_down(); // 전부아래로 이동
	void static rodate(); // 회전


	/* 이동 가능 확인 함수들 */
	bool static is_move_left(); //왼쪽으로 이동 할수있나 확인하는함수?
	bool static is_move_right();//오른쪽으로 이동 할수있나 확인하는함수?
	bool static is_move_down();// 아래로 이동 할수있나 확인하는함수?

	/* 랜덤으로 변경시켜주기 */
	void static randomize();

	~Fold();
};