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
int SetPositionByLine(FILE *fp, int nLine)  
{  
    int i = 0;  
    char buffer[MAX_SIZE + 1];  
    fpos_t pos;  
  
    rewind(fp);  
    for (; i < nLine; i++)  
        fgets(buffer, MAX_SIZE, fp);  
    fgetpos(fp, &pos);  
    return 0;  
} 
int run()
{

	
	FILE * fp;
    int n;
	int num = 1;

	printf("等待设备连接.......\n");
    system("echo \"Test Start Time:\" > QDLoder_Time.txt && date >> QDLoder_Time.txt");
	while(1)
	{	
        char cmd[50]="adb devices | tr '\n' ' ' > devices.txt";
        system(cmd);
	    //Creat_Msg();
	    char filename[] = "devices.txt"; //文件名
        char buf[MAX_SIZE]={0};
        if((fp = fopen(filename,"r")) == NULL) //判断文件是否存在及可读
        { 
            printf("error!"); 
            return -1; 
        }
		
		
         memset(buf, 0, sizeof(buf));  
         fgets(buf, sizeof(buf) - 1, fp); // 包含了换行符  
         n = StringFind(buf, "MDM9607");
         if( n == 0)
		 {		   
		    printf("find the mdm9607 devices!!!\n");
			  
			system("adb root reach && \
			adb shell rm /system/111.mp3 &&\
			adb push 111.mp3 /system &&\
			adb reboot");
			printf("reset count = %d\n",num);
            num++;	
			sleep(180);
            continue;			
	     }
	     else
		{
		    sleep(2);
			printf("devices into QDLoder!!!\n");
			system("echo \"End Time about into QDLoder:\" >> QDLoder_Time.txt && date >> QDLoder_Time.txt");
			break;
		}
			
		fclose(fp);
	}
	    //if(num == 3)
		//break;
        system("rm -f devices.txt msg.txt");
        return 0;	
}

void main(void)
{
	run();
}