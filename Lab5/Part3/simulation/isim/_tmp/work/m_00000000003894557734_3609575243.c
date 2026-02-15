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
static const char *ng0 = "C:/Xilinx/10.1/ISE/Lab_YLR/lab5_2/alu64_syntest.v";
static int ng1[] = {0, 0};
static int ng2[] = {0, 0, 0, 0};
static unsigned int ng3[] = {25U, 0U, 0U, 0U};
static unsigned int ng4[] = {10U, 0U, 0U, 0U};
static unsigned int ng5[] = {0U, 0U};
static unsigned int ng6[] = {30U, 0U, 0U, 0U};
static unsigned int ng7[] = {1U, 0U};
static unsigned int ng8[] = {4278255360U, 0U, 4278255360U, 0U};
static unsigned int ng9[] = {252645135U, 0U, 252645135U, 0U};
static unsigned int ng10[] = {2U, 0U};
static unsigned int ng11[] = {3U, 0U};
static unsigned int ng12[] = {4U, 0U};
static unsigned int ng13[] = {5U, 0U, 0U, 0U};
static unsigned int ng14[] = {3U, 0U, 0U, 0U};
static unsigned int ng15[] = {5U, 0U};
static unsigned int ng16[] = {1U, 0U, 0U, 0U};
static unsigned int ng17[] = {4U, 0U, 0U, 0U};
static unsigned int ng18[] = {6U, 0U};
static unsigned int ng19[] = {0U, 0U, 2147483648U, 0U};
static unsigned int ng20[] = {7U, 0U};
static unsigned int ng21[] = {43690U, 0U, 0U, 0U};
static unsigned int ng22[] = {4294945450U, 0U, 4294967295U, 0U};
static unsigned int ng23[] = {8U, 0U};
static unsigned int ng24[] = {2U, 0U, 0U, 0U};
static unsigned int ng25[] = {9U, 0U};



static void I35_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(35, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1140);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void A36_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;

LAB0:    t1 = (t0 + 2020U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng0);
    t2 = (t0 + 1936);
    xsi_process_wait(t2, 10000000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1140);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    *((unsigned int *)t3) = t10;
    *((unsigned int *)t7) = 0;
    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB5:    t15 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t15 & 1U);
    t16 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t16 & 1U);
    t17 = (t0 + 1140);
    xsi_vlogvar_assign_value(t17, t3, 0, 0, 1);
    goto LAB2;

LAB6:    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t8);
    *((unsigned int *)t3) = (t11 | t12);
    t13 = *((unsigned int *)t7);
    t14 = *((unsigned int *)t8);
    *((unsigned int *)t7) = (t13 | t14);
    goto LAB5;

}

static void I40_2(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 2148U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(40, ng0);

LAB4:    xsi_set_current_line(41, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(43, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 25000000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng13)));
    xsi_vlog_unsigned_unary_minus(t4, 64, t2, 64);
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 64);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(59, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(60, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(68, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng23)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(72, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 1416);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2064);
    xsi_process_wait(t2, 40000000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(74, ng0);
    xsi_vlog_stop(1);
    goto LAB1;

}


extern void work_m_00000000003894557734_3609575243_init()
{
	static char *pe[] = {(void *)I35_0,(void *)A36_1,(void *)I40_2};
	xsi_register_didat("work_m_00000000003894557734_3609575243", "isim/_tmp/work/m_00000000003894557734_3609575243.didat");
	xsi_register_executes(pe);
}
