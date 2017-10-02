#include "display.h"

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
    
    cmd(COLOR_RGB(255, 255, 255));
    cmd_text(X_START, y_start, SMALl_FONT_SIZE, 0, "WATER");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "TEMP");
    cmd_text(X_START, y_start += SPACING + NEWLINE, SMALl_FONT_SIZE, 0, "OIL");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "TEMP");
    cmd_text(X_START, y_start += SPACING + NEWLINE, SMALl_FONT_SIZE, 0, "FUEL");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "USED");
    cmd_text(X_START, y_start += SPACING + NEWLINE, SMALl_FONT_SIZE, 0, "BATT");
    cmd_text(X_START, y_start += SPACING, SMALl_FONT_SIZE, 0, "VOLTS");
    cmd_text(X_START_SPEED, Y_START_SPEED, SMALl_FONT_SIZE, 0, "SPEED");
    cmd_text(X_START_SPEED, Y_START_SPEED + SPACING, SMALl_FONT_SIZE, 0, "KPH");
    cmd_text(X_START_SPEED + 45, Y_START_SPEED - 10, LARGE_FONT_SIZE, 0, "115");
    
    

    //    cmd_memwrite(REG_PWM_DUTY,4);
}

void display_rpm(int rpm) {   
    cmd(BEGIN(POINTS));
    cmd(COLOR_RGB(80, 80, 80));
    cmd(POINT_SIZE(1750));
    cmd(VERTEX2II(240, 115, 0, 0));
    cmd(COLOR_RGB(0, 0, 0));
    cmd(POINT_SIZE(1650));
    cmd(VERTEX2II(240, 115, 0, 0));

    cmd(COLOR_RGB(255, 255, 255));
    cmd_bgcolor(0x323232);
    cmd_gauge(GAUGE_X,GAUGE_Y,GAUGE_SIZE,OPT_NOPOINTER|GAUGE_OPTIONS,GAUGE_MAJOR_DIVISION,GAUGE_MINOR_DIVISION,rpm/1000,GAUGE_RANGE);
    cmd(COLOR_RGB(255, 0, 0));
    cmd_gauge(GAUGE_X,GAUGE_Y,GAUGE_SIZE,OPT_NOTICKS|GAUGE_OPTIONS,GAUGE_MAJOR_DIVISION,GAUGE_MINOR_DIVISION,rpm/1000,GAUGE_RANGE);

    cmd(COLOR_RGB(255, 255, 255));
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
}

void display_gear(int gear) {
    cmd(LINE_WIDTH(GEAR_LINE_WIDTH));
    cmd(COLOR_RGB(202, 125, 0));
    cmd(BEGIN(LINES));
    switch (gear) {
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