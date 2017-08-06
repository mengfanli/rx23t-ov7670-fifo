/*
 * camera.c
 *
 *  Created on: 2017年8月3日
 *      Author: Cotyledon
 */

//#include "platform.h"
#include "../cg_src/r_cg_icu.h"
#include "../cg_src/r_cg_userdefine.h"

#include "OV7670.h"
#include "OV7670cfg.h"
#include "sccb.h"
#include "camera.h"
#include "../delay/delay.h"


/* private variables. */
static bool first_VSYNC = true;
static bool start_get_image = false;
static bool new_frame_FIFO_ready = false;

//static uint8_t img[CAM_WIDTH * CAM_HEIGHT * 2];
//
static const int collect_w_step = OV_WIDTH / CAM_WIDTH;
static const int collect_h_step = OV_HEIGHT / CAM_HEIGHT;
uint8_t gray;
uint8_t start[2]={0x01,0xfe};
uint8_t end[2]={0xfe,0x01};

/* private functions declarations. */
static void reset_read_FIFO(void);
static void get_data(int i, int j);
static void get_none(void);

#define OE OV7670_OREN
#define SET_BIT_LOW	0
#define SET_BIT_HIGH 1
#define WRST	OV7670_WRST
#define RRST	OV7670_RRST
#define WEN		OV7670_WREN
#define RCK_L	OV7670_RCK_L
#define RCK_H	OV7670_RCK_H
#define FIFO_DATA	PORT4.PIDR.BYTE

/* public functions definitions. */
uint8_t cam_init(void)
{
    uint8_t device_id;
    uint16_t i=0;
    uint8_t temp;
    /* restore. */
    SCCB_Init();
    if (SCCB_WR_Reg(0x12, 0x80)) return 1;

    /* read product ID. */

 	temp=SCCB_RD_Reg(0x0b);
	if(temp!=0x73)return 2;
 	temp=SCCB_RD_Reg(0x0a);
	if(temp!=0x76)return 2;
    /* initialize. */

    for (i = 0; i < sizeof(ov7670_init_reg_tbl)/sizeof(ov7670_init_reg_tbl[0]); i++)
    {
        if (SCCB_WR_Reg(ov7670_init_reg_tbl[i][0], ov7670_init_reg_tbl[i][1]))
            return 3;
    }

    /* start get image. */
    start_get_image = true;
    R_ICU_IRQ0_Start();
    return 0;
}

uint8_t read_img_from_FIFO(void)
{
	int j=0,i=OV_HEIGHT - 1;
    if (!new_frame_FIFO_ready)
    {
        return 0;
    }
    else
    {
    	OE = SET_BIT_LOW;
//    	R_SCI1_AsyncTransmit(start,2);
        reset_read_FIFO();
        for (j=0; j < OV_WIDTH; j++)
        {
            for (i=OV_HEIGHT - 1; i >=0; i--)
            {
                if (i % collect_h_step == 0 && j % collect_w_step == 0)
                {
                    get_data(i, j);
                }
                else
                {
                    get_none();
                }
            }
        }
        OE = SET_BIT_HIGH;
//        R_SCI1_AsyncTransmit(end,2);
        /* read over, start next image. */
        new_frame_FIFO_ready = false;
        first_VSYNC = true;
        start_get_image = true;
        return 1;
    }
}

void put_image_to_show()
{
//	yuv_to_gray(img);
	R_SCI1_AsyncTransmit(start,2);
	R_SCI1_AsyncTransmit(img_gray,CAM_WIDTH * CAM_HEIGHT);
	R_SCI1_AsyncTransmit(end,2);

}
void yuv_to_gray(unsigned char *image)
{
	uint16_t i=0;
	for(i=0;i<CAM_WIDTH * CAM_HEIGHT;i++)
	{
//		img_gray[i]=img[i*2];
	}
}
void image_binaryzation(uint8_t threshold)
{
	image_binaryzation_fix(img_gray,CAM_WIDTH * CAM_HEIGHT,threshold);
}
uint8_t image_binaryzation_fix(uint8_t *img_buf, uint32_t size,uint8_t threshold)
{
	uint32_t i;
	for (i = 0; i < size; i++)
	{
		img_buf[i] = img_buf[i] < threshold ? 0xff : 0;

	}
	return 0;
}

void get_img(unsigned char **image, int *width, int *height)
{
//    *image  = img;
//    *width  = CAM_WIDTH;
//    *height = CAM_HEIGHT;
}

void IRQ0_IntHandler(void)
{
    if (first_VSYNC && start_get_image) {
        WRST = SET_BIT_LOW;
        WRST = SET_BIT_HIGH;
        WEN = SET_BIT_HIGH;		//FIFO 写使能
        first_VSYNC = false;
        start_get_image = false;
    } else {
        WEN = SET_BIT_LOW;
        new_frame_FIFO_ready = true;
    }
}

/* private functions definitions. */
static void reset_read_FIFO(void)
{
    RRST = SET_BIT_LOW;
    RCK_L;
    RCK_H;
    RCK_L;
    RRST = SET_BIT_HIGH;
    RCK_H;
}

static void get_data(int i, int j)
{
    RCK_L;
//    img[(i/collect_h_step * CAM_WIDTH + j/collect_w_step) * 2] = FIFO_DATA;
    img_gray[i/collect_h_step * CAM_WIDTH + j/collect_w_step]=FIFO_DATA;
//    img_gray[i/collect_h_step * CAM_WIDTH + j/collect_w_step]=FIFO_DATA < 100 ? 0xff : 0;//元数据直接二值化
//    gray=FIFO_DATA;
    RCK_H;
    RCK_L;
//    img[(i/collect_h_step * CAM_WIDTH + j/collect_w_step) * 2 + 1] = FIFO_DATA;
//    img_gray[(i/collect_h_step * CAM_WIDTH + j/collect_w_step)] = FIFO_DATA;
    RCK_H;
//    R_SCI1_AsyncTransmit(&gray,1);
}

static void get_none(void)
{
    RCK_L;
    RCK_H;
    RCK_L;
    RCK_H;
}
