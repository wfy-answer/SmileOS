#include "../type/type.h"
#include "color.h"
#include "sheet.h"
#include "corner.h"
#include "window.h"

void showInfo(Sheet *sheet, int x, int y, int key)
{
    Color mainColor;
    mainColor.red = 30;
    mainColor.green = 30;
    mainColor.blue = 30;

    Color color;
    color.red = 240;
    color.green = 240;
    color.blue = 240;

    drawRect((*sheet).buffer, sheet, x, y, 100, 50, color);
    printInteger(sheet, key, x, y, mainColor);
    refreshSheetMap((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, 0);
    refreshSheetSub((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, (*sheet).z, (*sheet).z);
}

void showString(Sheet *sheet, int x, int y, char *string, int size) {
	Color mainColor;
    mainColor.red = 30;
    mainColor.green = 30;
    mainColor.blue = 30;

	printString(sheet, string, size, x, y, mainColor);	
	refreshSheetMap((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, 0);
    refreshSheetSub((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, (*sheet).z, (*sheet).z);
}

void showHexIntegerTest(int x, int y, int key)
{
	Color mainColor;
    mainColor.red = 0xFF;
    mainColor.green = 0xFF;
    mainColor.blue = 0xFF;

	u8 *buffer = (u8 *)0xe0000000;

    printHexIntegerTest(buffer, key, x, y, mainColor);
}

void showBufferInfo(Sheet *sheet, char *buffer)
{
	Color mainColor;
    mainColor.red = 30;
    mainColor.green = 30;
    mainColor.blue = 30;	
		
	int totalSize = 256, rowNum = 16, columnNum = 16;

	int x=0,y=0;
	for (y=0;y<columnNum;++y) {
		for (x=0;x<rowNum;++x) {
			char data= *(buffer+y*16+x);
			printHexByte(sheet, data, x*28+90, y*28+32, mainColor);
		}	
	}

	refreshSheetMap((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, 0);
    refreshSheetSub((*sheet).x, (*sheet).y, (*sheet).x+(*sheet).width, (*sheet).y+(*sheet).height, (*sheet).z, (*sheet).z);
}

void showMemoryInfoTest(u8 *buffer)
{
	Color mainColor;
    mainColor.red = 240;
    mainColor.green = 240;
    mainColor.blue = 80;	
		
	int totalSize = 256, rowNum = 16, columnNum = 16;

	u8 *vram = (u8 *)0xe0000000;

	int x=0,y=0;
	for (y=0;y<columnNum;++y) {
		for (x=0;x<rowNum;++x) {
			char data= *(buffer+y*16+x);
			printHexByteTest(vram, data, x*28+400, y*28+32, mainColor);
		}	
	}
}


