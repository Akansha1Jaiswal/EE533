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



static void A642_0(char *t0)
{
    char t5[8];
    char t19[8];
    char t26[8];
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
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    char *t61;

LAB0:    t1 = (t0 + 5488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(642, ng0);
    t2 = (t0 + 5668);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(642, ng0);

LAB5:    xsi_set_current_line(643, ng0);
    t3 = (t0 + 652U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t3 = (t5 + 4U);
    t6 = (t4 + 4U);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t6) != 0)
        goto LAB8;

LAB9:    t12 = (t5 + 4U);
    t13 = *((unsigned int *)t5);
    t14 = (!(t13));
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB10;

LAB11:    memcpy(t26, t5, 8);

LAB12:    t54 = (t26 + 4U);
    t55 = *((unsigned int *)t54);
    t56 = (~(t55));
    t57 = *((unsigned int *)t26);
    t58 = (t57 & t56);
    t59 = (t58 != 0);
    if (t59 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(653, ng0);

LAB24:    xsi_set_current_line(654, ng0);
    t2 = (t0 + 828U);
    t3 = *((char **)t2);
    t2 = (t0 + 2988);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(654, ng0);
    t2 = (t0 + 916U);
    t3 = *((char **)t2);
    t2 = (t0 + 3080);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(655, ng0);
    t2 = (t0 + 1004U);
    t3 = *((char **)t2);
    t2 = (t0 + 3172);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(656, ng0);
    t2 = (t0 + 1092U);
    t3 = *((char **)t2);
    t2 = (t0 + 3264);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(656, ng0);
    t2 = (t0 + 1180U);
    t3 = *((char **)t2);
    t2 = (t0 + 3356);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(657, ng0);
    t2 = (t0 + 1268U);
    t3 = *((char **)t2);
    t2 = (t0 + 3448);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(657, ng0);
    t2 = (t0 + 1356U);
    t3 = *((char **)t2);
    t2 = (t0 + 3540);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(658, ng0);
    t2 = (t0 + 1444U);
    t3 = *((char **)t2);
    t2 = (t0 + 3632);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(658, ng0);
    t2 = (t0 + 1532U);
    t3 = *((char **)t2);
    t2 = (t0 + 3724);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(658, ng0);
    t2 = (t0 + 1620U);
    t3 = *((char **)t2);
    t2 = (t0 + 3816);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(659, ng0);
    t2 = (t0 + 1708U);
    t3 = *((char **)t2);
    t2 = (t0 + 3908);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 5, 0LL);
    xsi_set_current_line(659, ng0);
    t2 = (t0 + 1796U);
    t3 = *((char **)t2);
    t2 = (t0 + 4000);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(660, ng0);
    t2 = (t0 + 1884U);
    t3 = *((char **)t2);
    t2 = (t0 + 4092);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(660, ng0);
    t2 = (t0 + 1972U);
    t3 = *((char **)t2);
    t2 = (t0 + 4184);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(661, ng0);
    t2 = (t0 + 2060U);
    t3 = *((char **)t2);
    t2 = (t0 + 4276);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(661, ng0);
    t2 = (t0 + 2148U);
    t3 = *((char **)t2);
    t2 = (t0 + 4368);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(662, ng0);
    t2 = (t0 + 2236U);
    t3 = *((char **)t2);
    t2 = (t0 + 4460);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(662, ng0);
    t2 = (t0 + 2324U);
    t3 = *((char **)t2);
    t2 = (t0 + 4552);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(663, ng0);
    t2 = (t0 + 2412U);
    t3 = *((char **)t2);
    t2 = (t0 + 4644);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 12, 0LL);
    xsi_set_current_line(663, ng0);
    t2 = (t0 + 2500U);
    t3 = *((char **)t2);
    t2 = (t0 + 4736);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(664, ng0);
    t2 = (t0 + 2588U);
    t3 = *((char **)t2);
    t2 = (t0 + 4828);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(664, ng0);
    t2 = (t0 + 2676U);
    t3 = *((char **)t2);
    t2 = (t0 + 4920);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(665, ng0);
    t2 = (t0 + 2764U);
    t3 = *((char **)t2);
    t2 = (t0 + 5012);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 2, 0LL);

LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t5) = 1;
    goto LAB9;

LAB8:    *((unsigned int *)t5) = 1;
    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    t17 = (t0 + 740U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t19 + 4U);
    t20 = (t18 + 4U);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t20) != 0)
        goto LAB15;

LAB16:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 | t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4U);
    t31 = (t19 + 4U);
    t32 = (t26 + 4U);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t19) = 1;
    goto LAB16;

LAB15:    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB16;

LAB17:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4U);
    t41 = (t19 + 4U);
    t42 = *((unsigned int *)t40);
    t43 = (~(t42));
    t44 = *((unsigned int *)t5);
    t45 = (t44 & t43);
    t46 = *((unsigned int *)t41);
    t47 = (~(t46));
    t48 = *((unsigned int *)t19);
    t49 = (t48 & t47);
    t50 = (~(t45));
    t51 = (~(t49));
    t52 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t52 & t50);
    t53 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t53 & t51);
    goto LAB19;

LAB20:    xsi_set_current_line(643, ng0);

LAB23:    xsi_set_current_line(644, ng0);
    t60 = ((char*)((ng1)));
    t61 = (t0 + 2988);
    xsi_vlogvar_generic_wait_assign_value(t61, t60, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(644, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3080);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(644, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3172);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(645, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3264);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(645, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3356);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(646, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3448);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(646, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3540);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(646, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3632);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(647, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3724);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(647, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3816);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(647, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3908);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 5, 0LL);
    xsi_set_current_line(648, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4000);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(648, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4092);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(648, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4184);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(649, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4276);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(649, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4368);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(649, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4460);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(650, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4552);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(650, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4644);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 12, 0LL);
    xsi_set_current_line(651, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4736);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(651, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4828);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(651, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4920);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(652, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 5012);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 2, 0LL);
    goto LAB22;

}


extern void work_m_00000000000471786415_3604615181_init()
{
	static char *pe[] = {(void *)A642_0};
	xsi_register_didat("work_m_00000000000471786415_3604615181", "isim/_tmp/work/m_00000000000471786415_3604615181.didat");
	xsi_register_executes(pe);
}
