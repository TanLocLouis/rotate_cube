#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

struct point {
	float x, y, z;
};

void rotate(point& p, float x, float y, float z) {
	float rad = 0;
	
	rad = x;
	p.y = cos(rad) * p.y - sin(rad) * p.z;
	p.z = sin(rad) * p.y + cos(rad) * p.z;
	
	rad = y;
	p.x = cos(rad) * p.x + sin(rad) * p.z;
	p.z = -sin(rad) * p.x + cos(rad) * p.z;
	
	rad = z;
	p.x = cos(rad) * p.x - sin(rad) * p.y;
	p.y = sin(rad) * p.x + cos(rad) * p.y;
}


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 15, x + 50);
}

void line(float x1, float y1, float x2, float y2) {
	gotoxy(x1, y1);
	for (int i = 0; i < 10; i++) {
		int newx = x1 + ((x2 - x1) / 10) * i;
		int newy = y1 + ((y2 - y1) / 10) * i;
		gotoxy(newx, newy);
		cout << "*";
	}	
}

void showp(point& p) {
	gotoxy((int) p.x,(int) p.y);
	cout << "*";
}

int main() {
	vector<point> p {
		{-20, -20, -20},
		{20, -20, -20},
		{20, 20, -20},
		{-20, 20, -20},
	
		{-20, -20, 20},
		{20, -20, 20},
		{20, 20, 20},
		{-20, 20, 20}
	};
	
	/*for (auto &x : p) {
		rotate(x, 1, 1, 1);
		showp(x);
	}*/
	
	while (true) {
		for (int i = 0; i < 8; i++) {
			rotate(p[i], 0.1, 0.1, 0.1);
			showp(p[i]);
		}
		
		line(p[0].x, p[0].y, p[1].x, p[1].y);
		line(p[1].x, p[1].y, p[2].x, p[2].y);
		line(p[2].x, p[2].y, p[3].x, p[3].y);
		line(p[0].x, p[0].y, p[3].x, p[3].y);
		
		line(p[4].x, p[4].y, p[5].x, p[5].y);
		line(p[5].x, p[5].y, p[6].x, p[6].y);
		line(p[6].x, p[6].y, p[7].x, p[7].y);
		line(p[4].x, p[4].y, p[7].x, p[7].y);
		
		line(p[0].x, p[0].y, p[4].x, p[4].y);
		line(p[1].x, p[1].y, p[5].x, p[5].y);
		line(p[2].x, p[2].y, p[6].x, p[6].y);
		line(p[3].x, p[3].y, p[7].x, p[7].y);
		
		Sleep(100);
		system("cls");
	}


	return 0;
}
