#ifndef   __TEST_H__
#define   __TEST_H__

#define MAX_SIZE 100
/*查找特定字符串,查找成功返回0，查找失败返回-1*/
int StringFind(const char *pSrc, const char *pDst);

/*获取高通usb deviceID,返回值为DevicesID 例如/dev/bus/usb/003/001*/
char * get_Qualcomm(int num);

/* 修改serialno (修改adb devices MDM9607的标识)*/
int edit_serno(int num);

/*系统重新获取usb信息*/
int reget_usb_msg(char *DevicesID);

/*修改serialno系统重新识别usb*/
int Devices_Reget(int num);

/* fastboot 烧录 */
int fastboot(int num);

/* 多台同时烧录*/
int run();

/*多线程 烧录*/
int pthread_load();

void * fastboot_1();

void * fastboot_2()


#endif
