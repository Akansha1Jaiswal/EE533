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



static void G36_0(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 2404U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 3);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4396);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    xsi_vlog_notGate(t16, t4);
    t17 = (t0 + 4396);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    t22 = (t21 + 4U);
    t23 = 1U;
    t24 = t23;
    t25 = (t16 + 4U);
    t26 = *((unsigned int *)t16);
    t23 = (t23 & t26);
    t27 = *((unsigned int *)t25);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t28 & 4294967294U);
    t29 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t29 | t23);
    t30 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t30 & 4294967294U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 | t24);
    t32 = (t0 + 4396);
    xsi_driver_vfirst_trans(t32, 0, 0);
    t33 = (t0 + 4248);
    *((int *)t33) = 1;

LAB1:    return;
}

static void G37_1(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 2532U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 2);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 2);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4432);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    xsi_vlog_notGate(t16, t4);
    t17 = (t0 + 4432);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    t22 = (t21 + 4U);
    t23 = 1U;
    t24 = t23;
    t25 = (t16 + 4U);
    t26 = *((unsigned int *)t16);
    t23 = (t23 & t26);
    t27 = *((unsigned int *)t25);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t28 & 4294967294U);
    t29 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t29 | t23);
    t30 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t30 & 4294967294U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 | t24);
    t32 = (t0 + 4432);
    xsi_driver_vfirst_trans(t32, 0, 0);
    t33 = (t0 + 4256);
    *((int *)t33) = 1;

LAB1:    return;
}

static void G38_2(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 2660U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 1);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 1);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4468);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    xsi_vlog_notGate(t16, t4);
    t17 = (t0 + 4468);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    t22 = (t21 + 4U);
    t23 = 1U;
    t24 = t23;
    t25 = (t16 + 4U);
    t26 = *((unsigned int *)t16);
    t23 = (t23 & t26);
    t27 = *((unsigned int *)t25);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t28 & 4294967294U);
    t29 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t29 | t23);
    t30 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t30 & 4294967294U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 | t24);
    t32 = (t0 + 4468);
    xsi_driver_vfirst_trans(t32, 0, 0);
    t33 = (t0 + 4264);
    *((int *)t33) = 1;

LAB1:    return;
}

static void G39_3(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;

LAB0:    t1 = (t0 + 2788U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 0);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 4504);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    xsi_vlog_notGate(t16, t4);
    t17 = (t0 + 4504);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t20 = (t19 + 40U);
    t21 = *((char **)t20);
    t22 = (t21 + 4U);
    t23 = 1U;
    t24 = t23;
    t25 = (t16 + 4U);
    t26 = *((unsigned int *)t16);
    t23 = (t23 & t26);
    t27 = *((unsigned int *)t25);
    t24 = (t24 & t27);
    t28 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t28 & 4294967294U);
    t29 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t29 | t23);
    t30 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t30 & 4294967294U);
    t31 = *((unsigned int *)t22);
    *((unsigned int *)t22) = (t31 | t24);
    t32 = (t0 + 4504);
    xsi_driver_vfirst_trans(t32, 0, 0);
    t33 = (t0 + 4272);
    *((int *)t33) = 1;

LAB1:    return;
}

static void G42_4(char *t0)
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
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;

LAB0:    t1 = (t0 + 2916U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 1620U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t5 = *((char **)t2);
    t2 = (t0 + 1796U);
    t6 = *((char **)t2);
    t2 = (t0 + 4540);
    t7 = (t2 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    xsi_vlog_AndGate(t10, 4U, t3, t4, t5, t6);
    t11 = (t0 + 4540);
    t12 = (t11 + 32U);
    t13 = *((char **)t12);
    t14 = (t13 + 40U);
    t15 = *((char **)t14);
    t16 = (t15 + 4U);
    t17 = 1U;
    t18 = t17;
    t19 = (t10 + 4U);
    t20 = *((unsigned int *)t10);
    t17 = (t17 & t20);
    t21 = *((unsigned int *)t19);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t22 & 4294967294U);
    t23 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t23 | t17);
    t24 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t24 & 4294967294U);
    t25 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t25 | t18);
    t26 = (t0 + 4540);
    xsi_driver_vfirst_trans(t26, 0, 0);
    t27 = (t0 + 4280);
    *((int *)t27) = 1;

LAB1:    return;
}

static void G45_5(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 3044U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 1620U);
    t4 = *((char **)t2);
    t2 = (t0 + 1708U);
    t5 = *((char **)t2);
    t2 = (t0 + 564U);
    t6 = *((char **)t2);
    memset(t7, 0, 8);
    t2 = (t7 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t8);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t2) = t14;
    t15 = (t0 + 4576);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    xsi_vlog_AndGate(t19, 4U, t3, t4, t5, t7);
    t20 = (t0 + 4576);
    t21 = (t20 + 32U);
    t22 = *((char **)t21);
    t23 = (t22 + 40U);
    t24 = *((char **)t23);
    t25 = (t24 + 4U);
    t26 = 1U;
    t27 = t26;
    t28 = (t19 + 4U);
    t29 = *((unsigned int *)t19);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t31 & 4294967294U);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t32 | t26);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 4294967294U);
    t34 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t34 | t27);
    t35 = (t0 + 4576);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t36 = (t0 + 4288);
    *((int *)t36) = 1;

LAB1:    return;
}

static void G48_6(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 3172U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 1620U);
    t4 = *((char **)t2);
    t2 = (t0 + 564U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4U);
    t7 = (t5 + 4U);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t14 = (t0 + 1796U);
    t15 = *((char **)t14);
    t14 = (t0 + 4612);
    t16 = (t14 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    xsi_vlog_AndGate(t19, 4U, t3, t4, t6, t15);
    t20 = (t0 + 4612);
    t21 = (t20 + 32U);
    t22 = *((char **)t21);
    t23 = (t22 + 40U);
    t24 = *((char **)t23);
    t25 = (t24 + 4U);
    t26 = 1U;
    t27 = t26;
    t28 = (t19 + 4U);
    t29 = *((unsigned int *)t19);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t31 & 4294967294U);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t32 | t26);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 4294967294U);
    t34 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t34 | t27);
    t35 = (t0 + 4612);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t36 = (t0 + 4296);
    *((int *)t36) = 1;

LAB1:    return;
}

static void G51_7(char *t0)
{
    char t6[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;

LAB0:    t1 = (t0 + 3300U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 1620U);
    t4 = *((char **)t2);
    t2 = (t0 + 564U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4U);
    t7 = (t5 + 4U);
    t8 = *((unsigned int *)t5);
    t9 = (t8 >> 1);
    t10 = (t9 & 1);
    *((unsigned int *)t6) = t10;
    t11 = *((unsigned int *)t7);
    t12 = (t11 >> 1);
    t13 = (t12 & 1);
    *((unsigned int *)t2) = t13;
    t14 = (t0 + 564U);
    t15 = *((char **)t14);
    memset(t16, 0, 8);
    t14 = (t16 + 4U);
    t17 = (t15 + 4U);
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t14) = t23;
    t24 = (t0 + 4648);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t26 + 40U);
    t28 = *((char **)t27);
    xsi_vlog_AndGate(t28, 4U, t3, t4, t6, t16);
    t29 = (t0 + 4648);
    t30 = (t29 + 32U);
    t31 = *((char **)t30);
    t32 = (t31 + 40U);
    t33 = *((char **)t32);
    t34 = (t33 + 4U);
    t35 = 1U;
    t36 = t35;
    t37 = (t28 + 4U);
    t38 = *((unsigned int *)t28);
    t35 = (t35 & t38);
    t39 = *((unsigned int *)t37);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t40 & 4294967294U);
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 | t35);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 4294967294U);
    t43 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t43 | t36);
    t44 = (t0 + 4648);
    xsi_driver_vfirst_trans(t44, 0, 0);
    t45 = (t0 + 4304);
    *((int *)t45) = 1;

LAB1:    return;
}

static void G54_8(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
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
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 3428U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 564U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4U);
    t6 = (t4 + 4U);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t13 = (t0 + 1708U);
    t14 = *((char **)t13);
    t13 = (t0 + 1796U);
    t15 = *((char **)t13);
    t13 = (t0 + 4684);
    t16 = (t13 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    xsi_vlog_AndGate(t19, 4U, t3, t5, t14, t15);
    t20 = (t0 + 4684);
    t21 = (t20 + 32U);
    t22 = *((char **)t21);
    t23 = (t22 + 40U);
    t24 = *((char **)t23);
    t25 = (t24 + 4U);
    t26 = 1U;
    t27 = t26;
    t28 = (t19 + 4U);
    t29 = *((unsigned int *)t19);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t31 & 4294967294U);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t32 | t26);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 4294967294U);
    t34 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t34 | t27);
    t35 = (t0 + 4684);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t36 = (t0 + 4312);
    *((int *)t36) = 1;

LAB1:    return;
}

static void G57_9(char *t0)
{
    char t5[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
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
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;

LAB0:    t1 = (t0 + 3556U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 564U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4U);
    t6 = (t4 + 4U);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t13 = (t0 + 1708U);
    t14 = *((char **)t13);
    t13 = (t0 + 564U);
    t15 = *((char **)t13);
    memset(t16, 0, 8);
    t13 = (t16 + 4U);
    t17 = (t15 + 4U);
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t13) = t23;
    t24 = (t0 + 4720);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t26 + 40U);
    t28 = *((char **)t27);
    xsi_vlog_AndGate(t28, 4U, t3, t5, t14, t16);
    t29 = (t0 + 4720);
    t30 = (t29 + 32U);
    t31 = *((char **)t30);
    t32 = (t31 + 40U);
    t33 = *((char **)t32);
    t34 = (t33 + 4U);
    t35 = 1U;
    t36 = t35;
    t37 = (t28 + 4U);
    t38 = *((unsigned int *)t28);
    t35 = (t35 & t38);
    t39 = *((unsigned int *)t37);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t40 & 4294967294U);
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 | t35);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 4294967294U);
    t43 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t43 | t36);
    t44 = (t0 + 4720);
    xsi_driver_vfirst_trans(t44, 0, 0);
    t45 = (t0 + 4320);
    *((int *)t45) = 1;

LAB1:    return;
}

static void G60_10(char *t0)
{
    char t5[8];
    char t15[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;

LAB0:    t1 = (t0 + 3684U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 564U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4U);
    t6 = (t4 + 4U);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t13 = (t0 + 564U);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    t13 = (t15 + 4U);
    t16 = (t14 + 4U);
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 1);
    t19 = (t18 & 1);
    *((unsigned int *)t15) = t19;
    t20 = *((unsigned int *)t16);
    t21 = (t20 >> 1);
    t22 = (t21 & 1);
    *((unsigned int *)t13) = t22;
    t23 = (t0 + 1796U);
    t24 = *((char **)t23);
    t23 = (t0 + 4756);
    t25 = (t23 + 32U);
    t26 = *((char **)t25);
    t27 = (t26 + 40U);
    t28 = *((char **)t27);
    xsi_vlog_AndGate(t28, 4U, t3, t5, t15, t24);
    t29 = (t0 + 4756);
    t30 = (t29 + 32U);
    t31 = *((char **)t30);
    t32 = (t31 + 40U);
    t33 = *((char **)t32);
    t34 = (t33 + 4U);
    t35 = 1U;
    t36 = t35;
    t37 = (t28 + 4U);
    t38 = *((unsigned int *)t28);
    t35 = (t35 & t38);
    t39 = *((unsigned int *)t37);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t40 & 4294967294U);
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 | t35);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 4294967294U);
    t43 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t43 | t36);
    t44 = (t0 + 4756);
    xsi_driver_vfirst_trans(t44, 0, 0);
    t45 = (t0 + 4328);
    *((int *)t45) = 1;

LAB1:    return;
}

static void G63_11(char *t0)
{
    char t5[8];
    char t15[8];
    char t25[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;

LAB0:    t1 = (t0 + 3812U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 564U);
    t4 = *((char **)t2);
    memset(t5, 0, 8);
    t2 = (t5 + 4U);
    t6 = (t4 + 4U);
    t7 = *((unsigned int *)t4);
    t8 = (t7 >> 2);
    t9 = (t8 & 1);
    *((unsigned int *)t5) = t9;
    t10 = *((unsigned int *)t6);
    t11 = (t10 >> 2);
    t12 = (t11 & 1);
    *((unsigned int *)t2) = t12;
    t13 = (t0 + 564U);
    t14 = *((char **)t13);
    memset(t15, 0, 8);
    t13 = (t15 + 4U);
    t16 = (t14 + 4U);
    t17 = *((unsigned int *)t14);
    t18 = (t17 >> 1);
    t19 = (t18 & 1);
    *((unsigned int *)t15) = t19;
    t20 = *((unsigned int *)t16);
    t21 = (t20 >> 1);
    t22 = (t21 & 1);
    *((unsigned int *)t13) = t22;
    t23 = (t0 + 564U);
    t24 = *((char **)t23);
    memset(t25, 0, 8);
    t23 = (t25 + 4U);
    t26 = (t24 + 4U);
    t27 = *((unsigned int *)t24);
    t28 = (t27 >> 0);
    t29 = (t28 & 1);
    *((unsigned int *)t25) = t29;
    t30 = *((unsigned int *)t26);
    t31 = (t30 >> 0);
    t32 = (t31 & 1);
    *((unsigned int *)t23) = t32;
    t33 = (t0 + 4792);
    t34 = (t33 + 32U);
    t35 = *((char **)t34);
    t36 = (t35 + 40U);
    t37 = *((char **)t36);
    xsi_vlog_AndGate(t37, 4U, t3, t5, t15, t25);
    t38 = (t0 + 4792);
    t39 = (t38 + 32U);
    t40 = *((char **)t39);
    t41 = (t40 + 40U);
    t42 = *((char **)t41);
    t43 = (t42 + 4U);
    t44 = 1U;
    t45 = t44;
    t46 = (t37 + 4U);
    t47 = *((unsigned int *)t37);
    t44 = (t44 & t47);
    t48 = *((unsigned int *)t46);
    t45 = (t45 & t48);
    t49 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t49 & 4294967294U);
    t50 = *((unsigned int *)t42);
    *((unsigned int *)t42) = (t50 | t44);
    t51 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t51 & 4294967294U);
    t52 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t52 | t45);
    t53 = (t0 + 4792);
    xsi_driver_vfirst_trans(t53, 0, 0);
    t54 = (t0 + 4336);
    *((int *)t54) = 1;

LAB1:    return;
}

static void G66_12(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    t1 = (t0 + 3940U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 3);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1620U);
    t13 = *((char **)t12);
    t12 = (t0 + 1708U);
    t14 = *((char **)t12);
    t12 = (t0 + 1796U);
    t15 = *((char **)t12);
    t12 = (t0 + 4828);
    t16 = (t12 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    xsi_vlog_AndGate(t19, 4U, t4, t13, t14, t15);
    t20 = (t0 + 4828);
    t21 = (t20 + 32U);
    t22 = *((char **)t21);
    t23 = (t22 + 40U);
    t24 = *((char **)t23);
    t25 = (t24 + 4U);
    t26 = 1U;
    t27 = t26;
    t28 = (t19 + 4U);
    t29 = *((unsigned int *)t19);
    t26 = (t26 & t29);
    t30 = *((unsigned int *)t28);
    t27 = (t27 & t30);
    t31 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t31 & 4294967294U);
    t32 = *((unsigned int *)t24);
    *((unsigned int *)t24) = (t32 | t26);
    t33 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t33 & 4294967294U);
    t34 = *((unsigned int *)t25);
    *((unsigned int *)t25) = (t34 | t27);
    t35 = (t0 + 4828);
    xsi_driver_vfirst_trans(t35, 0, 0);
    t36 = (t0 + 4344);
    *((int *)t36) = 1;

LAB1:    return;
}

static void G69_13(char *t0)
{
    char t4[8];
    char t16[8];
    char *t1;
    char *t2;
    char *t3;
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
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;

LAB0:    t1 = (t0 + 4068U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 564U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t4 + 4U);
    t5 = (t3 + 4U);
    t6 = *((unsigned int *)t3);
    t7 = (t6 >> 3);
    t8 = (t7 & 1);
    *((unsigned int *)t4) = t8;
    t9 = *((unsigned int *)t5);
    t10 = (t9 >> 3);
    t11 = (t10 & 1);
    *((unsigned int *)t2) = t11;
    t12 = (t0 + 1620U);
    t13 = *((char **)t12);
    t12 = (t0 + 1708U);
    t14 = *((char **)t12);
    t12 = (t0 + 564U);
    t15 = *((char **)t12);
    memset(t16, 0, 8);
    t12 = (t16 + 4U);
    t17 = (t15 + 4U);
    t18 = *((unsigned int *)t15);
    t19 = (t18 >> 0);
    t20 = (t19 & 1);
    *((unsigned int *)t16) = t20;
    t21 = *((unsigned int *)t17);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t12) = t23;
    t24 = (t0 + 4864);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t26 + 40U);
    t28 = *((char **)t27);
    xsi_vlog_AndGate(t28, 4U, t4, t13, t14, t16);
    t29 = (t0 + 4864);
    t30 = (t29 + 32U);
    t31 = *((char **)t30);
    t32 = (t31 + 40U);
    t33 = *((char **)t32);
    t34 = (t33 + 4U);
    t35 = 1U;
    t36 = t35;
    t37 = (t28 + 4U);
    t38 = *((unsigned int *)t28);
    t35 = (t35 & t38);
    t39 = *((unsigned int *)t37);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t40 & 4294967294U);
    t41 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t41 | t35);
    t42 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t42 & 4294967294U);
    t43 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t43 | t36);
    t44 = (t0 + 4864);
    xsi_driver_vfirst_trans(t44, 0, 0);
    t45 = (t0 + 4352);
    *((int *)t45) = 1;

LAB1:    return;
}


extern void work_m_00000000000027167369_0108052367_init()
{
	static char *pe[] = {(void *)G36_0,(void *)G37_1,(void *)G38_2,(void *)G39_3,(void *)G42_4,(void *)G45_5,(void *)G48_6,(void *)G51_7,(void *)G54_8,(void *)G57_9,(void *)G60_10,(void *)G63_11,(void *)G66_12,(void *)G69_13};
	xsi_register_didat("work_m_00000000000027167369_0108052367", "isim/_tmp/work/m_00000000000027167369_0108052367.didat");
	xsi_register_executes(pe);
}
