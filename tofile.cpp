///// this is a program to product random float numbers
#include<Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <float.h>
#include <string>

const int a = INT_MIN/2;
const int b = INT_MAX/2;
using namespace std;



int main()
{

    //测量时间,代码来自张睿豪
    double span = 0;
    double counts = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime); 

    FILE * fp = fopen("v1.txt", "wb");
    //v1中生成随机数
    if(fp)
    {
        cout << "file v1 is open."<<endl;
    //读入随机数
         srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    //for (int i = 0; i < 200000000; i++) 
    for (int i = 0; i < 2000000; i++) 
    {
        
        //float r = a + rand()%(b-a) + rand()/double(RAND_MAX);
        float r1 = rand()/double(RAND_MAX);
        //to_string(r1);
        fprintf(fp, "%f,",  r1);

        //cout << "a: " << a <<" b: "<<b <<endl;
        //cout  << r + rand()/double(RAND_MAX) << endl;
    }
    fclose(fp);

        //randomNum1.clear();
        //randomNum1.seekg(0);

    }else{
        cout <<"something in v1 is wrong." <<endl;
    }

    fp = fopen("v2.txt", "wb");
    //v1中生成随机数
    if(fp)
    {
        cout << "file v2 is open."<<endl;
    //读入随机数
     //    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    //for (int i = 0; i < 200000000; i++) 
    for (int i = 0; i < 2000000; i++) 
    {
        
        //float r = a + rand()%(b-a) + rand()/double(RAND_MAX);
        float r1 = rand()/double(RAND_MAX);
        //to_string(r1);
        fprintf(fp, "%f,",  r1);

        //cout << "a: " << a <<" b: "<<b <<endl;
        //cout  << r + rand()/double(RAND_MAX) << endl;
    }
    fclose(fp);

        //randomNum1.clear();
        //randomNum1.seekg(0);

    }else{
        cout <<"something in v2 is wrong." <<endl;
    }

    QueryPerformanceCounter(&nEndTime);                                                //停止计时
    span = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart; //计算程序执行时间单位为s
    cout << "(time: " << span * 1000 << "ms)" << endl;
    return 0;
}