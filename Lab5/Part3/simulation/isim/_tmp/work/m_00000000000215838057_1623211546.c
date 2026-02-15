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
static const char *ng0 = "C:/Xilinx/10.1/ISE/Lab_YLR/lab5_2/alu64_test.v";
static int ng1[] = {0, 0, 0, 0};
static int ng2[] = {0, 0};
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



static void I51_0(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 1800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(51, ng0);

LAB4:    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(55, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 100000000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(61, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(66, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(71, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng13)));
    xsi_vlog_unsigned_unary_minus(t4, 64, t2, 64);
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t4, 0, 0, 64);
    xsi_set_current_line(74, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(77, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(79, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(82, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(83, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(85, ng0);
    t2 = ((char*)((ng21)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng22)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng23)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(89, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(90, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1140);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(94, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1232);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng25)));
    t3 = (t0 + 1324);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1716);
    xsi_process_wait(t2, 20000000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(97, ng0);
    xsi_vlog_stop(1);
    goto LAB1;

}


extern void work_m_00000000000215838057_1623211546_init()
{
	static char *pe[] = {(void *)I51_0};
	xsi_register_didat("work_m_00000000000215838057_1623211546", "isim/_tmp/work/m_00000000000215838057_1623211546.didat");
	xsi_register_executes(pe);
}
