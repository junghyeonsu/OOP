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


/* �� ������ */
Map::Map() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j] = 0;
		}
	}
}

/* �� ����Ʈ �Լ� */
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

/* ���� �������ϴ� �Լ� */
void Map::explosion() {
	int count = 0;
	for (int i = 0; i < 12; i++) {

		for (int j = 0; j < 5; j++) {
			
			int value = map[i][j];
			
			if (check_explosion(i, j, 0, value) >= 4) {
				explosion_map();// ������
				reset_is_explosion(); //reset �迭 �ʱ�ȭ
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
	/* ���� �� */
	if (map[x][y] == value) {

		/* õ���̰� ����*/
		if(x == 0 && y == 0) {
			/* ������ �˻� */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y+1, count, value);
			}
			/* �Ʒ� �˻� */
			if (map[x+1][y] == value && map[x+1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x+1, y, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* õ�� */
		if (x == 0 && y != 0) {
			/* ������ �˻� */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* �Ʒ� �˻� */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x][y-1] == value && map[x][y-1] != 0) {
				is_explosion[x][y-1] = 1;
				allcount += check_explosion(x, y-1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* ���� */
		if (x != 0 && y == 0) {
			/* ������ �˻� */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* �Ʒ� �˻� */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x-1][y] == value && map[x-1][y] != 0) {
				is_explosion[x-1][y] = 1;
				allcount += check_explosion(x-1, y, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* �ٴ��̰� ������ */
		if(x == 11 && y == 4) {
			/* ���� �˻� */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* ������ */
		if (x != 11 && y == 4) {
			/* �Ʒ� �˻� */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* �ٴ� */
		if (x == 11 && y != 4) {
			/* ������ �˻� */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* ���� �˻� */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}

		/* ��� */
		if (x != 11 && y != 4 && x != 0 && y != 0) {
			/* ������ �˻� */
			if (map[x][y + 1] == value && map[x][y + 1] != 0) {
				is_explosion[x][y + 1] = 1;
				allcount += check_explosion(x, y + 1, count, value);
			}
			/* �Ʒ� �˻� */
			if (map[x + 1][y] == value && map[x + 1][y] != 0) {
				is_explosion[x + 1][y] = 1;
				allcount += check_explosion(x + 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x - 1][y] == value && map[x - 1][y] != 0) {
				is_explosion[x - 1][y] = 1;
				allcount += check_explosion(x - 1, y, count, value);
			}
			/* ���� �˻� */
			if (map[x][y - 1] == value && map[x][y - 1] != 0) {
				is_explosion[x][y - 1] = 1;
				allcount += check_explosion(x, y - 1, count, value);
			}
			temp = allcount;
			allcount = 0;
			return temp;
		}
		
	}
	/* ���� ���� �� */
	else {
		return 0;
	}
}

/* x������ �ؿ� ���� üũ�ϴ� �Լ� */
int Map::check_bottom_left(int x) {
	for (int i = 11; i > 0; i--) {
		if (map[i][x] == 0) {
			return i;
		}
	}
}

/* location2 �־��ָ�� */
int Map::check_bottom_right(int x) {
	for (int i = 11; i > 0; i--) {
		if (map[i][x] == 0) {
			return i;
		}
	}
}


/* ���� �ʿ� ����ϴ� �Լ� */
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
