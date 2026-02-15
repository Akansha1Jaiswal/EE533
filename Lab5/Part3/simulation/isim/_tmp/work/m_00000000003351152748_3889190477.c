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
static unsigned int ng0[] = {0U, 0U, 0U, 0U};



static void C77_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;

LAB0:    t1 = (t0 + 3988U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2148U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 8U);
    t6 = (t3 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 31);
    t9 = (t8 & 1);
    *((unsigned int *)t4) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 31);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t13 = (t0 + 4620);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 1U;
    t20 = t19;
    t21 = (t4 + 4U);
    t22 = *((unsigned int *)t4);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294967294U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294967294U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 0);
    t28 = (t0 + 4552);
    *((int *)t28) = 1;

LAB1:    return;
}

static void C86_1(char *t0)
{
    char t3[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4116U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1180U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng0)));
    xsi_vlogtype_concat(t3, 64, 64, 2U, t2, 63, t4, 1);
    t5 = (t0 + 4656);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t3, 0, 64);
    xsi_driver_vfirst_trans(t5, 0, 63);
    t10 = (t0 + 4560);
    *((int *)t10) = 1;

LAB1:    return;
}

static void C91_2(char *t0)
{
    char t3[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4244U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3116U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng0)));
    xsi_vlogtype_concat(t3, 64, 64, 2U, t2, 63, t4, 1);
    t5 = (t0 + 4692);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t3, 0, 64);
    xsi_driver_vfirst_trans(t5, 0, 63);
    t10 = (t0 + 4568);
    *((int *)t10) = 1;

LAB1:    return;
}

static void C96_3(char *t0)
{
    char t3[16];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 4372U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 3292U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng0)));
    xsi_vlogtype_concat(t3, 64, 64, 2U, t2, 63, t4, 1);
    t5 = (t0 + 4728);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t3, 0, 64);
    xsi_driver_vfirst_trans(t5, 0, 63);
    t10 = (t0 + 4576);
    *((int *)t10) = 1;

LAB1:    return;
}


extern void work_m_00000000003351152748_3889190477_init()
{
	static char *pe[] = {(void *)C77_0,(void *)C86_1,(void *)C91_2,(void *)C96_3};
	xsi_register_didat("work_m_00000000003351152748_3889190477", "isim/_tmp/work/m_00000000003351152748_3889190477.didat");
	xsi_register_executes(pe);
}
