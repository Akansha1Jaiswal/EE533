/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                         */
/*  \   \        Copyright (c) 2003-2007 Xilinx, Inc.                 */
/*  /   /        All Right Reserved.                                  */
/* /---/   /\                                                         */
/* \   \  /  \                                                        */
/*  \___\/\___\                                                       */
/**********************************************************************/

/* This file is designed for use with ISim build 0x734844ce */

#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/MEM_WB.v";
static const char *ng1 = "WB: thread=%0d WRegEn=%b Rd=%d MemToReg=%b mem_data=%h alu=%h";



static void A48_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    t1 = (t0 + 2316U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2496);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(49, ng0);
    t3 = (t0 + 1708U);
    t4 = *((char **)t3);
    t3 = (t0 + 1532U);
    t5 = *((char **)t3);
    t3 = (t0 + 1444U);
    t6 = *((char **)t3);
    t3 = (t0 + 1620U);
    t7 = *((char **)t3);
    t3 = (t0 + 1356U);
    t8 = *((char **)t3);
    t3 = (t0 + 1268U);
    t9 = *((char **)t3);
    xsi_vlogfile_write(1, 0, ng1, 7, t0, (char)118, t4, 2, (char)118, t5, 1, (char)118, t6, 4, (char)118, t7, 1, (char)118, t8, 32, (char)118, t9, 32);
    goto LAB2;

}


extern void work_m_00000000002464337281_1643280950_init()
{
	static char *pe[] = {(void *)A48_0};
	xsi_register_didat("work_m_00000000002464337281_1643280950", "isim/_tmp/work/m_00000000002464337281_1643280950.didat");
	xsi_register_executes(pe);
}
