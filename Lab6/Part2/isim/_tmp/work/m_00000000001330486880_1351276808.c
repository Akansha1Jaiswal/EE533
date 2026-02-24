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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/control_unit.v";
static unsigned int ng1[] = {0U, 0U};
static int ng2[] = {0, 0};
static int ng3[] = {1, 0};
static unsigned int ng4[] = {4U, 0U};
static unsigned int ng5[] = {2U, 0U};



static void A38_0(char *t0)
{
    char t11[8];
    char t12[8];
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
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;

LAB0:    t1 = (t0 + 2252U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 2432);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(38, ng0);

LAB5:    xsi_set_current_line(41, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 1316);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 4);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1500);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(44, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1592);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1684);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1776);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(48, ng0);
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

LAB7:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 652U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 740U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 828U);
    t3 = *((char **)t2);
    t2 = (t3 + 4U);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB44;

LAB45:
LAB46:
LAB29:
LAB12:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(48, ng0);

LAB9:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 916U);
    t10 = *((char **)t4);
    t4 = (t0 + 1316);
    xsi_vlogvar_assign_value(t4, t10, 0, 0, 4);
    xsi_set_current_line(50, ng0);
    t2 = (t0 + 1004U);
    t3 = *((char **)t2);
    t2 = (t0 + 1408);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1684);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

LAB10:    xsi_set_current_line(54, ng0);

LAB13:    xsi_set_current_line(55, ng0);
    t4 = (t0 + 1092U);
    t10 = *((char **)t4);
    memset(t12, 0, 8);
    t4 = (t12 + 4U);
    t13 = (t10 + 4U);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t10);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB14;

LAB15:    if (*((unsigned int *)t13) != 0)
        goto LAB16;

LAB17:    t19 = (t12 + 4U);
    t20 = *((unsigned int *)t12);
    t21 = *((unsigned int *)t19);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB18;

LAB19:    t24 = *((unsigned int *)t12);
    t25 = (~(t24));
    t26 = *((unsigned int *)t19);
    t27 = (t25 || t26);
    if (t27 > 0)
        goto LAB20;

LAB21:    if (*((unsigned int *)t19) > 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t12) > 0)
        goto LAB24;

LAB25:    memcpy(t11, t28, 8);

LAB26:    t29 = (t0 + 1316);
    xsi_vlogvar_assign_value(t29, t11, 0, 0, 4);
    xsi_set_current_line(56, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1500);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1684);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1776);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB12;

LAB14:    *((unsigned int *)t12) = 1;
    goto LAB17;

LAB16:    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB17;

LAB18:    t23 = ((char*)((ng4)));
    goto LAB19;

LAB20:    t28 = ((char*)((ng5)));
    goto LAB21;

LAB22:    xsi_vlog_unsigned_bit_combine(t11, 4, t23, 4, t28, 4);
    goto LAB26;

LAB24:    memcpy(t11, t23, 8);
    goto LAB26;

LAB27:    xsi_set_current_line(62, ng0);

LAB30:    xsi_set_current_line(63, ng0);
    t4 = (t0 + 1092U);
    t10 = *((char **)t4);
    memset(t12, 0, 8);
    t4 = (t12 + 4U);
    t13 = (t10 + 4U);
    t14 = *((unsigned int *)t13);
    t15 = (~(t14));
    t16 = *((unsigned int *)t10);
    t17 = (t16 & t15);
    t18 = (t17 & 1U);
    if (t18 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t13) != 0)
        goto LAB33;

LAB34:    t19 = (t12 + 4U);
    t20 = *((unsigned int *)t12);
    t21 = *((unsigned int *)t19);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB35;

LAB36:    t24 = *((unsigned int *)t12);
    t25 = (~(t24));
    t26 = *((unsigned int *)t19);
    t27 = (t25 || t26);
    if (t27 > 0)
        goto LAB37;

LAB38:    if (*((unsigned int *)t19) > 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t12) > 0)
        goto LAB41;

LAB42:    memcpy(t11, t28, 8);

LAB43:    t29 = (t0 + 1316);
    xsi_vlogvar_assign_value(t29, t11, 0, 0, 4);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1592);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB29;

LAB31:    *((unsigned int *)t12) = 1;
    goto LAB34;

LAB33:    *((unsigned int *)t12) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB34;

LAB35:    t23 = ((char*)((ng4)));
    goto LAB36;

LAB37:    t28 = ((char*)((ng5)));
    goto LAB38;

LAB39:    xsi_vlog_unsigned_bit_combine(t11, 4, t23, 4, t28, 4);
    goto LAB43;

LAB41:    memcpy(t11, t23, 8);
    goto LAB43;

LAB44:    xsi_set_current_line(68, ng0);

LAB47:    xsi_set_current_line(69, ng0);
    t4 = ((char*)((ng4)));
    t10 = (t0 + 1316);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 4);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB46;

}


extern void work_m_00000000001330486880_1351276808_init()
{
	static char *pe[] = {(void *)A38_0};
	xsi_register_didat("work_m_00000000001330486880_1351276808", "isim/_tmp/work/m_00000000001330486880_1351276808.didat");
	xsi_register_executes(pe);
}
