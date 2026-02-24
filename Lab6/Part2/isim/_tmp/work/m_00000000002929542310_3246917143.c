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



static void A694_0(char *t0)
{
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

LAB0:    t1 = (t0 + 2972U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(694, ng0);
    t2 = (t0 + 3152);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(694, ng0);

LAB5:    xsi_set_current_line(695, ng0);
    t3 = (t0 + 652U);
    t4 = *((char **)t3);
    t3 = (t4 + 4U);
    t5 = *((unsigned int *)t3);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(700, ng0);

LAB10:    xsi_set_current_line(701, ng0);
    t2 = (t0 + 740U);
    t3 = *((char **)t2);
    t2 = (t0 + 1668);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(702, ng0);
    t2 = (t0 + 828U);
    t3 = *((char **)t2);
    t2 = (t0 + 1760);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(703, ng0);
    t2 = (t0 + 916U);
    t3 = *((char **)t2);
    t2 = (t0 + 1852);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 4, 0LL);
    xsi_set_current_line(704, ng0);
    t2 = (t0 + 1004U);
    t3 = *((char **)t2);
    t2 = (t0 + 1944);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(705, ng0);
    t2 = (t0 + 1092U);
    t3 = *((char **)t2);
    t2 = (t0 + 2036);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(706, ng0);
    t2 = (t0 + 1180U);
    t3 = *((char **)t2);
    t2 = (t0 + 2128);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(707, ng0);
    t2 = (t0 + 740U);
    t3 = *((char **)t2);
    t2 = (t0 + 2312);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(708, ng0);
    t2 = (t0 + 1268U);
    t3 = *((char **)t2);
    t2 = (t0 + 2404);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 1, 0LL);
    xsi_set_current_line(709, ng0);
    t2 = (t0 + 1356U);
    t3 = *((char **)t2);
    t2 = (t0 + 2496);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 32, 0LL);
    xsi_set_current_line(710, ng0);
    t2 = (t0 + 1444U);
    t3 = *((char **)t2);
    t2 = (t0 + 2220);
    xsi_vlogvar_generic_wait_assign_value(t2, t3, 2, 0, 0, 2, 0LL);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(695, ng0);

LAB9:    xsi_set_current_line(696, ng0);
    t10 = ((char*)((ng1)));
    t11 = (t0 + 1668);
    xsi_vlogvar_generic_wait_assign_value(t11, t10, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(696, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1760);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(696, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1852);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 4, 0LL);
    xsi_set_current_line(697, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1944);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(697, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2036);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(697, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2128);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(698, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2312);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(698, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2404);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 1, 0LL);
    xsi_set_current_line(699, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2496);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 32, 0LL);
    xsi_set_current_line(699, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2220);
    xsi_vlogvar_generic_wait_assign_value(t3, t2, 1, 0, 0, 2, 0LL);
    goto LAB8;

}


extern void work_m_00000000002929542310_3246917143_init()
{
	static char *pe[] = {(void *)A694_0};
	xsi_register_didat("work_m_00000000002929542310_3246917143", "isim/_tmp/work/m_00000000002929542310_3246917143.didat");
	xsi_register_executes(pe);
}
