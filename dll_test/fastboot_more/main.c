#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>
#include <pthread.h>

#include <unistd.h>
#define MAX_SIZE 100

/*查找特定字符串*/
int StringFind(const char *pSrc, const char *pDst)
{
	char * temp = NULL;
	
	temp = strstr(pSrc, pDst);
	if(NULL!=temp)
	{
		return 0;
	}
	else{
		return -1;
	}
}
/*获取高通usb口*/
char * get_Qualcomm(int num)
{
    FILE * fp;
    int n, i=0;
    char filename[] = "msg.txt"; //文件名
    char buf[MAX_SIZE]={0};
    char bus[4]={0};
    char devices[4]={0};
	char temp[30]={0};
    static char DevicesID[30]={0};
    if((fp = fopen(filename,"r")) == NULL) //判断文件是否存在及可读
    { 
        printf("error!"); 
        return; 
    }
    while(1) 
    {  
	     if(feof(fp))
		 {
			 break;
		 }
		memset(buf, 0, sizeof(buf)); 
		memset(DevicesID, 0, sizeof(DevicesID));
		memset(bus, 0, sizeof(bus));
		memset(devices, 0, sizeof(devices));
        
        fgets(buf, sizeof(buf)-1, fp); // 包含了换行符  
        n = StringFind(buf, "Qualcomm");
		if(n == 0)
	    {  
           strncpy(DevicesID, "/dev/bus/usb/", 13);
           strncpy(bus, buf+4, 3);
           strcat(bus,"/");
           strncpy(devices, buf+15, 3);
           strcat(DevicesID, bus);
	       strcat(DevicesID, devices);
	       printf("第%d台的ID：%s\n",num ,DevicesID);
		   reget_usb_msg(DevicesID);
		   }

    }
    fclose(fp);
    return DevicesID;

}

/* 修改serialno */
int edit_serno(int num)
{
     char cmd[100]={0};
     system("adb -s MDM9607 root reach");
     sprintf(cmd, "adb -s MDM9607 shell \"echo -n %d > sys/class/android_usb/android0/iSerial\"", num);
     printf("设备 %d : %s\n", num ,cmd);
     system(cmd);
     return 0;
}

/*创建usb_msg文件*/
int Creat_Msg()
{
    char cmd[20]="lsusb > msg.txt";
    system(cmd);
    return 0;
}
/*系统重新获取usb信息*/
int reget_usb_msg(char *DevicesID)
{
	int fd;
	fd = open(DevicesID, O_WRONLY);
	ioctl(fd, USBDEVFS_RESET, 0);
	close(fd);
	return 0;
}

/*修改设备ID，让系统重新识别*/
int Devices_Reget(int num)
{
    char * test=NULL;
    int n;
    if((n=Creat_Msg()) != 0)
    {
	printf("Create Msg file fail!\n");
        return -1;
    }
    edit_serno(num);
    get_Qualcomm(num);
	printf("设备:%d 修改成功\n", num);
    return 0;
}

/* adb devices 获取MDM9607后修改iSeral*/
int run()
{

	
	FILE * fp;
    int n;
	int num = 1;

	printf("等待设备连接.......\n");

	while(1)
	{	
        char cmd[30]="adb devices > devices.txt";
        system(cmd);
	    Creat_Msg();
	
	    char filename[] = "devices.txt"; //文件名
        char buf[MAX_SIZE]={0};
        if((fp = fopen(filename,"r")) == NULL) //判断文件是否存在及可读
        { 
            printf("error!"); 
            return -1; 
        }
         while(!feof(fp))  
        {  
            memset(buf, 0, sizeof(buf));  
            fgets(buf, sizeof(buf) - 1, fp); // 包含了换行符  
            n = StringFind(buf, "MDM9607");
            if( n == 0)
		    {
               Devices_Reget(num);
		   
		       //printf("Devices_Reget 运行%d次", num);
               num++;		   
	        }
	    }
		
	    if(num == 3)
		break;
	
	    fclose(fp);
	}
	    sleep(2);
	    pthread_load();
	    printf("线程运行结束，移除设备！！！\n");
        system("rm -f devices.txt msg.txt");
        return 0;
	
}

/* fastboot 烧录 */
int fastboot(int num)
{
	char cmd_1[20]={0};
	char cmd_2[256]={0};
	sprintf(cmd_1, "adb -s %d reboot bootloader", num);
	sprintf(cmd_2,"%s%s","fastboot flash boot mdm9607-boot.img;fastboot flash aboot appsboot.mbn;fastboot flash recovery mdm9607-boot.img;fastboot flash recoveryfs mdm9607-recovery.ubi;fastboot flash system mdm9607-sysfs.ubi;fastboot flash modem NON-HLOS.ubi;","fastboot reboot");
	printf("命令：%s\n",cmd_1);
	system(cmd_1);
	sleep(1);
	system(cmd_2);
	
	return 0;
	
	
}

int main(void)
{
/* 	while(1)
	{
        run();
		printf("延迟10秒后重新运行程序，请及时更换设备！！！\n");
		sleep(10);
	} */
	
	run();
    return 0;
}
