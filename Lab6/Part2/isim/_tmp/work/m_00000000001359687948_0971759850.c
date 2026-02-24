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
static const char *ng0 = "C:/Documents and Settings/student/My Documents/Lab/MT_pipe/pipeineMT_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {4, 0};
static int ng3[] = {16, 0};
static unsigned int ng4[] = {3735928559U, 0U};
static int ng5[] = {1, 0};
static const char *ng6 = "  PASS | %s | T%0d R%0d = %0d";
static const char *ng7 = "  FAIL | %s | T%0d R%0d = %0d (expected %0d)";
static const char *ng8 = "[%04d] CAPTURE: T%0d R%0d <= %0d";
static const char *ng9 = "[%04d] IF:T%0d PC=%0d instr=%08h | ID:T%0d EX:T%0d WB:T%0d";
static const char *ng10 = "[%04d] WB: T%0d R%0d <= %0d";
static const char *ng11 = "simple_4thread.vcd";
static int ng12[] = {10, 0};
static const char *ng13 = "=== PC CHECK (during reset) ===";
static const char *ng14 = "  T0=%0d T1=%0d T2=%0d T3=%0d";
static int ng15[] = {2, 0};
static int ng16[] = {3, 0};
static const char *ng17 = "  Expected: 0, 64, 128, 192";
static const char *ng18 = "=== Running 3-instruction programs ===";
static int ng19[] = {100, 0};
static const char *ng20 = "";
static const char *ng21 = "=== RESULTS ===";
static unsigned int ng22[] = {0U, 0U};
static unsigned int ng23[] = {2U, 0U};
static unsigned int ng24[] = {8U, 0U};
static int ng25[] = {1598112836, 0, 21552, 0, 0, 0};
static unsigned int ng26[] = {1U, 0U};
static unsigned int ng27[] = {30U, 0U};
static int ng28[] = {1598112836, 0, 21553, 0, 0, 0};
static unsigned int ng29[] = {9U, 0U};
static int ng30[] = {1598112836, 0, 21554, 0, 0, 0};
static unsigned int ng31[] = {3U, 0U};
static int ng32[] = {1598112836, 0, 21555, 0, 0, 0};
static const char *ng33 = "=== ISOLATION CHECK ===";
static const char *ng34 = "  T0 R0 = %0d (expect 5  - MOV R0,#5)";
static const char *ng35 = "  T0 R1 = %0d (expect 3  - MOV R1,#3)";
static const char *ng36 = "  T1 R1 = %0d (expect 20 - MOV R1,#20)";
static unsigned int ng37[] = {17U, 0U};
static const char *ng38 = "  T2 R1 = %0d (expect 2  - MOV R1,#2)";
static unsigned int ng39[] = {33U, 0U};
static const char *ng40 = "  T3 R1 = %0d (expect 15 - MOV R1,#15)";
static unsigned int ng41[] = {49U, 0U};
static const char *ng42 = "=== SUMMARY: %0d passed %0d failed ===";



static int sp_clear_shadow(char *t1, char *t2)
{
    char t7[8];
    char t16[8];
    char t17[8];
    int t0;
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
    char *t14;
    char *t15;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    int t32;
    char *t33;
    unsigned int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    int t39;
    int t40;

LAB0:    t0 = 1;
    t3 = (t1 + 456);
    xsi_vlog_subprogram_setdisablestate(t3, &&LAB2);
    xsi_set_current_line(23, ng0);

LAB3:    xsi_set_current_line(24, ng0);
    xsi_set_current_line(24, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 1640);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB4:    t3 = (t1 + 1640);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng2)));
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB5;

LAB6:
LAB2:    xsi_vlog_dispose_subprogram_invocation(t2);
    t0 = 0;

LAB1:    return t0;
LAB5:    xsi_set_current_line(25, ng0);
    xsi_set_current_line(25, ng0);
    t14 = ((char*)((ng1)));
    t15 = (t1 + 1732);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);

LAB7:    t3 = (t1 + 1732);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(24, ng0);
    t3 = (t1 + 1640);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng5)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 1640);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB4;

LAB8:    xsi_set_current_line(25, ng0);

LAB10:    xsi_set_current_line(26, ng0);
    t14 = ((char*)((ng4)));
    t15 = (t1 + 1456);
    t18 = (t1 + 1456);
    t19 = (t18 + 40U);
    t20 = *((char **)t19);
    t21 = (t1 + 1456);
    t22 = (t21 + 36U);
    t23 = *((char **)t22);
    t24 = (t1 + 1640);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t1 + 1732);
    t28 = (t27 + 32U);
    t29 = *((char **)t28);
    xsi_vlog_generic_convert_array_indices(t16, t17, t20, t23, 2, 2, t26, 32, 1, t29, 32, 1);
    t30 = (t16 + 4U);
    t31 = *((unsigned int *)t30);
    t32 = (!(t31));
    t33 = (t17 + 4U);
    t34 = *((unsigned int *)t33);
    t35 = (!(t34));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB11;

LAB12:    xsi_set_current_line(27, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t1 + 1548);
    t5 = (t1 + 1548);
    t6 = (t5 + 40U);
    t8 = *((char **)t6);
    t14 = (t1 + 1548);
    t15 = (t14 + 36U);
    t18 = *((char **)t15);
    t19 = (t1 + 1640);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    t22 = (t1 + 1732);
    t23 = (t22 + 32U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_array_indices(t7, t16, t8, t18, 2, 2, t21, 32, 1, t24, 32, 1);
    t25 = (t7 + 4U);
    t9 = *((unsigned int *)t25);
    t32 = (!(t9));
    t26 = (t16 + 4U);
    t10 = *((unsigned int *)t26);
    t35 = (!(t10));
    t36 = (t32 && t35);
    if (t36 == 1)
        goto LAB13;

LAB14:    xsi_set_current_line(25, ng0);
    t3 = (t1 + 1732);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng5)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 1732);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB7;

LAB11:    t37 = *((unsigned int *)t16);
    t38 = *((unsigned int *)t17);
    t39 = (t37 - t38);
    t40 = (t39 + 1);
    xsi_vlogvar_assign_value(t15, t14, 0, *((unsigned int *)t17), t40);
    goto LAB12;

LAB13:    t11 = *((unsigned int *)t7);
    t12 = *((unsigned int *)t16);
    t39 = (t11 - t12);
    t40 = (t39 + 1);
    xsi_vlogvar_assign_value(t4, t3, 0, *((unsigned int *)t16), t40);
    goto LAB14;

}

static int sp_check(char *t1, char *t2)
{
    char t4[8];
    char t5[8];
    char t9[8];
    char t36[8];
    char t57[8];
    char t66[8];
    int t0;
    char *t3;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
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
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t65;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;

LAB0:    t0 = 1;
    t3 = (t1 + 696);
    xsi_vlog_subprogram_setdisablestate(t3, &&LAB2);
    xsi_set_current_line(57, ng0);

LAB3:    xsi_set_current_line(58, ng0);
    t6 = (t1 + 1548);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t10 = (t1 + 1548);
    t11 = (t10 + 40U);
    t12 = *((char **)t11);
    t13 = (t1 + 1548);
    t14 = (t13 + 36U);
    t15 = *((char **)t14);
    t16 = (t1 + 2008);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t1 + 2100);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    xsi_vlog_generic_get_array_select_value(t9, 1, t8, t12, t15, 2, 2, t18, 2, 2, t21, 4, 2);
    memset(t5, 0, 8);
    t22 = (t5 + 4U);
    t23 = (t9 + 4U);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t9);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t23) != 0)
        goto LAB6;

LAB7:    t29 = (t5 + 4U);
    t30 = *((unsigned int *)t5);
    t31 = *((unsigned int *)t29);
    t32 = (t30 || t31);
    if (t32 > 0)
        goto LAB8;

LAB9:    t49 = *((unsigned int *)t5);
    t50 = (~(t49));
    t51 = *((unsigned int *)t29);
    t52 = (t50 || t51);
    if (t52 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t29) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t5) > 0)
        goto LAB14;

LAB15:    memcpy(t4, t57, 8);

LAB16:    t73 = (t1 + 2376);
    xsi_vlogvar_assign_value(t73, t4, 0, 0, 32);
    xsi_set_current_line(62, ng0);
    t3 = (t1 + 2376);
    t6 = (t3 + 32U);
    t7 = *((char **)t6);
    t8 = (t1 + 2192);
    t10 = (t8 + 32U);
    t11 = *((char **)t10);
    memset(t4, 0, 8);
    t12 = (t7 + 4U);
    t13 = (t11 + 4U);
    if (*((unsigned int *)t7) != *((unsigned int *)t11))
        goto LAB19;

LAB17:    if (*((unsigned int *)t12) != *((unsigned int *)t13))
        goto LAB19;

LAB18:    *((unsigned int *)t4) = 1;

LAB19:    t14 = (t4 + 4U);
    t24 = *((unsigned int *)t14);
    t25 = (~(t24));
    t26 = *((unsigned int *)t4);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(66, ng0);

LAB24:    xsi_set_current_line(67, ng0);
    t3 = (t1 + 2284);
    t6 = (t3 + 32U);
    t7 = *((char **)t6);
    t8 = (t1 + 2008);
    t10 = (t8 + 32U);
    t11 = *((char **)t10);
    t12 = (t1 + 2100);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    t15 = (t1 + 2376);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t18 = (t1 + 2192);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    xsi_vlogfile_write(1, 0, ng7, 6, t1, (char)118, t7, 80, (char)118, t11, 2, (char)118, t14, 4, (char)118, t17, 32, (char)118, t20, 32);
    xsi_set_current_line(69, ng0);
    t3 = (t1 + 1916);
    t6 = (t3 + 32U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t7, 32, t8, 32);
    t10 = (t1 + 1916);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 32);

LAB22:
LAB2:    xsi_vlog_dispose_subprogram_invocation(t2);
    t0 = 0;

LAB1:    return t0;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t5) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB7;

LAB8:    t33 = (t1 + 1456);
    t34 = (t33 + 32U);
    t35 = *((char **)t34);
    t37 = (t1 + 1456);
    t38 = (t37 + 40U);
    t39 = *((char **)t38);
    t40 = (t1 + 1456);
    t41 = (t40 + 36U);
    t42 = *((char **)t41);
    t43 = (t1 + 2008);
    t44 = (t43 + 32U);
    t45 = *((char **)t44);
    t46 = (t1 + 2100);
    t47 = (t46 + 32U);
    t48 = *((char **)t47);
    xsi_vlog_generic_get_array_select_value(t36, 32, t35, t39, t42, 2, 2, t45, 2, 2, t48, 4, 2);
    goto LAB9;

LAB10:    t53 = (t1 + 5892);
    t54 = *((char **)t53);
    t55 = ((((char*)(t54))) + 32U);
    t56 = *((char **)t55);
    t58 = (t1 + 5912);
    t59 = *((char **)t58);
    t60 = ((((char*)(t59))) + 40U);
    t61 = *((char **)t60);
    t62 = (t1 + 5932);
    t63 = *((char **)t62);
    t64 = ((((char*)(t63))) + 36U);
    t65 = *((char **)t64);
    t67 = (t1 + 2100);
    t68 = (t67 + 32U);
    t69 = *((char **)t68);
    t70 = (t1 + 2008);
    t71 = (t70 + 32U);
    t72 = *((char **)t71);
    xsi_vlogtype_concat(t66, 6, 6, 2U, t72, 2, t69, 4);
    xsi_vlog_generic_get_array_select_value(t57, 32, t56, t61, t65, 2, 1, t66, 6, 2);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t4, 32, t36, 32, t57, 32);
    goto LAB16;

LAB14:    memcpy(t4, t36, 8);
    goto LAB16;

LAB20:    xsi_set_current_line(62, ng0);

LAB23:    xsi_set_current_line(63, ng0);
    t15 = (t1 + 2284);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t18 = (t1 + 2008);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    t21 = (t1 + 2100);
    t22 = (t21 + 32U);
    t23 = *((char **)t22);
    t29 = (t1 + 2376);
    t33 = (t29 + 32U);
    t34 = *((char **)t33);
    xsi_vlogfile_write(1, 0, ng6, 5, t1, (char)118, t17, 80, (char)118, t20, 2, (char)118, t23, 4, (char)118, t34, 32);
    xsi_set_current_line(65, ng0);
    t3 = (t1 + 1824);
    t6 = (t3 + 32U);
    t7 = *((char **)t6);
    t8 = ((char*)((ng5)));
    memset(t4, 0, 8);
    xsi_vlog_signed_add(t4, 32, t7, 32, t8, 32);
    t10 = (t1 + 1824);
    xsi_vlogvar_assign_value(t10, t4, 0, 0, 32);
    goto LAB22;

}

static void I5_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(5, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1180);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void A6_1(char *t0)
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

LAB0:    t1 = (t0 + 2980U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(6, ng0);
    t2 = (t0 + 2896);
    xsi_process_wait(t2, 5000000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(6, ng0);
    t4 = (t0 + 1180);
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
    t17 = (t0 + 1180);
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

static void I9_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(9, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1364);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void A10_3(char *t0)
{
    char t7[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;

LAB0:    t1 = (t0 + 3236U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(10, ng0);
    t2 = (t0 + 4056);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(10, ng0);
    t3 = (t0 + 1364);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng5)));
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t5, 32, t6, 32);
    t8 = (t0 + 1364);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB2;

}

static void A33_4(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
    char t79[8];
    char t80[8];
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
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    int t95;
    char *t96;
    unsigned int t97;
    int t98;
    int t99;
    unsigned int t100;
    unsigned int t101;
    int t102;
    int t103;

LAB0:    t1 = (t0 + 3364U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng0);
    t2 = (t0 + 4064);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(33, ng0);

LAB5:    xsi_set_current_line(34, ng0);
    t4 = (t0 + 1272);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 5960);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(34, ng0);

LAB27:    xsi_set_current_line(35, ng0);
    t75 = (t0 + 5984);
    t76 = *((char **)t75);
    t77 = ((((char*)(t76))) + 20U);
    t78 = *((char **)t77);
    t77 = (t0 + 1456);
    t81 = (t0 + 1456);
    t82 = (t81 + 40U);
    t83 = *((char **)t82);
    t84 = (t0 + 1456);
    t85 = (t84 + 36U);
    t86 = *((char **)t85);
    t87 = (t0 + 6016);
    t88 = *((char **)t87);
    t89 = ((((char*)(t88))) + 20U);
    t90 = *((char **)t89);
    t89 = (t0 + 6040);
    t91 = *((char **)t89);
    t92 = ((((char*)(t91))) + 20U);
    t93 = *((char **)t92);
    xsi_vlog_generic_convert_array_indices(t79, t80, t83, t86, 2, 2, t90, 2, 2, t93, 4, 2);
    t92 = (t79 + 4U);
    t94 = *((unsigned int *)t92);
    t95 = (!(t94));
    t96 = (t80 + 4U);
    t97 = *((unsigned int *)t96);
    t98 = (!(t97));
    t99 = (t95 && t98);
    if (t99 == 1)
        goto LAB28;

LAB29:    xsi_set_current_line(37, ng0);
    t2 = ((char*)((ng5)));
    t4 = (t0 + 1548);
    t5 = (t0 + 1548);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    t8 = (t0 + 1548);
    t15 = (t8 + 36U);
    t16 = *((char **)t15);
    t22 = (t0 + 6072);
    t26 = *((char **)t22);
    t27 = ((((char*)(t26))) + 20U);
    t28 = *((char **)t27);
    t27 = (t0 + 6096);
    t29 = *((char **)t27);
    t31 = ((((char*)(t29))) + 20U);
    t41 = *((char **)t31);
    xsi_vlog_generic_convert_array_indices(t3, t14, t7, t16, 2, 2, t28, 2, 2, t41, 4, 2);
    t31 = (t3 + 4U);
    t9 = *((unsigned int *)t31);
    t61 = (!(t9));
    t42 = (t14 + 4U);
    t10 = *((unsigned int *)t42);
    t62 = (!(t10));
    t95 = (t61 && t62);
    if (t95 == 1)
        goto LAB30;

LAB31:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1364);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6128);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 20U);
    t15 = *((char **)t8);
    t8 = (t0 + 6152);
    t16 = *((char **)t8);
    t22 = ((((char*)(t16))) + 20U);
    t26 = *((char **)t22);
    t22 = (t0 + 6176);
    t27 = *((char **)t22);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    xsi_vlogfile_write(1, 0, ng8, 5, t0, (char)119, t5, 32, (char)118, t15, 2, (char)118, t26, 4, (char)118, t29, 32);
    goto LAB26;

LAB28:    t100 = *((unsigned int *)t79);
    t101 = *((unsigned int *)t80);
    t102 = (t100 - t101);
    t103 = (t102 + 1);
    xsi_vlogvar_generic_wait_assign_value(t77, t78, 2, 0, *((unsigned int *)t80), t103, 0LL);
    goto LAB29;

LAB30:    t11 = *((unsigned int *)t3);
    t12 = *((unsigned int *)t14);
    t98 = (t11 - t12);
    t99 = (t98 + 1);
    xsi_vlogvar_generic_wait_assign_value(t4, t2, 1, 0, *((unsigned int *)t14), t99, 0LL);
    goto LAB31;

}

static void I49_5(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(49, ng0);

LAB2:    xsi_set_current_line(49, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1824);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(49, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1916);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);

LAB1:    return;
}

static void A75_6(char *t0)
{
    char t3[8];
    char t32[8];
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
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
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
    char *t44;
    char *t45;

LAB0:    t1 = (t0 + 3620U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 4072);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(75, ng0);

LAB5:    xsi_set_current_line(76, ng0);
    t4 = (t0 + 1272);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    t14 = (t3 + 4U);
    t15 = *((unsigned int *)t14);
    t16 = (~(t15));
    t17 = *((unsigned int *)t3);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(77, ng0);
    t20 = (t0 + 1364);
    t21 = (t20 + 32U);
    t22 = *((char **)t21);
    t23 = (t0 + 6204);
    t24 = *((char **)t23);
    t25 = ((((char*)(t24))) + 32U);
    t26 = *((char **)t25);
    t27 = (t0 + 6232);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 32U);
    t30 = *((char **)t29);
    t31 = ((char*)((ng5)));
    memset(t32, 0, 8);
    xsi_vlog_unsigned_minus(t32, 32, t30, 32, t31, 32);
    t33 = (t0 + 6256);
    t34 = *((char **)t33);
    t35 = ((((char*)(t34))) + 20U);
    t36 = *((char **)t35);
    t35 = (t0 + 6280);
    t37 = *((char **)t35);
    t38 = ((((char*)(t37))) + 20U);
    t39 = *((char **)t38);
    t38 = (t0 + 6304);
    t40 = *((char **)t38);
    t41 = ((((char*)(t40))) + 20U);
    t42 = *((char **)t41);
    t41 = (t0 + 6336);
    t43 = *((char **)t41);
    t44 = ((((char*)(t43))) + 20U);
    t45 = *((char **)t44);
    xsi_vlogfile_write(1, 0, ng9, 8, t0, (char)119, t22, 32, (char)118, t26, 2, (char)118, t32, 32, (char)118, t36, 32, (char)118, t39, 2, (char)118, t42, 2, (char)118, t45, 2);
    goto LAB12;

}

static void A88_7(char *t0)
{
    char t3[8];
    char t14[8];
    char t30[8];
    char t37[8];
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
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    char *t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    char *t51;
    char *t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    int t61;
    int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;

LAB0:    t1 = (t0 + 3748U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 4080);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(88, ng0);

LAB5:    xsi_set_current_line(89, ng0);
    t4 = (t0 + 1272);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t3 + 4U);
    t8 = (t6 + 4U);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB9;

LAB7:    if (*((unsigned int *)t8) == 0)
        goto LAB6;

LAB8:    *((unsigned int *)t3) = 1;
    *((unsigned int *)t7) = 1;

LAB9:    memset(t14, 0, 8);
    t15 = (t14 + 4U);
    t16 = (t3 + 4U);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t3);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t16) != 0)
        goto LAB12;

LAB13:    t22 = (t14 + 4U);
    t23 = *((unsigned int *)t14);
    t24 = *((unsigned int *)t22);
    t25 = (t23 || t24);
    if (t25 > 0)
        goto LAB14;

LAB15:    memcpy(t37, t14, 8);

LAB16:    t69 = (t37 + 4U);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t37);
    t73 = (t72 & t71);
    t74 = (t73 != 0);
    if (t74 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB2;

LAB6:    *((unsigned int *)t3) = 1;
    goto LAB9;

LAB10:    *((unsigned int *)t14) = 1;
    goto LAB13;

LAB12:    *((unsigned int *)t14) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB13;

LAB14:    t26 = (t0 + 6364);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 20U);
    t29 = *((char **)t28);
    memset(t30, 0, 8);
    t28 = (t30 + 4U);
    t31 = (t29 + 4U);
    t32 = *((unsigned int *)t31);
    t33 = (~(t32));
    t34 = *((unsigned int *)t29);
    t35 = (t34 & t33);
    t36 = (t35 & 1U);
    if (t36 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t31) != 0)
        goto LAB19;

LAB20:    t38 = *((unsigned int *)t14);
    t39 = *((unsigned int *)t30);
    t40 = (t38 & t39);
    *((unsigned int *)t37) = t40;
    t41 = (t14 + 4U);
    t42 = (t30 + 4U);
    t43 = (t37 + 4U);
    t44 = *((unsigned int *)t41);
    t45 = *((unsigned int *)t42);
    t46 = (t44 | t45);
    *((unsigned int *)t43) = t46;
    t47 = *((unsigned int *)t43);
    t48 = (t47 != 0);
    if (t48 == 1)
        goto LAB21;

LAB22:
LAB23:    goto LAB16;

LAB17:    *((unsigned int *)t30) = 1;
    goto LAB20;

LAB19:    *((unsigned int *)t30) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB20;

LAB21:    t49 = *((unsigned int *)t37);
    t50 = *((unsigned int *)t43);
    *((unsigned int *)t37) = (t49 | t50);
    t51 = (t14 + 4U);
    t52 = (t30 + 4U);
    t53 = *((unsigned int *)t14);
    t54 = (~(t53));
    t55 = *((unsigned int *)t51);
    t56 = (~(t55));
    t57 = *((unsigned int *)t30);
    t58 = (~(t57));
    t59 = *((unsigned int *)t52);
    t60 = (~(t59));
    t61 = (t54 & t56);
    t62 = (t58 & t60);
    t63 = (~(t61));
    t64 = (~(t62));
    t65 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t65 & t63);
    t66 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t66 & t64);
    t67 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t67 & t63);
    t68 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t68 & t64);
    goto LAB23;

LAB24:    xsi_set_current_line(90, ng0);
    t75 = (t0 + 1364);
    t76 = (t75 + 32U);
    t77 = *((char **)t76);
    t78 = (t0 + 6396);
    t79 = *((char **)t78);
    t80 = ((((char*)(t79))) + 20U);
    t81 = *((char **)t80);
    t80 = (t0 + 6420);
    t82 = *((char **)t80);
    t83 = ((((char*)(t82))) + 20U);
    t84 = *((char **)t83);
    t83 = (t0 + 6444);
    t85 = *((char **)t83);
    t86 = ((((char*)(t85))) + 20U);
    t87 = *((char **)t86);
    xsi_vlogfile_write(1, 0, ng10, 5, t0, (char)119, t77, 32, (char)118, t81, 2, (char)118, t84, 4, (char)118, t87, 32);
    goto LAB26;

}

static void I97_8(char *t0)
{
    char t22[8];
    char t24[8];
    char t38[8];
    char t52[8];
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
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t23;
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
    char *t35;
    char *t36;
    char *t37;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t53;
    char *t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;

LAB0:    t1 = (t0 + 3876U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(97, ng0);

LAB4:    xsi_set_current_line(98, ng0);
    xsi_vcd_dumpfile(ng11);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3792);
    xsi_vcd_dumpvars_args(*((unsigned int *)t2), t3, (char)109, t0, (char)101);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 3792);
    t3 = (t0 + 456);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB6:    t5 = (t0 + 3840);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    t9 = (t8 + 132U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);
    if (t13 != 0)
        goto LAB8;

LAB7:    t6 = (t0 + 456);
    xsi_vlog_subprogram_popinvocation(t6);

LAB5:    t14 = (t0 + 3840);
    t15 = *((char **)t14);
    t14 = (t0 + 456);
    t16 = (t0 + 3840);
    t17 = *((char **)t16);
    t16 = (t0 + 3792);
    t18 = 0;
    xsi_delete_subprogram_invocation(t14, t17, t0, t16, t18);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 1272);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t2 + 4U);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t21 = *((unsigned int *)t2);
    t13 = (t21 & t20);
    t4 = (t0 + 6448);
    *((int *)t4) = t13;

LAB9:    t5 = (t0 + 6448);
    if (*((int *)t5) > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(108, ng0);
    xsi_vlogfile_write(1, 0, ng13, 1, t0);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 6460);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6472);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6484);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng1)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 32, 1);
    t16 = (t0 + 6496);
    t17 = *((char **)t16);
    t18 = ((((char*)(t17))) + 32U);
    t23 = *((char **)t18);
    t25 = (t0 + 6508);
    t26 = *((char **)t25);
    t27 = ((((char*)(t26))) + 40U);
    t28 = *((char **)t27);
    t29 = (t0 + 6520);
    t30 = *((char **)t29);
    t31 = ((((char*)(t30))) + 36U);
    t32 = *((char **)t31);
    t33 = ((char*)((ng5)));
    xsi_vlog_generic_get_array_select_value(t24, 32, t23, t28, t32, 2, 1, t33, 32, 1);
    t34 = (t0 + 6532);
    t35 = *((char **)t34);
    t36 = ((((char*)(t35))) + 32U);
    t37 = *((char **)t36);
    t39 = (t0 + 6544);
    t40 = *((char **)t39);
    t41 = ((((char*)(t40))) + 40U);
    t42 = *((char **)t41);
    t43 = (t0 + 6556);
    t44 = *((char **)t43);
    t45 = ((((char*)(t44))) + 36U);
    t46 = *((char **)t45);
    t47 = ((char*)((ng15)));
    xsi_vlog_generic_get_array_select_value(t38, 32, t37, t42, t46, 2, 1, t47, 32, 1);
    t48 = (t0 + 6568);
    t49 = *((char **)t48);
    t50 = ((((char*)(t49))) + 32U);
    t51 = *((char **)t50);
    t53 = (t0 + 6580);
    t54 = *((char **)t53);
    t55 = ((((char*)(t54))) + 40U);
    t56 = *((char **)t55);
    t57 = (t0 + 6592);
    t58 = *((char **)t57);
    t59 = ((((char*)(t58))) + 36U);
    t60 = *((char **)t59);
    t61 = ((char*)((ng16)));
    xsi_vlog_generic_get_array_select_value(t52, 32, t51, t56, t60, 2, 1, t61, 32, 1);
    xsi_vlogfile_write(1, 0, ng14, 5, t0, (char)118, t22, 32, (char)118, t24, 32, (char)118, t38, 32, (char)118, t52, 32);
    xsi_set_current_line(111, ng0);
    xsi_vlogfile_write(1, 0, ng17, 1, t0);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 3792);
    xsi_process_wait(t2, 1000000LL);
    *((char **)t1) = &&LAB13;

LAB1:    return;
LAB8:    t5 = (t0 + 3876U);
    *((char **)t5) = &&LAB6;
    goto LAB1;

LAB10:    xsi_set_current_line(105, ng0);
    t6 = (t0 + 4088);
    *((int *)t6) = 1;
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    t2 = (t0 + 6448);
    t13 = *((int *)t2);
    *((int *)t2) = (t13 - 1);
    goto LAB9;

LAB13:    xsi_set_current_line(113, ng0);
    t3 = ((char*)((ng1)));
    t4 = (t0 + 1272);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(114, ng0);
    xsi_vlogfile_write(1, 0, ng18, 1, t0);
    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng19)));
    t3 = (t2 + 4U);
    t19 = *((unsigned int *)t3);
    t20 = (~(t19));
    t21 = *((unsigned int *)t2);
    t13 = (t21 & t20);
    t4 = (t0 + 6596);
    *((int *)t4) = t13;

LAB14:    t5 = (t0 + 6596);
    if (*((int *)t5) > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(120, ng0);
    xsi_vlogfile_write(1, 0, ng20, 1, t0);
    xsi_set_current_line(121, ng0);
    xsi_vlogfile_write(1, 0, ng21, 1, t0);
    xsi_set_current_line(122, ng0);
    t2 = ((char*)((ng22)));
    t3 = ((char*)((ng23)));
    t4 = ((char*)((ng24)));
    t5 = ((char*)((ng25)));
    t6 = (t0 + 3792);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2008);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2100);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2192);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2284);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB19:    t14 = (t0 + 3840);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t23 = *((char **)t18);
    t25 = (t23 + 0U);
    t26 = *((char **)t25);
    t13 = ((int  (*)(char *, char *))t26)(t0, t15);
    if (t13 != 0)
        goto LAB21;

LAB20:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB18:    t27 = (t0 + 3840);
    t28 = *((char **)t27);
    t27 = (t0 + 696);
    t29 = (t0 + 3840);
    t30 = *((char **)t29);
    t29 = (t0 + 3792);
    t31 = 0;
    xsi_delete_subprogram_invocation(t27, t30, t0, t29, t31);
    xsi_set_current_line(123, ng0);
    t2 = ((char*)((ng26)));
    t3 = ((char*)((ng22)));
    t4 = ((char*)((ng27)));
    t5 = ((char*)((ng28)));
    t6 = (t0 + 3792);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2008);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2100);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2192);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2284);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB23:    t14 = (t0 + 3840);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t23 = *((char **)t18);
    t25 = (t23 + 0U);
    t26 = *((char **)t25);
    t13 = ((int  (*)(char *, char *))t26)(t0, t15);
    if (t13 != 0)
        goto LAB25;

LAB24:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB22:    t27 = (t0 + 3840);
    t28 = *((char **)t27);
    t27 = (t0 + 696);
    t29 = (t0 + 3840);
    t30 = *((char **)t29);
    t29 = (t0 + 3792);
    t31 = 0;
    xsi_delete_subprogram_invocation(t27, t30, t0, t29, t31);
    xsi_set_current_line(124, ng0);
    t2 = ((char*)((ng23)));
    t3 = ((char*)((ng22)));
    t4 = ((char*)((ng29)));
    t5 = ((char*)((ng30)));
    t6 = (t0 + 3792);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2008);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2100);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2192);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2284);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB27:    t14 = (t0 + 3840);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t23 = *((char **)t18);
    t25 = (t23 + 0U);
    t26 = *((char **)t25);
    t13 = ((int  (*)(char *, char *))t26)(t0, t15);
    if (t13 != 0)
        goto LAB29;

LAB28:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB26:    t27 = (t0 + 3840);
    t28 = *((char **)t27);
    t27 = (t0 + 696);
    t29 = (t0 + 3840);
    t30 = *((char **)t29);
    t29 = (t0 + 3792);
    t31 = 0;
    xsi_delete_subprogram_invocation(t27, t30, t0, t29, t31);
    xsi_set_current_line(125, ng0);
    t2 = ((char*)((ng31)));
    t3 = ((char*)((ng22)));
    t4 = ((char*)((ng27)));
    t5 = ((char*)((ng32)));
    t6 = (t0 + 3792);
    t7 = (t0 + 696);
    t8 = xsi_create_subprogram_invocation(t6, 0, t0, t7, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t7, t8);
    t9 = (t0 + 2008);
    xsi_vlogvar_assign_value(t9, t2, 0, 0, 2);
    t10 = (t0 + 2100);
    xsi_vlogvar_assign_value(t10, t3, 0, 0, 4);
    t11 = (t0 + 2192);
    xsi_vlogvar_assign_value(t11, t4, 0, 0, 32);
    t12 = (t0 + 2284);
    xsi_vlogvar_assign_value(t12, t5, 0, 0, 80);

LAB31:    t14 = (t0 + 3840);
    t15 = *((char **)t14);
    t16 = (t15 + 40U);
    t17 = *((char **)t16);
    t18 = (t17 + 132U);
    t23 = *((char **)t18);
    t25 = (t23 + 0U);
    t26 = *((char **)t25);
    t13 = ((int  (*)(char *, char *))t26)(t0, t15);
    if (t13 != 0)
        goto LAB33;

LAB32:    t15 = (t0 + 696);
    xsi_vlog_subprogram_popinvocation(t15);

LAB30:    t27 = (t0 + 3840);
    t28 = *((char **)t27);
    t27 = (t0 + 696);
    t29 = (t0 + 3840);
    t30 = *((char **)t29);
    t29 = (t0 + 3792);
    t31 = 0;
    xsi_delete_subprogram_invocation(t27, t30, t0, t29, t31);
    xsi_set_current_line(128, ng0);
    xsi_vlogfile_write(1, 0, ng20, 1, t0);
    xsi_set_current_line(129, ng0);
    xsi_vlogfile_write(1, 0, ng33, 1, t0);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 6616);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6636);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6656);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng22)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    xsi_vlogfile_write(1, 0, ng34, 2, t0, (char)118, t22, 32);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 6676);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6696);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6716);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng26)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    xsi_vlogfile_write(1, 0, ng35, 2, t0, (char)118, t22, 32);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 6736);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6756);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6776);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng37)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    xsi_vlogfile_write(1, 0, ng36, 2, t0, (char)118, t22, 32);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 6796);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6816);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6836);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng39)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    xsi_vlogfile_write(1, 0, ng38, 2, t0, (char)118, t22, 32);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 6856);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 32U);
    t5 = *((char **)t4);
    t6 = (t0 + 6876);
    t7 = *((char **)t6);
    t8 = ((((char*)(t7))) + 40U);
    t9 = *((char **)t8);
    t10 = (t0 + 6896);
    t11 = *((char **)t10);
    t12 = ((((char*)(t11))) + 36U);
    t14 = *((char **)t12);
    t15 = ((char*)((ng41)));
    xsi_vlog_generic_get_array_select_value(t22, 32, t5, t9, t14, 2, 1, t15, 6, 2);
    xsi_vlogfile_write(1, 0, ng40, 2, t0, (char)118, t22, 32);
    xsi_set_current_line(141, ng0);
    xsi_vlogfile_write(1, 0, ng20, 1, t0);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 1824);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t0 + 1916);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    xsi_vlogfile_write(1, 0, ng42, 3, t0, (char)119, t4, 32, (char)119, t7, 32);
    xsi_set_current_line(145, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

LAB15:    xsi_set_current_line(117, ng0);
    t6 = (t0 + 4096);
    *((int *)t6) = 1;
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    t2 = (t0 + 6596);
    t13 = *((int *)t2);
    *((int *)t2) = (t13 - 1);
    goto LAB14;

LAB21:    t14 = (t0 + 3876U);
    *((char **)t14) = &&LAB19;
    goto LAB1;

LAB25:    t14 = (t0 + 3876U);
    *((char **)t14) = &&LAB23;
    goto LAB1;

LAB29:    t14 = (t0 + 3876U);
    *((char **)t14) = &&LAB27;
    goto LAB1;

LAB33:    t14 = (t0 + 3876U);
    *((char **)t14) = &&LAB31;
    goto LAB1;

}


extern void work_m_00000000001359687948_0971759850_init()
{
	static char *pe[] = {(void *)I5_0,(void *)A6_1,(void *)I9_2,(void *)A10_3,(void *)A33_4,(void *)I49_5,(void *)A75_6,(void *)A88_7,(void *)I97_8};
	static char *se[] = {(void *)sp_clear_shadow,(void *)sp_check};
	xsi_register_didat("work_m_00000000001359687948_0971759850", "isim/_tmp/work/m_00000000001359687948_0971759850.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
