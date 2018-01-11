#include "display.h"

void display(int rpm, int oilP, int fuelP, int tp, int speed, int gear, int engTemp, int oilTemp, int battVolts) {
    display_start();
    display_labels();
    display_waterTemp(engTemp);
    display_oilTemp(oilTemp);
    display_fuel(4.3);
    display_battery(battVolts);
    display_oilPress(oilP);
    display_gear(gear);
    display_rpm(rpm);
    display_speed(speed);
    display_tp(tp);
    display_laptime(0, 0, 0, 0);
    display_message("hello");
    display_end();
}

void display_start() {
    cmd(CMD_DLSTART);
    cmd(CLEAR_COLOR_RGB(20, 20, 20));
    cmd(CLEAR(1, 1, 1));
}

void display_end() {
    cmd(DISPLAY());
    cmd(CMD_SWAP);
    cmd_exec();
}

void display_labels() {
    int y_start = Y_START;
    
    //sensor labels
    cmd(COLOR_RGB(255, 255, 255));
    cmd_text(X_START, y_start, SMALl_FONT_SIZE, 0, "WATER");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "TEMP");
    cmd_text(X_START, y_start += NEWLINE, SMALl_FONT_SIZE, 0, "OIL");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "TEMP");
    cmd_text(X_START, y_start += NEWLINE, SMALl_FONT_SIZE, 0, "FUEL");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "USED");
    cmd_text(X_START, y_start += NEWLINE, SMALl_FONT_SIZE, 0, "BATT");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "VOLTS");
    cmd_text(X_START, y_start += NEWLINE, SMALl_FONT_SIZE, 0, "OIL");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "PRESS");
    cmd_text(X_START_SPEED, Y_START_SPEED, SMALl_FONT_SIZE, 0, "SPEED");
    cmd_text(X_START_SPEED, Y_START_SPEED + SPACING, SMALl_FONT_SIZE, 0, "KPH");
    cmd_text(380, 180, 26, 0, "TP");
    cmd_text(459, 174, 28, 0, "%");
    
    //rpm gauge
    //draw external xircle
    cmd(BEGIN(POINTS));
    cmd(COLOR_RGB(20, 20, 20));
    cmd(POINT_SIZE(1750));
    cmd(VERTEX2II(240, 115, 0, 0));
    cmd(COLOR_RGB(60, 60, 60));
    cmd(POINT_SIZE(1650));
    cmd(VERTEX2II(240, 115, 0, 0)); 
    //    cmd_memwrite(REG_PWM_DUTY,4);
}

void display_message(char* message) {
    cmd(BEGIN(RECTS));
    cmd(COLOR_RGB(60, 60, 60));
    cmd(VERTEX2II(350, 215, 0, 0));
    cmd(VERTEX2II(134, 230, 0, 0));
    cmd(COLOR_RGB(255, 255, 255));
    cmd_text(240, 222, 28, OPT_CENTER, "R18 ");
}

void display_laptime(float current, float best, float last, int lap) {
    cmd(COLOR_RGB(255, 0, 0));
    cmd(BEGIN(EDGE_STRIP_B));
    cmd(VERTEX2II(0, 200, 0, 0));
    cmd(VERTEX2II(187, 200, 0, 0));
    cmd(VERTEX2II(216, 173, 0, 0));
    cmd(VERTEX2II(263, 173, 0, 0));
    cmd(VERTEX2II(292, 200, 0, 0));
    cmd(VERTEX2II(480, 200, 0, 0));

    cmd(COLOR_RGB(0, 0, 0));
    cmd(BEGIN(EDGE_STRIP_B));
    cmd(VERTEX2II(0, 205, 0, 0));
    cmd(VERTEX2II(189, 204, 0, 0));
    cmd(VERTEX2II(217, 177, 0, 0));
    cmd(VERTEX2II(261, 177, 0, 0));
    cmd(VERTEX2II(289, 204, 0, 0));
    cmd(VERTEX2II(483, 205, 0, 0));

    //lap time labels
    cmd(COLOR_RGB(255, 125, 0));
    cmd_text(5, 207, 27, 0, "LAST");
    cmd_number(66, 217, 27, OPT_CENTER, 0);
    cmd_text(448, 207, 27, OPT_RIGHTX, "BEST");
    cmd_number(475, 207, 27, OPT_RIGHTX, 0);
    cmd_text(240, 165, 27, OPT_CENTER, "LAP");
    cmd_number(240, 190, 29, OPT_CENTER, 0);

    // last lap time
    cmd(COLOR_RGB(255, 255, 255));
    cmd_number(36, 222, 30, OPT_RIGHTX, 0);
    cmd_text(39, 238, 28, OPT_CENTER, ":");
    cmd_number(42, 222, 30, OPT_NODL, 0);
    cmd_text(79, 238, 28, OPT_CENTER, ":");
    cmd_number(82, 221, 30, OPT_NODL, 0);

    // best lap time
    cmd_number(397, 222, 30, OPT_RIGHTX, 0);
    cmd_text(400, 239, 28, OPT_CENTER, ":");
    cmd_number(403, 222, 30, OPT_NODL, 0);
    cmd_text(439, 239, 28, OPT_CENTER, ":");
    cmd_number(475, 222, 30, OPT_RIGHTX, 0);

    // current lap time
    cmd_number(217, 237, 30, OPT_RIGHTX, 0);
    cmd_text(221, 254, 28, OPT_CENTER, ":");
    cmd_number(240, 255, 30, OPT_CENTER, 0);
    cmd_text(261, 254, 28, OPT_CENTER, ":");
    cmd_number(298, 237, 30, OPT_RIGHTX, 0);
}

void display_waterTemp(int temp) {
    cmd(COLOR_RGB(255, 255, 255));
    cmd_number(64, 7, 28, 0, temp);
}

void display_oilTemp(int temp) {
    cmd_number(66, 48, 28, 0, temp);
}

void display_fuel(int level) {
    cmd_number(66, 89, 28, 0, 3);
    cmd_text(78, 90, 28, 0, ".");
    cmd_number(83, 89, 28, 0, 3);
}

void display_battery(int volts) {
    cmd_number(66, 130, 28, 0, volts/10);
    cmd_text(90, 131, 28, 0, ".");
    cmd_number(96, 130, 28, 0, volts%10);
}

void display_oilPress(float pressure) {
    cmd_number(66, 171, 28, 0, pressure);
}

void display_tp(int tp) {
    cmd_number(455, 166, 30, OPT_RIGHTX, tp);
}

void display_speed(int speed) {
    cmd_number(X_START_SPEED + 115, Y_START_SPEED - 10, LARGE_FONT_SIZE, OPT_RIGHTX, speed);
}

void display_rpm(int rpm) {   
    int first_digit = rpm/1000;
    int second_digit = (rpm/100)%10;
    cmd(COLOR_RGB(255, 255, 255));
    //gauge without pointer
    cmd_bgcolor(0x323232);
    cmd_gauge(GAUGE_X, GAUGE_Y, GAUGE_SIZE, OPT_NOPOINTER | GAUGE_OPTIONS, GAUGE_MAJOR_DIVISION, GAUGE_MINOR_DIVISION, 0, GAUGE_RANGE);
    // draw red pointer
    cmd(COLOR_RGB(255, 0, 0));
    if(first_digit < 2) {
        cmd_gauge(GAUGE_X,GAUGE_Y,GAUGE_SIZE,OPT_NOTICKS|GAUGE_OPTIONS,GAUGE_MAJOR_DIVISION,GAUGE_MINOR_DIVISION,first_digit,GAUGE_RANGE);
    } else {
        int val = ((first_digit-2)*5)+(second_digit/2);
        cmd_gauge(GAUGE_X,GAUGE_Y,GAUGE_SIZE,OPT_NOTICKS|GAUGE_OPTIONS,GAUGE_MAJOR_DIVISION,GAUGE_MINOR_DIVISION,val,GAUGE_RANGE);
    }
    // display RPM
    cmd(COLOR_RGB(255, 255, 255));
    cmd_number(237, 89, 31, OPT_RIGHTX, first_digit);
    cmd_number(243, 89, 31, 0, second_digit);
    //draw gauge labels
    cmd_text(183, 161, 28, 0, "2");
    cmd_text(160, 130, 28, 0, "3");
    cmd_text(155, 92, 28, 0, "4");
    cmd_text(171, 58, 28, 0, "5");
    cmd_text(201, 33, 28, 0, "6");
    cmd_text(235, 26, 28, 0, "7");
    cmd_text(269, 33, 28, 0, "8");
    cmd_text(298, 58, 28, 0, "9");
    cmd_text(301, 92, 28, 0, "10");
    cmd_text(299, 130, 28, 0, "11");
    cmd_text(274, 161, 28, 0, "12");
    cmd_text(241, 114, 31, OPT_CENTER, ".");
    cmd_text(267, 108, 28, 0, "k");
    cmd_text(227, 132, 26, 0, "RPM");
}

void display_gear(int gear) {
    cmd(LINE_WIDTH(GEAR_LINE_WIDTH));
    cmd(COLOR_RGB(202, 125, 0));
    cmd(BEGIN(LINES));
    switch (gear) {
        case 0:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+116, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            break;
        case 1:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+40, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+40, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+39, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+20, GEAR_POSITION_OFFSET_Y+30, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+25, GEAR_POSITION_OFFSET_Y+116, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+55, GEAR_POSITION_OFFSET_Y+116, 0, 0));
            break;
        case 2:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+16, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+64, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+66, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            break;
        case 3:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+16, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            break;
        case 4:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+64, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+16, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+77, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            break;
        case 5:
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+15, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+16, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+64, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+114, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+77, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+65, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            break;
        case 6:
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+15, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+15, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+16, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X, GEAR_POSITION_OFFSET_Y+115, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+65, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+80, GEAR_POSITION_OFFSET_Y+114, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+77, GEAR_POSITION_OFFSET_Y+65, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+65, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+1, GEAR_POSITION_OFFSET_Y+115, 0, 0));
             cmd(VERTEX2II(GEAR_POSITION_OFFSET_X+79, GEAR_POSITION_OFFSET_Y+115, 0, 0));
            break;
        default:
            
            break;
    }
}