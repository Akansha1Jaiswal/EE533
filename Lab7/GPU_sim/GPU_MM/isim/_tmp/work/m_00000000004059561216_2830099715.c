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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/GPU_MM/simd_alu1.v";
static const char *ng1 = "SIMD_ALU1 LOADED FROM CORRECT FILE";
static int ng2[] = {0, 0};
static const char *ng3 = "[ALU1 t=%0t] op=%b srcA=%h srcB=%h";
static unsigned int ng4[] = {6U, 0U};
static unsigned int ng5[] = {7U, 0U};
static const char *ng6 = "[ALU1-SUB] a=%h b=%h -> r0=%h r1=%h r2=%h r3=%h";
static unsigned int ng7[] = {8U, 0U};
static unsigned int ng8[] = {9U, 0U};
static unsigned int ng9[] = {17U, 0U};
static unsigned int ng10[] = {18U, 0U};
static unsigned int ng11[] = {19U, 0U};
static unsigned int ng12[] = {4U, 0U};
static unsigned int ng13[] = {10U, 0U};
static int ng14[] = {1, 0};



static void I42_0(char *t0)
{

LAB0:    xsi_set_current_line(42, ng0);
    xsi_vlogfile_write(1, 0, ng1, 1, t0);

LAB1:    return;
}

static void N44_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 3344U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 652U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5200);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5060);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N45_2(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 3472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 652U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 16);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 16);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5236);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5068);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N46_3(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 3600U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 652U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5272);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5076);
    *((int *)t28) = 1;

LAB1:    return;
}

static void N47_4(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 3728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 652U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 16);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5308);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5084);
    *((int *)t28) = 1;

LAB1:    return;
}

static void N49_5(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 3856U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 740U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5344);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5092);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N50_6(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 3984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 740U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 16);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 16);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5380);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5100);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N51_7(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 4112U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 740U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5416);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5108);
    *((int *)t28) = 1;

LAB1:    return;
}

static void N52_8(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 4240U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 740U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 16);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5452);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5116);
    *((int *)t28) = 1;

LAB1:    return;
}

static void N54_9(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 828U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 0);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 0);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5488);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5124);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N55_10(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;

LAB0:    t1 = (t0 + 4496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 828U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 4U);
    t6 = *((unsigned int *)t4);
    t7 = (t6 >> 16);
    *((unsigned int *)t3) = t7;
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 16);
    *((unsigned int *)t2) = t9;
    t10 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t10 & 65535U);
    t11 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t11 & 65535U);
    t12 = (t0 + 5524);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t16 + 4U);
    t18 = 65535U;
    t19 = t18;
    t20 = (t3 + 4U);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t23 & 4294901760U);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 | t18);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 & 4294901760U);
    t26 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t26 | t19);
    xsi_driver_vfirst_trans(t12, 0, 15U);
    t27 = (t0 + 5132);
    *((int *)t27) = 1;

LAB1:    return;
}

static void N56_11(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 4624U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 828U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 0);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5560);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5140);
    *((int *)t28) = 1;

LAB1:    return;
}

static void N57_12(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
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

LAB0:    t1 = (t0 + 4752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 828U);
    t4 = *((char **)t2);
    memset(t3, 0, 8);
    t2 = (t3 + 4U);
    t5 = (t4 + 8U);
    t6 = (t4 + 12U);
    t7 = *((unsigned int *)t5);
    t8 = (t7 >> 16);
    *((unsigned int *)t3) = t8;
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 16);
    *((unsigned int *)t2) = t10;
    t11 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t11 & 65535U);
    t12 = *((unsigned int *)t2);
    *((unsigned int *)t2) = (t12 & 65535U);
    t13 = (t0 + 5596);
    t14 = (t13 + 32U);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 4U);
    t19 = 65535U;
    t20 = t19;
    t21 = (t3 + 4U);
    t22 = *((unsigned int *)t3);
    t19 = (t19 & t22);
    t23 = *((unsigned int *)t21);
    t20 = (t20 & t23);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 & 4294901760U);
    t25 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t25 | t19);
    t26 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t26 & 4294901760U);
    t27 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t27 | t20);
    xsi_driver_vfirst_trans(t13, 0, 15U);
    t28 = (t0 + 5148);
    *((int *)t28) = 1;

LAB1:    return;
}

static void A70_13(char *t0)
{
    char t10[16];
    char t16[8];
    char t25[8];
    char t26[8];
    char t34[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;

LAB0:    t1 = (t0 + 4880U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 5156);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(70, ng0);

LAB5:    xsi_set_current_line(71, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 16);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2464);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2556);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2648);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2740);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(76, ng0);

LAB9:    xsi_set_current_line(77, ng0);
    t4 = xsi_vlog_time(t10, 1000000.000000000, 1000.000000000000);
    t11 = (t0 + 916U);
    t12 = *((char **)t11);
    t11 = (t0 + 652U);
    t13 = *((char **)t11);
    t11 = (t0 + 740U);
    t14 = *((char **)t11);
    xsi_vlogfile_write(1, 0, ng3, 5, t0, (char)118, t10, 64, (char)118, t12, 5, (char)118, t13, 64, (char)118, t14, 64);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 916U);
    t3 = *((char **)t2);

LAB10:    t2 = ((char*)((ng4)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng5)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng7)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng8)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng9)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng10)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng11)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng12)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng13)));
    t15 = xsi_vlog_unsigned_case_compare(t3, 5, t2, 5);
    if (t15 == 1)
        goto LAB27;

LAB28:
LAB30:
LAB29:    xsi_set_current_line(157, ng0);

LAB161:    xsi_set_current_line(158, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 16);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2464);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 16);
    xsi_set_current_line(160, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2556);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 16);
    xsi_set_current_line(161, ng0);
    t2 = ((char*)((ng2)));
    t4 = (t0 + 2648);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 16);

LAB31:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng14)));
    t4 = (t0 + 2740);
    xsi_vlogvar_assign_value(t4, t2, 0, 0, 1);
    goto LAB8;

LAB11:    xsi_set_current_line(81, ng0);

LAB32:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1532U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_add(t16, 16, t11, 16, t12, 16);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 16);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1620U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_add(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_add(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1796U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_add(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    goto LAB31;

LAB13:    xsi_set_current_line(89, ng0);

LAB33:    xsi_set_current_line(90, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1532U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_minus(t16, 16, t11, 16, t12, 16);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 16);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1620U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_minus(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_minus(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1796U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_minus(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 652U);
    t4 = *((char **)t2);
    t2 = (t0 + 740U);
    t11 = *((char **)t2);
    t2 = (t0 + 2372);
    t12 = (t2 + 32U);
    t13 = *((char **)t12);
    t14 = (t0 + 2464);
    t17 = (t14 + 32U);
    t18 = *((char **)t17);
    t19 = (t0 + 2556);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    t22 = (t0 + 2648);
    t23 = (t22 + 32U);
    t24 = *((char **)t23);
    xsi_vlogfile_write(1, 0, ng6, 7, t0, (char)118, t4, 64, (char)118, t11, 64, (char)118, t13, 16, (char)118, t18, 16, (char)118, t21, 16, (char)118, t24, 16);
    goto LAB31;

LAB15:    xsi_set_current_line(101, ng0);

LAB34:    xsi_set_current_line(102, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1532U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t11, 16, t12, 16);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 16);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1620U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1796U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    goto LAB31;

LAB17:    xsi_set_current_line(109, ng0);

LAB35:    xsi_set_current_line(110, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1532U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t11, 16, t12, 16);
    t4 = (t0 + 1884U);
    t13 = *((char **)t4);
    memset(t25, 0, 8);
    xsi_vlog_signed_add(t25, 16, t16, 16, t13, 16);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t25, 0, 0, 16);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1620U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 1972U);
    t12 = *((char **)t2);
    memset(t25, 0, 8);
    xsi_vlog_signed_add(t25, 16, t16, 16, t12, 16);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t25, 0, 0, 16);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2060U);
    t12 = *((char **)t2);
    memset(t25, 0, 8);
    xsi_vlog_signed_add(t25, 16, t16, 16, t12, 16);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t25, 0, 0, 16);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1796U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_multiply(t16, 16, t4, 16, t11, 16);
    t2 = (t0 + 2148U);
    t12 = *((char **)t2);
    memset(t25, 0, 8);
    xsi_vlog_signed_add(t25, 16, t16, 16, t12, 16);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t25, 0, 0, 16);
    goto LAB31;

LAB19:    xsi_set_current_line(117, ng0);

LAB36:    xsi_set_current_line(118, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1092U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_lshift(t16, 16, t11, 16, t12, 4);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 16);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_lshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_lshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_lshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    goto LAB31;

LAB21:    xsi_set_current_line(125, ng0);

LAB37:    xsi_set_current_line(126, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1092U);
    t12 = *((char **)t4);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_rshift(t16, 16, t11, 16, t12, 4);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t16, 0, 0, 16);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_rshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_rshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1092U);
    t11 = *((char **)t2);
    memset(t16, 0, 8);
    xsi_vlog_signed_arith_rshift(t16, 16, t4, 16, t11, 4);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t16, 0, 0, 16);
    goto LAB31;

LAB23:    xsi_set_current_line(133, ng0);

LAB38:    xsi_set_current_line(134, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 1532U);
    t12 = *((char **)t4);
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 16, t11, 16, t12, 16);
    memset(t25, 0, 8);
    t4 = (t25 + 4U);
    t13 = (t26 + 4U);
    t5 = *((unsigned int *)t13);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t13) != 0)
        goto LAB41;

LAB42:    t14 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t14);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB43;

LAB44:    t30 = *((unsigned int *)t25);
    t31 = (~(t30));
    t32 = *((unsigned int *)t14);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB45;

LAB46:    if (*((unsigned int *)t14) > 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t25) > 0)
        goto LAB49;

LAB50:    memcpy(t16, t19, 8);

LAB51:    t17 = (t0 + 2372);
    xsi_vlogvar_assign_value(t17, t16, 0, 0, 16);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 1620U);
    t11 = *((char **)t2);
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 16, t4, 16, t11, 16);
    memset(t25, 0, 8);
    t2 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t12) != 0)
        goto LAB54;

LAB55:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB56;

LAB57:    t30 = *((unsigned int *)t25);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB58;

LAB59:    if (*((unsigned int *)t13) > 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t25) > 0)
        goto LAB62;

LAB63:    memcpy(t16, t18, 8);

LAB64:    t14 = (t0 + 2464);
    xsi_vlogvar_assign_value(t14, t16, 0, 0, 16);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t11 = *((char **)t2);
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 16, t4, 16, t11, 16);
    memset(t25, 0, 8);
    t2 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t12) != 0)
        goto LAB67;

LAB68:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB69;

LAB70:    t30 = *((unsigned int *)t25);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB71;

LAB72:    if (*((unsigned int *)t13) > 0)
        goto LAB73;

LAB74:    if (*((unsigned int *)t25) > 0)
        goto LAB75;

LAB76:    memcpy(t16, t18, 8);

LAB77:    t14 = (t0 + 2556);
    xsi_vlogvar_assign_value(t14, t16, 0, 0, 16);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 1796U);
    t11 = *((char **)t2);
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 16, t4, 16, t11, 16);
    memset(t25, 0, 8);
    t2 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB78;

LAB79:    if (*((unsigned int *)t12) != 0)
        goto LAB80;

LAB81:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB82;

LAB83:    t30 = *((unsigned int *)t25);
    t31 = (~(t30));
    t32 = *((unsigned int *)t13);
    t33 = (t31 || t32);
    if (t33 > 0)
        goto LAB84;

LAB85:    if (*((unsigned int *)t13) > 0)
        goto LAB86;

LAB87:    if (*((unsigned int *)t25) > 0)
        goto LAB88;

LAB89:    memcpy(t16, t18, 8);

LAB90:    t14 = (t0 + 2648);
    xsi_vlogvar_assign_value(t14, t16, 0, 0, 16);
    goto LAB31;

LAB25:    xsi_set_current_line(141, ng0);

LAB91:    xsi_set_current_line(142, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = (t0 + 2372);
    xsi_vlogvar_assign_value(t4, t11, 0, 0, 16);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = (t0 + 2464);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 16);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = (t0 + 2556);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 16);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = (t0 + 2648);
    xsi_vlogvar_assign_value(t2, t4, 0, 0, 16);
    goto LAB31;

LAB27:    xsi_set_current_line(150, ng0);

LAB92:    xsi_set_current_line(151, ng0);
    t4 = (t0 + 1180U);
    t11 = *((char **)t4);
    t4 = ((char*)((ng2)));
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 32, t11, 16, t4, 32);
    memset(t25, 0, 8);
    t12 = (t25 + 4U);
    t13 = (t26 + 4U);
    t5 = *((unsigned int *)t13);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t13) != 0)
        goto LAB95;

LAB96:    t14 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t14);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB97;

LAB98:    t43 = *((unsigned int *)t25);
    t44 = (~(t43));
    t45 = *((unsigned int *)t14);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB99;

LAB100:    if (*((unsigned int *)t14) > 0)
        goto LAB101;

LAB102:    if (*((unsigned int *)t25) > 0)
        goto LAB103;

LAB104:    memcpy(t16, t21, 8);

LAB105:    t22 = (t0 + 2372);
    xsi_vlogvar_assign_value(t22, t16, 0, 0, 16);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 1268U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 32, t4, 16, t2, 32);
    memset(t25, 0, 8);
    t11 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB110;

LAB111:    if (*((unsigned int *)t12) != 0)
        goto LAB112;

LAB113:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB114;

LAB115:    t43 = *((unsigned int *)t25);
    t44 = (~(t43));
    t45 = *((unsigned int *)t13);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB116;

LAB117:    if (*((unsigned int *)t13) > 0)
        goto LAB118;

LAB119:    if (*((unsigned int *)t25) > 0)
        goto LAB120;

LAB121:    memcpy(t16, t20, 8);

LAB122:    t21 = (t0 + 2464);
    xsi_vlogvar_assign_value(t21, t16, 0, 0, 16);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 1356U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 32, t4, 16, t2, 32);
    memset(t25, 0, 8);
    t11 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB127;

LAB128:    if (*((unsigned int *)t12) != 0)
        goto LAB129;

LAB130:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB131;

LAB132:    t43 = *((unsigned int *)t25);
    t44 = (~(t43));
    t45 = *((unsigned int *)t13);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB133;

LAB134:    if (*((unsigned int *)t13) > 0)
        goto LAB135;

LAB136:    if (*((unsigned int *)t25) > 0)
        goto LAB137;

LAB138:    memcpy(t16, t20, 8);

LAB139:    t21 = (t0 + 2556);
    xsi_vlogvar_assign_value(t21, t16, 0, 0, 16);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 1444U);
    t4 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t26, 0, 8);
    xsi_vlog_signed_greater(t26, 32, t4, 16, t2, 32);
    memset(t25, 0, 8);
    t11 = (t25 + 4U);
    t12 = (t26 + 4U);
    t5 = *((unsigned int *)t12);
    t6 = (~(t5));
    t7 = *((unsigned int *)t26);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB144;

LAB145:    if (*((unsigned int *)t12) != 0)
        goto LAB146;

LAB147:    t13 = (t25 + 4U);
    t27 = *((unsigned int *)t25);
    t28 = *((unsigned int *)t13);
    t29 = (t27 || t28);
    if (t29 > 0)
        goto LAB148;

LAB149:    t43 = *((unsigned int *)t25);
    t44 = (~(t43));
    t45 = *((unsigned int *)t13);
    t46 = (t44 || t45);
    if (t46 > 0)
        goto LAB150;

LAB151:    if (*((unsigned int *)t13) > 0)
        goto LAB152;

LAB153:    if (*((unsigned int *)t25) > 0)
        goto LAB154;

LAB155:    memcpy(t16, t20, 8);

LAB156:    t21 = (t0 + 2648);
    xsi_vlogvar_assign_value(t21, t16, 0, 0, 16);
    goto LAB31;

LAB39:    *((unsigned int *)t25) = 1;
    goto LAB42;

LAB41:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB42;

LAB43:    t17 = (t0 + 1180U);
    t18 = *((char **)t17);
    goto LAB44;

LAB45:    t17 = (t0 + 1532U);
    t19 = *((char **)t17);
    goto LAB46;

LAB47:    xsi_vlog_unsigned_bit_combine(t16, 16, t18, 16, t19, 16);
    goto LAB51;

LAB49:    memcpy(t16, t18, 8);
    goto LAB51;

LAB52:    *((unsigned int *)t25) = 1;
    goto LAB55;

LAB54:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t2) = 1;
    goto LAB55;

LAB56:    t14 = (t0 + 1268U);
    t17 = *((char **)t14);
    goto LAB57;

LAB58:    t14 = (t0 + 1620U);
    t18 = *((char **)t14);
    goto LAB59;

LAB60:    xsi_vlog_unsigned_bit_combine(t16, 16, t17, 16, t18, 16);
    goto LAB64;

LAB62:    memcpy(t16, t17, 8);
    goto LAB64;

LAB65:    *((unsigned int *)t25) = 1;
    goto LAB68;

LAB67:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t2) = 1;
    goto LAB68;

LAB69:    t14 = (t0 + 1356U);
    t17 = *((char **)t14);
    goto LAB70;

LAB71:    t14 = (t0 + 1708U);
    t18 = *((char **)t14);
    goto LAB72;

LAB73:    xsi_vlog_unsigned_bit_combine(t16, 16, t17, 16, t18, 16);
    goto LAB77;

LAB75:    memcpy(t16, t17, 8);
    goto LAB77;

LAB78:    *((unsigned int *)t25) = 1;
    goto LAB81;

LAB80:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t2) = 1;
    goto LAB81;

LAB82:    t14 = (t0 + 1444U);
    t17 = *((char **)t14);
    goto LAB83;

LAB84:    t14 = (t0 + 1796U);
    t18 = *((char **)t14);
    goto LAB85;

LAB86:    xsi_vlog_unsigned_bit_combine(t16, 16, t17, 16, t18, 16);
    goto LAB90;

LAB88:    memcpy(t16, t17, 8);
    goto LAB90;

LAB93:    *((unsigned int *)t25) = 1;
    goto LAB96;

LAB95:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB96;

LAB97:    t17 = (t0 + 1180U);
    t18 = *((char **)t17);
    memcpy(t34, t18, 8);
    t32 = *((unsigned int *)t18);
    t33 = (t32 & 32768U);
    t30 = t33;
    t17 = (t18 + 4U);
    t35 = *((unsigned int *)t17);
    t36 = (t35 & 32768U);
    t31 = t36;
    t37 = (t33 != 0);
    if (t37 == 1)
        goto LAB106;

LAB107:    t39 = (t36 != 0);
    if (t39 == 1)
        goto LAB108;

LAB109:    t41 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t41 & 4294967295U);
    t20 = (t34 + 4U);
    t42 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t42 & 4294967295U);
    goto LAB98;

LAB99:    t21 = ((char*)((ng2)));
    goto LAB100;

LAB101:    xsi_vlog_unsigned_bit_combine(t16, 32, t34, 32, t21, 32);
    goto LAB105;

LAB103:    memcpy(t16, t34, 8);
    goto LAB105;

LAB106:    t38 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t38 | 4294901760U);
    goto LAB107;

LAB108:    t19 = (t34 + 4U);
    t40 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t40 | 4294901760U);
    goto LAB109;

LAB110:    *((unsigned int *)t25) = 1;
    goto LAB113;

LAB112:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB113;

LAB114:    t14 = (t0 + 1268U);
    t17 = *((char **)t14);
    memcpy(t34, t17, 8);
    t32 = *((unsigned int *)t17);
    t33 = (t32 & 32768U);
    t30 = t33;
    t14 = (t17 + 4U);
    t35 = *((unsigned int *)t14);
    t36 = (t35 & 32768U);
    t31 = t36;
    t37 = (t33 != 0);
    if (t37 == 1)
        goto LAB123;

LAB124:    t39 = (t36 != 0);
    if (t39 == 1)
        goto LAB125;

LAB126:    t41 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t41 & 4294967295U);
    t19 = (t34 + 4U);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & 4294967295U);
    goto LAB115;

LAB116:    t20 = ((char*)((ng2)));
    goto LAB117;

LAB118:    xsi_vlog_unsigned_bit_combine(t16, 32, t34, 32, t20, 32);
    goto LAB122;

LAB120:    memcpy(t16, t34, 8);
    goto LAB122;

LAB123:    t38 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t38 | 4294901760U);
    goto LAB124;

LAB125:    t18 = (t34 + 4U);
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t40 | 4294901760U);
    goto LAB126;

LAB127:    *((unsigned int *)t25) = 1;
    goto LAB130;

LAB129:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB130;

LAB131:    t14 = (t0 + 1356U);
    t17 = *((char **)t14);
    memcpy(t34, t17, 8);
    t32 = *((unsigned int *)t17);
    t33 = (t32 & 32768U);
    t30 = t33;
    t14 = (t17 + 4U);
    t35 = *((unsigned int *)t14);
    t36 = (t35 & 32768U);
    t31 = t36;
    t37 = (t33 != 0);
    if (t37 == 1)
        goto LAB140;

LAB141:    t39 = (t36 != 0);
    if (t39 == 1)
        goto LAB142;

LAB143:    t41 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t41 & 4294967295U);
    t19 = (t34 + 4U);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & 4294967295U);
    goto LAB132;

LAB133:    t20 = ((char*)((ng2)));
    goto LAB134;

LAB135:    xsi_vlog_unsigned_bit_combine(t16, 32, t34, 32, t20, 32);
    goto LAB139;

LAB137:    memcpy(t16, t34, 8);
    goto LAB139;

LAB140:    t38 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t38 | 4294901760U);
    goto LAB141;

LAB142:    t18 = (t34 + 4U);
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t40 | 4294901760U);
    goto LAB143;

LAB144:    *((unsigned int *)t25) = 1;
    goto LAB147;

LAB146:    *((unsigned int *)t25) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB147;

LAB148:    t14 = (t0 + 1444U);
    t17 = *((char **)t14);
    memcpy(t34, t17, 8);
    t32 = *((unsigned int *)t17);
    t33 = (t32 & 32768U);
    t30 = t33;
    t14 = (t17 + 4U);
    t35 = *((unsigned int *)t14);
    t36 = (t35 & 32768U);
    t31 = t36;
    t37 = (t33 != 0);
    if (t37 == 1)
        goto LAB157;

LAB158:    t39 = (t36 != 0);
    if (t39 == 1)
        goto LAB159;

LAB160:    t41 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t41 & 4294967295U);
    t19 = (t34 + 4U);
    t42 = *((unsigned int *)t19);
    *((unsigned int *)t19) = (t42 & 4294967295U);
    goto LAB149;

LAB150:    t20 = ((char*)((ng2)));
    goto LAB151;

LAB152:    xsi_vlog_unsigned_bit_combine(t16, 32, t34, 32, t20, 32);
    goto LAB156;

LAB154:    memcpy(t16, t34, 8);
    goto LAB156;

LAB157:    t38 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t38 | 4294901760U);
    goto LAB158;

LAB159:    t18 = (t34 + 4U);
    t40 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t40 | 4294901760U);
    goto LAB160;

}


extern void work_m_00000000004059561216_2830099715_init()
{
	static char *pe[] = {(void *)I42_0,(void *)N44_1,(void *)N45_2,(void *)N46_3,(void *)N47_4,(void *)N49_5,(void *)N50_6,(void *)N51_7,(void *)N52_8,(void *)N54_9,(void *)N55_10,(void *)N56_11,(void *)N57_12,(void *)A70_13};
	xsi_register_didat("work_m_00000000004059561216_2830099715", "isim/_tmp/work/m_00000000004059561216_2830099715.didat");
	xsi_register_executes(pe);
}
