// puyopuyo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <ctime>
#include "Fold.h"
#include "map.h"
#include "Tree.h"

// 메인함수 
int main() {

	Map map;

	int i = 0;
	int input = 1;
	Fold fold[10];
	Tree tree[5];
	/* 트리안되는게 맨 밑으로 내리는거랑
	눕히는거.. (회전) == four , five 인덱스가 이상한거같음!
	*/

	// p를 입력하면 게임이 종료된다.
	while (input != 112) {
		// 1,2,3 나눠서 블럭 출력
		fold[i].print();
		map.print();
		input = getchar(); //아스키코드 입력받는 아이
		// a 입력했을 때 = 왼쪽이동
		if (input == 97) { fold[i].move_left(); }
		// d 입력했을 때 = 오른쪽이동
		else if (input == 100) { fold[i].move_right(); }
		// s 입력했을 때 = 아래로이동
		else if (input == 115) {
			fold[i].move_down();
			if (fold[i].is_move_down() == false) {
				fold[i].init_location();
				i++; 
			}
		}
		// x 입력했을 때 = 제일아래로 이동
		else if (input == 120) {
			fold[i].move_all_down();
			i++;
			//map.explosion();
			fold[i].init_location();
			fold[i].randomize();
		}
		// e 눌렀을 때 = 회전
		else if (input == 101) { fold[i].rodate(); }
	}

	
}
