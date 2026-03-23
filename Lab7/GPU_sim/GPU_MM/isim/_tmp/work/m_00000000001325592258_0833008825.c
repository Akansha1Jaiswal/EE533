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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/GPU_MM/simd_alu2.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U, 0U, 0U};
static unsigned int ng3[] = {0U, 0U};



static void A39_0(char *t0)
{
    char t10[16];
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
    char *t15;

LAB0:    t1 = (t0 + 1708U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1888);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(40, ng0);
    t3 = (t0 + 564U);
    t4 = *((char **)t3);
    t3 = (t4 + 4U);
    t5 = *((unsigned int *)t3);
    t6 = (~(t5));
    t7 = *((unsigned int *)t4);
    t8 = (t7 & t6);
    t9 = (t8 != 0);
    if (t9 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(49, ng0);

LAB10:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(40, ng0);

LAB9:    xsi_set_current_line(41, ng0);
    t11 = (t0 + 652U);
    t12 = *((char **)t11);
    t11 = (t0 + 740U);
    t13 = *((char **)t11);
    t11 = (t0 + 828U);
    t14 = *((char **)t11);
    t11 = (t0 + 916U);
    t15 = *((char **)t11);
    xsi_vlogtype_concat(t10, 64, 64, 4U, t15, 16, t14, 16, t13, 16, t12, 16);
    t11 = (t0 + 1140);
    xsi_vlogvar_assign_value(t11, t10, 0, 0, 64);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB8;

}


extern void work_m_00000000001325592258_0833008825_init()
{
	static char *pe[] = {(void *)A39_0};
	xsi_register_didat("work_m_00000000001325592258_0833008825", "isim/_tmp/work/m_00000000001325592258_0833008825.didat");
	xsi_register_executes(pe);
}
