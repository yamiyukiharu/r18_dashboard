#include "mcc_generated_files/mcc.h"
#include "Gue/FT800.h"

#define SMALl_FONT_SIZE 26
#define LARGE_FONT_SIZE 31
#define SPACING (SMALl_FONT_SIZE/2 +2)
#define NEWLINE (SMALl_FONT_SIZE/2 +2)
#define X_START 5
#define Y_START 5
#define X_START_SPEED 360
#define Y_START_SPEED 150
#define GEAR_LINE_WIDTH 96
#define GEAR_POSITION_OFFSET_X 380
#define GEAR_POSITION_OFFSET_Y 0
#define GAUGE_X 240
#define GAUGE_Y 115
#define GAUGE_SIZE 130
#define GAUGE_OPTIONS OPT_NOBACK | OPT_FLAT
#define GAUGE_MAJOR_DIVISION 10
#define GAUGE_MINOR_DIVISION 5
#define GAUGE_RANGE 10

void display_start();
void display_labels();
void display_gear(int gear);
void display_rpm(int rpm);
void display_end();
