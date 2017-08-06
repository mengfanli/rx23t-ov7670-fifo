/*
 * OV7670cfg.h
 *
 *  Created on: 2017年8月4日
 *      Author: Cotyledon
 */

#ifndef OV7670CFG_H_
#define OV7670CFG_H_

const uint8_t ov7670_init_reg_tbl[][2]=
{
    //Frame Rate Adjustment for 24Mhz input clock
    //25fps PCLK=24MHz
    {0x11, 0x80},//软件应用手册上设置的是0x80，例程设置的是0x00
    {0x6b, 0x40},//PLL控制,软件应用手册上设置的是0x0a,例程设置的是0x40,将PLL调高的话就会产生花屏
    {0x2a, 0x00},
    {0x2b, 0x00},
    {0x92, 0x66},
    {0x93, 0x00},
    {0x3b, 0x0a},

    //Output format
    {0x12, 0x14},//QVGA(320*240)，RGB565
//    {0x12, 0x10},//QVGA, YUV

    //RGB555/565 option(must set COM7[2] = 1 and COM7[0] = 0)
//    {0x40, 0x90},//RGB565,effective only when RGB444[1] is low
//    {0x8c, 0x00},

    //YUV:YUYV 4:2:2
    {0x40, 0xc0},
    {0x3a, 0x04},//0100
    {0x3d, 0x88},

    //Special effects - 特效
    //normal
    {0x67, 0xc0},
    {0x68, 0x80},

    //Mirror/VFlip Enable - 水平镜像/竖直翻转使能
    {0x1e, 0x07},//修改配置值将产生图像显示上下或左右颠倒

    //Banding Filter Setting for 24Mhz Input Clock - 条纹滤波器
    //30fps for 60Hz light frequency
    {0x13, 0xe7},//banding filer enable
    {0x9d, 0x98},//50Hz banding filer
    {0x9e, 0x7f},//60Hz banding filer
    {0xa5, 0x03},//4 step for 50Hz
    {0xab, 0x03},//4 step for 60Hz
    {0x3b, 0x0a},//select 50Hz banding filer

    //   Simple White Balance - 白平衡
    //   {0x13, 0xe7},//AWB、AGC、AGC Enable and ...
    //   {0x6f, 0x9f},//simple AWB

    //AWBC - 自动白平衡控制(Automatic white balance control)
    {0x43, 0x14},//用户手册里这些寄存器的值都是保留(Reserved),不用设置的呀？
    {0x44, 0xf0},
    {0x45, 0x34},
    {0x46, 0x58},
    {0x47, 0x28},
    {0x48, 0x3a},

    //AWB Control
    {0x59, 0x88},//用户手册连寄存器都是保留，初始值都没提供
    {0x5a, 0x88},
    {0x5b, 0x44},
    {0x5c, 0x67},
    {0x5d, 0x49},
    {0x5e, 0x0e},

    //AWB Control
    {0x6c, 0x0a},
    {0x6d, 0x55},
    {0x6e, 0x11},
    {0x6f, 0x9f},

    //AGC/AEC - Automatic Gain Control自动增益补偿/Automatic exposure Control自动曝光控制
    {0x00, 0x00},
    {0x14, 0x20},
    {0x24, 0x75},
    {0x25, 0x63},
    {0x26, 0xA5},

    //AEC algorithm selection - AEC公式选择
    {0xaa, 0x94},//基于平均值的AEC算法Average-based AEC algorithm/基于直方图的AEC算法Histogram-based AEC algorithm

    //基于直方图的AGC/AEC的控制
    {0x9f, 0x78},
    {0xa0, 0x68},
    {0xa6, 0xdf},
    {0xa7, 0xdf},
    {0xa8, 0xf0},
    {0xa9, 0x90},

    //Fix Gain Control - 固定增益控制
    {0x69, 0x5d},//Fix gain for Gr channel/for Gb channel/for R channel/for B channel

    //Color saturation 颜色饱和度 + 0
    {0x4f, 0x80},
    {0x50, 0x80},
    {0x51, 0x00},
    {0x52, 0x22},
    {0x53, 0x5e},
    {0x54, 0x80},
    {0x58, 0x9e},

    //驱动能力
    {0x09, 0x00},

    //Brightness - 亮度 + 0
    {0x55, 0x00},

    //Contrast - 对比度 + 0
    {0x56, 0x40},

    {0x57, 0x80},//0x40,  change according to Jim's request

    //Gamma Curve - 伽马曲线
    {0x7a, 0x20},
    {0x7b, 0x1c},
    {0x7c, 0x28},
    {0x7d, 0x3c},
    {0x7e, 0x55},
    {0x7f, 0x68},
    {0x80, 0x76},
    {0x81, 0x80},
    {0x82, 0x88},
    {0x83, 0x8f},
    {0x84, 0x96},
    {0x85, 0xa3},
    {0x86, 0xaf},
    {0x87, 0xc4},
    {0x88, 0xd7},
    {0x89, 0xe8},

    //Matrix Coefficient - 色彩矩阵系数
    {0x4f, 0x80},
    {0x50, 0x80},
    {0x51, 0x00},
    {0x52, 0x22},
    {0x53, 0x5e},
    {0x54, 0x80},

    //Lens Correction Option - 镜头补偿选项
    {0x62, 0x00},
    {0x63, 0x00},
    {0x64, 0x04},
    {0x65, 0x20},
    {0x66, 0x05},
    {0x94, 0x04},//effective only when LCC5[2] is high
    {0x95, 0x08},//effective only when LCC5[2] is high


    //注释这些配置的话，就倾斜显示，并显示多块，这到底是控制什么的？跟时序图有关？
    {0x17, 0x16},//行频Horizontal Frame开始高八位(低三位在HREF[2：0])
    {0x18, 0x04},//行频Horizontal Frame结束高八位(低三位在HREF[5：3])
    {0x19, 0x02},//场频Vertical Frame开始高八位(低二位在VREF[1：0])
    {0x1a, 0x7b},//场频Vertical Frame结束高八位(低二位在VREF[3：2])
    {0x32, 0x80},//HREF
    {0x03, 0x06},//VREF
//    {0x32, 0x80},
//    {0x17, 0x16},
//    {0x18, 0x04},//5
//    {0x19, 0x02},
//    {0x1a, 0x7a},//0x7a,
//    {0x03, 0x0a},//0x0a,

    //注释这个配置的话，就显示花屏了
    {0x15, 0x00},//配置PCLK、HREF、VSYNC相关

    //Automatic black Level Compensation - 自动黑电平校正
    {0xb0, 0x84},//调试时注释这项配置时，颜色显示不正常了，红色变绿色，绿色变红色，但用户手册对这寄存器是保留RSVD
    {0xb1, 0x0c},
    {0xb2, 0x0e},
    {0xb3, 0x82},
    {0xb8, 0x0a},

    //SCALING_xx寄存器
    {0x70, 0x00},
    {0x71, 0x00},
    {0x72, 0x11},
    {0x73, 0x08},
    {0x3e, 0x00},

    //ADC
    {0x37, 0x1d},//ADC控制ADC Control
    {0x38, 0x71},//ADC和模拟共模控制ADC and Analog Common Mode Control
    {0x39, 0x2a},//ADC偏移控制ADC Offset Control

    //零杂的寄存器
    {0x92, 0x00},//空行低八位Dummy Line low 8 bits
    {0xa2, 0x02},//像素时钟延时
    {0x0c, 0x0c},
    {0x10, 0x00},
    {0x0d, 0x01},
    {0x0f, 0x4b},
    {0x3c, 0x78},
    {0x74, 0x19},

    //用户手册里这几个寄存器都是保留RSVD
    {0x0e, 0x61},
    {0x16, 0x02},
    {0x21, 0x02},
    {0x22, 0x91},
    {0x29, 0x07},
    {0x33, 0x0b},
    {0x35, 0x0b},
    {0x4d, 0x40},
    {0x4e, 0x20},
    {0x8d, 0x4f},
    {0x8e, 0x00},
    {0x8f, 0x00},
    {0x90, 0x00},
    {0x91, 0x00},
    {0x96, 0x00},
    {0x9a, 0x80},

    //网友提供
    //成像效果或许更好，最下一行可能出现蓝色抖动
    {0x01, 0x40},
    {0x02, 0x40},
    {0x41, 0x08},
    {0x3f, 0x00},
    {0x75, 0x05},
    {0x76, 0xe1},
    {0x4c, 0x00},
    {0x77, 0x01},
    {0x4b, 0x09},
    {0xc9, 0x60},
    {0x41, 0x38},
    {0x34, 0x11},
    {0xa4, 0x89},
    {0x97, 0x30},
    {0x98, 0x20},
    {0x99, 0x30},
    {0x9b, 0x29},
    {0x9c, 0x03},
    {0x78, 0x04},
    {0x79, 0x01},
    {0xc8, 0xf0},
    {0x79, 0x0f},
    {0xc8, 0x00},
    {0x79, 0x10},
    {0xc8, 0x7e},
    {0x79, 0x0a},
    {0xc8, 0x80},
    {0x79, 0x0b},
    {0xc8, 0x01},
    {0x79, 0x0c},
    {0xc8, 0x0f},
    {0x79, 0x0d},
    {0xc8, 0x20},
    {0x79, 0x09},
    {0xc8, 0x80},
    {0x79, 0x02},
    {0xc8, 0xc0},
    {0x79, 0x03},
    {0xc8, 0x40},
    {0x79, 0x05},
    {0xc8, 0x30},
    {0x79, 0x26},
    {0x09, 0x00},
};

#endif /* OV7670CFG_H_ */
