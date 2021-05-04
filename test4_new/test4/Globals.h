#ifndef GLOBALS_H
#define GLOBALS_H
#include "windows.h"
#include <QString>
typedef struct 
 {
int td[5];	//通道检测结果
int dj[5];	//等级结果
}JIANCE;
 extern JIANCE  *jiance;
 extern QString biaozhun;
 extern QString weimi;
#endif //GLOBALS_H