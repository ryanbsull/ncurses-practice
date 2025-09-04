#include <ncurses.h>
#include <math.h>
#include <unistd.h>

enum dir {
	LEFT = -1,
	RIGHT = 1,
	FWD = 1,
	BACK = -1,
};

enum side {
	x_side,
	y_side
};

typedef struct {
	float x, y, z;
} vec3;

typedef struct {
	float x, y;
} vec2;

typedef struct {
	vec2 pos;
	vec2 dir;
	vec2 cam;
} player;

player state;

int map[] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,
		1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

void draw_line(vec2* start, vec2* end) {
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

void draw_pojnt(vec2* p) {
	mvaddch(p->y, p->x, 'x');
}

int loop() {
	return 0;
}

int init() {
	initscr();

	state.pos.x = 10;
	state.pos.y = 10;
	state.dir.x = 1;
	state.dir.y = 0;
	// define camera plane where the view will be projected onto
	state.cam.x = 0;
	state.cam.y = 0.66;

	return 0;
}

int main() {
	init();
	while(1) {
		loop();
		usleep(700);
		refresh();
		erase();
	}
	endwin();
	return 0;
}
