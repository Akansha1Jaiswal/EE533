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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/pipeline_MT.v";
static int ng1[] = {0, 0};
static int ng2[] = {64, 0};
static unsigned int ng3[] = {0U, 0U};
static int ng4[] = {1, 0};



static void I561_0(char *t0)
{
    char t5[8];
    char t14[8];
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
    char *t12;
    char *t13;
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
    int t27;
    char *t28;
    unsigned int t29;
    int t30;
    int t31;
    unsigned int t32;
    unsigned int t33;
    int t34;
    int t35;

LAB0:    xsi_set_current_line(561, ng0);

LAB2:    xsi_set_current_line(562, ng0);
    xsi_set_current_line(562, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1592);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB3:    t1 = (t0 + 1592);
    t2 = (t1 + 32U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_less(t5, 32, t3, 32, t4, 32);
    t6 = (t5 + 4U);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB4;

LAB5:
LAB1:    return;
LAB4:    xsi_set_current_line(563, ng0);
    t12 = ((char*)((ng3)));
    t13 = (t0 + 1500);
    t16 = (t0 + 1500);
    t17 = (t16 + 40U);
    t18 = *((char **)t17);
    t19 = (t0 + 1500);
    t20 = (t19 + 36U);
    t21 = *((char **)t20);
    t22 = (t0 + 1592);
    t23 = (t22 + 32U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_array_indices(t14, t15, t18, t21, 2, 1, t24, 32, 1);
    t25 = (t14 + 4U);
    t26 = *((unsigned int *)t25);
    t27 = (!(t26));
    t28 = (t15 + 4U);
    t29 = *((unsigned int *)t28);
    t30 = (!(t29));
    t31 = (t27 && t30);
    if (t31 == 1)
        goto LAB6;

LAB7:    xsi_set_current_line(562, ng0);
    t1 = (t0 + 1592);
    t2 = (t1 + 32U);
    t3 = *((char **)t2);
    t4 = ((char*)((ng4)));
    memset(t5, 0, 8);
    xsi_vlog_signed_add(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 1592);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    goto LAB3;

LAB6:    t32 = *((unsigned int *)t14);
    t33 = *((unsigned int *)t15);
    t34 = (t32 - t33);
    t35 = (t34 + 1);
    xsi_vlogvar_assign_value(t13, t12, 0, *((unsigned int *)t15), t35);
    goto LAB7;

}

static void A567_1(char *t0)
{
    char t12[8];
    char t13[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned int t22;
    int t23;
    char *t24;
    unsigned int t25;
    int t26;
    int t27;
    unsigned int t28;
    unsigned int t29;
    int t30;
    int t31;

LAB0:    t1 = (t0 + 2196U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(567, ng0);
    t2 = (t0 + 2504);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(567, ng0);

LAB5:    xsi_set_current_line(568, ng0);
    t3 = (t0 + 740U);
    t4 = *((char **)t3);
    t3 = (t4 + 4U);
    t5 = *((unsigned int *)t3);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(569, ng0);
    t10 = (t0 + 916U);
    t11 = *((char **)t10);
    t10 = (t0 + 1500);
    t14 = (t0 + 1500);
    t15 = (t14 + 40U);
    t16 = *((char **)t15);
    t17 = (t0 + 1500);
    t18 = (t17 + 36U);
    t19 = *((char **)t18);
    t20 = (t0 + 828U);
    t21 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t12, t13, t16, t19, 2, 1, t21, 6, 2);
    t20 = (t12 + 4U);
    t22 = *((unsigned int *)t20);
    t23 = (!(t22));
    t24 = (t13 + 4U);
    t25 = *((unsigned int *)t24);
    t26 = (!(t25));
    t27 = (t23 && t26);
    if (t27 == 1)
        goto LAB9;

LAB10:    goto LAB8;

LAB9:    t28 = *((unsigned int *)t12);
    t29 = *((unsigned int *)t13);
    t30 = (t28 - t29);
    t31 = (t30 + 1);
    xsi_vlogvar_generic_wait_assign_value(t10, t11, 2, 0, *((unsigned int *)t13), t31, 0LL);
    goto LAB10;

}

static void A573_2(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 2324U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(573, ng0);
    t2 = (t0 + 2512);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(573, ng0);

LAB5:    xsi_set_current_line(574, ng0);
    t3 = (t0 + 1500);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t7 = (t0 + 1500);
    t8 = (t7 + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 1500);
    t11 = (t10 + 36U);
    t12 = *((char **)t11);
    t13 = (t0 + 1004U);
    t14 = *((char **)t13);
    xsi_vlog_generic_get_array_select_value(t6, 32, t5, t9, t12, 2, 1, t14, 6, 2);
    t13 = (t0 + 1316);
    xsi_vlogvar_generic_wait_assign_value(t13, t6, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(575, ng0);
    t2 = (t0 + 1500);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1500);
    t7 = (t5 + 40U);
    t8 = *((char **)t7);
    t9 = (t0 + 1500);
    t10 = (t9 + 36U);
    t11 = *((char **)t10);
    t12 = (t0 + 1092U);
    t13 = *((char **)t12);
    xsi_vlog_generic_get_array_select_value(t6, 32, t4, t8, t11, 2, 1, t13, 6, 2);
    t12 = (t0 + 1408);
    xsi_vlogvar_generic_wait_assign_value(t12, t6, 2, 0, 0, 32, 0LL);
    goto LAB2;

}


extern void work_m_00000000004237913771_3950345391_init()
{
	static char *pe[] = {(void *)I561_0,(void *)A567_1,(void *)A573_2};
	xsi_register_didat("work_m_00000000004237913771_3950345391", "isim/_tmp/work/m_00000000004237913771_3950345391.didat");
	xsi_register_executes(pe);
}
