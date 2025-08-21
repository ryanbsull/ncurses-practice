#include <ncurses.h>
#include <math.h>
#include <unistd.h>

typedef struct {
	float x, y, z;
} vec3;

typedef struct {
	float x, y;
} vec2;

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

int loop() {
	return 0;
}

int main() {
	initscr();
	while(1) {
		loop();
		usleep(700);
		refresh();
		erase();
	}
	endwin();
	return 0;
}
