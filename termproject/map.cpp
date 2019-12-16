#include "map.h"
#include <stdio.h>

#define clear() printf("\033[H\033[J")

int Map::map[12][5] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};

int Map::is_explosion[12][5] =
{
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0}
};


/* 맵 생성자 */
Map::Map() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j] = 0;
		}
	}
}

/* 맵 프린트 함수 */
void Map::print() {
	clear();
	printf("							SCORE : 0");
	printf("\n");
	printf("\n");
	for (int i = 0; i < 12; i++) {
		printf("					                ");
		for (int j = 0; j < 5; j++) {
			printf("%d  ", map[i][j]);
		}
		printf("\n"); printf("\n");
	}
}

/* 블럭들 터지게하는 함수 */
void Map::explosion() {
	int count = 0;
	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 5; j++) {
			
			int value = map[i][j];
			
			if (check_explosion(i, j, 0, value) >= 4) {
				explosion_map();// 터지고
				reset_is_explosion(); //reset 배열 초기화
			}
			

		}

	}
}

static int allcount = 0;

void Map::explosion_map() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			if (map[i][j] != 0) {
				map[i][j] = 0;
			}
		}
	}
}


int Map::check_explosion(int x, int y, int count, int value) {
	int temp = 0;
	/* 같을 때 */
	if (map[x][y] == value) {

		/* 천장이고 왼쪽*/
		if(x == 0 && y == 0) {
			/* 오른쪽 검사 */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y+1, count, value);
			}
			/* 아래 검사 */
			if (map[x+1][y] == value && map[x+1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x+1, y, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 천장 */
		if (x == 0 && y != 0) {
			/* 오른쪽 검사 */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* 아래 검사 */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* 왼쪽 검사 */
			if (map[x][y-1] == value && map[x][y-1] != 0) {
				is_explosion[x][y-1] = 1;
				allcount += check_explosion(x, y-1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 왼쪽 */
		if (x != 0 && y == 0) {
			/* 오른쪽 검사 */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* 아래 검사 */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* 위쪽 검사 */
			if (map[x-1][y] == value && map[x-1][y] != 0) {
				is_explosion[x-1][y] = 1;
				allcount += check_explosion(x-1, y, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 바닥이고 오른쪽 */
		if(x == 11 && y == 4) {
			/* 위쪽 검사 */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* 왼쪽 검사 */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 오른쪽 */
		if (x != 11 && y == 4) {
			/* 아래 검사 */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* 위쪽 검사 */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* 왼쪽 검사 */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 바닥 */
		if (x == 11 && y != 4) {
			/* 오른쪽 검사 */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* 위쪽 검사 */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* 왼쪽 검사 */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* 가운데 */
		if (x != 11 && y != 4 && x != 0 && y != 0) {
			/* 오른쪽 검사 */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* 아래 검사 */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* 위쪽 검사 */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* 왼쪽 검사 */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}
		
	}
	/* 같지 않을 때 */
	else {
		return 0;
	}
}

/* x누를때 밑에 왼쪽 체크하는 함수 */
int Map::check_bottom_left(int x) {
	for (int i = 11; i > 0; i--) {
		if (map[i][x] == 0) {
			return i;
		}
	}
}

/* location2 넣어주면됨 */
int Map::check_bottom_right(int x) {
	for (int i = 11; i > 0; i--) {
		if (map[i][x] == 0) {
			return i;
		}
	}
}


/* 블럭을 맵에 등록하는 함수 */
void Map::block_set_toMap(int x, int y, int value) {
	map[x][y] = value;
}


void Map::reset_is_explosion() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			is_explosion[i][j] = 0;
		}
	}
}
