#include <ncurses.h>
#include <math.h>
#include <unistd.h>

typedef struct {
	float x, y, z;
} vec3;

typedef struct {
	float x, y;
} vec2;

typedef struct {
	vec3 vertex[8];
	vec2 edge[12];
	vec3 center;
} polygon;

void rotate(vec3* p, float x, float y, float z) {
	p->y = (cos(x) * p->y) - (sin(x) * p->z);
	p->z = (cos(x) * p->z) + (sin(x) * p->y);

	p->x = (cos(y) * p->x) + (sin(y) * p->z);
	p->z = (cos(y) * p->z) - (sin(y) * p->x);

	p->x = (cos(z) * p->x) - (sin(z) * p->y);
	p->y = (cos(z) * p->y) + (sin(z) * p->x);
}

void get_center(polygon* c, int len) {
	c->center.x = 0; c->center.y = 0; c->center.z = 0;
	for (int i = 0; i < len; i++) {
		c->center.x += c->vertex[i].x;
		c->center.y += c->vertex[i].y;
		c->center.z += c->vertex[i].z;
	}

	c->center.x /= len;
	c->center.y /= len;
	c->center.z /= len;
}

void draw_line(vec3* start, vec3* end) {
	float dx = end->x - start->x;
	float dy = end->y - start->y;
	float len = sqrt(dx*dx + dy*dy);
	float angle = atan2(dy, dx);
	int x, y;

	for (float i = 0; i < len; i++) {
		x = (int)(start->x + i * cos(angle))  + 1;
		y = (int)(start->y + i * sin(angle)) + 1;
		mvaddch(y, x, 'x');
	}
}

int draw_cube() {
	static polygon c = {
		{
			{80, 10, 0},
			{100, 10, 0},
			{100, 30, 0},
			{80, 30, 0},

			{80, 10, 20},
			{100, 10, 20},
			{100, 30, 20},
			{80, 30, 20},
		},
		{
			{0,4},
			{1,5},
			{2,6},
			{3,7},

			{0,1},
			{1,2},
			{2,3},
			{3,0},

			{4,5},
			{5,6},
			{6,7},
			{7,4},
		},
		{0,0,0},
	};
	get_center(&c, 8);

	for (int i = 0; i < 8; i++) {
		c.vertex[i].x -= c.center.x;
		c.vertex[i].y -= c.center.y;
		c.vertex[i].z -= c.center.z;
		rotate(&c.vertex[i], 0.001, 0.002, 0.003);
		c.vertex[i].x += c.center.x;
		c.vertex[i].y += c.center.y;
		c.vertex[i].z += c.center.z;
	}

	for (int i = 0; i < 12; i++)
		draw_line(&c.vertex[(int)c.edge[i].x], &c.vertex[(int)c.edge[i].y]);
	return 0;
}

int main() {
	initscr();
	while(1) {
		draw_cube();
		usleep(700);
		refresh();
		erase();
	}
	endwin();
	return 0;
}
