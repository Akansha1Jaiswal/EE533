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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/cond_eval.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {10U, 0U};
static unsigned int ng4[] = {11U, 0U};
static unsigned int ng5[] = {12U, 0U};
static unsigned int ng6[] = {13U, 0U};
static unsigned int ng7[] = {14U, 0U};



static void A30_0(char *t0)
{
    char t8[8];
    char t24[8];
    char t35[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    int t59;
    int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;

LAB0:    t1 = (t0 + 1616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng0);
    t2 = (t0 + 1796);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(30, ng0);

LAB5:    xsi_set_current_line(31, ng0);
    t3 = (t0 + 564U);
    t4 = *((char **)t3);

LAB6:    t3 = ((char*)((ng1)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t3, 4);
    if (t5 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng6)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng7)));
    t5 = xsi_vlog_unsigned_case_compare(t4, 4, t2, 4);
    if (t5 == 1)
        goto LAB19;

LAB20:
LAB22:
LAB21:    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB23:    goto LAB2;

LAB7:    xsi_set_current_line(32, ng0);
    t6 = (t0 + 740U);
    t7 = *((char **)t6);
    t6 = (t0 + 1140);
    xsi_vlogvar_assign_value(t6, t7, 0, 0, 1);
    goto LAB23;

LAB9:    xsi_set_current_line(33, ng0);
    t3 = (t0 + 740U);
    t6 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4U);
    t7 = (t6 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    *((unsigned int *)t8) = t10;
    *((unsigned int *)t3) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB25;

LAB24:    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 1U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 1U);
    t17 = (t0 + 1140);
    xsi_vlogvar_assign_value(t17, t8, 0, 0, 1);
    goto LAB23;

LAB11:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 652U);
    t6 = *((char **)t3);
    t3 = (t0 + 916U);
    t7 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4U);
    t17 = (t6 + 4U);
    t18 = (t7 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t17);
    t13 = *((unsigned int *)t18);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t17);
    t19 = *((unsigned int *)t18);
    t20 = (t16 | t19);
    t21 = (~(t20));
    t22 = (t15 & t21);
    if (t22 != 0)
        goto LAB29;

LAB26:    if (t20 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t8) = 1;

LAB29:    t23 = (t0 + 1140);
    xsi_vlogvar_assign_value(t23, t8, 0, 0, 1);
    goto LAB23;

LAB13:    xsi_set_current_line(35, ng0);
    t3 = (t0 + 652U);
    t6 = *((char **)t3);
    t3 = (t0 + 916U);
    t7 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4U);
    t17 = (t6 + 4U);
    t18 = (t7 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t17);
    t13 = *((unsigned int *)t18);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t17);
    t19 = *((unsigned int *)t18);
    t20 = (t16 | t19);
    t21 = (~(t20));
    t22 = (t15 & t21);
    if (t22 != 0)
        goto LAB31;

LAB30:    if (t20 != 0)
        goto LAB32;

LAB33:    t23 = (t0 + 1140);
    xsi_vlogvar_assign_value(t23, t8, 0, 0, 1);
    goto LAB23;

LAB15:    xsi_set_current_line(36, ng0);
    t3 = (t0 + 740U);
    t6 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4U);
    t7 = (t6 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    *((unsigned int *)t8) = t10;
    *((unsigned int *)t3) = 0;
    if (*((unsigned int *)t7) != 0)
        goto LAB35;

LAB34:    t15 = *((unsigned int *)t8);
    *((unsigned int *)t8) = (t15 & 1U);
    t16 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t16 & 1U);
    t17 = (t0 + 652U);
    t18 = *((char **)t17);
    t17 = (t0 + 916U);
    t23 = *((char **)t17);
    memset(t24, 0, 8);
    t17 = (t24 + 4U);
    t25 = (t18 + 4U);
    t26 = (t23 + 4U);
    t19 = *((unsigned int *)t18);
    t20 = *((unsigned int *)t23);
    t21 = (t19 ^ t20);
    t22 = *((unsigned int *)t25);
    t27 = *((unsigned int *)t26);
    t28 = (t22 ^ t27);
    t29 = (t21 | t28);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 | t31);
    t33 = (~(t32));
    t34 = (t29 & t33);
    if (t34 != 0)
        goto LAB39;

LAB36:    if (t32 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t24) = 1;

LAB39:    t36 = *((unsigned int *)t8);
    t37 = *((unsigned int *)t24);
    t38 = (t36 & t37);
    *((unsigned int *)t35) = t38;
    t39 = (t8 + 4U);
    t40 = (t24 + 4U);
    t41 = (t35 + 4U);
    t42 = *((unsigned int *)t39);
    t43 = *((unsigned int *)t40);
    t44 = (t42 | t43);
    *((unsigned int *)t41) = t44;
    t45 = *((unsigned int *)t41);
    t46 = (t45 != 0);
    if (t46 == 1)
        goto LAB40;

LAB41:
LAB42:    t67 = (t0 + 1140);
    xsi_vlogvar_assign_value(t67, t35, 0, 0, 1);
    goto LAB23;

LAB17:    xsi_set_current_line(37, ng0);
    t3 = (t0 + 740U);
    t6 = *((char **)t3);
    t3 = (t0 + 652U);
    t7 = *((char **)t3);
    t3 = (t0 + 916U);
    t17 = *((char **)t3);
    memset(t8, 0, 8);
    t3 = (t8 + 4U);
    t18 = (t7 + 4U);
    t23 = (t17 + 4U);
    t9 = *((unsigned int *)t7);
    t10 = *((unsigned int *)t17);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t18);
    t13 = *((unsigned int *)t23);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t18);
    t19 = *((unsigned int *)t23);
    t20 = (t16 | t19);
    t21 = (~(t20));
    t22 = (t15 & t21);
    if (t22 != 0)
        goto LAB44;

LAB43:    if (t20 != 0)
        goto LAB45;

LAB46:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t8);
    t29 = (t27 | t28);
    *((unsigned int *)t24) = t29;
    t25 = (t6 + 4U);
    t26 = (t8 + 4U);
    t39 = (t24 + 4U);
    t30 = *((unsigned int *)t25);
    t31 = *((unsigned int *)t26);
    t32 = (t30 | t31);
    *((unsigned int *)t39) = t32;
    t33 = *((unsigned int *)t39);
    t34 = (t33 != 0);
    if (t34 == 1)
        goto LAB47;

LAB48:
LAB49:    t49 = (t0 + 1140);
    xsi_vlogvar_assign_value(t49, t24, 0, 0, 1);
    goto LAB23;

LAB19:    xsi_set_current_line(38, ng0);
    t3 = ((char*)((ng2)));
    t6 = (t0 + 1140);
    xsi_vlogvar_assign_value(t6, t3, 0, 0, 1);
    goto LAB23;

LAB25:    t11 = *((unsigned int *)t8);
    t12 = *((unsigned int *)t7);
    *((unsigned int *)t8) = (t11 | t12);
    t13 = *((unsigned int *)t3);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t13 | t14);
    goto LAB24;

LAB28:    *((unsigned int *)t8) = 1;
    *((unsigned int *)t3) = 1;
    goto LAB29;

LAB31:    *((unsigned int *)t8) = 1;
    goto LAB33;

LAB32:    *((unsigned int *)t8) = 1;
    *((unsigned int *)t3) = 1;
    goto LAB33;

LAB35:    t11 = *((unsigned int *)t8);
    t12 = *((unsigned int *)t7);
    *((unsigned int *)t8) = (t11 | t12);
    t13 = *((unsigned int *)t3);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t3) = (t13 | t14);
    goto LAB34;

LAB38:    *((unsigned int *)t24) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB39;

LAB40:    t47 = *((unsigned int *)t35);
    t48 = *((unsigned int *)t41);
    *((unsigned int *)t35) = (t47 | t48);
    t49 = (t8 + 4U);
    t50 = (t24 + 4U);
    t51 = *((unsigned int *)t8);
    t52 = (~(t51));
    t53 = *((unsigned int *)t49);
    t54 = (~(t53));
    t55 = *((unsigned int *)t24);
    t56 = (~(t55));
    t57 = *((unsigned int *)t50);
    t58 = (~(t57));
    t59 = (t52 & t54);
    t60 = (t56 & t58);
    t61 = (~(t59));
    t62 = (~(t60));
    t63 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t63 & t61);
    t64 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t64 & t62);
    t65 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t65 & t61);
    t66 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t66 & t62);
    goto LAB42;

LAB44:    *((unsigned int *)t8) = 1;
    goto LAB46;

LAB45:    *((unsigned int *)t8) = 1;
    *((unsigned int *)t3) = 1;
    goto LAB46;

LAB47:    t36 = *((unsigned int *)t24);
    t37 = *((unsigned int *)t39);
    *((unsigned int *)t24) = (t36 | t37);
    t40 = (t6 + 4U);
    t41 = (t8 + 4U);
    t38 = *((unsigned int *)t40);
    t42 = (~(t38));
    t43 = *((unsigned int *)t6);
    t59 = (t43 & t42);
    t44 = *((unsigned int *)t41);
    t45 = (~(t44));
    t46 = *((unsigned int *)t8);
    t60 = (t46 & t45);
    t47 = (~(t59));
    t48 = (~(t60));
    t51 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t51 & t47);
    t52 = *((unsigned int *)t39);
    *((unsigned int *)t39) = (t52 & t48);
    goto LAB49;

}


extern void work_m_00000000000490572257_1448083333_init()
{
	static char *pe[] = {(void *)A30_0};
	xsi_register_didat("work_m_00000000000490572257_1448083333", "isim/_tmp/work/m_00000000000490572257_1448083333.didat");
	xsi_register_executes(pe);
}
